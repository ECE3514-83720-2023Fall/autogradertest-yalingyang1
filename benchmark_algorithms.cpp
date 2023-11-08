#include <fstream>
#include <iostream>
#include <cassert>

#include "algorithms_sort.hpp"
#include "stopwatch.hpp"

#include <random>

#define MAX_LENGTH 1000
#define STRIDE 20

int main()
{ 
    std::mt19937 gen;
    std::random_device rd;
    gen.seed(rd());
    std::uniform_int_distribution<int> p(1,MAX_LENGTH*10);
    
    int array1[MAX_LENGTH]; // space for the array
    int array2[MAX_LENGTH]; // space for the array
    int array3[MAX_LENGTH]; // space for the array
    
    Stopwatch watch, watch2, watch3;
    
    for(std::size_t n = 10; n <= MAX_LENGTH; n+=STRIDE){
        
        watch.reset();
        watch2.reset();
        watch3.reset();
        for(int repeat = 0; repeat < 20; ++repeat){
            // generate a random list of ints to sort
            for(std::size_t i = 0; i < n; ++i){
                array1[i] = p(gen);
                array2[i] = array1[i];
                array3[i] = array1[i];
            }
            
            // time the sort
            watch.start();
            ece3514::SelectionSort(array1, n);
            watch.stop();
            
            watch2.start();
				ece3514::BubbleSort(array2, n);
            watch2.stop();

            watch3.start();
				ece3514::YourSort(array2, n);
            watch3.stop();

        }
        std::cout << n << " "  << watch.averageTime() << " " 
        << watch2.averageTime() << " " << watch3.averageTime() << std::endl;
    }
    return 0;
}
