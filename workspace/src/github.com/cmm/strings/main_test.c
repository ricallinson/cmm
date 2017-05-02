#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "github.com/cmm/strings/main.h"

void TestSubstringEmpty() {
	char *str = StringsSubstring("", 0, 0);
	assert(strcmp(str, "") == 0);
	free(str);
}

void TestSubstringReturnEmpty() {
	char *str = StringsSubstring("bar", 0, 0);
	assert(strcmp(str, "") == 0);
	free(str);
}

void TestSubstringReturnFirst() {
	char *str = StringsSubstring("bar", 0, 1);
	assert(strcmp(str, "b") == 0);
	free(str);
}

void TestSubstringReturnSecond() {
	char *str = StringsSubstring("bar", 1, 2);
	assert(strcmp(str, "a") == 0);
	free(str);
}

void TestSubstringReturnThird() {
	char *str = StringsSubstring("bar", 2, 3);
	assert(strcmp(str, "r") == 0);
	free(str);
}

void TestSubstringReturnAll() {
	char *str = StringsSubstring("bar", 0, 3);
	assert(strcmp(str, "bar") == 0);
	free(str);
}

void TestSubstringAllWithoutSize() {
	char *str = StringsSubstring("bar", 0, -1);
	assert(strcmp(str, "bar") == 0);
	free(str);
}

void TestSubstringReturnLast() {
	char *str = StringsSubstring("bar", -2, -1);
	assert(strcmp(str, "r") == 0);
	free(str);
}

void TestStringsConcat() {
	char *str = StringsConcat("foo", "bar");
	assert(strcmp(str, "foobar") == 0);
	free(str);
}

int main() {
	// Substring.
	TestSubstringEmpty();
	TestSubstringReturnEmpty();
	TestSubstringReturnFirst();
	TestSubstringReturnSecond();
	TestSubstringReturnThird();
	TestSubstringReturnAll();
	TestSubstringAllWithoutSize();
	TestSubstringReturnLast();
	return 0;
}
