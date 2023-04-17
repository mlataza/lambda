#include "lambda.hpp"
#include "lexer.hpp"

using namespace std;

int main()
{
  // Define built-in lambdas here 
  auto x = lambda("x");
  auto id = lambda("x", lambda("x"));
  auto TRUE = lambda("x", lambda("y", lambda("x")));
  auto FALSE = lambda("x", lambda("y", lambda("y")));
  auto N0 = lambda("f", lambda("x", lambda("x")));
  auto N1 = lambda("f", lambda("x", lambda(lambda("f"), lambda("x"))));
  auto N2 = lambda("f", lambda("x", lambda(lambda("f"), lambda(lambda("f"), lambda("x")))));
  auto SUCC = lambda("n", 
    lambda("f", 
      lambda("x", 
        lambda(
          lambda("f"), 
          lambda(
            lambda(
              lambda("n"), 
              lambda("f")
            ), 
            lambda("x")
          )
        )
      )
    )
  );
  auto PLUS = lambda("m", lambda("n", lambda("f", lambda("x", 
    lambda(
      lambda(
        lambda("m"),
        lambda("f")
      ),
      lambda(
        lambda(
          lambda("n"),
          lambda("f")
        ),
        lambda("x")
      )
    )
  ))));
  auto MULT = lambda("m", lambda("n", lambda("f",
    lambda(
      lambda("m"),
      lambda(
        lambda("n"),
        lambda("f")
      )
    )
  )));
  auto POW = lambda("b", lambda("e", 
    lambda(
      lambda("e"),
      lambda("b")
    )
  ));
  auto AND = lambda("p", lambda("q", 
    lambda(
      lambda(
        lambda("p"),
        lambda("q")
      ),
      lambda("p")
    )
  ));
  auto OR = lambda("p", lambda("q", 
    lambda(
      lambda(
        lambda("p"),
        lambda("p")
      ),
      lambda("q")
    )
  ));
  auto NOT = lambda("p",
    lambda(
      lambda(
        lambda("p"),
        lambda("FALSE")
      ),
      lambda("TRUE")
    )
  );
  auto IFTHENELSE = lambda("p", lambda("a", lambda("b",
    lambda(
      lambda(
        lambda("p"),
        lambda("a")
      ),
      lambda("b")
    )
  )));
  auto ISZERO = lambda("n",
    lambda(
      lambda(
        lambda("n"),
        lambda("x",
          lambda("FALSE")
        )
      ),
      lambda("TRUE")
    )
  );
  auto LEQ = lambda("m", lambda("n",
    lambda(
      lambda("ISZERO"),
      lambda(
        lambda(
          lambda("SUB"),
          lambda("m")
        ),
        lambda("n")
      )
    )
  ));
  auto PAIR = lambda("x", lambda("y", lambda("f", 
    lambda(
      lambda(
        lambda("f"),
        lambda("x")
      ),
      lambda("y")
    )
  )));
  auto FIRST = lambda("p",
    lambda(
      lambda("p"),
      lambda("TRUE")
    )
  );
  auto SECOND = lambda("p",
    lambda(
      lambda("p"),
      lambda("FALSE")
    )
  );
  auto NIL = lambda("x", lambda("TRUE"));
  auto LNULL = lambda("p", 
    lambda(
      lambda("p"),
      lambda("x", lambda("y",
        lambda("FALSE")
      ))
    )
  );
  auto Y = lambda("g",
    lambda(
      lambda("x",
        lambda(
          lambda("g"),
          lambda(
            lambda("x"),
            lambda("x")
          )
        )
      ),
      lambda("x",
        lambda(
          lambda("g"),
          lambda(
            lambda("x"),
            lambda("x")
          )
        )
      )
    )
  );
  auto PRED = lambda("n", lambda("f", lambda("x",
    lambda(
      lambda(
        lambda(
          lambda("n"),
          lambda("g", lambda("h", 
            lambda(
              lambda("h"),
              lambda(
                lambda("g"),
                lambda("f")
              )
            )
          ))
        ),
        lambda("u", lambda("x"))
      ),
      lambda("u", lambda("u"))
    )
  )));
  auto SUB = lambda("m", lambda("n", 
    lambda(
      lambda(
        lambda("n"),
        lambda("PRED")
      ),
      lambda("m")
    )
  ));

  cout << x << '\n';
  cout << id << '\n';
  cout << TRUE << '\n';
  cout << FALSE << '\n';
  cout << N0 << '\n';
  cout << N1 << '\n';
  cout << N2 << '\n';
  cout << SUCC << '\n';
  cout << PLUS << '\n';
  cout << MULT << '\n';
  cout << POW << '\n';
  cout << AND << '\n';
  cout << OR << '\n';
  cout << NOT << '\n';
  cout << IFTHENELSE << '\n';
  cout << ISZERO << '\n';
  cout << LEQ << '\n';
  cout << PAIR << '\n';
  cout << FIRST << '\n';
  cout << SECOND << '\n';
  cout << NIL << '\n';
  cout << LNULL << '\n';
  cout << Y << '\n';
  cout << PRED << '\n';
  cout << SUB << '\n';


  // TEST THE LEXER HERE 
  //Lexer lexer{std::cin};
  //auto token = lexer.get();

  //cout << token.type << ',' << token.lexeme << '\n';
}