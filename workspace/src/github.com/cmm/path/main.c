#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "github.com/cmm/strings/main.h"

// Base returns the last element of path. Trailing slashes are removed before extracting the last element. 
// If the path is empty, Base returns ".". If the path consists entirely of slashes, Base returns "/".
char *PathBase(char *path) {
	// If the path is empty return the relative current directory.
	if (strcmp(path, "") == 0) {
		char *res = malloc(sizeof(char) * 2);
		res[0] = '.';
		res[1] = 0;
		return res;
	}
	// Copy the path into a new array so it can be changed without side effects.
	char *res = StringsSubstring(path, 0, strlen(path));
	// Strip trailing slashes.
	while (strlen(res) > 0 && res[strlen(res)-1] == '/') {
		// Create a new array with the shortened path.
		char* tmp = StringsSubstring(res, 0, strlen(res)-1);
		// Free the old result value memory now we have the new array tmp.
		free(res);
		// Copy tmp into the return value pointer.
		res = StringsSubstring(tmp, 0, strlen(tmp));
		// Now free the tmp value memory as we don't need it anymore.
		free(tmp);
	}
	// Find the last element
	for (int i = strlen(res); i > 0; i--) {
		if (res[i] == '/') {
			res = StringsSubstring(res, 0, i);
			break;
		}
	}
	// If empty now, it had only slashes.
	if (strcmp(res, "") == 0) {
		free(res);
		char *res = malloc(sizeof(char) * 2);
		res[0] = '/';
		res[1] = 0;
		return res;
	}
	return res;
}

// Clean returns the shortest path name equivalent to path
// by purely lexical processing. It applies the following rules
// iteratively until no further processing can be done:
//
//	1. Replace multiple slashes with a single slash.
//	2. Eliminate each . path name element (the current directory).
//	3. Eliminate each inner .. path name element (the parent directory)
//	   along with the non-.. element that precedes it.
//	4. Eliminate .. elements that begin a rooted path:
//	   that is, replace "/.." by "/" at the beginning of a path.
//
// The returned path ends in a slash only if it is the root "/".
//
// If the result of this process is an empty string, Clean
// returns the string ".".
//
// See also Rob Pike, ``Lexical File Names in Plan 9 or
// Getting Dot-Dot Right,''
// https://9p.io/sys/doc/lexnames.html
char *PathClean(char *path) {
	// If the path is empty return the relative current directory.
	if (strcmp(path, "") == 0) {
		char *res = malloc(sizeof(char) * 2);
		res[0] = '.';
		res[1] = 0;
		return res;
	}

	int rooted = 0;
	if (path[0] == '/') {
		rooted = 1;
	}
	int n = strlen(path);
	char *buf = malloc(n);
	int i = 0;
	int r = 0;
	int dotdot = 0;

	if (rooted == 1) {
		buf[i] = '/';
		i++;
		r++;
		dotdot++;
	}

	while (r < n) {
		if (path[r] == '/') {
			// Empty path element.
			r++;
		} else if (path[r] == '.' && (r+1 == n || path[r+1] == '/')) {
			// . element.
			r++;
		} else if (path[r] == '.' && path[r+1] == '.' && (r+2 == n || path[r+2] == '/')) {

		} else {

		}
	}
	if (i == 0) {
		buf[i] = '.';
		i++;
	}
	char *cleaned = StringsSubstring(buf, 0, i);
	free(buf);
	printf("%s\n", cleaned);
	return cleaned;
}

char *PathDir(char *path) {
	return "";
}

char *PathExt(char *path) {
	return "";
}

int PathIsAbs(char *path) {
	return 0;
}

char *PathJoin() {
	return "";
}

int PathMatch() {
	return 0;
}
