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
* A publicly declared `struct` must have public `CreateStructName()` and `DestroyStructName()` functions which should manage all memory for that `struct`.
* The `src` directory must contain __all__ code required to compile the binary (no linked binaries are allowed).
* The `pkg` directory contains all generated code made from the `src` directory.
* The `bin` directory contains compiled binaries installed via this workspace.
* Files ending in `_test.c` are only used by test compiles.

## Setup

	git clone git@github.com:ricallinson/cmm.git
	. ./cmm/cmm.sh
	go build ./cmm/workspace/src/github.com/cmm/cmmb # Then add to execution path.
	cd ./cmm/workspace/src/github.com/cmm/hello
	cmm here
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

Removes the `pkg` and `_gcov` directories;

	cmm clean

Download and install packages and dependencies for the given URI;

	TODO: cmm get <Package URI>

Execute all `_test.c` files in the current directory;

	cmm test

Execute all `_test.c` files in the current directory and all sub directories recursively;

	TODO: cmm test ...

Compile the files in the current directory and place the binary in the `bin` directory;

	cmm install
