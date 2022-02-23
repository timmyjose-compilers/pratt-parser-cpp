#pragma once

#ifndef EVALUATOR_H
#define EVALUATOR_H "evaluator.h"
#endif

#include "parser.h"
#include "visitor.h"
#include <memory>

class evaluator_t : public visitor_t {
  parser_t parser;

public:
  evaluator_t(parser_t parser) : parser(parser) {}

  double evaluate();
  double visit(const number_t *);
  double visit(const unary_expr_t *);
  double visit(const binary_expr_t *);
};
