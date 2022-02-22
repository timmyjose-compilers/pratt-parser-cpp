#pragma once

#ifndef PARSER_H
#define PARSER_H "parser.h"
#endif

#include "ast.h"
#include "scanner.h"

class parser_t {
private:
  scanner_t scanner;

public:
  parser_t(scanner_t scanner) : scanner(scanner) {}
  ~parser_t() {}

  expression_t parse();
};
