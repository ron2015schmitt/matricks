#define MATRICKS_DEBUG


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
  mdtitle("Vector functions that return a scalar (dot product, sum, min, max etc)");
  matricks_preamble();

  header3("dot product—the `|` operator");
  text("* The dot product is accomplished via the `|` operator, such that the dot product takes a form similar to P.A.M. Dirac's 'bra-ket' notation.");
  text("* This definition becomes very useful for taking the product of matrices because any number of matrices can be multiplied in a single line of code.");
  
#if CPP11 == 1
  {
    cr();
    cr();
    example(Nex++,"Dot product of two vectors `(v1|v2)`");
    codestart("C++");
    codemultiwcomment("C++11 list initialization", Vector<double> v1({1,2,3,4}));
    codemultiwcomment("C++11 list initialization", Vector<double> v2({1,-1,1,-1}));
    codeend();
    cr();
#endif

   
    resultstart2("");
    resultmulti( (v1|v1) );
    resultmulti( (v2|v2) );
    resultmulti( (v1|v2) );
    resultmulti( (v2|v1) );
    resultmulti( (v1|(2*v2+1)) );
    resultend();
  }



  {
    cr();
    cr();
    example(Nex++,"`sum` the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,2,3,4}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1, 2, 3, 4} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( sum(v) );
    resultmulti( sum(2*exp(v)+1) );
    resultend();
  }


  {
    cr();
    cr();
    example(Nex++,"Compute the _product_ of the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,2,3,4}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1, 2, 3, 4} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( prod(v) );
    resultmulti( prod(2*exp(v)+1) );
    resultend();
  }



    {
    cr();
    cr();
    example(Nex++,"Find the _minimum_ of the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,20,-1,0}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1,20,-1,0} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( v );
    resultmulti( min(v) );
    resultmulti( 2*exp(v)+1 );
    resultmulti( min(2*exp(v)+1) );
    resultend();
  }


      {
    cr();
    cr();
    example(Nex++,"Find the _maximum_ of the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,20,-1,0}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1,20,-1,0} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( v );
    resultmulti( max(v) );
    resultmulti( 2*exp(v)+1 );
    resultmulti( max(2*exp(v)+1) );
    resultend();
  }

  
  matricks_toc();
  return 0;
}
