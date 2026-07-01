"""
VSL-DSP HID I/O Module (OPCIONAL)
Comunicación real con hardware via hidapi.
Requiere: pip install hidapi

⚠️ Este módulo solo funcionará cuando los 3 bloqueadores estén resueltos:
   - VSL_VENDOR_ID
   - VSL_PRODUCT_ID
   - VSL_REPORT_ID
"""

from typing import Optional
import sys

try:
    import hid
    HID_AVAILABLE = True
except ImportError:
    HID_AVAILABLE = False
    print("⚠️ Advertencia: hidapi no está instalado. I/O real no disponible.")
    print("   Instalar con: pip install hidapi")

from vsl_config import (
    VSL_VENDOR_ID,
    VSL_PRODUCT_ID,
    validate_configuration
)
from vsl_transport import VSLPacket


class VSLDevice:
    """
    Gestor de dispositivo VSL-DSP con patrón Singleton.
    Maneja la conexión HID y envío de paquetes.
    """
    
    _instance: Optional['VSLDevice'] = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance._initialized = False
        return cls._instance
    
    def __init__(self):
        if self._initialized:
            return
        
        if not HID_AVAILABLE:
            raise RuntimeError("hidapi no está disponible")
        
        is_valid, message = validate_configuration()
        if not is_valid:
            raise RuntimeError(f"Configuración inválida: {message}")
        
        self._handle: Optional[hid.device] = None
        self._initialized = True
    
    def open(self) -> bool:
        """
        Abre la conexión con el dispositivo VSL.
        
        Returns:
            True si la conexión fue exitosa, False en caso contrario
        """
        if self._handle is not None:
            print("⚠️ Dispositivo ya está abierto")
            return True
        
        try:
            self._handle = hid.device()
            self._handle.open(VSL_VENDOR_ID, VSL_PRODUCT_ID)
            
            # Obtener información del dispositivo
            manufacturer = self._handle.get_manufacturer_string()
            product = self._handle.get_product_string()
            
            print(f"✅ Dispositivo VSL conectado:")
            print(f"   Manufacturer: {manufacturer}")
            print(f"   Product: {product}")
            print(f"   VID:PID: {VSL_VENDOR_ID:04X}:{VSL_PRODUCT_ID:04X}")
            
            return True
        
        except Exception as e:
            print(f"❌ Error abriendo dispositivo: {e}")
            self._handle = None
            return False
    
    def close(self):
        """Cierra la conexión con el dispositivo."""
        if self._handle:
            try:
                self._handle.close()
                print("✅ Dispositivo VSL cerrado")
            except Exception as e:
                print(f"⚠️ Error cerrando dispositivo: {e}")
            finally:
                self._handle = None
    
    def send_packet(self, packet: VSLPacket) -> bool:
        """
        Envía un paquete VSL al dispositivo.
        
        Args:
            packet: VSLPacket a enviar
            
        Returns:
            True si el envío fue exitoso
        """
        if self._handle is None:
            print("❌ Error: Dispositivo no está abierto. Llama a open() primero.")
            return False
        
        # Validar paquete antes de enviar
        is_valid, message = packet.validate()
        if not is_valid:
            print(f"❌ Error: Paquete inválido - {message}")
            return False
        
        try:
            # Enviar via HID Write (Output Report)
            # Nota: Alternativamente usar send_feature_report() si el dispositivo usa Feature Reports
            bytes_written = self._handle.write(packet.buffer)
            
            if bytes_written < 0:
                print(f"❌ Error en escritura HID: {bytes_written}")
                return False
            
            print(f"✅ Paquete enviado: {packet}")
            print(f"   Bytes escritos: {bytes_written}")
            
            return True
        
        except Exception as e:
            print(f"❌ Error enviando paquete: {e}")
            return False
    
    def __enter__(self):
        """Context manager entry."""
        self.open()
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        """Context manager exit."""
        self.close()


def enumerate_vsl_devices():
    """
    Enumera todos los dispositivos HID conectados.
    Útil para descubrir VID/PID del hardware.
    """
    if not HID_AVAILABLE:
        print("❌ hidapi no está disponible")
        return
    
    print("=== Enumeración de Dispositivos HID ===\n")
    
    for device_info in hid.enumerate():
        vendor_id = device_info['vendor_id']
        product_id = device_info['product_id']
        manufacturer = device_info['manufacturer_string']
        product = device_info['product_string']
        
        # Filtrar por fabricantes conocidos de audio
        if manufacturer and any(keyword in manufacturer.lower() 
                               for keyword in ['presonus', 'audiobox', 'studiolive']):
            print(f"🎵 Dispositivo de Audio Encontrado:")
            print(f"   VID:PID       : 0x{vendor_id:04X}:0x{product_id:04X}")
            print(f"   Manufacturer  : {manufacturer}")
            print(f"   Product       : {product}")
            print(f"   Path          : {device_info['path']}")
            print(f"   Interface     : {device_info['interface_number']}")
            print("---\n")


# ============================================================================
# EJEMPLO DE USO
# ============================================================================

if __name__ == "__main__":
    print("=== VSL-DSP HID I/O Module ===\n")
    
    # Opción 1: Enumerar dispositivos (descubrimiento)
    if len(sys.argv) > 1 and sys.argv[1] == "--enumerate":
        enumerate_vsl_devices()
        sys.exit(0)
    
    # Opción 2: Test de conexión (requiere valores configurados)
    is_valid, message = validate_configuration()
    if not is_valid:
        print(f"❌ {message}")
        print("\nEjecuta con --enumerate para descubrir dispositivos:")
        print("   python vsl_hid_io.py --enumerate")
        sys.exit(1)
    
    # Test de conexión
    try:
        device = VSLDevice()
        
        if device.open():
            print("\n✅ Test de conexión exitoso")
            
            # Ejemplo: Enviar un paquete de prueba
            from vsl_config import GAIN_CH1
            from vsl_core import vsl_encode_gain, vsl_final_encode_to_int
            
            test_value = 0.75
            encoded_float = vsl_encode_gain(test_value, GAIN_CH1)
            encoded_int = vsl_final_encode_to_int(encoded_float, GAIN_CH1)
            
            test_packet = VSLPacket(GAIN_CH1.dsp_param_id, encoded_int)
            
            print(f"\nEnviando paquete de prueba (Gain 75%)...")
            device.send_packet(test_packet)
            
            device.close()
        else:
            print("❌ No se pudo conectar al dispositivo")
    
    except Exception as e:
        print(f"❌ Error: {e}")
        import traceback
        traceback.print_exc()
