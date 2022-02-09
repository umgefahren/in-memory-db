//
// Created by Hannes Furmans on 09.02.22.
//

#include <gtest/gtest.h>
#include "arraysort.h"
#include <string>
#include <vector>
#include <iostream>
#include <thread>

using namespace std;

TEST(ArraySort, Basic) {
   vector<int> unsorted;

   int value1 = 1;
   int value2 = 2;
   int value3 = 3;
   unsorted.push_back(value3);
   unsorted.push_back(value1);
   unsorted.push_back(value2);
    quicksort(0, 2, &unsorted);

    for (int i = 0; i < unsorted.size(); i++) {
        auto element = unsorted[i];
        ASSERT_EQ(element, i + 1);
    }
}

TEST(ArraySortConcurrent, Basic) {
    vector<int> unsorted;

    for (int j = 10000; j >= 0; j--) {
        unsorted.push_back(j);
        // cout << "J => " << j << "\n";
    }

    cout << unsorted.size() << " " << std::thread::hardware_concurrency() << "\n";



    quicksort_concurrent(0, unsorted.size() - 1, &unsorted, 0, std::thread::hardware_concurrency());

    for (int i = 0; i < unsorted.size(); i++) {
        auto element = unsorted[i];
        // cout << "Element => " << element << "\n";
        ASSERT_EQ(i, element);
    }
}