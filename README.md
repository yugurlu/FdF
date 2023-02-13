# FdF
FdF is a 42 Project to learn about 3d programming. The program takes a map as parameter and creates its 3d representation.

It uses the library miniLibX, developed internally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard, mouse and “expose”. Pretty much, this project introduces the events programming.

## Getting Started

### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`

### Executing

To execute the program:

`./fdf <fdf-file>`

#### Try it!

Try running the following:

`./fdf maps/test_maps/42.fdf`

`./fdf maps/test_maps/mars.fdf`

`./fdf maps/personal/panama.fdf`
