#include "../include/ast.h"
#include "../include/parser.h"
#include <cstdlib>
#include <memory>
#include <string>

const int LOWEST_PRECEDENCE = -1;
const int HIGHEST_PRECEDENCE = 40;

std::unique_ptr<expression_t> parser_t::nud(token_t tok) {
  switch (tok.tok_kind()) {
  case LPAREN: {
    std::unique_ptr<expression_t> expr = parse_expression();
    if (curr_tok.tok_kind() != RPAREN) {
      std::cerr << "Missing right parenthesis" << std::endl;
      std::exit(1);
    }
    curr_tok = scanner.scan();
    return expr;
  }
  case NUMBER:
    return std::make_unique<number_t>(std::stoi(tok.tok_spelling()));
  case PLUS:
  case MINUS:
    return std::make_unique<unary_expr_t>(tok.tok_kind(),
                                          parse_expression(HIGHEST_PRECEDENCE));
  default:
    throw "nud is not applicable for this token";
  }

  return nullptr;
}

std::unique_ptr<expression_t>
parser_t::led(std::unique_ptr<expression_t> left, token_kind_t op,
              std::unique_ptr<expression_t> right) {
  return std::make_unique<binary_expr_t>(std::move(left), std::move(op),
                                         std::move(right));
}

int parser_t::lbp(token_kind_t kind) {
  switch (kind) {
  case PLUS:
  case MINUS:
    return 10;
  case MUL:
  case DIV:
    return 20;
  case POW:
    return 30;
  case MOD:
    return 40;
  default:
    return LOWEST_PRECEDENCE; // for EOI, etc.
  }
}

bool is_right_associative(token_kind_t kind) {
  switch (kind) {
  case POW:
    return true;
  default:
    return false;
  }
}

std::unique_ptr<expression_t> parser_t::parse_expression(int rbp) {
  token_t tok = curr_tok;
  curr_tok = scanner.scan();
  std::unique_ptr<expression_t> left = nud(tok);

  while (rbp < lbp(curr_tok.tok_kind())) {
    token_kind_t kind = curr_tok.tok_kind();
    curr_tok = scanner.scan();
    if (is_right_associative(kind)) {
      left = led(std::move(left), kind, parse_expression(lbp(kind) - 1));
    } else {
      left = led(std::move(left), kind, parse_expression(lbp(kind)));
    }
  }
  return left;
}

std::unique_ptr<expression_t> parser_t::parse() {
  curr_tok = scanner.scan();
  std::unique_ptr<expression_t> ast = parse_expression();
  if (curr_tok.tok_kind() != EOI) {
    std::cerr << "extraneous tokens, curr_tok = " << curr_tok << std::endl;
    std::exit(1);
  }

  return ast;
}
