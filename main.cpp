#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <algorithm>

#include "parser.h"

std::string read_file(std::string filename) {
  std::ifstream t(filename);
  return std::string(std::istreambuf_iterator<char>(t),
		     std::istreambuf_iterator<char>());
}

std::string trim(std::string &str)
{
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
  str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
  return str;
}

int main(int argc, char **argv) {
  std::string line_in;
  if (argc != 2) {
    std::cout << "Expected 1 input argument, received " << argc << std::endl;
    return 0;
  }
  const auto file_str = read_file(argv[1]);
  const auto statements = get_statements(file_str);
  std::cout << statements.size() << std::endl;
  for (const std::string &statement : statements) {
    std::cout << i << " " << statement << std::endl;
  }
  return 0;
}
