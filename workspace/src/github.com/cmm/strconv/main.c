// Module Strings.

#include <assert.h>
#include <string.h>

char *StringsFormatInt(int val) {
	const int n = snprintf(NULL, 0, "%d", val);
	assert(n > 0);
	char *res = malloc(n + 1);
	int c = snprintf(res, n+1, "%d", val);
	assert(res[n] == '\0');
	assert(c == n);
	return res;
}

char *StringsFormatUint(unsigned int val) {
	const int n = snprintf(NULL, 0, "%d", val);
	assert(n > 0);
	char *res = malloc(n + 1);
	int c = snprintf(res, n+1, "%d", val);
	assert(res[n] == '\0');
	assert(c == n);
	return res;
}

char *StringsFormatUlong(unsigned long val) {
	const int n = snprintf(NULL, 0, "%lu", val);
	assert(n > 0);
	char *res = malloc(n + 1);
	int c = snprintf(res, n+1, "%lu", val);
	assert(res[n] == '\0');
	assert(c == n);
	return res;
}
