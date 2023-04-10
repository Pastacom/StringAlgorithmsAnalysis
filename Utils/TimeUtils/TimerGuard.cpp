//
// Created by shind_wvnx on 01.04.2023.
//

#include "TimerGuard.h"

/**
 * Constructor to register elapsed time.
 * @param time pointer to average time
 */

TimerGuard::TimerGuard(std::chrono::duration<double> *time) {
    start = std::chrono::high_resolution_clock::now();
    total = time;
}
/**
 * Destructor adding current sorting time, to compute average sorting time.
 */
TimerGuard::~TimerGuard() {
    std::chrono::duration<double> res = std::chrono::high_resolution_clock::now() - start;
    *total += res;
}