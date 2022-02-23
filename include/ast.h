#pragma once

#ifndef AST_H
#define AST_H "ast.h"
#endif

#include "token.h"
#include <iostream>
#include <memory>
#include <string>

struct expression_t {
  virtual ~expression_t() {}
  virtual void show(std::ostream &) const = 0;

  friend std::ostream &operator<<(std::ostream &os, const expression_t &expr) {
    expr.show(os);
    return os;
  }
};

struct number_t : expression_t {
  int val;

  number_t(int val) : val(val) {}

  void show(std::ostream &os) const override { os << this->val; }
};

struct unary_expr_t : expression_t {
  token_kind_t op;
  std::unique_ptr<expression_t> expr;

  unary_expr_t(token_kind_t op, std::unique_ptr<expression_t> expr)
      : op(op), expr(std::move(expr)) {}

  void show(std::ostream &os) const override {
    os << "(" << token_kind_to_str(this->op) << " " << *this->expr << ")";
  }
};

struct binary_expr_t : expression_t {
  std::unique_ptr<expression_t> left;
  token_kind_t op;
  std::unique_ptr<expression_t> right;

  binary_expr_t(std::unique_ptr<expression_t> left, token_kind_t op,
                std::unique_ptr<expression_t> right)
      : left(std::move(left)), op(op), right(std::move(right)) {}

  void show(std::ostream &os) const override {
    os << "(" << *this->left << " " << token_kind_to_str(this->op) << " "
       << *this->right << ")";
  }
};
