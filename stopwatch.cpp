#include "stopwatch.hpp"

#include <limits>
#include <cmath>

Stopwatch::Stopwatch(){
  reset();
}

void Stopwatch::start(){
  if(m_state == STOPPED){
    m_state = RUNNING;
    m_start = std::chrono::system_clock::now();
  }
}

void Stopwatch::stop(){
  if(m_state == RUNNING){
    m_state = STOPPED;
    time_point_t stop = std::chrono::system_clock::now();
    duration_t elapsed_seconds = stop-m_start;
    m_last = elapsed_seconds.count();
    m_total += elapsed_seconds.count();
    m_laps += 1;
  }
}

void Stopwatch::lap(){
  if(m_state == RUNNING){
    time_point_t stop = std::chrono::system_clock::now();
    duration_t elapsed_seconds = stop-m_start;
    m_last = elapsed_seconds.count();
    m_total += elapsed_seconds.count();
    m_laps += 1;
    m_start = std::chrono::system_clock::now();
  }
}

void Stopwatch::reset(){
  m_state = STOPPED;
  m_start = std::chrono::system_clock::now();
  m_last = 0.0;
  m_total = 0.0;
  m_laps = 0;
}

bool Stopwatch::isrunning(){
  return m_state == RUNNING;
}

double Stopwatch::elapsedTime(){
  return m_last;
}

double Stopwatch::averageTime(){

  if(m_laps == 0){
    return std::numeric_limits<double>::quiet_NaN();
  }
  return m_total/m_laps;
}
