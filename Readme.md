### Origin
This is a fork of msx_qrcode: 
https://github.com/MartinezTorres/msx_qrcode/tree/master

Which in turn is a fork of Nayuki's QR Code:
https://github.com/nayuki/QR-Code-generator

### A runtime QR Code generator for the Game Boy that can build with GBDK-2020

- The QR Code functions are configured to be ROM banked (~4800 bytes)
- The RAM usage appears to be modest
- The QR Code size must be selected at compile time. See `src/qr/qrcodegen.h`
- This demo does a very slow APA mode render of the QR Code at 4x. You can implement your own more optimized rendering. See `src/qr_wrapper.c`

![Game Boy QR Code Example](/gameboy_qrcode_screenshot.png)

See: https://github.com/gbdk-2020/gbdk-2020

TODO: There are a bunch of dead code warnings in the qr code generation that could be removed.


