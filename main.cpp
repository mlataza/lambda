#include "lambda.hpp"

using namespace std;

int main()
{
  // Test the lambda here 
  auto x = lambda("x");
  auto id = lambda("x", lambda("x"));
  auto tru = lambda("x", lambda("y", lambda("x")));
  auto fls = lambda("x", lambda("y", lambda("y")));
  auto n0 = lambda("f", lambda("x", lambda("x")));
  auto n1 = lambda("f", lambda("x", lambda(lambda("f"), lambda("x"))));
  auto n2 = lambda("f", lambda("x", lambda(lambda("f"), lambda(lambda("f"), lambda("x")))));
  auto n0a = lambda(lambda("f", lambda("x", lambda("x"))), lambda("y"));

  cout << x << '\n';
  cout << id << '\n';
  cout << tru << '\n';
  cout << fls << '\n';
  cout << n0 << '\n';
  cout << n1 << '\n';
  cout << n2 << '\n';
  cout << n2 << '\n';
}