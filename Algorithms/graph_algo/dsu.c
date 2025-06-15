// Disjoint Set union
// Core idea it to keep track of elements in distinct set and also be able to do two operations
// 1. tell which set an element belongs to
// 2. do an union of sets
#include <stdio.h>
#include <stdlib.h>

// For now just considering only two sets
// a struct containing two arrays one for the elements in mst and another for which are not in the mst

typedef struct {
    int in_mst[32];
    int not_mst[32];
} sets;


