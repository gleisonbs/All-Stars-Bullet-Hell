#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template<typename Out>
void split(const std::string&, char, Out);

std::vector<std::string> split(const std::string &, char);

#endif // UTIL_HPP
