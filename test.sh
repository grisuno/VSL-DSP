#!/bin/bash
# ====================================================================
# VSL-DSP: Captura COMPLETA de tráfico USB del AudioBox
# ====================================================================

CAPTURE_FILE="vsl_official_complete.pcap"
CAPTURE_DURATION=60  # segundos

echo "========================================================================"
echo "  CAPTURA DE TRÁFICO USB - AudioBox 22 VSL"
echo "========================================================================"
echo ""

# Verificar que el dispositivo está conectado
if ! lsusb -d 194f:0101 > /dev/null 2>&1; then
    echo "❌ ERROR: AudioBox 22 VSL no está conectado"
    exit 1
fi

echo "✅ AudioBox 22 VSL detectado"
echo ""

# Cargar módulo usbmon
echo "📡 Cargando módulo de monitoreo USB..."
sudo modprobe usbmon

# Verificar permisos
if [ ! -r /sys/kernel/debug/usb/usbmon/ ]; then
    echo "⚠️ Requiere permisos de superusuario"
fi

echo ""
echo "========================================================================"
echo "  INSTRUCCIONES PARA LA CAPTURA"
echo "========================================================================"
echo ""
echo "1. La captura comenzará en 5 segundos"
echo "2. Una vez iniciada, tienes ${CAPTURE_DURATION} segundos para:"
echo "   - Abrir el software Universal Control de PreSonus"
echo "   - Mover UN control (ej: gain del canal 1)"
echo "   - Esperar 2 segundos"
echo "   - Mover OTRO control (ej: gain del canal 2)"
echo "   - Cerrar el software"
echo ""
echo "3. La captura se detendrá automáticamente"
echo ""

read -p "Presiona ENTER cuando estés listo..."

echo ""
echo "🚀 Iniciando captura en 5 segundos..."
sleep 5

echo ""
echo "📡 CAPTURANDO... (${CAPTURE_DURATION} segundos)"
echo "   ¡AHORA ABRE EL SOFTWARE Y MUEVE CONTROLES!"
echo ""

# Capturar en usbmon0 (TODOS los buses USB)
sudo timeout ${CAPTURE_DURATION} tcpdump -i usbmon0 -w ${CAPTURE_FILE} 2>&1 | \
    grep -v "tcpdump: listening" &
TCPDUMP_PID=$!

# Contador visual
for i in $(seq 1 $CAPTURE_DURATION); do
    printf "\r   Tiempo restante: %2d segundos" $((CAPTURE_DURATION - i))
    sleep 1
done

wait $TCPDUMP_PID 2>/dev/null

echo ""
echo ""
echo "✅ Captura completada"
echo ""

# Verificar que se capturó algo
if [ ! -f "${CAPTURE_FILE}" ]; then
    echo "❌ ERROR: No se creó el archivo de captura"
    exit 1
fi

FILESIZE=$(stat -f%z "${CAPTURE_FILE}" 2>/dev/null || stat -c%s "${CAPTURE_FILE}" 2>/dev/null)
echo "📁 Archivo: ${CAPTURE_FILE}"
echo "📊 Tamaño: $((FILESIZE / 1024)) KB"

if [ $FILESIZE -lt 1000 ]; then
    echo ""
    echo "⚠️ ADVERTENCIA: Archivo muy pequeño"
    echo "   Puede que no se haya usado el software durante la captura"
fi

echo ""
echo "--- ANÁLISIS RÁPIDO ---"
echo ""

# Verificar si hay tráfico del AudioBox
PACKET_COUNT=$(sudo tshark -r ${CAPTURE_FILE} -Y "usb.idVendor == 0x194f" 2>/dev/null | wc -l)

if [ $PACKET_COUNT -gt 0 ]; then
    echo "✅ Se capturaron $PACKET_COUNT paquetes del AudioBox"
    echo ""
    echo "🎉 ¡ÉXITO! Ahora analiza con:"
    echo "   ./analyze_official_traffic.sh"
else
    echo "❌ No se capturó tráfico del AudioBox (0x194F)"
    echo ""
    echo "Posibles causas:"
    echo "   1. El software no se ejecutó durante la captura"
    echo "   2. El software no se comunicó con el dispositivo"
    echo "   3. El software usa otro método de comunicación"
    echo ""
    echo "Verifica que:"
    echo "   - El software Universal Control esté instalado"
    echo "   - El AudioBox esté conectado y detectado por el software"
    echo "   - Hayas movido controles durante los ${CAPTURE_DURATION} segundos"
fi

echo ""
echo "========================================================================"

# Cambiar permisos para análisis
sudo chmod 644 ${CAPTURE_FILE}