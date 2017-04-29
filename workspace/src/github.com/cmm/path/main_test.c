#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "github.com/cmm/path/main.h"

void TestPathBaseEmpty() {
	char *path = PathBase("");
	assert(strcmp(path, ".") == 0);
	free(path);
}

void TestPathBaseRootPath() {
	char *path = PathBase("/foo/bar/baz");
	assert(strcmp(path, "baz") == 0);
	free(path);
}

void TestPathBaseRelativePath() {
	char *path = PathBase("./bar/baz");
	assert(strcmp(path, "baz") == 0);
	free(path);
}

void TestPathBaseRoot() {
	char *path = PathBase("/");
	assert(strcmp(path, "/") == 0);
	free(path);
}

void TestPathBaseRootPathBroken() {
	char *path = PathBase("/foo//bar//baz");
	assert(strcmp(path, "baz") == 0);
	free(path);
}

void TestPathBaseRootPathFile() {
	char *path = PathBase("/foo/bar/baz.txt");
	assert(strcmp(path, "baz.txt") == 0);
	free(path);
}

void TestPathCleanEmpty() {
	char *path = PathClean("");
	assert(strcmp(path, ".") == 0);
	free(path);
}

void TestPathCleanRoot() {
	char *path = PathClean("/");
	assert(strcmp(path, "/") == 0);
	free(path);
}

void TestPathCleanBadRoot() {
	char *path = PathClean("///");
	assert(strcmp(path, "/") == 0);
	free(path);
}

void TestPathCleanRelative() {
	char *path = PathClean("./");
	assert(strcmp(path, ".") == 0);
	free(path);
}

void TestPathCleanBacktrack() {
	char *path = PathClean("/foo/bar/../baz");
	assert(strcmp(path, "/foo/baz") == 0);
	free(path);
}

void TestPathCleanBacktrackMore() {
	char *path = PathClean("/foo/bar/../baz/..");
	assert(strcmp(path, "/foo") == 0);
	free(path);
}

void TestPathCleanBacktrackRelative() {
	char *path = PathClean("./foo/bar/../baz/..");
	assert(strcmp(path, "foo") == 0);
	free(path);
}

void TestPathDirEmpty() {
	char *path = PathDir("");
	assert(strcmp(path, ".") == 0);
	free(path);
}

void TestPathDirRootPath() {
	char *path = PathDir("/foo/bar/baz");
	assert(strcmp(path, "/foo/bar") == 0);
	free(path);
}

void TestPathDirRelativePath() {
	char *path = PathDir("./bar/baz");
	assert(strcmp(path, "bar") == 0);
	free(path);
}

void TestPathDirRoot() {
	char *path = PathDir("/");
	assert(strcmp(path, "/") == 0);
	free(path);
}

void TestPathDirRootPathBroken() {
	char *path = PathDir("/foo//bar//baz");
	assert(strcmp(path, "/foo/bar") == 0);
	free(path);
}

void TestPathDirRootPathFile() {
	char *path = PathDir("/foo/bar/baz.txt");
	assert(strcmp(path, "/foo/bar") == 0);
	free(path);
}

void TestPathIsAbsTrue() {
	int val = PathIsAbs("/foo/bar/baz.txt");
	assert(val == 1);
}

void TestPathIsAbsFalse() {
	int val = PathIsAbs("./foo/bar/baz.txt");
	assert(val == 0);
}

int main() {
	// Base.
	TestPathBaseEmpty();
	TestPathBaseRootPath();
	TestPathBaseRelativePath();
	TestPathBaseRoot();
	TestPathBaseRootPathBroken();
	TestPathBaseRootPathFile();
	// Clean.
	TestPathCleanEmpty();
	TestPathCleanRoot();
	TestPathCleanBadRoot();
	TestPathCleanRelative();
	TestPathCleanBacktrack();
	TestPathCleanBacktrackMore();
	TestPathCleanBacktrackRelative();
	// Dir.
	TestPathDirEmpty();
	TestPathDirRootPath();
	TestPathDirRelativePath();
	TestPathDirRoot();
	TestPathDirRootPathBroken();
	TestPathDirRootPathFile();
	// IsAbs.
	TestPathIsAbsTrue();
	TestPathIsAbsFalse();
	return 0;
}
