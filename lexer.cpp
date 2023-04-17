#include "lexer.hpp"

#include <cctype>

Lexer::Lexer(std::istream &is)
    : state_{Lexer::State::OUTSIDE_TOKEN}, input_{is}, tokens_{}
{
}

Lexer::Token Lexer::get()
{
  // Return the front of the tokens queue if not empty
  if (tokens_.empty())
  {
    return next();
  }
  else 
  {
    Token token = tokens_.front();
    tokens_.pop_front();
    return token; 
  }
}

Lexer::Token Lexer::peek()
{
  // Check if the queue of tokens is not empty
  if (tokens_.empty())
  {
    tokens_.push_back(next());
  }

  return tokens_.front();
}

Lexer::Token Lexer::next()
{
  // Define eof token 
  auto eofToken = Token{Token::END_OF_FILE, ""};

  // Clear the lexeme
  lexeme_ = "";

  // Skip spaces
  while (!input_.eof() && isspace(input_.peek()) && state_ == State::OUTSIDE_TOKEN)
  {
    input_.get();
  }

  // Check if EOF is received
  if (input_.eof())
  {
    return eofToken;
  }

  // Change the state 
  char c = input_.peek();
  /*
  switch (c)
  {
    case '.':
      input_.get();
      state_ = STATE
  }
  */

  // Read the input stream and check if a token has been formed 
  while (input_.eof() && state_ != OUTSIDE_TOKEN)
  {
    
  }

  return {};
}