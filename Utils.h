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

/** parses a string into an integer 
 *  @param  str the string to parse
 *  e.g.  stringAsInt("1") returns 1
 *  e.g.  stringAsInt("-1") returns -1
 */
int stringAsInt(const std::string& str);

/** parses a string into an double
 *  @param  str the string to parse
 *  e.g.  stringAsDouble("1") returns 1.0
 *  e.g.  stringAsDouble("-1") returns -1.0
 *  e.g.  stringAsDouble("-1.12") returns -1.12
 *  e.g.  stringAsDouble("foo") throws an error
 */
double stringAsDouble(const std::string& str);

}  //  end namespace 'mm'
