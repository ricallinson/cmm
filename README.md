# C Minus Minus

An experiment in coding C differently.

## Thoughts

Steal all the good things from Go.

* A module directory contains *.c files.
* Any public functions or variables must start with a capital letter.
* An `_` used to start a function or variable name will be replaced with the modules directory name and become public.
* Header files are generated automatically from publicly declared functions or variables.
* A publicly declared `struct` must have _Create() and _Free() functions which `malloc` and `free` all memory for that `struct`.
