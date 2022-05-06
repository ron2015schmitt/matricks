#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>

#define MATHQ_DEBUG 1
#include "mathq.h"

int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  markdown_preamble();

  CR();
  CR();

  vspace();
  header2("Logic Operators");
  text("For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).\n");

  CR();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| `!` | logical NOT | ");
  text("| `\\|\\|` | logical OR | ");
  text("| `&&` | logical AND | ");
  CR();

  text("**CAVEAT**: C++ also has binary bit-wise operators `&` and `|`.  Mistyping the above operators can cause painful bugs. \n");

  CR();
  text("Examples:\n");
  codestart("C++");
  trdisp(true);
  trdisp(false);
  trdisp(!true);
  trdisp(!false);
  trdisp(true && true);
  trdisp(true && false);
  trdisp(true || false);
  codeend();

  text("* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`\n");
  codestart("C++");
  trdisp(!true);
  trdisp(!8);
  trdisp(!!8.293);
  trdisp(true && 3);
  trdisp(true && 0);
  codeend();

  vspace();

  return 0;
}
