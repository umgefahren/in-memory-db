//
// Created by Hannes Furmans on 09.02.22.
//

#ifndef IN_MEMORY_DB_ARRAYSORT_H
#define IN_MEMORY_DB_ARRAYSORT_H

#endif //IN_MEMORY_DB_ARRAYSORT_H

#include <string>
#include <vector>

void quicksort(int left, int right, std::vector<int> * data);

void quicksort_concurrent(int left, int right, std::vector<int> * data, int depth, int limit);