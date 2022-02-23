#pragma once

#ifndef TOKEN_H
#define TOKEN_H "token.h"
#endif

#include <iostream>
#include <string>

typedef enum {
  PLUS,
  MINUS,
  MUL,
  DIV,
  MOD,
  POW,
  LPAREN,
  RPAREN,
  NUMBER,
  EOI,
  ILLEGAL
} token_kind_t;

const char *token_kind_to_str(const token_kind_t);

class token_t {
private:
  token_kind_t kind;
  std::string spelling;

public:
  token_t() {}
  token_t(token_kind_t kind, std::string spelling)
      : kind(kind), spelling(spelling) {}

  ~token_t() {}

  token_kind_t tok_kind();
  std::string &tok_spelling();

  friend std::ostream &operator<<(std::ostream &os, const token_t &tok) {
    return os << "<" << token_kind_to_str(tok.kind) << ";" << tok.spelling
              << ">" << std::endl;
  }
};
