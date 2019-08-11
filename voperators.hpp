// START-OF-NOTICE
// Copyright 2003, Columbia University
// Authors: Ron Schmitt
//
//
// This file is part of the Columbia Object Oriented 
// Linear-algebra Library (COOLL).
//
// You should have received a copy of the License Agreement for the
// COOLL along with the software;  see the file LICENSE.  
// If not, contact
// Department of Applied Physics and Applied Mathematics
// Columbia Univeristy 
// New York, NY 10027
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
// END-OF-NOTICE
//===========================================================================




#ifndef VOPERATORS_H
#define VOPERATORS_H 1


#include <string>
#include <sstream>


namespace COOLL {



  /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an LAvector or a Vexpr
   * B = either an LAvector or a Vexpr
   ************************************************************
   */

  // vector + vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApAdd<D> > 
  operator+(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApAdd<D> >(a,b);
  }



  // vector - vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApSubtract<D> > 
  operator-(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApSubtract<D> >(a,b);
  }


  // vector * vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApMultiply<D> > 
  operator*(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApMultiply<D> >(a,b);
  }


  // vector / vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApDivide<D> > 
  operator/(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApDivide<D> >(a,b);
  }




  /*

  // vector , vector

  template <class D, class A, class B> 
  inline VConcatOp<D,VorE<D,A>,VorE<D,B> > 
  operator,(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VConcatOp<D,VorE<D,A>,VorE<D,B> >(a,b);
  }

  // vectorexp , scalar

  template <class D, class A> 
  inline VConcatOp<D,VorE<D,A>,VScalObj<D> > 
  operator,(const VorE<D,A>& a, const D b)
  {
    return  VConcatOp<D,VorE<D,A>,VScalObj<D> >(a,VScalObj<D>(b));
  }

  */




  /************************************************************
   *               Templates for vector/scalar Operators
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an LAvector or a Vexpr
   ************************************************************
   */


  // vector + scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApAdd<D> > 
  operator+(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApAdd<D> >(a,b);
  }

  // scalar + vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApAdd<D> > 
  operator+(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApAdd<D> > (a,b);
  }


  // vector - scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApSubtract<D> > 
  operator-(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApSubtract<D> >(a,b);
  }

  // scalar - vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApSubtract<D> > 
  operator-(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApSubtract<D> > (a,b);
  }

  // vector * scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApMultiply<D> > 
  operator*(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApMultiply<D> >(a,b);
  }

  // scalar * vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApMultiply<D> > 
  operator*(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApMultiply<D> > (a,b);
  }

  // vector / scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApDivide<D> > 
  operator/(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApDivide<D> >(a,b);
  }

  // scalar / vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApDivide<D> > 
  operator/(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApDivide<D> > (a,b);
  }


  // the following are defined for convenience

  // vector + (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApAdd<D> > 
  operator+(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApAdd<D> >(a,b);
  }

  // (int scalar) + vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApAdd<D> > 
  operator+(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApAdd<D> > (a,b);
  }


  // vector - (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApSubtract<D> > 
  operator-(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApSubtract<D> >(a,b);
  }

  // (int scalar) - vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApSubtract<D> > 
  operator-(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApSubtract<D> > (a,b);
  }

  // vector * (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApMultiply<D> > 
  operator*(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApMultiply<D> >(a,b);
  }

  // (int scalar) * vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApMultiply<D> > 
  operator*(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApMultiply<D> > (a,b);
  }

  // vector / (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApDivide<D> > 
  operator/(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApDivide<D> >(a,b);
  }

  // (int scalar) / vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApDivide<D> > 
  operator/(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApDivide<D> > (a,b);
  }





  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an LAvector or a Vexpr
   *****************************************************************
   */

  // +(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApPlus<D> > 
  operator+(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApPlus<D> >(a);
  }


  // -(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApMinus<D> > 
  operator-(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApMinus<D> >(a);
  }


  // vcast(vector)

  template <class D2, class D1, class A> 
  inline VFuncOp<D2,VorE<D1,A>,ApCast<D1,D2> > 
  vcast(const VorE<D1,A>& a)
  {
    return  VFuncOp<D2,VorE<D1,A>,ApCast<D1,D2> >(a);
  }


  // vcast(matrix)

  template <class D2, class D1, class A> 
  inline LAvector<D2> 
  vcast(const MorE<D1,A>& a)
  {
    const unsigned int N = a.size();
#ifdef COOLL_CAREFUL
    std::string name=a.debugtxt();
    name = "vcast("+name+")";
    if ( mexpr_is_size_bad(a.size()) ){ 
      mbad_expr_in_unary(a,"vcast");
      LAvector<D2> y(0,name);
      return y;
    }
    LAvector<D2> y(N,name);
#else
    LAvector<D2> y(N);
#endif

    for(unsigned int i = 0; i<N; i++) 
      y[i] = static_cast<D2>(a(i));
    return y;
  }



