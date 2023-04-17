#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <deque>
#include <iostream>

class Lexer
{
public:
  struct Token
  {
    enum Type
    {
      END_OF_FILE,
      LAMBDA,
      VARIABLE,
      DOT,
      LPAREN, 
      RPAREN
    };

    Type type; 
    std::string lexeme; 
  };

  Lexer(std::istream &is);
  Token get();
  Token peek();

private:
  Token next();

  enum State
  {
    OUTSIDE_TOKEN,
    LPAREN,
    RPAREN,
    DOT
  };

  State state_;
  std::istream &input_; 
  std::deque<Token> tokens_; 
  std::string lexeme_;
};

#endif 