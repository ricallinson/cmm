#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "github.com/cmm/strconv/main.h"

void TestStringsFormatInt() {
	char *str1 = StringsFormatInt(1);
	assert(strcmp(str1, "1") == 0);
	free(str1);

	char *str2 = StringsFormatInt(10);
	assert(strcmp(str2, "10") == 0);
	free(str2);
}

void TestStringsFormatUint() {
	char *str1 = StringsFormatUint((unsigned int)1);
	assert(strcmp(str1, "1") == 0);
	free(str1);

	char *str2 = StringsFormatUint(10);
	assert(strcmp(str2, "10") == 0);
	free(str2);
}

void TestStringsFormatUlong() {
	char *str1 = StringsFormatUlong((unsigned long)1);
	assert(strcmp(str1, "1") == 0);
	free(str1);

	char *str2 = StringsFormatUlong(10);
	assert(strcmp(str2, "10") == 0);
	free(str2);
}

int main() {
	TestStringsFormatInt();
	TestStringsFormatUint();
	TestStringsFormatUlong();
	return 0;
}
