#include "../include/evaluator.h"
#include <cmath>

double evaluator_t::evaluate() {
  auto expr = parser.parse();
  return expr->accept(*this);
}

double evaluator_t::visit(const number_t *num) { return num->val; }

double evaluator_t::visit(const unary_expr_t *unary) {
  switch (unary->op) {
  case PLUS:
    return unary->expr->accept(*this);
  case MINUS:
    return -unary->expr->accept(*this);
  default:
    throw "unreachable";
  }
}

double evaluator_t::visit(const binary_expr_t *binary) {
  auto lhs = binary->left->accept(*this);
  auto rhs = binary->right->accept(*this);

  switch (binary->op) {
  case PLUS:
    return lhs + rhs;
  case MINUS:
    return lhs - rhs;
  case MUL:
    return lhs * rhs;
  case DIV:
    return lhs / rhs;
  case MOD:
    return fmod(lhs, rhs);
  case POW:
    return pow(lhs, rhs);
  default:
    throw "unreachable";
  }
}
