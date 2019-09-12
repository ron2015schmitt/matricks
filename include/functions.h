#ifndef FUNCTIONS_H
#define FUNCTIONS_H 1


namespace matricks {



  /************************************************************
   *          Functions that apply to all tensors
   ************************************************************
   */


  /************************************************************
   *               Binary Functions 
   *
   * D = data type, e.g. double
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



  // pow(vector,vector)

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApPow<D> > 
    pow(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApPow<D> >(a,b);
    }


  
  // atan2(vector,vector)

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApAtan2<D> > 
    atan2(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApAtan2<D> >(a,b);
    }



  template <class D, typename TypeHelper<D>::binary_func F, class A, class B> 
    inline VBinOp<D, VorE<D,A>, VorE<D,B>, ApFun2<D,F> > 
    op2(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D, VorE<D,A>, VorE<D,B>, ApFun2<D,F> >(a,b);
    }


  

  // complexvector + realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApAddCR<D> > 
    operator+(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApAddCR<D> >(a,b);
    }
  // realvector + complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApAddRC<D> > 
    operator+(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApAddRC<D> >(a,b);
    }


  // complexvector - realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApSubtractCR<D> > 
    operator-(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApSubtractCR<D> >(a,b);
    }
  // realvector - complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApSubtractRC<D> > 
    operator-(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApSubtractRC<D> >(a,b);
    }



  // complexvector * realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApMultiplyCR<D> > 
    operator*(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApMultiplyCR<D> >(a,b);
    }
  // realvector * complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApMultiplyRC<D> > 
    operator*(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApMultiplyRC<D> >(a,b);
    }



  // complexvector / realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApDivideCR<D> > 
    operator/(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApDivideCR<D> >(a,b);
    }
  // realvector / complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApDivideRC<D> > 
    operator/(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApDivideRC<D> >(a,b);
    }




  // *** functions that return a complex vector from 2 real vectors ***

  // vpolar(r,phi)

  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApPolar<D> > 
    vpolar(const VorE<D,A>& r, const VorE<D,B>& phi)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApPolar<D> >(r,phi);
    }


  // vcomplex(x,y)

  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApComplex<D> > 
    vcomplex(const VorE<D,A>& x, const VorE<D,B>& y)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApComplex<D> >(x,y);
    }



  // pow(complexvector,realscalar)

  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> > 
    pow(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> >(a,b);
    }

  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>, ApRoundZeros<std::complex<D> > > 
    roundzero(const VorE<std::complex<D>,A>& a, const D tol = MatricksHelper<D>::tolerance)
    {
      return  CVecOpScal<D,VorE<std::complex<D>,A>, ApRoundZeros<std::complex<D> > >(a,tol);
    }


  // pow(complexvector,intscalar)

  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> > 
    pow(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> >(a,static_cast<D>(b));
    }

  // pow(realscalar,complexvector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> > 
    pow(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> >(a,b);
    }

  // pow(intscalar,complexvector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> > 
    pow(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> >(static_cast<D>(a),b);
    }


 
  
  // vcomplex(vector,realscalar)

  
  template <class D, class A, class B> 
    inline VecOpScal<std::complex<D>, VorE<D,A>, ApComplex<D> > 
    vcomplex(const VorE<D,A>& a, const D b)
    {
      return  CVecOpScal<D,VorE<D,A>,ApComplex<D > >(a,b);
    }
  // vcomplex(vector,intscalar)

  template <class D, class A> 
    inline CVecOpScal<D,VorE<D,A>,ApComplex<D > > 
    vcomplex(const VorE<D,A>& a, const int b)
    {
      return  CVecOpScal<D,VorE<D,A>,ApComplex<D > >(a,static_cast<D>(b));
    }

  // vcomplex(realscalar,vector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<D,B>,ApComplex<D > > 
    vcomplex(const D a, const VorE<D,B>& b)
    {
      return  CScalOpVec<D,VorE<D,B>,ApComplex<D > >(a,b);
    }
  // vcomplex(intscalar,vector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<D,B>,ApComplex<D > > 
    vcomplex(const int a, const VorE<D,B>& b)
    {
      return  CScalOpVec<D,VorE<D,B>,ApComplex<D > >(static_cast<D>(a),b);
    }


  




  // a==b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApEqual<D> >  
    operator==( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApEqual<D> >(a,b);
  }


  // a!=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApNotEqual<D> >  
    operator!=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApNotEqual<D> >(a,b);
  }



  // a<=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLessEqual<D> >  
    operator<=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLessEqual<D> >(a,b);
  }


  // a>=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreaterEqual<D> >  
    operator>=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreaterEqual<D> >(a,b);
  }


  // a<b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLess<D> >  
    operator<( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLess<D> >(a,b);
  }


  // a>b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreat<D> >  
    operator>( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreat<D> >(a,b);
  }




  /************************************************************
   *               vector/scalar Operators
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an Vector or a Vexpr
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




  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,ApRoundZeros<D> > 
    roundzero(const VorE<D,A>& a, const D tolerance = MatricksHelper<D>::tolerance)
    {
      return  VecOpScal<D,VorE<D,A>,ApRoundZeros<D> >(a, tolerance);
    }



  // pow(vector,scalar)

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,ApPow<D> > 
    pow(const VorE<D,A>& a, const D b)
    {
      return  VecOpScal<D,VorE<D,A>,ApPow<D> >(a,b);
    }

  // pow(scalar,vector)

  template <class D, class B> 
    inline ScalOpVec<D,VorE<D,B>,ApPow<D> > 
    pow( const D a, const VorE<D,B>& b)
    {
      return  ScalOpVec<D,VorE<D,B>,ApPow<D> >(a,b);
    }



  // realvector + complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,ApAddRC<D> > 
    operator+(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,ApAddRC<D> >( a,b );
    }

  // complexscalar +  realvector 
  template <class D, class B> 
    inline ScalOpVec< std::complex<D>,VorE<D,B>,ApAddCR<D> > 
    operator+(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,ApAddCR<D> >( a, b );
    }
  // complexvector + realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> > 
    operator+(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> >(a,b);  
    }
  // complexvector + intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> > 
    operator+(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar + complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D> > 
    operator+(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D> >(a,b);  
    }
  // intscalar + complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D> > 
    operator+(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D > >(static_cast<D>(a),b);  
    }



  // realvector - complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,ApSubtractRC<D> > 
    operator-(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,ApSubtractRC<D> >( a,b );
    }

  // complexscalar -  realvector 
  template <class D, class B> 
    inline ScalOpVec< std::complex<D>,VorE<D,B>,ApSubtractCR<D> > 
    operator-(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,ApSubtractCR<D> >( a, b );
    }
  // complexvector - realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> > 
    operator-(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> >(a,b);  
    }
  // complexvector - intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> > 
    operator-(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar - complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D> > 
    operator-(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D> >(a,b);  
    }
  // intscalar - complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D> > 
    operator-(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D > >(static_cast<D>(a),b);  
    }


  // realvector * complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,ApMultiplyRC<D> > 
    operator*(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,ApMultiplyRC<D> >( a,b );
    }

  // complexscalar *  realvector 
  template <class D, class B> 
    inline ScalOpVec<std::complex<D>,VorE<D,B>,ApMultiplyCR<D> > 
    operator*(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,ApMultiplyCR<D> >( a, b );
    }
  // complexvector * realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> > 
    operator*(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> >(a,b);  
    }
  // complexvector * intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> > 
    operator*(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar * complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D> > 
    operator*(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D> >(a,b);  
    }
  // intscalar * complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D> > 
    operator*(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D > >(static_cast<D>(a),b);  
    }


  // division

  // realvector / complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,ApDivideRC<D> > 
    operator/(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,ApDivideRC<D> >( a,b );
    }

  // complexscalar /  realvector 
  template <class D, class B> 
    inline ScalOpVec< std::complex<D>,VorE<D,B>,ApDivideCR<D> > 
    operator/(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,ApDivideCR<D> >( a, b );
    }
  // complexvector / realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> > 
    operator/(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> >(a,b);  
    }
  // complexvector / intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> > 
    operator/(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar / complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D> > 
    operator/(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D> >(a,b);  
    }
  // intscalar / complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D> > 
    operator/(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D > >(static_cast<D>(a),b);  
    }



  
  // vector && scalar

  template <class A> 
    inline VecOpScal<bool,VorE<bool,A>,ApAnd > 
    operator&&(const VorE<bool,A>& a, const bool b)
    {
      return  VecOpScal<bool,VorE<bool,A>,ApAnd >(a,b);
    }

  // scalar && vector

  template <class B> 
    inline ScalOpVec<bool,VorE<bool,B>,ApAnd > 
    operator&&(const bool a, const VorE<bool,B>& b)
    {
      return  ScalOpVec<bool,VorE<bool,B>,ApAnd >(a,b);
    }

  
  // vector || scalar

  template <class A> 
    inline VecOpScal<bool,VorE<bool,A>,ApOr > 
    operator||(const VorE<bool,A>& a, const bool b)
    {
      return  VecOpScal<bool,VorE<bool,A>,ApOr >(a,b);
    }

  // scalar || vector

  template <class B> 
    inline ScalOpVec<bool,VorE<bool,B>,ApOr > 
    operator||(const bool a, const VorE<bool,B>& b)
    {
      return  ScalOpVec<bool,VorE<bool,B>,ApOr >(a,b);
    }



  // vector == scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApEqual<D> > 
    operator==(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApEqual<D> >(a,b);
    }

  // scalar == vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApEqual<D> > 
    operator==(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApEqual<D> >(a,b);
    }

  // vector != scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> > 
    operator!=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> >(a,b);
    }

  // scalar != vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> > 
    operator!=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> >(a,b);
    }
  // vector <= scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> > 
    operator<=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> >(a,b);
    }

  // scalar <= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> > 
    operator<=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> >(a,b);
    }
  // vector >= scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> > 
    operator>=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> >(a,b);
    }

  // scalar >= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> > 
    operator>=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> >(a,b);
    }
  // vector < scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLess<D> > 
    operator<(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLess<D> >(a,b);
    }

  // scalar < vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLess<D> > 
    operator<(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLess<D> >(a,b);
    }
  // vector > scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreat<D> > 
    operator>(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreat<D> >(a,b);
    }

  // scalar > vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreat<D> > 
    operator>(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreat<D> >(a,b);
    }



  // the following are defined for convenience

  // vector == int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApEqual<D> > 
    operator==(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar == vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApEqual<D> > 
    operator==(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApEqual<D> >(static_cast<D>(a),b);
    }

  // vector != int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> > 
    operator!=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar != vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> > 
    operator!=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> >(static_cast<D>(a),b);
    }
  // vector <= int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> > 
    operator<=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar <= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> > 
    operator<=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> >(static_cast<D>(a),b);
    }
  // vector >= int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> > 
    operator>=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar >= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> > 
    operator>=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> >(static_cast<D>(a),b);
    }
  // vector < int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLess<D> > 
    operator<(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLess<D> >(a,static_cast<D>(b));
    }

  // int scalar < vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLess<D> > 
    operator<(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLess<D> >(static_cast<D>(a),b);
    }
  // vector > int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreat<D> > 
    operator>(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreat<D> >(a,static_cast<D>(b));
    }

  // int scalar > vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreat<D> > 
    operator>(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreat<D> >(static_cast<D>(a),b);
    }

  // vector && vector

  template <class A, class B> 
    inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApAnd > 
    operator&&(const VorE<bool,A>& a, const VorE<bool,B>& b)
    {
      return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApAnd >(a,b);
    }

  // vector || vector

  template <class A, class B> 
    inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApOr > 
    operator||(const VorE<bool,A>& a, const VorE<bool,B>& b)
    {
      return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApOr >(a,b);
    }


  /****************************************************************
   *              Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Vector or a Vexpr
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



  // !(vector)

  template <class A> 
    inline VFuncOp<bool,VorE<bool,A>,ApNot > 
    operator!(const VorE<bool,A>& a)
    {
      return  VFuncOp<bool,VorE<bool,A>,ApNot >(a);
    }
  
  


  
  // dcast from D1 to D2

  template <class D2, class D1, class A> 
    inline VFuncOp<D2,VorE<D1,A>,ApCast<D1,D2> > 
    dcast(const VorE<D1,A>& a)
    {
      return  VFuncOp<D2,VorE<D1,A>,ApCast<D1,D2> >(a);
    }



  

  // user-defined functions
  template <class D, typename TypeHelper<D>::unary_func F, class A> 
    inline VFuncOp<D, VorE<D,A>, ApFun1<D,F> > 
    op1(const VorE<D,A>& a)
    {
      return  VFuncOp<D, VorE<D,A>, ApFun1<D,F> >(a);
    }


  // sin(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSin<D> > 
    sin(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSin<D> >(a);
    }


  // cos(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCos<D> > 
    cos(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCos<D> >(a);
    }



  // tan(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApTan<D> > 
    tan(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApTan<D> >(a);
    }


  // sqrt(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSqrt<D> > 
    sqrt(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSqrt<D> >(a);
    }

  // sqr(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSqr<D> > 
    sqr(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSqr<D> >(a);
    }

  // cube(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCube<D> > 
    cube(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCube<D> >(a);
    }


  // exp(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApExp<D> > 
    exp(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApExp<D> >(a);
    }


  // abs(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAbs<D> > 
    abs(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAbs<D> >(a);
    }


  // sgn(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSign<D> > 
    sgn(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSign<D> >(a);
    }


  // log(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApLog<D> > 
    log(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApLog<D> >(a);
    }


  // log10(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApLog10<D> > 
    log10(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApLog10<D> >(a);
    }


  // log2(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApLog2<D> > 
    log2(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApLog2<D> >(a);
    }



  // asin(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAsin<D> > 
    asin(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAsin<D> >(a);
    }


  // acos(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAcos<D> > 
    acos(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAcos<D> >(a);
    }


  // atan(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAtan<D> > 
    atan(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAtan<D> >(a);
    }





  // ceil(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCeil<D> > 
    ceil(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCeil<D> >(a);
    }


  // floor(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApFloor<D> > 
    floor(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApFloor<D> >(a);
    }


  // round(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApRound<D> > 
    round(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApRound<D> >(a);
    }


  // sinh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSinh<D> > 
    sinh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSinh<D> >(a);
    }


  // cosh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCosh<D> > 
    cosh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCosh<D> >(a);
    }


  // tanh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApTanh<D> > 
    tanh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApTanh<D> >(a);
    }


  // conj(complex vector)

  template <class D, class A> 
    inline VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> > 
    conj(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> >(a);
    }


  template <class D, class A> 
    inline VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> > 
    operator~(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> >(a);
    }


  
  // *** functions that return a real vector from a complex vector ***

  // abs(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,ApCAbs<D> > 
    abs(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,ApCAbs<D> >(a);
    }


  // arg(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,ApArg<D> > 
    arg(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,ApArg<D> >(a);
    }


  

  // real(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,ApReal<D> > 
    real(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,ApReal<D> >(a);
    }

  // imag(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,ApImag<D> > 
    imag(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,ApImag<D> >(a);
    }


  
  // round(complex vector)

  template <class D, class A> 
    inline VFuncOp<std::complex<D>, VorE<std::complex<D>, A> , ApRoundCplx<D> > 
    round(const VorE<std::complex<D>,A>& a)  {
    return VFuncOp<std::complex<D>, VorE<std::complex<D>, A>, ApRoundCplx<D> >(a);
  }



  


  /****************************************************************************
   * Binary Functions/Operators that return scalars
   ****************************************************************************
   */






  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
    D sum( const VorE<D,A>& a ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"sum");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }



  
  // prod(a)

  template <class D, class A> 
    D prod( const VorE<D,A>& a ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"prod");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result *= a[i];
    
    return result;
  }





  // norm(a)

  template <class D, class A> 
    D norm( const VorE<D,A>& a ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"norm");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0]*a[0];

    for (register index_type i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <class D, class A> 
    D min( const VorE<D,A>& a ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"min");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <class D, class A> 
    D max( const VorE<D,A>& a ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"max");
      return 0;
    }
