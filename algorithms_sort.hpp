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



// TODO -- implement your sort here...
template<typename T>
void YourSort(T *list, std::size_t N){
    
	
}

} // end namespace
#endif
