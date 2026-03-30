# Boardoza Rotary Encoder EC1101S Breakout Board

The **Boardoza Rotary Encoder EC1101S Breakout Board** is a multifunctional input and visual feedback solution that combines a **mechanical rotary encoder with an integrated push button** and **addressable RGB LEDs (ARGB)** on a single compact PCB. This board converts rotational motion into digital signals while simultaneously enabling dynamic visual effects through programmable LEDs.

By integrating **14 cascaded ARGB LEDs** directly around the encoder, the board allows users to visually represent rotation, direction, speed, or system states. Each encoder movement can be interpreted by a microcontroller (such as Arduino, ESP32, or similar platforms) to control LED color, brightness, and animation patterns, making it ideal for interactive interfaces, control panels, and creative electronics projects.

## [Click here to purchase!](https://www.ozdisan.com/ureticiler/boardoza)

| Front Side | Back Side |
|:---:|:---:|
| ![ROTARY ENCODER EC1101S Front](./assets/B-ROTARY%20ENCODER_EC1101S%20Front.png) | ![ROTARY ENCODER EC1101S Back](./assets/B-ROTARY%20ENCODER_EC1101S%20Back.png) |

---

## Key Features

- **Rotary Encoder with Push Button:** Mechanical rotary encoder with integrated momentary push button for menu navigation and user input.
- **Integrated Addressable RGB LEDs:** Features 14 cascaded ARGB LEDs for dynamic visual feedback and animation effects.
- **Quadrature Output Signals:** Provides A and B channel outputs for accurate direction and rotation detection.
- **Visual Motion Representation:** Encoder rotation can be visually expressed through programmable LED color, pattern, and brightness changes.
- **Wide Logic Compatibility:** Fully compatible with both 3.3 V and 5 V microcontroller systems.
- **Expandable LED Chain:** ARGB data and clock input/output pins allow cascading with additional LED boards.
- **20 Pulses per Revolution:** Provides 20 pulses per 360° rotation (per phase) for precise rotational detection.

---

## Technical Specifications  

**Model:** Rotary Encoder EC1101S  
**Manufacturer:** Boardoza  
**Encoder Type:** Mechanical rotary encoder with push button  
**LED Type:** Addressable RGB (ARGB)  
**Number of LEDs:** 14  
**LED Interface:** Serial Data (DIN/DOUT), Clock (CIN/COUT)  
**Signal Outputs:** Encoder A, Encoder B, Push Button (SW)  
**Input Voltage:** 3.3 V / 5 V  
**Logic Level:** 3.3 V / 5 V compatible  
**Operating Temperature:** -40 °C to +85 °C  
**Board Dimensions:** 40 mm × 40 mm  


---

## Board Pinout

### **( J1 ) Main Connector**

| Pin Number | Pin Name | Description |
|:---:|:---:|---|
| 1 | VCC (3V3–5V) | Power supply input |
| 2 | SW | Encoder push button output (Active Low) |
| 3 | DOUT | ARGB serial data output |
| 4 | COUT | ARGB clock output |
| 5 | CIN | ARGB clock input |
| 6 | DIN | ARGB serial data input |
| 7 | Terminal_B | Encoder B channel output |
| 8 | Terminal_A | Encoder A channel output |
| 9 | GND | Ground |

---

## Board Dimensions

![Board Dimensions](./assets/B-ROTARY%20ENCODER_EC1101S%20Dimensions.png)

---

## Step Files

[Boardoza ROTARY ENCODER.step](./assets/B-ROTARY%20ENCODER_EC1101S%20Step.step)

---

## Datasheet

- [PLCC IC + RGB LEDs Datasheet.pdf](./assets/PLCC%20IC+RGB%20LEDs%20Datasheet.pdf)  
- [ROTARY ENCODER EC1101S Breakout Datasheet.pdf](./assets/B-ROTARY%20ENCODER_EC1101S%20Datasheet.pdf)

---

## Version History

- **V1.0.0** – Initial Release

---

## Support

- For questions or technical support, please contact **support@boardoza.com**

---

## **License**

This repository contains both hardware and software components:

### **Hardware Design**

[![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

All hardware design files are licensed under [Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

### **Software/Firmware**

[![BSD-3-Clause][bsd-shield]][bsd]

All software and firmware are licensed under [BSD 3-Clause License][bsd].

[bsd]: https://opensource.org/licenses/BSD-3-Clause
[bsd-shield]: https://img.shields.io/badge/License-BSD%203--Clause-blue.svg
