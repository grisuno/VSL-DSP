"""
VSL-DSP Transport Module
Construcción y validación de paquetes HID.
"""

from typing import Optional
from vsl_config import (
    VSL_PACKET_SIZE,
    VSL_REPORT_ID,
    VSLParameter,
    validate_configuration
)


class VSLPacket:
    """
    Representa un paquete HID VSL-DSP de 64 bytes.
    Implementa construcción y validación con seguridad de tipos.
    """
    
    def __init__(self, param_id: int, encoded_value: int, report_id: Optional[int] = None):
        """
        Construye un paquete VSL-DSP.
        
        Args:
            param_id: ID del parámetro DSP (16-bit, ej: 0x1A01)
            encoded_value: Valor codificado (16-bit, 0-65535)
            report_id: Report ID HID (8-bit, None usa configuración global)
            
        Raises:
            ValueError: Si los valores están fuera de rango
            RuntimeError: Si VSL_REPORT_ID no está configurado y report_id es None
        """
        # Validación de rangos
        if not (0 <= param_id <= 0xFFFF):
            raise ValueError(f"param_id fuera de rango 16-bit: 0x{param_id:X}")
        
        if not (0 <= encoded_value <= 0xFFFF):
            raise ValueError(f"encoded_value fuera de rango 16-bit: {encoded_value}")
        
        # Determinar Report ID
        if report_id is None:
            if VSL_REPORT_ID is None:
                raise RuntimeError(
                    "VSL_REPORT_ID no configurado. "
                    "Proporciona report_id explícitamente o configura VSL_REPORT_ID."
                )
            report_id = VSL_REPORT_ID
        
        if not (0 <= report_id <= 0xFF):
            raise ValueError(f"report_id fuera de rango 8-bit: 0x{report_id:X}")
        
        self.param_id = param_id
        self.encoded_value = encoded_value
        self.report_id = report_id
        self._buffer = self._build_buffer()
    
    def _build_buffer(self) -> bytearray:
        """
        Construye el buffer de 64 bytes según el protocolo VSL-DSP.
        
        Estructura (Little-Endian):
          [0]    : Report ID
          [1-2]  : Parameter ID (LSB, MSB)
          [3-4]  : Encoded Value (LSB, MSB)
          [5-63] : Padding (0x00)
        
        Returns:
            bytearray de 64 bytes
        """
        buf = bytearray(VSL_PACKET_SIZE)
        
        # Byte 0: Report ID
        buf[0] = self.report_id
        
        # Bytes 1-2: Parameter ID (Little-Endian)
        buf[1] = self.param_id & 0xFF          # LSB
        buf[2] = (self.param_id >> 8) & 0xFF   # MSB
        
        # Bytes 3-4: Encoded Value (Little-Endian)
        buf[3] = self.encoded_value & 0xFF          # LSB
        buf[4] = (self.encoded_value >> 8) & 0xFF   # MSB
        
        # Bytes 5-63: Ya son 0x00 por inicialización de bytearray
        
        return buf
    
    @property
    def buffer(self) -> bytes:
        """Retorna el buffer como bytes inmutables."""
        return bytes(self._buffer)
    
    def hex_dump(self, num_bytes: int = 8) -> str:
        """
        Genera un hex dump del paquete para debugging.
        
        Args:
            num_bytes: Número de bytes a mostrar (default: 8)
            
        Returns:
            String con formato hexadecimal
        """
        hex_bytes = [f"0x{b:02X}" for b in self._buffer[:num_bytes]]
        return " ".join(hex_bytes)
    
    def validate(self) -> tuple[bool, str]:
        """
        Valida la integridad del paquete.
        
        Returns:
            (is_valid, message)
        """
        # Verificar tamaño
        if len(self._buffer) != VSL_PACKET_SIZE:
            return False, f"Tamaño inválido: {len(self._buffer)} != {VSL_PACKET_SIZE}"
        
        # Verificar Report ID
        if self._buffer[0] != self.report_id:
            return False, "Report ID corrupto en buffer"
        
        # Verificar reconstrucción de Parameter ID (Little-Endian)
        reconstructed_id = self._buffer[1] | (self._buffer[2] << 8)
        if reconstructed_id != self.param_id:
            return False, f"Parameter ID corrupto: {reconstructed_id:04X} != {self.param_id:04X}"
        
        # Verificar reconstrucción de Encoded Value
        reconstructed_val = self._buffer[3] | (self._buffer[4] << 8)
        if reconstructed_val != self.encoded_value:
            return False, f"Encoded Value corrupto: {reconstructed_val} != {self.encoded_value}"
        
        return True, "Paquete válido"
    
    def __repr__(self) -> str:
        return (
            f"VSLPacket(report_id=0x{self.report_id:02X}, "
            f"param_id=0x{self.param_id:04X}, "
            f"value={self.encoded_value})"
        )


def build_packet_safe(param: VSLParameter, encoded_value: int) -> Optional[VSLPacket]:
    """
    Construye un paquete con manejo de errores.
    
    Args:
        param: Parámetro DSP
        encoded_value: Valor codificado (0-65535)
        
    Returns:
        VSLPacket o None si hay error
    """
    try:
        packet = VSLPacket(param.dsp_param_id, encoded_value)
        is_valid, message = packet.validate()
        
        if not is_valid:
            print(f"⚠️ Error de validación: {message}")
            return None
        
        return packet
    
    except (ValueError, RuntimeError) as e:
        print(f"⚠️ Error construyendo paquete: {e}")
        return None


if __name__ == "__main__":
    from vsl_config import GAIN_CH1
    
    print("=== Tests de vsl_transport.py ===\n")
    
    # Test 1: Construcción con Report ID explícito (bypass del bloqueador)
    print("Test 1: Construcción con Report ID explícito (0x01)")
    packet = VSLPacket(param_id=0x1A01, encoded_value=40793, report_id=0x01)
    
    print(f"  {packet}")
    print(f"  Hex Dump: {packet.hex_dump()}")
    
    is_valid, message = packet.validate()
    print(f"  Validación: {'✅' if is_valid else '❌'} - {message}\n")
    
    # Test 2: Verificación de endianness
    print("Test 2: Verificación de Little-Endian")
    buf = packet.buffer
    print(f"  Byte[1] (ID LSB): 0x{buf[1]:02X} (esperado: 0x01)")
    print(f"  Byte[2] (ID MSB): 0x{buf[2]:02X} (esperado: 0x1A)")
    print(f"  Byte[3] (Val LSB): 0x{buf[3]:02X} (esperado: 0x39)")
    print(f"  Byte[4] (Val MSB): 0x{buf[4]:02X} (esperado: 0x9F)")
    
    assert buf[1] == 0x01 and buf[2] == 0x1A, "❌ Error en endianness de ID"
    assert buf[3] == 0x39 and buf[4] == 0x9F, "❌ Error en endianness de Value"
    print("  ✅ Endianness verificado correctamente\n")
    
    # Test 3: Validación de rangos
    print("Test 3: Validación de rangos")
    try:
        bad_packet = VSLPacket(param_id=0x1FFFF, encoded_value=40793, report_id=0x01)
        print("  ❌ Error: Debería haber lanzado ValueError")
    except ValueError as e:
        print(f"  ✅ ValueError capturado correctamente: {e}")