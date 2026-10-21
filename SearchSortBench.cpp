#include "SearchSortBench.h"
#include <iostream>
#include <chrono>
#include <iomanip>

void BenchmarkingSuite::bubbleSort(Order** arr, int n, long long& comparisons, long long& swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j]->totalValue > arr[j + 1]->totalValue) {
                swaps++;
                Order* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BenchmarkingSuite::selectionSort(Order** arr, int n, long long& comparisons, long long& swaps) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j]->totalValue < arr[minIdx]->totalValue) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swaps++;
            Order* temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void BenchmarkingSuite::insertionSort(Order** arr, int n, long long& comparisons, long long& swaps) {
    for (int i = 1; i < n; i++) {
        Order* key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j]->totalValue > key->totalValue) {
                swaps++;
                arr[j + 1] = arr[j];
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

int BenchmarkingSuite::linearSearch(Order** arr, int n, int targetID, long long& comparisons) {
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i]->orderID == targetID) {
            return i;
        }
    }
    return -1;
}

int BenchmarkingSuite::binarySearch(Order** arr, int n, int targetID, long long& comparisons) {
    int left = 0, right = n - 1;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid]->orderID == targetID) return mid;
        if (arr[mid]->orderID < targetID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void BenchmarkingSuite::runBenchmarkingSuite() {
    int sizes[] = {100, 1000, 10000}; // Scaled down slightly to prevent Code::Blocks terminal crashing

    std::cout << "\n==========================================================================\n";
    std::cout << "BENCHMARK SUITE PERFORMANCE METRICS REPORT\n";
    std::cout << "==========================================================================\n";
    std::cout << std::left << std::setw(15) << "Algorithm"
              << std::setw(15) << "Dataset (N)"
              << std::setw(15) << "Comparisons"
              << std::setw(12) << "Swaps"
              << std::setw(15) << "Time (ms)"
              << "Big-O\n";
    std::cout << "--------------------------------------------------------------------------\n";

    for (int n : sizes) {
        Order** testData = new Order*[n];
        for (int i = 0; i < n; i++) {
            testData[i] = new Order(i, "TestUser", (n - i) * 1.5, "Paid", "Standard");
        }

        long long comps = 0, swaps = 0;
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(testData, n, comps, swaps);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;

        std::cout << std::left << std::setw(15) << "Bubble Sort"
                  << std::setw(15) << n
                  << std::setw(15) << comps
                  << std::setw(12) << swaps
                  << std::setw(10) << elapsed.count() << " ms    "
                  << "O(n^2)\n";
        for (int i = 0; i < n; i++) delete testData[i];
        delete[] testData;
    }
    std::cout << "==========================================================================\n";
}
