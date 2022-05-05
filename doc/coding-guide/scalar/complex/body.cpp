#define MATHQ_DEBUG 1

#include "mathq.h"
#include "gitmd.h"

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;
  using namespace md;

  cr();
  cr();

  header2("Introduction");

  text("\n<br>\n");
  header2("Size of complex numbers");

  text("C++ supports several different signed integer types.  The size of each depends on the CPU and compiler.  For a 64-bit CPU running Linux, they have the following number of bits:");

  cr();
  cr();
  codestart("C++");
  printf("CHAR_BIT = %d bits\n", CHAR_BIT);
  printf("CHAR_BIT*sizeof(char) = %ld bits\n", CHAR_BIT * sizeof(char));
  printf("CHAR_BIT*sizeof(short) = %ld bits\n", CHAR_BIT * sizeof(short));
  printf("CHAR_BIT*sizeof(int) = %ld bits\n", CHAR_BIT * sizeof(int));
  printf("CHAR_BIT*sizeof(long) = %ld bits\n", CHAR_BIT * sizeof(long));
  printf("CHAR_BIT*sizeof(long long) = %ld bits\n", CHAR_BIT * sizeof(long long));
  codeend();

  text("The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.");
  cr();
  text("\n<br>\n");
  header2("Operators and functions");

  header3("Arithmetic Operators");
  text("The operators ```+, -, *, /, %``` are the addition, subtraction, multiplication, division, and modulus operators respectively.\n");
  text("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| ```+``` | addition | ");
  text("| ```-``` | subtraction | ");
  text("| ```*``` | multiplication | ");
  text("| ```/``` | division | ");
  text("| ```%``` | modulus | ");
  cr();

  text("* If both numerator and denominator are integers, the division operator gives the integer division result.\n");
  codestart("C++");
  disp(7 / 2);
  codeend();
  text("* The modulus operator ```a % b```, gives the remainder after integer divison of ```a``` by ```b```.\n");
  codestart("C++");
  disp(7 % 2);
  codeend();
  text("* The function [```std::div```](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.\n");

  codestart("C++");
  codemulti(div_t result = div(7, 2));
  codeend();
  text("With result:\n");
  codestart("C++");
  disp(result.quot);
  disp(result.rem);
  codeend();

  // Exponentiation and the power function
  text("\n<br>\n");
  header3("Exponentiation and the ```pow``` function");
  text("C++ does not have an exponentiation operator.  Instead it provides the [```std::pow```](https://en.cppreference.com/w/cpp/numeric/math/div) function");
  codestart("C++");
  disp(pow(2, 8));
  codeend();

  text("\n<br>\n");
  header3("Logic Operators");
  text("For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| ```!``` | logical NOT | ");
  text("| `\\|\\|` | logical OR | ");
  text("| ```&&``` | logical AND | ");
  cr();

  text("Examples:\n");
  codestart("C++");
  disp(true);
  disp(false);
  disp(!true);
  disp(!false);
  disp(true && true);
  disp(true && false);
  disp(true || false);
  codeend();

  text("* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`\n");
  codestart("C++");
  disp(!true);
  disp(!8);
  disp(!!8.293);
  disp(true && 3);
  disp(true && 0);
  codeend();

  text("\n<br>\n");
  header3("Relational Operators");

  text("For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| `==` | equal to | ");
  text("| `!=` | not equal to | ");
  text("| `<` | less than | ");
  text("| `<=` | less than or equal to | ");
  text("| `>` | greater than | ");
  text("| `>=` | greater than or equal to | ");
  // text("| `<=>` | three-way comparison | ");
  cr();

  text("Examples:\n");
  codestart("C++");
  disp((2 == 2));
  disp((1 / 2 == 0.5));
  disp((1. / 2 == 0.5));
  disp((-2 < 34.2));
  disp((2 > 0));
  codeend();

  text("\n<br>\n");
  header3("Mathematical functions from the C++ ``std`` library");

  header4("C++ ``std`` library common functions");

  cr();
  text("The following are [common mathematical functions](https://en.cppreference.com/w/cpp/numeric/math) implemented in the C++ `std` library");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `abs` | [absolute value](https://en.cppreference.com/w/cpp/numeric/math/abs) | ");
  text("| `ceil` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/math/ceil) | ");
  text("| `floor` | [floor function](https://en.cppreference.com/w/cpp/numeric/math/floor) | ");
  text("| `trunc` | [truncate function](https://en.cppreference.com/w/cpp/numeric/math/trunc) | ");
  text("| `round` | [round function](https://en.cppreference.com/w/cpp/numeric/math/round) | ");
  cr();
  cr();

  text("*Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `sin` | [sine](https://en.cppreference.com/w/cpp/numeric/math/sin) | ");
  text("| `cos` | [cosine](https://en.cppreference.com/w/cpp/numeric/math/cos) | ");
  text("| `tan` | [tangent](https://en.cppreference.com/w/cpp/numeric/math/tan) | ");
  cr();
  cr();

  text("*Inverse Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `asin` | [arc sine](https://en.cppreference.com/w/cpp/numeric/math/asin) | ");
  text("| `acos` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acos) | ");
  text("| `atan` | [arc tangent](https://en.cppreference.com/w/cpp/numeric/math/atan) | ");
  text("| `atan2(y, x)` | [arc tangent of y/x with quadrant](https://en.cppreference.com/w/cpp/numeric/math/atan2) | ");
  cr();
  cr();

  text("*Hyperbolic Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `sinh` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/math/sinh) | ");
  text("| `cosh` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/math/cosh) | ");
  text("| `tanh` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/math/tanh) | ");
  cr();
  cr();

  text("*Inverse Hyperbolic Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `asinh` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/math/asinh) | ");
  text("| `acosh` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acosh) | ");
  text("| `atanh` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/math/atanh) | ");

  cr();
  cr();

  text("*Exponentiation*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/math/pow) | ");
  text("| `sqrt` | [Square Root](https://en.cppreference.com/w/cpp/numeric/math/sqrt) | ");
  text("| `cqrt` | [Cube Root](https://en.cppreference.com/w/cpp/numeric/math/cqrt) | ");

  cr();
  cr();

  text("*Exponentials*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `exp` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp) | ");
  text("| `exp2` | [2<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp2) | ");
  text("| `expm1` | [e<sup>x</sup> - 1](https://en.cppreference.com/w/cpp/numeric/math/expm1) | ");
  cr();
  cr();

  text("*Logarithms*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `log` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log) | ");
  text("| `log10` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log10) | ");
  text("| `log2` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log2) | ");
  text("| `log1p` | [ln(x + 1)](https://en.cppreference.com/w/cpp/numeric/math/log1p) | ");
  text("| `logb` | [extracts exponent of the number and returns a floating point type](https://en.cppreference.com/w/cpp/numeric/math/logb) | ");
  text("| `ilogb` | [extracts exponent of the number and returns an integral type](https://en.cppreference.com/w/cpp/numeric/math/ilogb) | ");

  cr();
  cr();

  text("*Other Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `erf` | [error function, erf(x)](https://en.cppreference.com/w/cpp/numeric/math/erf) | ");
  text("| `erfc` | [complimentary error function, erfc(x)](https://en.cppreference.com/w/cpp/numeric/math/erfc) | ");
  text("| `tgamma` | [Gamma Function, Γ(x)](https://en.cppreference.com/w/cpp/numeric/math/tgamma) | ");
  text("| `lgamma` | [Natural Logarithm of the Gamma Function, ln(Γ(x))](https://en.cppreference.com/w/cpp/numeric/math/lgamma) | ");
  cr();
  cr();


  header4("C++ ``std`` library special functions");

  text("The following [special mathematical functions](https://en.cppreference.com/w/cpp/numeric/special_functions) implemented in the C++ `std` library");
  cr();

  text("*Bessel Functions*");
  cr();
  text("| <div style='width:180px'>function</div> | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `cyl_bessel_j(𝜈, x)` | _J_<sub>𝜈</sub>(_x_) | [Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_j) | ");
  text("| `cyl_neumann(𝜈, x)` | _Y_<sub>𝜈</sub>(_x_) | [Bessel (aka Neumann or Weber) function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_neumann) | ");
  text("| `cyl_bessel_i(𝜈, x)` | _I_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_i) | ");
  text("| `cyl_bessel_k(𝜈, x)` | _K_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_k) | ");

  cr();
  cr();
  text("*Spherical Bessel Functions*");
  cr();
  text("| <div style='width:180px'>function</div> | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `sph_bessel(n, x)` | _j_<sub>n</sub>(_x_) | [Spherical Bessel function of the 1st kind of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_bessel) | ");
  text("| `sph_neumann(n, x)` | _y_<sub>n</sub>(_x_) | [Spherical Bessel (aka Neumann or Weber) function of the 2nd kind of degree n, aka Spherical Neumann function](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_neumann) | ");
  cr();
  cr();


  text("*Orthogonal Polynomials*");
  cr();
  text("| <div style='width:180px'>function</div>  | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `hermite(n, x)` | _H_<sub>n</sub>(_x_) | [Hermite polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/hermite) | ");
  text("| `laguerre(n, x)` | _L_<sub>n</sub>(_x_) | [Laguerre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/laguerre) | ");
  text("| `legendre(n, x)` | _P_<sub>n</sub>(_x_) | [Legendre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/legendre) | ");
  text("| `assoc_laguerre(n, m, x)` | _L_<sub>n,m</sub>(_x_) | [Associated Laguerre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_laguerre) | ");
  text("| `assoc_legendre(n, m, x)` | _P_<sub>n,m</sub>(_x_) | [Associated Legendre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_legendre) | ");
  cr();
  cr();

  text("*Other Special Functions*");
  cr();
  text("| <div style='width:180px'>function</div> | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `beta(x, y)` |  B(_x_,_y_) | [Euler beta function (Euler Integral of the 1st kind)](https://en.cppreference.com/w/cpp/numeric/special_functions/beta) | ");
  text("| `comp_ellint_1(k)` |  _K_(_k_) |  [Complete elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_1) | ");
  text("| `comp_ellint_2(k)` |  _E_(_k_) |  [Complete elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_2) | ");
  text("| `comp_ellint_3(n, k)` |  _Π_(_n_,_k_) |  [Complete elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_3) | ");
  text("| `ellint_1(k, φ)` |  _F_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_1) | ");
  text("| `ellint_2(k, φ)` |  _E_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_2) | ");
  text("| `ellint_3(k, n, φ)` |  _Π_(_n_; _φ_, _k_) |  [(Incomplete) elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_3) | ");
  text("| `expint(x)` |  Ei(_x_) |  [Exponential Integral](https://en.cppreference.com/w/cpp/numeric/special_functions/expint) | ");
  text("| `riemann_zeta(x)` |  ζ(_x_) | [Riemann Zeta Function](https://en.cppreference.com/w/cpp/numeric/special_functions/riemann_zeta) | ");
  text("| `sph_legendre(l, m, θ)` | _Y_<sub>_l_</sub><sup>_m_</sup></sub>(_θ_, _φ_=0) | [Spherical Associated Legendre function<sup>†</sup> of degree _l_, order _m_](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_legendre) | ");
  cr();
  cr();
  text("† This is equal to a [Spherical Harmonic](https://en.wikipedia.org/wiki/Spherical_harmonics) with _φ_=0, as the notation implies.");

  header3("Mathematical functions from the Mathématiques library, namespace `mathq`");

  text("The following are mathematical functions implemented in the Mathématiques library, namespace `mathq`");
  cr();
  text("| function | description | ");
  text("| :---: | :---: | ");
  text("| `sgn(x)` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | ");
  text("| `zero(x)` | return a zero with the same type as x | ");
  text("| `sqr(x)` | x<sup>2</sup> | ");
  text("| `cube(x)` | x<sup>3</sup> | ");
  cr();
  cr();


  text("\n<br>\n");
  header2("More on types");

  header3("Type information");

  header4("typeid");

  text("The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). ");
  text("This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. ");
  cr();

  {
    text("Examples:\n");
    codestart("C++");
    codemulti(int n = 3);
    // disp(typeid(n).name());
    text("typeid(n).name() -> \"i\"");
    codemulti(string s = "hello");
    // disp(typeid(s).name());
    text("typeid(s).name() -> \"NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE\"");
    codeend();
  }

  header4("getTypeName");
  text("The function `mathq::display::getTypeName` returns a string that gives the actual human-readable type name. It works for most [fundamental types](https://en.cppreference.com/w/cpp/language/types) and all classes defined in ");
  {
    text("Examples:\n");
    codestart("C++");
    codemulti(int n = 3);
    // disp(getTypeName(n));
    text("getTypeName(n) -> \"int\"");
    codemulti(string s = "hello");
    // disp(getTypeName(s));
    text("getTypeName(s) -> \"std::string\"");
    codeend();
  }
  text("\n<br>\n");
  header3("Mixed-typed math and auto-promotion");
  cr();
  text("C++ automatically converts number types depending on context.");
  text("This is referred to as [implicit conversion](https://en.cppreference.com/w/c/language/conversion).");
  text("For example, when adding an integer and a floating point number, the integer is first converted to a floating point type before the addition takes place.");
  text("As another example, when adding two integers (or floating point types) of different sizes, the smaller size is first converted to the larger size. This porces is referred to as _promotion_.");

  {
    text("Examples:\n");
    codestart("C++");
    codemulti(short n1 = 3);
    codemulti(int n2 = 100);
    // tdisp(n1 * n2);
    text("n1 * n2 -> int 300");
    cr();
    codemulti(float x1 = 3);
    codemulti(double x2 = 0.1415);
    // tdisp(x1 + x2);
    text("x1 + x2 -> double 3.1415");
    cr();
    codemulti(int8_t y1 = 25);
    codemulti(double y2 = 0.25);
    // tdisp(y1 / y2 + y2);
    text("y1 / y2 + y2 -> double 100.25");
    codeend();
  }

  text("\n<br>\n");
  header3("Type Conversion");
  text("There are various ways to cast one type to another in C++.  ");
  text("Here we demonstrate [explicit conversion](https://en.cppreference.com/w/cpp/language/explicit_cast), which has two forms for the syntax: `(type) expression` or  `type(expression)` ");
  cr();
  cr();

  {
    text("Converting a floating point type to an integer:\n");
    codestart("C++");
    codemulti(int n1 = (int) 3.14 );
    // tdisp(n1);
    text("n1 -> 3");
    codemulti(int n2 = int(3.14) );
    // tdisp(n2);
    text("n2 -> 3");
    codeend();
  }

  {
    text("Forcing floating point division by converting the numerator to a `float`\n");
    codestart("C++");
    codemulti(double x = (21 + 1)/7 );
    // tdisp(x);
    text("x -> 3");
    codemulti(double y = float(21 + 1)/7 );
    // tdisp(y);
    text("y -> 3.14286");
    codeend();
  }


  return 0;
}
