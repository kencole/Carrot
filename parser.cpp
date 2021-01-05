#include "parser.h"
#include <iostream>

std::vector<std::string>
get_statements(const std::string& str) {
  std::vector<std::string> statements;
  unsigned long start = 0;
  long open_count = 0;
  for (unsigned long end = 0; end < str.length(); end++) {
    if (str[end] == '(') {
      open_count += 1;
      if (open_count == 1){
	// opened into new statement
	start = end;
      }
    } else if (str[end] == ')') {
      open_count -= 1;
      if (open_count == 0) {
	// closed prior statement
	statements.push_back(str.substr(start, end + 1 - start));
	start = end + 1;
      } else if (open_count < 0) {
	// found too many closes
	std::cout << str.substr(0, end + 1) << std::endl;
	std::cout << "Unexpected Token ')'" << std::endl;
	exit(1);
      }
    }
  }
  if (open_count > 0) {
    std::cout << str << std::endl;
    std::cout << "Unexpected End of Input" << std::endl;
    exit(1);
  }
  return statements;
}
