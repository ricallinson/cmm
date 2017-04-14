package main

import (
	"fmt"
	"os"
	"io/ioutil"
	"strings"
	"path"
	"path/filepath"
	"bytes"
)

// Cmm directories.
var (
	srcDir = os.Getenv("CMMPATH") + string(filepath.Separator) + "src" + string(filepath.Separator)
	pkgDir = os.Getenv("CMMPATH") + string(filepath.Separator) + "pkg" + string(filepath.Separator)
	binDir = os.Getenv("CMMPATH") + string(filepath.Separator) + "bin" + string(filepath.Separator)
)

func inArray(array []string, match string) bool {
	for _, item := range array {
		if item == match {
			return true
		}
	}
	return false
}

func dedup(src []string) []string {
	dest := []string{}
	for _, item := range src {
		if !inArray(dest, item) {
			dest = append(dest, item)
		}
	}
	return dest
}

func findPackageFiles(dir string, test bool) []string {
	pkgFiles := []string{}
	files, _ := ioutil.ReadDir(dir)
	for _, file := range files {
		if strings.HasSuffix(file.Name(), ".c") {
			if !test && !strings.HasSuffix(file.Name(), "_test.c") {
				pkgFiles = append(pkgFiles, dir + string(filepath.Separator) + file.Name())
			} else {
				pkgFiles = append(pkgFiles, dir + string(filepath.Separator) + file.Name())
			}
		}
    }
	return pkgFiles
}

// Recursively finds all package dependences for the given file.
func findFileDeps(file string, deps map[string]bool) {
	// Find dependencies for the given file.
	b, err := ioutil.ReadFile(file)
	if err != nil {
		panic(err)
	}
	lines := bytes.Split(b, []byte("\n"))
	for _, line := range lines {
		if bytes.HasPrefix(line, []byte("#include \"")) {
			parts := bytes.Split(line, []byte("\""))
			if len(parts) < 3 {
				continue
			}
			// Get the package from the included header file.
			pkg := string(parts[1][:bytes.LastIndexByte(parts[1], '/')])
			// Recursively this packages dependencies if we don't already have it.
			if _, got := deps[pkg]; !got {
				deps[pkg] = true
				findPackageDeps(pkg, false, deps)
			}
		}
	}
}

// For each file in a package recursively find its dependencies.
func findPackageDeps(dir string, test bool, deps map[string]bool) {
	files := findPackageFiles(dir, test)
	for _, file := range files {
		findFileDeps(file, deps)
	}
}

// Check for public 'struct' definitions that don't have a '_MallocStructName' or '_FreeStructName' function.
func findMissingStuctFunctions(b []byte) []byte {
	return b
}

// Replace '_' for functions starting '_' with the packages parent directory name but starting with an uppercase char.
func insertPackageNameIntoFunctionName(b []byte) []byte {
	return b
}

func generatePackageFiles(files []string) {
	for _, file := range files {
		generatePackageFile(file)
	}
}

func generatePackageFile(srcFile string) {
	// Read the file into memory.
	b, err1 := ioutil.ReadFile(srcFile)
	if err1 != nil {
		panic(err1)
	}
	b = findMissingStuctFunctions(b)
	b = insertPackageNameIntoFunctionName(b)
	// Save the generated file into the 'pkg' directory.
	pkgFile := strings.Replace(srcFile, srcDir, pkgDir, 1)
	if err := os.MkdirAll(path.Dir(pkgFile), 0777); err != nil {
		panic(err)
	}
	if err := ioutil.WriteFile(pkgFile, b, 0777); err != nil {
		panic(err)
	}
	fmt.Println(pkgFile)
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
	for dep, _ := range deps {
		files = append(files, findPackageFiles(srcDir + dep, false)...)
	}
	files = dedup(files)
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
		fmt.Println("You must provide a command to run.")
		return
	}
	dir, _ := os.Getwd()
	if len(args) == 2 {
		dir = srcDir + args[1]
	}
	switch args[0] {
	case "test":
		test(dir)
	case "install":
		install(dir)
	}
}
