# Embedded 2

## Supported mcu
* stm32f407 (stm32f4 discovery)
* [to be supported] stm32f103
* ti ....

## How to compile an example
* arm-none-eabi-gcc must be in PATH
* create a workspace folder (e.g. in embedded2/example/uart/workspace
* type cmake ../ -mcu="stm32f407" (you can specify `-DCMAKE_BUILD_TYPE=<Relesase|Debug>`)
* make
* two files will be created in the workspace folder:
	* openocd.cfg
	* .gdbinit
* launch openocd, you should see a message like : 

```
Open On-Chip Debugger 0.7.0 (2015-01-02-12:46)
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.sourceforge.net/doc/doxygen/bugs.html
srst_only separate srst_nogate srst_open_drain connect_deassert_srst
Info : This adapter doesn't support configurable speed
Info : STLINK v2 JTAG v17 API v2 SWIM v0 VID 0x0483 PID 0x3748
Info : Target voltage: 2.885076
Info : stm32f4x.cpu: hardware has 6 breakpoints, 4 watchpoints
```

* lauchn `arm-none-eabi-gdb test_uart_stm32f407`:
	* type `monitor reset init`
	* type `load`
	* type `run`

## Architecture 

```
embedded2
	|
	|____ backend	: specific code of each mcu 
	|
	|____ cmake		: cmake scripts
	|
	|____ example	: code examples
	|
	|____ hal		: hardware abstraction layer.
					  example must only use these headers
```