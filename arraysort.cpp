//
// Created by Hannes Furmans on 09.02.22.
//

#include "arraysort.h"
#include <vector>
#include <string>
#include <iostream>
#include <thread>

using namespace std;

void swap(int i, int j, vector<int> * data) {
    // cout << "Left => " << data->at(i) << " Right => " << data->at(j) << "\n";
    auto tmp = data->at(i);
    data->at(i) = data->at(j);
    data->at(j) = tmp;
    // cout << "After Left => " << data->at(i) << " Right => " << data->at(j) << "\n";
}

int divide(int left, int right, vector<int> * data) {
    int i = left;
    int j = right - 1;
    int pivot = data->at(right);

    while (i < j) {
        while (i < right && data->at(i) < pivot) {
            i += 1;
        }

        while (j > left && data->at(j) >= pivot) {
            j -= 1;
        }

        if (i < j) {
            swap(i, j, data);
        }
        // cout << "I => " << data->at(i) << " J => " << data->at(j) << " Pivot => " << pivot << "\n";
    }

    if (data->at(i) > pivot) {
        swap(i, right, data);
    }
    return i;
}

void quicksort(int left, int right, vector<int> * data) {
    if (left < right) {
        int divider = divide(left, right, data);

        int dividing_element = data->at(divider);

        // cout << "Dividing => " << dividing_element << "\n";

        quicksort(left, divider - 1, data);
        quicksort(divider + 1, right, data);
    }
}

void quicksort_concurrent(int left, int right, vector<int> * data, int depth, int limit) {
    if (left < right) {
        int divider = divide(left, right, data);
        int current_threads = 2 << (depth + 1);
        cout << "Current Threads " << current_threads << "\n";
        if (current_threads < limit) {
            thread left_thread(quicksort_concurrent, left, divider - 1, data, depth + 1, limit);
            thread right_thread(quicksort_concurrent, divider + 1, right, data, depth + 1, limit);
            left_thread.join();
            right_thread.join();
        } else {
            // cout << "Shifting to single threaded " << current_threads << "\n";
            quicksort(left, divider - 1, data);
            quicksort(divider + 1, right, data);
        }
    }
}