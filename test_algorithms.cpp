#include "catch.hpp"

#include <string>

#include "algorithms_sort.hpp"

TEST_CASE("Test sort", "[algorithms]") {

	int array[10];
	int array2[10];
	int array3[10];
	for (std::size_t i=0; i<10; i++) {
		array[i] = 10-i;
		array2[i] = 10-i;
		array3[i] = 10-i;
	}

	ece3514::SelectionSort(array,10);
	for (std::size_t i=0; i<9; i++) {
		REQUIRE(array[i] <= array[i+1]);
	}

	ece3514::BubbleSort(array2,10);
	for (std::size_t i=0; i<9; i++) {
		REQUIRE(array2[i] <= array2[i+1]);
	}

	ece3514::YourSort(array3,10);
	for (std::size_t i=0; i<9; i++) {
		REQUIRE(array3[i] <= array3[i+1]);
	}
}
