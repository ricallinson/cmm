#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 
char *StringsSubstring(char *str, int from, int to) {
	int strSize = strlen(str);
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
	res[newSize] = 0;
	// printf("%s\n", res);
	return res;
}
