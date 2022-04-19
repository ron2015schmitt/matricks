#define MATHQ_DEBUG 1

#include "mathq.h"
#include "gitmd.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;

  cr();
  cr();

  header2("Integers");

  header3("Signed Integers");

  text("C++ supports several different signed integer types.  The size of each depends on the CPU and compiler.  However, for a 64-bit CPU running Linux, they are consistently the same:");

  cr();
  cr();
  codestart("C++");
  resultmulti(sizeof(char));
  resultmulti(sizeof(short));
  resultmulti(sizeof(int));
  resultmulti(sizeof(long));
  resultmulti(sizeof(long long));
  codeend();

  text("The C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.");
  cr();
  text("The maximum and minimum for each type are given below.");

  text("| Type | Min | Max |");
  text("| :--- | :---: | :---: |");
  printf("| ```char``` | %d | %d |\n", std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
  printf("| ```short``` | %d | %d |\n", std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
  printf("| ```int``` | %d | %d |\n", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
  printf("| ```long``` | %ld | %ld |\n", std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
  printf("| ```long long``` | %lld | %lld |\n", std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());

  cr();
  text("Here the C++ [```std::numeric_limits```](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");

  header2("Unsigned Integers");

  header3("Indexing Types");
  printf("sizeof(off_t) = %ld\n", sizeof(off_t));
  printf("sizeof(size_t) = %ld\n", sizeof(size_t));

  header2("Floating Point Numbers");

  printf("sizeof(float) = %ld\n", sizeof(float));
  printf("sizeof(double) = %ld\n", sizeof(double));
  printf("sizeof(double double) = %ld\n", sizeof(long double));

  header2("Auto-promotion");

  // text("The operators +,-,*,/ perform element-wise addition, subtraction, multiplication, and division respectively");

  // {
  //   cr();
  //   cr();
  //   example(Nex++,"Element-wise `Vector` math");
  //   codestart("C++");
  //   codemulti( Vector<double> v1(4) );
  //   codemultiNoteC11Array(v1 = {10,20,30,40});
  //   codemulti( Vector<double> v2(4) );
  //   codemultiNoteC11Array(v2 = {1,2,3,4});
  //   codeend();
  //   cr();
  //   disp(v1);
  //   disp(v1+v2);
  //   //(cout << "here")<<std::end;
  //   disp(v1);

  //   resultstart2("");
  //   resultmulti(v1 + v2);
  //   resultmulti(v1 - v2);
  //   resultmulti(v1 * v2);
  //   resultmulti(v1 / v2);
  //   resultend();
  // }

  // header3("Vector-scalar arithmetic");
  // text("* The binary operators +,-,*,/ can each be used to pair a scalar and a `Vector`.");
  // text("* In this case the scalar is operated on each element of the vector");

  // {
  //   cr();
  //   cr();
  //   example(Nex++,"math with scalars and `Vector`s");
  //   codestart("C++");
  //   codemulti( Vector<double> v1(4) );
  //   codemultiNoteC11Array(v1 = {10,20,30,40});
  //   codeend();
  //   cr();

  //   resultstart2("");
  //   resultmulti(v1 + 1);
  //   resultmulti(1 + v1);
  //   resultmulti(v1 - 10);
  //   resultmulti(40 - v1);
  //   resultmulti(v1 * 2);
  //   resultmulti(2 * v1);
  //   resultmulti(v1 / 10);
  //   resultmulti(120 / v1);
  //   resultmulti(1 + 120 / v1 - 8/8 + 5*v1*2);
  //   resultend();
  // }

  // header3("Vector math functions");
  // text("* A large number of functions is supported.  ");
  // text("* A function of a `Vector` operates on each element.  ");

  // {
  //   cr();
  //   cr();
  //   example(Nex++,"functions of a `Vector`—rounding and sign-related ");
  //   codestart("C++");
  //   codemulti( Vector<double> v(7) );
  //   codemultiNoteC11Array(v = {-2.5,-2.25,-1,0,1,2.25,2.5});
  //   codeend();
  //   cr();

  //   resultstart2(": rounding and sign-related");
  //   resultmulti( floor(v)  );
  //   resultmulti( ceil(v)  );
  //   resultmulti( round(v)  );
  //   resultmulti( sgn(v)  );
  //   resultmulti( abs(v)  );
  //   resultend();
  //   cr();
  // }

  // {
  //   cr();
  //   cr();
  //   example(Nex++,"functions of a `Vector`—powers, roots, and exponentiation");
  //   codestart("C++");
  //   codemulti( Vector<double> v(5) );
  //   codemultiNoteC11Array(v = {-1,0,1,2,4});
  //   codeend();
  //   cr();
  //   resultstart2(": powers, roots, and exponentiation");
  //   resultmulti( pow(2, v)  );
  //   resultmulti( pow(v, 2)  );
  //   resultmulti( pow(v,v)  );
  //   resultmulti( exp(v)  );
  //   resultmulti( log(v)  );
  //   resultmulti( log10(v)  );
  //   resultmulti( log2(v)  );
  //   resultmulti( sqr(v)  );
  //   resultmulti( cube(v)  );
  //   resultmulti( sqrt(v)  );
  //   resultend();
  //   cr();
  // }

  // {
  //   cr();
  //   cr();

  //   example(Nex++,"functions of a `Vector`—trig");
  //   codestart("C++");
  //   codemulti( Vector<double> v(5) );
  //   codemultiwcomment("C++11 constexpr",constexpr double pi = std::acos(-1) );
  //   codemultiNoteC11Array(v = {-pi, -pi/2, 0, pi/2, pi});
  //   codemulti( const double tol = 2e-16 );
  //   codeend();
  //   cr();

  //   resultstart2(": trig");
  //   resultmulti( sin(v)  );
  //   resultmulti( cos(v)  );
  //   resultmulti( tan(v)  );
  //   resultend();
  //   cr();
  //   text("The results are cleaner, when we round to a tolerance");
  //   cr();
  //   resultstart2(": trig with rounded zeros");
  //   resultmulti( roundzero(sin(v),tol)  );
  //   resultmulti( roundzero(cos(v),tol)  );
  //   resultmulti( roundzero(tan(v),tol)  );
  //   resultend();

  // }

  // {
  //   cr();
  //   cr();
  //   example(Nex++,"functions of a `Vector`—rounding and sign-related ");
  //   codestart("C++");
  //   codemulti( Vector<double> v(3) );
  //   codemultiNoteC11Array(v = {-1,0,1});
  //   codeend();
  //   cr();

  //   resultstart2(": hyperbolic trig");
  //   resultmulti( sinh(v)  );
  //   resultmulti( cosh(v)  );
  //   resultmulti( tanh(v)  );
  //   resultend();
  //   cr();
  // }

  // {
  //   cr();
  //   cr();
  //   example(Nex++,"functions of a `Vector`—inverse trig");
  //   codestart("C++");
  //   codemulti( double pi = std::acos(-1) );
  //   codemulti( Vector<double> v(3) );
  //   codemulti( Vector<double> v1(9) );
  //   codemulti( Vector<double> v2(9) );
  //   codemultiNoteC11Array(v = {-1,0,1});
  //   codemultiNoteC11Array(v1 = {-1,-1,-1, 0, 0, 0, 1, 1, 1});
  //   codemultiNoteC11Array(v2 = {-1, 0, 1,-1, 0, 1,-1, 0, 1});
  //   codeend();
  //   cr();

  //   resultstart2(": inverse trig");
  //   resultmulti( asin(v)/pi  );
  //   resultmulti( acos(v)/pi  );
  //   resultmulti( atan(v)/pi  );
  //   resultmulti( atan2(v1, v2)/pi  );
  //   resultend();
  // }

  // header3("Arbitrary combinations of the above functionality are supported");
  // text("* Because Mathématiques uses expression templating:");
  // text("  * no intermediate objects are created");
  // text("  * the expression is calculated in a single for loop");

  //   {
  //   cr();
  //   cr();
  //   example(Nex++,"A huge expression");
  //   codestart("C++");
  //   codemulti( Vector<double> v1(4) );
  //   codemultiNoteC11Array(v1 = {10,20,30,40});
  //   codemulti( Vector<double> v2(4) );
  //   codemultiNoteC11Array(v2 = {-1,-2,-3,-4});
  //   codeend();
  //   cr();

  //   resultstart2("");
  //   resultmulti(2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2) );
  //   resultend();
  // }

  // mathq_toc();

  return 0;
}
