#ifndef SEARCH_SORT_BENCH_H
#define SEARCH_SORT_BENCH_H

#include "OrderModel.h"

class BenchmarkingSuite {
public:
    static void bubbleSort(Order** arr, int n, long long& comparisons, long long& swaps);
    static void selectionSort(Order** arr, int n, long long& comparisons, long long& swaps);
    static void insertionSort(Order** arr, int n, long long& comparisons, long long& swaps);
    static int linearSearch(Order** arr, int n, int targetID, long long& comparisons);
    static int binarySearch(Order** arr, int n, int targetID, long long& comparisons);
    static void runBenchmarkingSuite();
};
#endif
