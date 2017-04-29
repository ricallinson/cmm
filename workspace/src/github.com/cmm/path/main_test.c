#include <stdio.h>
#include "github.com/cmm/path/main.h"

int main() {
	printf("%s\n", PathBase(""));
	printf("%s\n", PathBase("/foo/bar/baz"));
	return 0;
}
