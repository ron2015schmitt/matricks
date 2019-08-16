#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{

  int Nex = 1;
  
  cr();
  mdtitle("Vector math");
  matricks_preamble();

  header3("Element-wise arithmetic");
  text("The operators +,-,*,/ perform element wise addition, subtraction, multiplication, and division respectively");

  {
    cr();
    cr();
    example(Nex++,"Element-wise `Vector` math");
    codestart("C++");
    codemulti( Vector<double> v1(4) );
#if CPP11 == 1
    codemultiwcomment("C++11 list", v1 = {10,20,30,40});
#else
    codemulti( v1 = (const double[]) {10,20,30,40} );
#endif
    codemulti( Vector<double> v2(4) );
#if CPP11 == 1
    codemultiwcomment("C++11 list", v2 = {1,2,3,4});
#else
    codemulti( v2 = (const double[]) {1,2,3,4} );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti(v1 + v2);
    resultmulti(v1 - v2);
    resultmulti(v1 * v2);
    resultmulti(v1 / v2);
    resultend();
  }


  header3("Vector-scalar arithmetic");
  text("* The binary operators +,-,*,/ can each be used to pair a scalar and a `Vector`.");
  text("* In this case the scalar is operated on each element of the vector");

  {
    cr();
    cr();
    example(Nex++,"math with scalars and `Vector`s");
    codestart("C++");
    codemulti( Vector<double> v1(4) );
#if CPP11 == 1
    codemultiwcomment("C++11 list", v1 = {10,20,30,40});
#else
    codemulti( v1 = (const double[]) {10,20,30,40} );
#endif
    codeend();
    cr();

    resultstart2("");
    resultmulti(v1 + 1);
    resultmulti(1 + v1);
    resultmulti(v1 - 10);
    resultmulti(40 - v1);
    resultmulti(v1 * 2);
    resultmulti(2 * v1);
    resultmulti(v1 / 10);
    resultmulti(120 / v1);
    resultmulti(1 + 120 / v1 - 8/8 + 5*v1*2);
    resultend();
  }


  header3("Vector math functions");
  text("* A large number of functions is supported.  ");
  text("* A function of a `Vector` operates on each element.  ");
  
  {
    cr();
    cr();
    example(Nex++,"functions of a `Vector`");
    codestart("C++");
    codemulti( Vector<double> v(3) );
#if CPP11 == 1
    codemultiwcomment("C++11 list", v = {-2.5,-2.25,-1,0,1,2.25,2.5});
#else
    codemulti( v = (const double[]) {-2.5,-2.25,-1,0,1,2.25,2.5} );
#endif
    codeend();
    cr();

    resultstart2(": rounding and sign-related");
    resultmulti( floor(v)  );
    resultmulti( ceil(v)  );
    resultmulti( round(v)  );
    resultmulti( sgn(v)  );
    resultmulti( abs(v)  );
    resultstart2(": powers, roots, and exponentiation");
    //    resultmulti( pow(10,v)  );
    //    resultmulti( pow(v,2)  );
    //    resultmulti( pow(v2,2)  );
    resultmulti( exp(v)  );
    resultmulti( log(v)  );
    resultmulti( log10(v)  );
    resultmulti( sqr(v)  );
    resultmulti( cube(v)  );
    resultmulti( sqrt(v)  );
    resultstart2(": trig");
    resultmulti( sin(v)  );
    resultmulti( cos(v)  );
    resultmulti( tan(v)  );
    resultstart2(": hyperbolic trig");
    resultmulti( sinh(v)  );
    resultmulti( cosh(v)  );
    resultmulti( tanh(v)  );
    resultstart2(": inverse (ie 'arc') trig");
    resultmulti( asin(v)  );
    resultmulti( acos(v)  );
    resultmulti( atan(v)  );
    resultend();
  }



  header3("Arbitrary combinations of the above functionality are supported");

  
  matricks_toc();


  return 0;
}
