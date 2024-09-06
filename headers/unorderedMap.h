#ifndef unorderedMap_h
#define unorderedMap_h

#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 8
#define LOAD_FACTOR 0.75

typedef struct MapNode MapNode;
typedef struct unordered_map unordered_map;

unordered_map* mpcreateMap();
void mpinsert(unordered_map* map, int key, int value);
bool mpfind(unordered_map* map, int key, int* value);
void mperase(unordered_map* map, int key);
bool mpcontains(unordered_map* map, int key);
int mpgetSize(unordered_map* map);
bool mpisEmpty(unordered_map* map);
void mpclear(unordered_map* map);
void mpdeleteMap(unordered_map* map);
int** mpgetMap(unordered_map* map, int* length);

#endif
