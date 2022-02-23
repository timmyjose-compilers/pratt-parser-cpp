#pragma once

#ifndef VISITOR_H
#define VISITOR_H "visitor.h"
#endif

struct expression_t;
struct number_t;
struct unary_expr_t;
struct binary_expr_t;

struct visitor_t {
  virtual double visit(const number_t *) = 0;
  virtual double visit(const unary_expr_t *) = 0;
  virtual double visit(const binary_expr_t *) = 0;
};

struct visitor_element_t {
  virtual double accept(visitor_t &) const = 0;
  virtual ~visitor_element_t() {}
};
