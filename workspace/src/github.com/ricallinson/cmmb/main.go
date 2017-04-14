package main

import (
	"fmt"
	"os"
)

func findPackageFiles(dir string) []string {
	return []string{}
}

func findFileDeps(file string, deps map[string]bool) {
	
}

func findPackageDeps(dir string, deps map[string]bool) {
	
}

func generatePackageFiles(files []string) {

}

func generatePackageHeaderFiles(files []string) {

}

func testCompile(name string, files []string) {

}

func installCompile(name string, files []string) {
	
}

func executeTest(path string) {

}

// Walk all "_test.c" files in the current directory to find all package dependences.
// For each found package including the current directory package generate the build package files.
// Compile and execute the binary collecting gcov output.
func test(dir string) {
	name := "" + "_test"
	files := findPackageFiles(dir, true)
	deps := map[string]bool{}
	for _, file := range files {
		findFileDeps(file, deps)
	}
	for _, dep := range deps {
		files := append(files, findPackageFiles(dep, false)...)
	}
	generatePackageFiles(files)
	generatePackageHeaderFiles(files)
	testCompile(name, files)
	executeTest(name)
}

// Walk all "*.c" files but exclude "_test.c" files in the current directory to find all package dependences.
// For each found package including the current directory package generate the build package files.
// Compile the binary.
func install(dir string) {

}

func main () {
	args := os.Args[1:]
	if len(args) < 1 {
		fmt.Print("You must provide a command to run.")
		return
	}
	dir, _ := os.Getwd()
	switch args[0] {
	case "test":
		test(dir)
	case "install":
		install(dir)
	}
}
