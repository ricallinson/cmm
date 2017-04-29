#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *subset(char *array, int from, int to) {
	int arraySize = strlen(array);
	int n = 0;
	char *res = malloc((to-from)*sizeof(char));
	for(int i = from; i < to; i++) {
		res[n] = array[i];
		n++;
	}
	return res;
}

char *PathBase(char *path) {
	if (strcmp(path, "") == 0) {
		return ".";
	}
	// Copy the path into a new array so it can be changed without side effects.
	char *res = subset(path, 0, strlen(path));
	// Strip trailing slashes.
	while (strlen(res) > 0 && res[strlen(res)-1] == '/') {
		// Create a new array with the shortened path.
		char* tmp = subset(res, 0, strlen(res)-1);
		// Free the old result value memory now we have the new array tmp.
		free(res);
		// Copy tmp into the return value pointer.
		res = subset(tmp, 0, strlen(tmp));
		// Now free the tmp value memory as we don't need it anymore.
		free(tmp);
	}
	// Find the last element
	for (int i = strlen(res); i > 0; i--) {
		if (res[i] == '/') {
			res = subset(res, 0, i);
			break;
		}
	}
	// If empty now, it had only slashes.
	if (strcmp(res, "") == 0) {
		return "/";
	}
	return res;
}

char *PathClean(char *path) {
	return "";
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
