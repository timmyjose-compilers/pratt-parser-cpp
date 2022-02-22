#pragma once

#ifndef TOKEN_H
#define TOKEN_H "token.h"
#endif

#include <string>

typedef enum {
  PLUS,
  MINUS,
  MUL,
  DIV,
  MOD,
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
  const std::string &tok_spelling();
};
