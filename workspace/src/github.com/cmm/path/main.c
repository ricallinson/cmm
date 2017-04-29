#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "github.com/cmm/strings/main.h"

// Base returns the last element of path.
// Trailing slashes are removed before extracting the last element.
// If the path is empty, Base returns ".".
// If the path consists entirely of slashes, Base returns "/".
char *PathBase(char *path) {
	// If the path is empty return the relative current directory.
	if (strcmp(path, "") == 0) {
		char *res = malloc(sizeof(char) * 2);
		res[0] = '.';
		res[1] = 0;
		return res;
	}
	int end = strlen(path);
	// Find the last trailing slashes.
	while (end > 0) {
		if (path[end] != '/') {
			break;
		}
		end--;
	}
	// Find the last element starting at the last trailing slash.
	int start = end;
	while (start > 0) {
		if (path[start] == '/') {
			start++;
			break;
		}
		start--;
	}
	// If empty now, it had only slashes.
	if (start == end) {
		char *res = malloc(sizeof(char) * 2);
		res[0] = '/';
		res[1] = 0;
		return res;
	}
	// Return the new path string.
	// printf("%s\n", StringsSubstring(path, start, end));
	return StringsSubstring(path, start, end);
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
	int n = strlen(path);
	int i = 0; // Index in buffer.
	int r = 0; // Index in given path.
	int dotdot = 0; // Index of "..".
	char *buf = malloc(n);

	if (path[r] == '/') {
		rooted = 1;
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
			// .. element: remove to last /.
			r = r + 2;
			if (i > dotdot) {
				// Can backtrack.
				i--;
				while (i > dotdot && buf[i] != '/') {
					i--;
				}
			} else if (rooted == 0) {
				// Cannot backtrack, but not rooted, so append .. element.
				if (i > 0) {
					buf[i] = '/';
					i++;
				}
				buf[i] = '.';
				i++;
				buf[i] = '.';
				i++;
				dotdot = i;
			}
		} else {
			// Real path element.
			// Add slash if needed.
			if ((rooted == 1 && i != 1) || (rooted == 0 && i != 0)) {
				buf[i] = '/';
				i++;
			}
			// Copy element.
			while (r < n && path[r] != '/') {
				buf[i] = path[r];
				i++;
				r++;
			}
		}
	}

	// Turn empty buffer into ".".
	if (i == 0) {
		buf[i] = '.';
		i++;
	}

	char *cleaned = StringsSubstring(buf, 0, i);
	free(buf);
	// printf("%s\n", cleaned);
	return cleaned;
}

// Dir returns all but the last element of path, typically the path's directory.
// After dropping the final element, the path is Cleaned and trailing slashes are removed.
// If the path is empty, Dir returns ".".
// If the path consists entirely of slashes followed by non-slash bytes, Dir
// returns a single slash. In any other case, the returned path does not end in a
// slash.
char *PathDir(char *path) {
	// If the path is empty return the relative current directory.
	if (strcmp(path, "") == 0) {
		char *res = malloc(sizeof(char) * 2);
		res[0] = '.';
		res[1] = 0;
		return res;
	}
	int end = strlen(path);
	// Find the last trailing slashes.
	while (end > 0) {
		if (path[end] == '/') {
			break;
		}
		end--;
	}
	char *tmp = StringsSubstring(path, 0, end + 1);
	char *res = PathClean(tmp);
	free(tmp);
	// printf("%s\n", res);
	return res;
}

// Ext returns the file name extension used by path.
// The extension is the suffix beginning at the final dot
// in the final slash-separated element of path;
// it is empty if there is no dot.
char *PathExt(char *path) {
	int end = strlen(path);
	// Find the last dot.
	while (end > 0) {
		if (path[end] == '.') {
			break;
		}
		end--;
	}
	// printf("%s\n", StringsSubstring(path, end + 1, -1));
	return StringsSubstring(path, end + 1, -1);
}

int PathIsAbs(char *path) {
	if (strlen(path) > 0 && path[0] == '/') {
		return 1;
	}
	return 0;
}

char *PathJoin() {
	return "";
}

int PathMatch() {
	return 0;
}
