# C Minus Minus

An experiment in coding C like it was Go.

__VERY UNSTABLE__

## Thoughts

* A workspace is a directory with `src`, `pkg` and `bin` sub directories.
* A package directory path under the `src` sub directory is a URI to a git repository.
* Path based `imports` are be resolved by using the path segments as a URI for a `git clone` should the package path not exist in the `src` directory.
* A package directory contains `*.c` files (no `*.h` files).
* Header files are generated automatically from publicly declared functions and variables.
* Public functions or variables must start with the packages directory name and a capital letter.
* A publicly declared `struct` must have public `MallocStructName()` and `FreeStructName()` functions which should manage all memory for that `struct`.
* If a publicly declared `struct` does not have `MallocStructName()` or `FreeStructName()` functions an __attempt__ will be made to create them.
* The `src` directory must contain __all__ code required to compile the binary (no linked binaries are allowed).
* The `pkg` directory contains all generated code made from the `src` directory.
* The `bin` directory contains compiled binaries installed via this workspace.
* Files ending in `_test.c` are only used by test compiles.

## Setup

	go install ~/workspace/src/github.com/cmm/cmmb
	. ~/cmm.sh
	cd ~/workspace/src/github.com/cmm/hello
	cmm test

## Usage

Prints all commands `cmm` supports;

	cmm help

Prints the current version of `cmm`;

	cmm version

Prints all environment variables used by `cmm`;

	cmm env

Sets the current workspace by finding the workspace the current directory is in;

	cmm here

Create a new workspace at the given directory;

	cmm here .

Download and install packages and dependencies for the given URI;

	cmm get <Package URI>

Execute all `_test.c` files in the current directory;

	cmm test

Execute all `_test.c` files in the current directory and all sub directories recursively;

	cmm test ...

Execute the test files in the current directory and output line coverage in `gcov` format;

	cmm test -cover

Compile the files in the current directory and place the binary in the `bin` directory;

	cmm install
