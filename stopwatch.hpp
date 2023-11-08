#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>

class Stopwatch{
public:

  Stopwatch();

  // cannot copy or move a stopwatch
  Stopwatch(const Stopwatch &) = delete;
  Stopwatch & operator=(const Stopwatch &) = delete;
  Stopwatch(Stopwatch &&) = delete;
  Stopwatch & operator=(Stopwatch &&) = delete;

  void start();

  void stop();

  void lap();

  void reset();

  bool isrunning();
  
  double elapsedTime();

  double averageTime();
  
private:
  
  typedef std::chrono::time_point<std::chrono::system_clock> time_point_t;
  typedef std::chrono::duration<double> duration_t;

  enum State {STOPPED, RUNNING};

  State m_state;
  time_point_t m_start;
  double m_last;
  double m_total;
  std::size_t m_laps;
};

#endif
