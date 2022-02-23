#include "../include/ast.h"
#include "../include/parser.h"
#include "../include/scanner.h"
#include "../include/token.h"
#include <iostream>
#include <memory>

int main() {
  std::cout << "Pratt parsing demo for arithmetic expressions\n";

  std::string input;
  std::getline(std::cin, input);

  parser_t parser{scanner_t{input}};
  std::unique_ptr<expression_t> expr = parser.parse();
  std::cout << *expr << std::endl;

  return 0;
}
