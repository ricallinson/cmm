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
	// Strip trailing slashes.
	while (strlen(path) > 0 && path[strlen(path)-1] == '/') {
		path = subset(path, 0, strlen(path)-1);
	}
	// // Find the last element
	for (int i = strlen(path); i > 0; i--) {
		if (path[i] == '/') {
			path = subset(path, 0, i);
			break;
		}
	}
	// If empty now, it had only slashes.
	if (strcmp(path, "") == 0) {
		return "/";
	}
	return path;
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
