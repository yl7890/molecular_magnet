#pragma once

/** @file   Utils.h
 *  @brief  set of simple convenience/utility functions
 */

#include <string>
#include <vector>

namespace mm {

/** splits a string into several string by the token
 *  @param  line  the line to split
 *  @param  token the token onto which we split (default value = ',')
 *  e.g. splitString("this,is,a,comma,separated,line", ',')
 *  returns {"this", "is", "a", "comma", "separated", "line"}
 */
std::vector<std::string> splitString(const std::string& line, char token = ',');

}  //  end namespace 'mm'
