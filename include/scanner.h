#pragma once

#ifndef SCANNER_H
#define SCANNER_H "scanner.h"
#endif

#include "token.h"
#include <cstddef>
#include <iostream>

class scanner_t {
private:
  std::string input;
  char curr_char;
  size_t curr_idx;
  std::string curr_spelling;

  void skip_it();
  void eat(const token_kind_t);
  void eat_it();
  void skip_whitespace();

  token_kind_t scan_token();

public:
  scanner_t(std::string input) : input(input), curr_char(0), curr_idx(-1) {
    this->input += (char)0;
    eat_it();
  }
  ~scanner_t() {}

  token_t scan();
};
