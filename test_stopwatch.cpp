#include "catch.hpp"

#include <iostream>

#include "stopwatch.hpp"
#include <cmath>

TEST_CASE("Test the stopwatch", "[stopwatch]") {

  Stopwatch w;

  REQUIRE_FALSE(w.isrunning());
  REQUIRE(w.elapsedTime() == 0.0);
  REQUIRE(std::isnan(w.averageTime()));

  w.start();
  REQUIRE(w.isrunning());
  std::uint16_t count = 1;
  while(count != 0){
    count += 1;
  }
  w.stop();
  REQUIRE_FALSE(w.isrunning());
  
  std::clog << w.elapsedTime() << std::endl;

  REQUIRE(w.elapsedTime() == w.averageTime());

  w.reset();
  w.start();
  REQUIRE(w.isrunning());
  std::uint16_t count16 = 1;
  while(count16 != 0){
    count16 += 1;
  }
  w.lap();
  std::clog << w.elapsedTime() << std::endl;
  REQUIRE(w.isrunning());
  count16 = 1;
  while(count16 != 0){
    count16 += 1;
  }
  w.lap();
  std::clog << w.elapsedTime() << std::endl;
  REQUIRE(w.isrunning());
  count16 = 1;
  while(count16 != 0){
    count16 += 1;
  }
  w.stop();
  REQUIRE_FALSE(w.isrunning());
  
  std::clog << w.elapsedTime() << std::endl;
  std::clog << w.averageTime() << std::endl;

  REQUIRE(w.elapsedTime() != w.averageTime());

}
