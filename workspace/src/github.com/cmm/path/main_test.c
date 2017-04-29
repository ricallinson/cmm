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
	assert(strcmp(path, "/foo/bar") == 0);
	free(path);
}

void TestPathBaseRelativePath() {
	char *path = PathBase("./bar/baz");
	assert(strcmp(path, "./bar") == 0);
	free(path);
}

void TestPathBaseRoot() {
	char *path = PathBase("/");
	assert(strcmp(path, "/") == 0);
	free(path);
}

void TestPathBaseRootPathBroken() {
	char *path = PathBase("/foo//bar//baz");
	assert(strcmp(path, "/foo//bar/") == 0);
	free(path);
}

void TestPathCleanEmpty() {
	char *path = PathClean("");
	assert(strcmp(path, ".") == 0);
	free(path);
}

int main() {
	// Base.
	TestPathBaseEmpty();
	TestPathBaseRootPath();
	TestPathBaseRelativePath();
	TestPathBaseRoot();
	TestPathBaseRootPathBroken();
	// Clean.
	TestPathCleanEmpty();
	return 0;
}
