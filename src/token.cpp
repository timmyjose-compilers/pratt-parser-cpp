#include "../include/token.h"

token_kind_t token_t::tok_kind() { return this->kind; }

const std::string &token_t::tok_spelling() { return this->spelling; }

const char *token_kind_to_str(const token_kind_t kind) {
  switch (kind) {
  case PLUS:
    return "+";
  case MINUS:
    return "-";
  case MUL:
    return "*";
  case DIV:
    return "/";
  case MOD:
    return "%";
  case NUMBER:
    return "number";
  case EOI:
    return "<eof>";
  default:
    return "unknown";
  }
}
