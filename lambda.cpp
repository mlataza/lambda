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
    os << '(' << term->left_ << ' ' << term->right_ << ')';
  }

  return os;
}