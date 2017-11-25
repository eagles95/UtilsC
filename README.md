# UtilsC
Some Common Abstract Data Types implemented in C. Handy for various other projects.
# Notes
This implementation is completely modular, change `include/object.h` to suit your needs, the only requirement is a key atribute.<br />
All comparison between objects are done on the Compare method in `src/object.c`
# Usage
With no installation: <br />
`gcc -I pathToUtilsC/include/ pathToUtilsC/*.c yourcode.c`<br />
You can install with:<br />
`sudo make install`<br />
and compile your files with the `-lutilsc` gcc flag <br />
to uninstall:<br />
`sudo make uninstall`<br />
