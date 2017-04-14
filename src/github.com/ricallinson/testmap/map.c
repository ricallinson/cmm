
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
    MapItem *item = malloc(sizeof(MapItem));
    if (item == NULL) {
        return NULL;
    }
    item->key = strdup(key);
    if (item->key == NULL) {
        free(item);
        return NULL;
    }
    item->value = strdup(value);
    if (item->value == NULL) {
        free(item->key);
        free(item);
        return NULL;
    }
    item->prev = malloc(sizeof(MapItem));
    if (item->prev == NULL) {
        free(item->key);
        free(item->value);
        free(item);
        return NULL;
    }
    item->next = malloc(sizeof(MapItem));
    if (item->next == NULL) {
        free(item->key);
        free(item->value);
        free(item->prev);
        free(item);
        return NULL;
    }
    return item;
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

int MapStringFree(Map *map) {
    if (map != NULL) {
        free(map->first);
        free(map->last);
        free(map);
    }
    return 0
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
    // If found update its value.
    if (item != NULL) {
        free(item->value);
        item->value = strdup(value);
        return;
    }
    // Else, create a new MapItem and copy the key and value into it.

    // Point to the new MapItem from the last MapItem.
}
