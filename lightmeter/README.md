# lightmeter
An open hardware light meter designed for analog photography based on a BH1750 ambient light sensor running off of an ATMega328P microcontroller.

* Development has stopped, this project is dead.

### Current Iteration: Revision 1
<img src="https://imgur.com/pm2ZVXc.png" width=40% height=40%>
Image of prototype.

### Project Goals
* Build a compact, accurate handheld light meter.
* Design several alternatives, for hotshoe mounting and handheld direct & incident measuring.
  > PCB must be somewhat modular and versatile, so as to be used both in the handheld and hotshoe variants without changes to the design.

### Project Progress
- [x] Build A Prototype.
- [x] Find Sensor With Enough Range.
  > Decided on the BH1750 for it's better measurement range. Other variants of this chip exist with the same resolution but with analog voltage output instead of serial, but the ATMega328P doesn't have the best analog readouts, so readings would be bad.
- [x] Find Adequate Cheap Microcontroller.
  > Decided on the ATMega328P-AU due to it fitting my requirements. This might not be in future iterations as this chip is quite expensive for it's capabilities, however I happen to have just about 9 of these, so yeah... In the future, I plan to design a RP2040 version in the same form factor.
- [x] Find *Easily Viewable Under Heavy Sunlight* Screen.
  > Decided on the Nokia 5110 instead of an 128x64 OLED because of a better viewing experience under heavy sunlight.
- [ ] Build Prototype.
- [ ] Write Full Firmware.

### Licenses
* CERN Open Hardware Licence Version 2.0 - Strongly Reciprocal.
* GNU GENERAL PUBLIC LICENSE Verson 3.0.
