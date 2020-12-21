// Module Strings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create memory for the given string.
char *StringsCreate(char *str) {
	const int strSize = strlen(str);
	char *res = malloc(strSize + 1);
	for (int i = 0; i < strSize; i++) {
		res[i] = str[i];
	}
	// Make sure the new string is terminated with a null byte.
	res[strSize] = '\0';
	// printf("%s\n", res);
	return res;
}

// Free memory for the given string.
int *StringsDestroy(char *str) {
    // Free all memory used.
    free(str);
    return 0;
}

// 
char *StringsSubstring(char *str, int from, int to) {
	const int strSize = strlen(str);
	if (from < 0) {
		from = strSize + from + 1;
	}
	if (from > strSize) {
		from = strSize;
	}
	if (to < 0) {
		to = strSize + to + 1;
	}
	if (to < from) {
		to = from;
	}
	if (to > strSize) {
		to = strSize;
	}
	int newSize = to - from;
	int n = 0;
	char *res = malloc((newSize + 1) * sizeof(char));
	for(int i = from; i <= to; i++) {
		res[n] = str[i];
		n++;
	}
	// Make sure the new string is terminated with a null byte.
	res[newSize] = '\0';
	// printf("%s\n", res);
	return res;
}

//
char *StringsConcat(char *a, char *b) {
	const int sizeA = strlen(a);
	const int sizeB = strlen(b);
	char *res = malloc(sizeA + sizeB + 1);
	for (int i = 0; i < sizeA; i++) {
		res[i] = a[i];
	}
	for (int i = 0; i < sizeB; i++) {
		res[i + sizeA] = b[i];
	}
	res[sizeA + sizeB] = '\0';
	return res;
}

// 
char *StringsJoin(char *a, char *b, char *sep) {
	char *build = StringsConcat(a, sep);
	char *res = StringsConcat(build, b);
	free(build);
	return res;
}
