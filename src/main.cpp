#include "../include/ast.h"
#include "../include/parser.h"
#include "../include/scanner.h"
#include "../include/token.h"
#include <iostream>

int main() {
  std::cout << "Pratt parsing demo for arithmetic expressions\n";

  std::string input;
  std::getline(std::cin, input);

  scanner_t scanner(input);
  // token_t tok;
  // do {
  //   tok = scanner.scan();
  //   std::cout << "<kind: " << token_kind_to_str(tok.tok_kind())
  //             << ", spelling : " << tok.tok_spelling() << ">" << std::endl;
  // } while (tok.tok_kind() != EOI);

  parser_t parser(scanner);
  expression_t expr = parser.parse();
  // std::cout << expr << std::endl;

  return 0;
}