#endif
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result = std::max(result,a[i]);
    
    return result;
  }



  // norm(a)

  template <class D, class A> 
    inline D norm( const VorE<std::complex<D>,A>& a ) {
    D result = D();
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"norm");
      return 0;
    }
#endif
 
    for (register index_type i = a.size(); i--;) {
      D tempR = a[i].real(); 
      D tempI = a[i].imag(); 
      result += tempR*tempR + tempI*tempI;
    }
    return std::sqrt(result);
  }





  /****************************************************************************
   * Unary Functions/Operators that bools or index_type vectors
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class A> 
    inline bool alltrue( const VorE<bool,A>& a ) {
    bool result = true;
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"alltrue");
      return false;
    }
#endif
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result && a[i];
    
    return result;
  }


  // anytrue(a)

  template <class A> 
    inline bool anytrue( const VorE<bool,A>& a ) {
    bool result = false;
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"anytrue");
      return false;
    }
#endif
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result || a[i];
    
    return result;
  }


  // numtrue(a)

  template <class A> 
    inline size_type numtrue( const VorE<bool,A>& a ) {
    size_type result = 0;
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"numtrue");
      return 0;
    }
#endif
 
    for (register index_type i = 0; i< a.size(); i++)
      result += static_cast<index_type>(a[i]);
    
    return result;
  }


  


  // findtrue(a)

  template <class A> 
    inline Vector<index_type> findtrue( const VorE<bool,A>& a ) {
    int N = 0;
    
#if MATRICKS_DEBUG>0
    std::string s = "findtrue(" + a.debugtxt() + ")";
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"findtrue");
      //      Vector<index_type> y(0,s);
      Vector<index_type> y(0);
      return y;
    }
#endif

    for (register index_type i = 0; i< a.size(); i++)
      N += int(a[i]);
 
#if MATRICKS_DEBUG>0
    //   Vector<index_type> y(N,s);
    Vector<index_type> y(N);
#else
    Vector<index_type> y(N);
#endif

    index_type j =0;
    for (register index_type i = 0; i< a.size(); i++)
      if (a[i])
	y[j++] = i;
    
    return y;
  }







};

#endif 