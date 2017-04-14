// Entry Point for map tests.

#include <stdlib.h>
#include <stdio.h>
#include "github.com/ricallinson/testmap/map.h"

int main() {
    Map *map = MapStringCreate();
    MapStringPut(map, "foo", "123");
    MapStringDelete(map);
}
