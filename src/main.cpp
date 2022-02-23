#include "../include/ast.h"
#include "../include/evaluator.h"
#include "../include/parser.h"
#include "../include/scanner.h"
#include "../include/token.h"
#include <iostream>
#include <memory>

int main() {
  std::cout << "Pratt parsing demo for arithmetic expressions\n";

  std::string input;
  std::getline(std::cin, input);

  evaluator_t evaluator{parser_t{scanner_t{input}}};
  std::cout << evaluator.evaluate() << std::endl;

  return 0;
}
