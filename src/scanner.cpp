#include "../include/scanner.h"
#include "../include/token.h"
#include <cctype>
#include <iostream>

void scanner_t::skip_it() {
  this->curr_idx++;

  if (this->curr_idx >= this->input.size()) {
    std::cerr << "[skip_it] out of range (curr_idx = " << this->curr_idx
              << std::endl;
    std::exit(1);
  }

  this->curr_char = this->input[this->curr_idx];
}

void scanner_t::skip_whitespace() {
  while (isspace(curr_char)) {
    skip_it();
  }
}

void scanner_t::eat_it() {
  this->curr_idx++;
  if (this->curr_idx >= this->input.size()) {
    std::cerr << "[eat_it] out of range (curr_idx = " << this->curr_idx
              << std::endl;
    std::exit(1);
  }

  this->curr_spelling += this->curr_char;
  this->curr_char = this->input[this->curr_idx];
}

token_kind_t scanner_t::scan_token() {
  switch (curr_char) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    eat_it();
    while (isdigit(curr_char)) {
      eat_it();
    }
    return NUMBER;

  case '+':
    eat_it();
    return PLUS;

  case '-':
    eat_it();
    return MINUS;

  case '*':
    eat_it();
    return MUL;

  case '/':
    eat_it();
    return DIV;

  case '%':
    eat_it();
    return MOD;

  case '^':
    eat_it();
    return POW;

  case '(':
    eat_it();
    return LPAREN;

  case ')':
    eat_it();
    return RPAREN;

  case 0:
    return EOI;

  default:
    std::cerr << "Invalid character: " << curr_char << std::endl;
    std::exit(1);
  }
}

token_t scanner_t::scan() {
  if (isspace(this->curr_char)) {
    skip_whitespace();
  }

  curr_spelling.clear();
  token_kind_t curr_kind = scan_token();

  return token_t(curr_kind, curr_spelling);
}
