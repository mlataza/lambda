#include "lambda.hpp"

using namespace std;

// Constructors
Lambda::Lambda(string variable)
    : type_{VARIABLE}, variable_{variable}, left_{nullptr}, right_{nullptr}
{
}

Lambda::Lambda(string variable, unique_ptr<Lambda> body)
    : type_{ABSTRACTION}, variable_{variable}, left_{move(body)}, right_{nullptr}
{
}

Lambda::Lambda(unique_ptr<Lambda> func, unique_ptr<Lambda> param)
    : type_{APPLICATION}, variable_{}, left_{move(func)}, right_{move(param)}
{
}

// Query methods
Lambda::Type Lambda::type() const
{
  return type_;
}

// Output operation
ostream &operator<<(ostream &os, const unique_ptr<Lambda> &term)
{
  switch (term->type_)
  {
  case Lambda::VARIABLE:
    os << term->variable_;
    break;
  case Lambda::ABSTRACTION:
    os << '\\' << term->variable_ << '.' << term->left_;
    break;
  case Lambda::APPLICATION:
    if (term->left_->type_ == Lambda::ABSTRACTION)
    {
      // Enclose in parenthesis
      os << '(' << term->left_ << ')';
    }
    else 
    {
      os << term->left_;
    }
    os << ' ';
    
    if (term->right_->type_ == Lambda::ABSTRACTION  || term->right_->type_ == Lambda::APPLICATION)
    {
      os << '(' << term->right_ << ')';
    }
    else 
    {
      os << term->right_;
    }
    break;
  }

  return os;
}