  // vcast(C-array)

  template <class D2, class D1> 
  inline LAvector<D2>
  vcast(const D1* dptr, const unsigned int N)
  {
    LAvector<D2> y(N,"vcast(C-array)");
    for(unsigned int i = 0; i<N; i++) 
      y[i] = static_cast<D2>(dptr[i]);
    return  y;
  }

  

  // vcast(std::vector)

  template <class D2, class D1> 
  inline LAvector<D2>
  vcast(const std::vector<D1>& v2) {
    const unsigned int N = v2.size();
    LAvector<D2> y(N,"vcast(std::vector)");
    for(unsigned int i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v2[i]);
    return  y;
  }


  // vcast(std::valarray)

  template <class D2, class D1> 
  inline LAvector<D2>
  vcast(const std::valarray<D1>& v2) {
    const unsigned int N = v2.size();
    LAvector<D2> y(N,"vcast(std::valarray)");
    for(unsigned int i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v2[i]);
    return  y;
  }



  /****************************************************************
   * functions that convert vectors into other objects
   *****************************************************************
   */


  // toCarray(v)

  template <class D2, class D1, class A> 
  inline D2*
  toCarray(const VorE<D1,A>& v) {
    const unsigned int N = v.size();
    D2* dptr = new D2[N];
    for(unsigned int i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(v[i]);
    return  dptr;
  }

  

  // tostdvector(v)

  template <class D2, class D1, class A> 
  inline std::vector<D2>
  tostdvector(const VorE<D1,A>& v) {
    const unsigned int N = v.size();
    std::vector<D2> y(N);
    for(unsigned int i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  // tovalarray(v)

  template <class D2, class D1, class A> 
  inline std::valarray<D2>
  tovalarray(const VorE<D1,A>& v) {
    const unsigned int N = v.size();
    std::valarray<D2> y(N);
    for(unsigned int i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }


  /****************************************************************************
   * Binary Functions/Operators that return scalars
   ****************************************************************************
   */


  // dotproduct operator (a|b)

  template <class D, class A, class B> 
  inline D operator|( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    D result = D();
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b) || ( a.size() != b.size() ) ){ 
      vbad_expr_in_binary(a,b,"","|");
      return 0;
    }
#endif
 
    for (register unsigned int i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }












  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
  inline D sum( const VorE<D,A>& a ) {
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"sum");
      return 0;
    }
#endif
 
    const unsigned int N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register unsigned int i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }







  // norm(a)

  template <class D, class A> 
  inline D norm( const VorE<D,A>& a ) {
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"norm");
      return 0;
    }
#endif
 
    const unsigned int N = a.size();
    if (N==0)
      return 0;

    D result = a[0]*a[0];

    for (register unsigned int i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <class D, class A> 
  inline D min( const VorE<D,A>& a ) {
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"min");
      return 0;
    }
#endif
 
    const unsigned int N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register unsigned int i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <class D, class A> 
  inline D max( const VorE<D,A>& a ) {
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"max");
      return 0;
    }
#endif
    const unsigned int N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register unsigned int i = 1; i < N ; i++ )
      result = std::max(result,a[i]);
    
    return result;
  }







  /****************************************************************************
   * Unary Functions/Operators that perform "in place", modifying the argument
   ****************************************************************************
   */

  // sort(a)

  template <class D> void sort(LAvector<D>& a ) {

    const unsigned int N = a.size();
    if (N==0)
      return;

    // have to copy data into a vector, since valarray doesn't 
    // support sorting
    std::vector<D> data(N);
    
    for (register unsigned int i = 0; i < N ; i++ )
      data[i] = a[i];

    sort(data.begin(),data.end());
    
    for (register unsigned int i = 0; i < N ; i++ )
      a[i] = data[i];

  }



  // sort and return the sorted indices: sortwind(a)

  template <class DAT> class idpair {
  public:
    unsigned int ind;
    DAT dat;
    
    bool operator<(const idpair<DAT>& x2) const {
      return (this->dat < x2.dat);
    }
  };

  template <class D> LAvector<unsigned int> sortwind(LAvector<D>& a ) {

    const unsigned int N = a.size();
#ifdef COOLL_CAREFUL
    std::string name = "sortindices(" + a.debugtxt() +")";
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"sortwind");
      LAvector<unsigned int> ivec(0,name);
      return ivec;
    }
    LAvector<unsigned int> ivec(N,name);
#else
    LAvector<unsigned int> ivec(N);
#endif

    if (N==0)
      return ivec;
    
    std::vector<idpair<D> > data(N);
    

    for (register unsigned int i = 0; i < N ; i++ ) {
      data[i].ind = i;
      data[i].dat = a[i];
    }
    
    
    sort(data.begin(),data.end());
    
    
    for (register unsigned int i = 0; i < N ; i++ ) {
      ivec[i] = data[i].ind;
      a[i] = data[i].dat;
    }
    
    return ivec;
    
  }



};

#endif //VOPERATORS_H