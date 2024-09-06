#include "unorderedMap.h"

//-----------------Map node definition--------------------------

struct MapNode {
	int key;
	int value;
	struct MapNode* next;
};

//-----------------Map definition-------------------------------

struct unordered_map {
	MapNode** buckets;
	int size;          // Number of elements
	int capacity;      // Number of buckets
};

//-----------------Hash function--------------------------------

unsigned int mphashFunction(int key, int capacity) {
	return key % capacity;
}

// Create a new node
MapNode* mpcreateNode(int key, int value) {
	MapNode* newNode = (MapNode*)malloc(sizeof(MapNode));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

//-----------------Map Initialization---------------------------

unordered_map* createMap() {
	unordered_map* map = (unordered_map*)malloc(sizeof(unordered_map));
	map->capacity = INITIAL_CAPACITY;
	map->size = 0;
	map->buckets = (MapNode**)calloc(map->capacity, sizeof(MapNode*));
	return map;
}

//-----------------Resize Map-----------------------------------

void mpresizeMap(unordered_map* map) {
	int oldCapacity = map->capacity;
	int newCapacity = oldCapacity * 2;
	MapNode** newBuckets = (MapNode**)calloc(newCapacity, sizeof(MapNode*));

	for (int i = 0; i < oldCapacity; i++) {
		MapNode* node = map->buckets[i];
		while (node) {
			MapNode* next = node->next;
			unsigned int newIndex = mphashFunction(node->key, newCapacity);
			node->next = newBuckets[newIndex];
			newBuckets[newIndex] = node;
			node = next;
		}
	}

	free(map->buckets);
	map->buckets = newBuckets;
	map->capacity = newCapacity;
}

//-----------------Insert a key-value pair----------------------

void mpinsert(unordered_map* map, int key, int value) {
	if ((float)map->size / map->capacity > LOAD_FACTOR) {
		mpresizeMap(map);
	}

	unsigned int index = mphashFunction(key, map->capacity);
	MapNode* node = map->buckets[index];
	while (node) {
		if (node->key == key) {
			node->value = value;  // Update existing key
			return;
		}
		node = node->next;
	}

	// Insert new node
	MapNode* newNode = mpcreateNode(key, value);
	newNode->next = map->buckets[index];
	map->buckets[index] = newNode;
	map->size++;
}

//-----------------Find a value by key--------------------------

bool mpfind(unordered_map* map, int key, int* value) {
	unsigned int index = mphashFunction(key, map->capacity);
	MapNode* node = map->buckets[index];
	while (node) {
		if (node->key == key) {
			*value = node->value;
			return true;
		}
		node = node->next;
	}
	return false;
}

//-----------------Check if key exists in map-------------------

bool mpcontains(unordered_map* map, int key) {
	unsigned int index = mphashFunction(key, map->capacity);
	MapNode* node = map->buckets[index];
	while (node) {
		if (node->key == key) {
			return true;
		}
		node = node->next;
	}
	return false;
}

//-----------------Erase a key from map-------------------------

void mperase(unordered_map* map, int key) {
	unsigned int index = mphashFunction(key, map->capacity);
	MapNode* node = map->buckets[index];
	MapNode* prev = NULL;

	while (node) {
		if (node->key == key) {
			if (prev) {
				prev->next = node->next;
			} else {
				map->buckets[index] = node->next;
			}
			free(node);
			map->size--;
			return;
		}
		prev = node;
		node = node->next;
	}
}

//------------Return a 2D array with keys-value pairs-----------

int** mpgetMap(unordered_map* map, int* length) {
	int** result = (int**)malloc(map->size * sizeof(int*));
	int index = 0;

	for (int i = 0; i < map->capacity; i++) {
		MapNode* node = map->buckets[i];
		while (node) {
			result[index] = (int*)malloc(2 * sizeof(int));  // 2 columns: key and value
			result[index][0] = node->key;
			result[index][1] = node->value;
			index++;
			node = node->next;
		}
	}

	*length = map->size;
	return result;
}

//-----------------Number of elements in map--------------------

int mpgetSize(unordered_map* map) {
	return map->size;
}

//-----------------Check if map is empty------------------------

bool mpisEmpty(unordered_map* map) {
	return map->size == 0;
}

//-----------------Remove all key-value pairs-------------------

void mpclear(unordered_map* map) {
	for (int i = 0; i < map->capacity; i++) {
		MapNode* node = map->buckets[i];
		while (node) {
			MapNode* temp = node;
			node = node->next;
			free(temp);
		}
		map->buckets[i] = NULL;
	}
	map->size = 0;
}

//-----------------Delete map-----------------------------------

void deleteMap(unordered_map* map) {
	mpclear(map);
	free(map->buckets);
	free(map);
}