# orphans

*Community 7 | 7 files | cohesion 0.00*

## Definition

This community groups 7 file(s) rooted at `legacy` with dominant language sh (cohesion 0.00). Central symbols: `VSLParameter`, `__init__`, `analyze_pcap`, `bad`, `build_with_dkms`, `check_dependencies`, `check_root`, `copy_source_files`. Core file: `legacy/build-dkms.sh` (19 symbols). Documented purpose: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:.

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `install.sh` | sh | utility | 0 | yes |
| `legacy/app.py` | py | utility | 0 | yes |
| `legacy/build-dkms.sh` | sh | utility | 19 | yes |
| `legacy/test.sh` | sh | testing | 0 | yes |
| `legacy/vsl_config.py` | py | infrastructure | 3 | yes |
| `legacy/vsl_protocol_analyzer.py` | py | utility | 7 | yes |
| `tests/bdd_driver_gate.sh` | sh | infrastructure | 2 | yes |

## Key Symbols

- `print_header` (function, `legacy/build-dkms.sh:40`)
- `print_success` (function, `legacy/build-dkms.sh:48`)
- `print_error` (function, `legacy/build-dkms.sh:52`)
- `print_warning` (function, `legacy/build-dkms.sh:56`)
- `print_info` (function, `legacy/build-dkms.sh:60`)
- `check_root` (function, `legacy/build-dkms.sh:64`)
- `check_dependencies` (function, `legacy/build-dkms.sh:72`)
- `detect_audiobox` (function, `legacy/build-dkms.sh:101`)
- `create_source_structure` (function, `legacy/build-dkms.sh:123`)
- `copy_source_files` (function, `legacy/build-dkms.sh:138`)
- `create_dkms_conf` (function, `legacy/build-dkms.sh:174`)
- `create_makefile` (function, `legacy/build-dkms.sh:193`)
- `verify_mixer_quirks` (function, `legacy/build-dkms.sh:252`)
- `build_with_dkms` (function, `legacy/build-dkms.sh:295`)
- `install_module` (function, `legacy/build-dkms.sh:309`)
- `reload_module` (function, `legacy/build-dkms.sh:323`)
- `verify_installation` (function, `legacy/build-dkms.sh:344`)
- `show_usage_info` (function, `legacy/build-dkms.sh:394`)
- `main` (function, `legacy/build-dkms.sh:452`)
- `VSLParameter` (class, `legacy/vsl_config.py:40`) `class VSLParameter(NamedTuple)` - Estructura que replica exactamente VSL_Parameter del código C.
- `validate_configuration` (method, `legacy/vsl_config.py:92`) `def validate_configuration()` - Valida que todos los valores críticos estén configurados.
- `print_configuration_status` (method, `legacy/vsl_config.py:116`) `def print_configuration_status()` - Imprime el estado de la configuración con formato.
- `VSLParameter` (class, `legacy/vsl_protocol_analyzer.py:28`) `class VSLParameter` - Parámetros DSP descifrados con coeficientes y rangos.
- `__init__` (method, `legacy/vsl_protocol_analyzer.py:30`) `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1,`
- `reverse_map_gain` (method, `legacy/vsl_protocol_analyzer.py:67`) `def reverse_map_gain(encoded_value, param)` - Simula VSL_Decode_Gain. Convierte un entero a un valor de usuario (dB).
- `reverse_map_frequency` (method, `legacy/vsl_protocol_analyzer.py:95`) `def reverse_map_frequency(encoded_value, param)` - Simula VSL_Decode_Frequency. Convierte un entero a frecuencia (Hz).
- `get_decoded_value` (method, `legacy/vsl_protocol_analyzer.py:115`) `def get_decoded_value(encoded_value, param_id)` - Dirige la decodificación al motor DSP correcto.
- `decode_vsl_packet` (method, `legacy/vsl_protocol_analyzer.py:140`) `def decode_vsl_packet(data)` - Decodifica el payload de 64 bytes. (Regla #3: Seguridad)
- `analyze_pcap` (method, `legacy/vsl_protocol_analyzer.py:173`) `def analyze_pcap(pcap_file)` - Carga un archivo PCAP y filtra los paquetes USB VSL.
- `ok` (function, `tests/bdd_driver_gate.sh:29`)

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 0
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 0 (voicecloak/src: vc_denoise) and community 7 (orphans).
- [INFERRED] shares_context community 1 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 1 (voicecloak/src: vc_effects) and community 7 (orphans).
- [INFERRED] shares_context community 2 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 2 (legacy) and community 7 (orphans).
- [INFERRED] shares_context community 3 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 3 (voicecloak/src: vc_crypto) and community 7 (orphans).
- [INFERRED] shares_context community 4 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 4 (src) and community 7 (orphans).
- [INFERRED] shares_context community 5 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 5 (root) and community 7 (orphans).

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- What would break if the most connected file in orphans changed?
- Should orphans be split, given cohesion 0.00?

## Sources

- `install.sh`
- `legacy/app.py`
- `legacy/build-dkms.sh`
- `legacy/test.sh`
- `legacy/vsl_config.py`
- `legacy/vsl_protocol_analyzer.py`
- `tests/bdd_driver_gate.sh`
