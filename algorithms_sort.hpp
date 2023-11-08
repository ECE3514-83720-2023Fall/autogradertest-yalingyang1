#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <cstddef>
#include <cassert>

namespace ece3514 {

template<typename T>
void SelectionSort(T *list, std::size_t N){
    
    std::size_t last = N-1, max;
    while ((last > 0)) {
        max = 0;
        for (std::size_t i=1; i<=last; i++) {
            if (list[i] > list[max]) {
                max = i;
            }
        }
        // swap entries
        T temp = list[max];
        list[max] = list[last];
        list[last] = temp;
        
        last--;
    }
}
    
template<typename T>
void BubbleSort(T *list, std::size_t N){
    
    std::size_t last = N, nswaps = 1;
    while ((last > 0) && (nswaps >0)) {
        for (std::size_t i=0; i<last-1; i++) {
            if (list[i] > list[i+1]) {
                T temp = list[i+1];
                list[i+1] = list[i];
                list[i] = temp;
                nswaps++;
            }
        }
        last--;
    }
}

template<typename T>
void merge(T *list1, std::size_t n1, T *list2, std::size_t n2){
    // assume that the lists are adjacent in memory.
    T *array = new T[n1 + n2];
    std::size_t array_idx = 0, list1_idx = 0, list2_idx = 0;
    while ((list1_idx < n1) && (list2_idx < n2)) {
        if (list1[list1_idx] < list2[list2_idx]) {
            array[array_idx++] = list1[list1_idx++];
        } else {
            array[array_idx++] = list2[list2_idx++];
        }
    }
    for (std::size_t i = list1_idx; i < n1; i++) {
        array[array_idx++] = list1[i];
    }
    for (std::size_t i = list2_idx; i < n2; i++) {
        array[array_idx++] = list2[i];
    }
    for (std::size_t i = 0; i < n1 + n2; i++) {
        list1[i] = array[i];
    }
    delete [] array;
}

// my MergeSort
template<typename T>
void YourSort(T *list, std::size_t N){
    
    if (N<=10) {
        BubbleSort(list, N);
    } else {
        // split list, call sort recursively, merge
        std::size_t n1 = N/2;
        std::size_t n2 = N - n1;
        YourSort(&list[0],n1);
        YourSort(&list[n1],n2);
        merge(&list[0],n1,&list[n1],n2);
    }
}

} // end namespace
#endif
