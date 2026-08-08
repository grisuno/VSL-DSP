# vsl_decode_gain Specification

## Module: VSL_Decode_Gain (pure DSP function)

### Purpose

Reverse the exponential gain encoding produced by `VSL_Encode_Gain`.
Given an encoded float value received from the DSP, recover the linear
control position [0.0, 1.0] that produced it.

### Source

`VSL_Encode_Gain` (reverse-engineered from `FUN_00132c90`):

```
clamped = clamp(linear, 0.0, 1.0)
range   = curve_max_map - curve_min_map
if range <= epsilon: return coeff_offset_A
norm    = (clamped - curve_min_map) / range
exp     = expf(norm * log_factor)
return coeff_offset_A + coeff_C1 * exp
```

The inverse must satisfy:

```
linear == VSL_Decode_Gain(VSL_Encode_Gain(linear, &p), &p)
```

for every valid parameter `p` and linear value in [0, 1] within
floating-point tolerance.

### Mathematical Derivation

```
encoded = coeff_offset_A + coeff_C1 * exp(norm * log_factor)
encoded - coeff_offset_A = coeff_C1 * exp(norm * log_factor)
(encoded - coeff_offset_A) / coeff_C1 = exp(norm * log_factor)
log((encoded - coeff_offset_A) / coeff_C1) = norm * log_factor
norm = log((encoded - coeff_offset_A) / coeff_C1) / log_factor
linear = norm * (curve_max_map - curve_min_map) + curve_min_map
```

### Inputs

| Param          | Type                    | Description                                      |
| -------------- | ----------------------- | ------------------------------------------------ |
| `encoded_float`| `float`                 | Output of VSL_Encode_Gain or DSP readback         |
| `param`        | `const VSL_Parameter *` | Same coefficients used during encoding            |

### Output

`float` in [0.0, 1.0] representing the linear control position.

### Error Handling

| Condition                                        | Return value                       |
| ------------------------------------------------ | ---------------------------------- |
| `coeff_C1 <= epsilon` (avoid div-zero in log arg)| `curve_min_map` clamped to [0,1]   |
| `(encoded - offset_A) / C1 <= 0.0` (negative log)| `curve_min_map` clamped to [0,1]   |
| `log_factor <= epsilon`                          | `curve_min_map` clamped to [0,1]   |
| `range <= epsilon` (curve_min == curve_max)      | `curve_min_map` clamped to [0,1]   |
| Result outside [0,1]                             | Clamp to [0,1]                     |

### Behavior (BDD)

#### Scenario: round-trip is identity

```
Given param coefficients for AudioBox 22 VSL Gain CH1
And a linear value of 0.75
When linear_value is encoded with VSL_Encode_Gain
And the encoded float is decoded with VSL_Decode_Gain
Then the decoded value equals 0.75 within 1e-4 tolerance
```

#### Scenario: round-trip at extremes

```
Given param coefficients for AudioBox 22 VSL Gain CH1
And linear values 0.0 and 1.0
When each is encoded with VSL_Encode_Gain
And each encoded float is decoded with VSL_Decode_Gain
Then decoded values are 0.0 and 1.0 within 1e-4 tolerance
```

#### Scenario: round-trip at midpoint

```
Given param coefficients for AudioBox 22 VSL Gain CH1
And a linear value of 0.5
When encoded with VSL_Encode_Gain and decoded with VSL_Decode_Gain
Then the decoded value equals 0.5 within 1e-4 tolerance
```

#### Scenario: decode of minimum encoded value

```
Given param coefficients
When VSL_Decode_Gain is called with encoded_float = coeff_offset_A + coeff_C1 * 1.0
   (corresponding to linear = curve_min_map)
Then the result equals curve_min_map within 1e-4
```

#### Scenario: decode of maximum encoded value

```
Given param coefficients
When VSL_Decode_Gain is called with encoded_float = coeff_offset_A + coeff_C1 * exp(log_factor)
   (corresponding to linear = curve_max_map)
Then the result equals curve_max_map within 1e-4
```

#### Scenario: coeff_C1 zero is safe

```
Given coeff_C1 = 0.0
When VSL_Decode_Gain is called
Then the function returns curve_min_map clamped to [0,1]
And no division by zero or NaN is produced
```

#### Scenario: log_factor zero is safe

```
Given log_factor = 0.0
When VSL_Decode_Gain is called
Then the function returns curve_min_map clamped to [0,1]
And no division by zero occurs
```

#### Scenario: encoded value below offset

```
Given encoded_float < coeff_offset_A
When VSL_Decode_Gain is called
Then curve_min_map clamped to [0,1] is returned
And log of a negative number is not attempted
```

### Round-trip Validation Data

Using GAIN_CH1_COEFFS (coeff_offset_A=-10, coeff_C1=20, log_factor=4.60517,
curve_min_map=0.0, curve_max_map=1.0):

| Linear | Encoded (approx) | Decoded (approx) | Tolerance |
|--------|------------------|------------------|-----------|
| 0.00   | 10.000           | 0.000            | 1e-4      |
| 0.25   | 36.241           | 0.250            | 1e-4      |
| 0.50   | 109.982          | 0.500            | 1e-4      |
| 0.75   | 622.460          | 0.750            | 1e-4      |
| 1.00   | 1989.000         | 1.000            | 1e-4      |

### Safety

- Pure function: no allocation, no I/O, no static state.
- Every division is guarded against near-zero divisor.
- `logf` argument is guarded positive.
- Output is always clamped to [0, 1].
- No `restrict` violations; only reads through `param`.
