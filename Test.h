#pragma once

/** @file   Test.h
 *  @brief  Macros and functions to facilitate easy testing
 */

#include <iostream>
#include <iomanip>

#define MM_RUNTEST(TESTNAME)                                        \
  {                                                                 \
    std::cout << std::left << std::setw(32) << #TESTNAME;           \
    std::cout << (TESTNAME() ? "passed" : "FAILED *") << std::endl; \
  }
