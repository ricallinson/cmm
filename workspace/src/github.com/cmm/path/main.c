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
	// Copy the path into a new array.
	char* ret = subset(path, 0, strlen(path));
	// Strip trailing slashes.
	while (strlen(ret) > 0 && ret[strlen(ret)-1] == '/') {
		// Create a new array with the shortend path.
		char* tmp = subset(ret, 0, strlen(ret)-1);
		// Free the tmp value memory now we have the new array tmp.
		free(ret);
		// Copy tmp into the return value pointer.
		ret = subset(tmp, 0, strlen(tmp));
		// Now free the tmp value.
		free(tmp);
	}
	// Find the last element
	for (int i = strlen(ret); i > 0; i--) {
		if (ret[i] == '/') {
			ret = subset(ret, 0, i);
			break;
		}
	}
	// If empty now, it had only slashes.
	if (strcmp(ret, "") == 0) {
		return "/";
	}
	return ret;
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
