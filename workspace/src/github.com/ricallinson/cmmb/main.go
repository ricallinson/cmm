package main

import (
	"fmt"
	"os"
	"io/ioutil"
	"strings"
	"path"
	"path/filepath"
	"bytes"
	"regexp"
)

// Regexp
var (
	// Match all chars that are not letters or numbers.
	regexpCharsOnly = regexp.MustCompile("[^A-Za-z0-9_]")
	regexpStruct = regexp.MustCompile("typedef(.*)\\{([^}]*?)\\}([^;]*);")
	regexpFunction = regexp.MustCompile("[A-Za-z0-9_]* [A-Za-z0-9_]*\\(.*\\) ?{")
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

// Check for public 'struct' definitions that don't have a '_StructNameMalloc' or '_StructNameFree' function.
func findMissingStuctFunctions(b []byte) []byte {
	return b
}

func findPackageName(file string) []byte {
	pkgName := path.Base(path.Dir(file))
	return []byte(strings.Title(pkgName))
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
	// Save the generated file into the 'pkg' directory.
	pkgFile := strings.Replace(srcFile, srcDir, pkgDir, 1)
	if err := os.MkdirAll(path.Dir(pkgFile), 0777); err != nil {
		panic(err)
	}
	if err := ioutil.WriteFile(pkgFile, b, 0777); err != nil {
		panic(err)
	}
	// fmt.Println(string(findPackageName(srcFile)), pkgFile)
}

func generatePackageHeaderFiles(files []string) {
	for _, file := range files {
		generatePackageHeaderFile(file)
	}
}

// Find all struct definitions starting with an uppercase char.
func findPublicStructs(b []byte) [][]byte {
	structList := [][]byte{}
	structs := regexpStruct.FindAll(b, -1)
	// For each found struct copy it to the function list if it's public.
	for _, st := range structs {
		// Split the definition into lines.
		lines := bytes.Split(st, []byte("\n"))
		// Get the last line in the definition.
		line := lines[len(lines)-1:][0]
		// Remove all none chars.
		name := regexpCharsOnly.ReplaceAll(line, []byte(""))
		// If the name starts with an uppercase char then it's public.
		if name[0] == bytes.Title(name[:1])[0] {
			st = append(st, []byte("\n")...)
			structList = append(structList, st)
		}
	}
	return structList
}

// Find all function definitions starting with an uppercase char.
func findPublicFunctions(b []byte) [][]byte {
	funcList := [][]byte{}
	funcs := regexpFunction.FindAll(b, -1)
	// Each found function copy it to the function list.
	for _, fn := range funcs {
		// Split the definition into parts and grab the second.
		name := bytes.Split(fn, []byte(" "))[1]
		name = regexpCharsOnly.ReplaceAll(name, []byte(""))
		// If the name starts with an uppercase char then it's public.
		if name[0] == bytes.Title(name[:1])[0] {
			fn = fn[:bytes.LastIndex(fn, []byte(" "))]
			fn = append(fn, []byte(";\n")...)
			funcList = append(funcList, fn)
		}
	}
	return funcList
}

func generatePackageHeaderFile(srcFile string) {
	headerId := strings.ToLower(strings.Replace(srcFile, srcDir, "", 1))
	headerId = regexpCharsOnly.ReplaceAllLiteralString(headerId, "_")
	header := []byte("// Generated by 'cmm'.\n")
	header = append(header, []byte("// Publicly accessible package functions and attributes.\n")...)
	header = append(header, []byte("#ifndef " + headerId + " \n")...)
	header = append(header, []byte("#define " + headerId + " \n")...)
	pkgFile := strings.Replace(srcFile, srcDir, pkgDir, 1)
	pkgHeaderFile := pkgFile[:len(pkgFile) - 1] + "h"
	// Read the file into memory.
	b, err1 := ioutil.ReadFile(pkgFile)
	if err1 != nil {
		panic(err1)
	}
	for _, s := range findPublicStructs(b) {
		header = append(header, s...)
	}
	for _, s := range findPublicFunctions(b) {
		header = append(header, s...)
	}
	header = append(header, []byte("#endif\n")...)
	if err := ioutil.WriteFile(pkgHeaderFile, header, 0777); err != nil {
		panic(err)
	}
	// fmt.Println(pkgHeaderFile)
	// fmt.Println(string(header))
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
