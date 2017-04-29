#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "github.com/cmm/path/main.h"

void TestPathBaseEmpty() {
	char *path = PathBase("");
	assert(strcmp(path, ".") == 0);
	free(*path);
}

void TestPathBaseRootPath() {
	char *path = PathBase("/foo/bar/baz");
	assert(strcmp(path, "/foo/bar") == 0);
}

void TestPathBaseRelativePath() {
	char *path = PathBase("./bar/baz");
	assert(strcmp(path, "./bar") == 0);
}

void TestPathBaseRoot() {
	char *path = PathBase("/");
	assert(strcmp(path, "/") == 0);
}

void TestPathBaseRootPathBroken() {
	char *path = PathBase("/foo//bar//baz");
	assert(strcmp(path, "/foo//bar/") == 0);
}

int main() {
	TestPathBaseEmpty();
	TestPathBaseRootPath();
	TestPathBaseRelativePath();
	TestPathBaseRoot();
	TestPathBaseRootPathBroken();
	return 0;
}
