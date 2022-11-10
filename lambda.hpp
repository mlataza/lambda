#ifndef LAMBDA_H
#define LAMBDA_H

#include <iostream>
#include <string>
#include <memory>

class Lambda
{
public:
  enum Type
  {
    VARIABLE,
    ABSTRACTION,
    APPLICATION
  };

  // Constructors
  Lambda(std::string variable);
  Lambda(std::string variable, std::unique_ptr<Lambda> body);
  Lambda(std::unique_ptr<Lambda> func, std::unique_ptr<Lambda> param);

  // Query methods
  Type type() const;

  // Output
  friend std::ostream &operator<<(std::ostream &os, const std::unique_ptr<Lambda> &term);

private:
  Type type_;
  std::string variable_;
  std::unique_ptr<Lambda> left_;
  std::unique_ptr<Lambda> right_;
};

template <typename... T>
constexpr std::unique_ptr<Lambda> lambda(T&&... args)
{
  return std::make_unique<Lambda>(std::move(args)...);
}

#endif