#include <stdio.h>
#include <assert.h>
#include "github.com/cmm/path/main.h"

void TestPathBaseEmpty() {
	assert(strcmp(PathBase(""), ".") == 0);
}

void TestPathBaseRootPath() {
	assert(strcmp(PathBase("/foo/bar/baz"), "/foo/bar") == 0);
}

void TestPathBaseRelativePath() {
	assert(strcmp(PathBase("./bar/baz"), "./bar") == 0);
}

void TestPathBaseRoot() {
	assert(strcmp(PathBase("/"), "/") == 0);
}

void TestPathBaseRootPathBroken() {
	assert(strcmp(PathBase("/foo//bar//baz"), "/foo//bar/") == 0);
}

int main() {
	TestPathBaseEmpty();
	TestPathBaseRootPath();
	TestPathBaseRelativePath();
	TestPathBaseRoot();
	TestPathBaseRootPathBroken();
	return 0;
}
