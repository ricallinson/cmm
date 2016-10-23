
#include <stdlib.h>
#include <string.h>

typedef struct MapItem {
    char *key;
    char *value;
    struct MapItem *next;
    struct MapItem *prev;
} MapItem;

typedef struct {
    struct MapItem *first;
    struct MapItem *last;
    long length;
} Map;

MapItem *createMapItem(char *key, char *value) {
    return NULL;
}

MapItem *findMapItem(Map *map, char *key) {
    MapItem *item = map->first;
    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item;
        }
        item = item->next;
    }
    return NULL;
}

Map *MapStringCreate() {
    Map *map = malloc(sizeof(Map));
    if (map == NULL) {
        return NULL;
    }
    map->first = malloc(sizeof(MapItem));
    if (map->first == NULL) {
        free(map);
        return NULL;
    }
    map->last = malloc(sizeof(MapItem));
    if (map->last == NULL) {
        free(map->first);
        free(map);
        return NULL;
    }
    map->length = 0;
    return map;
}

void MapStringDelete(Map *map) {
    if (map != NULL) {
        free(map->first);
        free(map->last);
        free(map);
    }
}

char *MapStringGet(Map *map, char *key) {
    MapItem *item = findMapItem(map, key);
    if (item != NULL) {
        return item->value;
    }
    return NULL;
}

void MapStringPut(Map *map, char *key, char *value) {
    // Try and find the key.
    MapItem *item = findMapItem(map, key);
    if (item != NULL) {
        free(item->value);
        item->value = strdup(value);
        return;
    }
    // If found update value.
    // Else, create a new MapItem and copy key and value into it.
    // Point to the new MapItem from the last MapItem.
}
