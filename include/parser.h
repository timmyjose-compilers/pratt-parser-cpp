#pragma once

#ifndef PARSER_H
#define PARSER_H "parser.h"
#endif

#include "ast.h"
#include "scanner.h"
#include "token.h"
#include <cstddef>
#include <memory>

class parser_t {
private:
  scanner_t scanner;
  token_t curr_tok;

  int lbp(token_kind_t);
  std::unique_ptr<expression_t> led(std::unique_ptr<expression_t>, token_kind_t,
                                    std::unique_ptr<expression_t>);
  std::unique_ptr<expression_t> nud(token_t);
  std::unique_ptr<expression_t> parse_expression(int = 0);

public:
  parser_t(scanner_t scanner) : scanner(scanner) {}
  ~parser_t() {}

  std::unique_ptr<expression_t> parse();
};
