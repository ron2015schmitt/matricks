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




#ifndef VEXPR_H
#define VEXPR_H


#include <string>
#include <sstream>



namespace COOLL {










  /****************************************************************************
   * Vexpr -- Vector Expression template abstract class
   ****************************************************************************
   */
  template<class D, class EXP> 
  class Vexpr : public VorE<D,Vexpr<D,EXP> > {
  private:
    typedef  D DataT;
    inline EXP& derived() {
      return static_cast<EXP&>(*this);
    }
    inline const  EXP& derived() const {
      return static_cast<const EXP&>(*this);
    }

  public:

    inline const D operator[](const unsigned int i) const {
      return derived()[i];
    }

    inline unsigned int size(void) const {
      return derived().size();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }




    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      derived().outputglossary();
    }

    bool mustcopy(const void* vaddr) const {
      return derived().mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return derived().addrmatch(vaddr);
    }



  };






  /****************************************************************************
   * VWrapperObj Expression Template 
   *
   * abstract class 
   ****************************************************************************
   */
  template <class D, class DERIVED>
  class VWrapperObj : public  Vexpr<D,VWrapperObj<D,DERIVED> > {
  private:
    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

  public:

    inline const D operator[](const unsigned int i) const {  
      const unsigned int index = derived().index(i);
#ifdef COOLL_CAREFUL
      if (index>=derived().asize()) {
	vwrapper_out_of_bounds(debugtxt(),i,size());
	return derived().data(0);
      }
#endif
      return derived().data(index);
    }

    inline D& operator[](const unsigned int i) {  
      const unsigned int index = derived().index(i);
#ifdef COOLL_CAREFUL
      if (index>=derived().asize()) {
	vwrapper_out_of_bounds(debugtxt(),i,size());
	return derived().data(0);
      }
#endif
      return derived().data(index);
    }

    inline const unsigned int index(void) const {
      return derived().index();
    }

    inline unsigned int size(void) const {
      return derived().size();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }


    // Assign to constant value
    DERIVED& equals(const D d) { 
      for(unsigned int i=0; i<size(); i++) 
	(*this)[i]=d; 
      return derived();
    }
    // assign to recon object (issue error)
    DERIVED& equals(const VReconObj<D>& b) { 
#ifdef COOLL_CAREFUL
      vbad_reconassignment(a_.objectID(), b);
#endif
      return derived();
    }
    


    // assign to vector or expression
    template <class B>
    DERIVED& equals(const VorE<D,B>& rhs) { 

      const unsigned int N =size();

#ifdef COOLL_CAREFUL
      if ( size() !=  rhs.size() ){ 
	vbad_wrapper_assignment(debugtxt(),rhs.debugtxt());
	outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif

      if ( rhs.addrmatch(derived().addr()) ) {    
#ifdef COOLL_CAREFUL
	LAvector<D> y(N,debugtxt());
#else
	LAvector<D> y(N);
#endif
	for(register unsigned int i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register unsigned int i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(register unsigned int i=0; i<N; i++) 
	  derived()[i] = rhs[i]; 
      }
      return derived();
    }




    // assignment to matrix or submatrix (must be 1xN or Nx1)
    template <class B>
    DERIVED& equals(const MorE<D,B>& rhs) {

      const unsigned int N =size();
#ifdef COOLL_CAREFUL
      const unsigned int NR = rhs.Nrows();
      const unsigned int NC = rhs.Ncols();
      if ( ( N !=  rhs.size() ) 
	   || ( (NR!=1) && (NC!=1) ) ){ 
	vbad_wrapper_assignment_mat(derived().debugtxt(),rhs.debugtxt());
	derived().outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif


      if ( rhs.addrmatch(derived().addr()) ) {    
#ifdef COOLL_CAREFUL
	LAvector<D> y(N,debugtxt());
#else
	LAvector<D> y(N);
#endif
	y=rhs;
	for(register unsigned int i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(register unsigned int i=0; i<N; i++) 
	  derived()[i] = rhs(i); 
      }
      return derived();
    }


    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      return derived().outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return derived().mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return derived().addrmatch(vaddr);
    }

    const void *addr(void) const {
      return derived().addr();
    }
    
  };




  /****************************************************************************
   * VRangeObj Expression Template 
   *
   * wrapper for vector ranges  
   ****************************************************************************
   */
 
  template <class D>
  class VRangeObj : public  VWrapperObj<D,VRangeObj<D> > {
  private:
    LAvector<D>& a_;
    const unsigned int start_;
    const unsigned int end_;
    const unsigned int step_;
    const bool increasing_;

  public:
    VRangeObj(LAvector<D>& a, const unsigned int start, const unsigned int end, const int step)
      :   a_(a),  start_(start), end_(end), 
	  step_((step>=0)?step:-step), 
	  increasing_((end>=start)?true:false)
    { 
    }

    inline const D data(unsigned int i) const{
      return a_[i];
    }
    inline D& data(unsigned int i) {
      return a_[i];
    }


    // could improve speed for step=1 and step=-1 by creating a separate
    // function or template class that doesn't include the step multiply
    inline const unsigned int index(unsigned int i) const{
     if (increasing_) 
       return start_ + i * step_;
     else 
       return start_ - i * step_;      
    }


    inline unsigned int size(void) const {
     if (increasing_) 
       return (end_-start_)/step_ + 1;
     else 
       return (start_-end_)/step_ + 1;      
    }

    inline unsigned int asize(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VRangeObj;
    }

    template <class B>
    VRangeObj<D>& operator=(const B& b) { 
      return equals(b);
    }

    VRangeObj<D>& operator=(const VRangeObj<D>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_VRangeObj(a_.debugtxt(),start_,end_,step_);
    }

    void outputglossary(void) const {
      outputglossary_VRangeObj(a_.objectID(),debugtxt(),size());
    }

    bool mustcopy(const void *vaddr) const {
       return addrmatch(vaddr);
    }


    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(&a_);
    }

    const void *addr(void) const {
      return &a_;
    }


  };





  /****************************************************************************
   * VSetObj Expression Template 
   *
   * wrapper for a vector subset
   ****************************************************************************
   */
  template<class D>
  class VSetObj :  public  VWrapperObj<D,VSetObj<D> > {
  private:
    LAvector<D>& a_;
    const LAvector<unsigned int>& ii_;

  public:
    VSetObj(LAvector<D>& a, const LAvector<unsigned int>& ii)
      : a_(a), ii_(ii)
    { 
    }

    inline const D data(unsigned int i) const{
      return a_[i];
    }
    inline  D& data(unsigned int i) {
      return a_[i];
    }

    inline const unsigned int index(unsigned int i) const{
      return ii_[i];
    }


    inline VETypes vetype(void) const {
      return VE_VSetObj;
    }

    inline unsigned int size(void) const {
      return ii_.size();
    }

    inline unsigned int asize(void) const {
      return a_.size();
    }

    template <class B>
    VSetObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    VSetObj<D>& operator=(const VSetObj<D>& b) { 
      return equals(b);
    }


    std::string debugtxt(void) const {
      return debugtxt_VSetObj(a_.debugtxt(),ii_.debugtxt());
    }

    void outputglossary(void) const {
      outputglossary_VSetObj(a_.objectID(),ii_.objectID(),debugtxt(),size());
    }

    bool mustcopy(const void *vaddr) const {
      return addrmatch(vaddr);
    }


    bool addrmatch(const void *vaddr) const {
      return (vaddr==static_cast<const void*>(&a_)) ||(vaddr==static_cast<const void*>(&ii_)) ;
    }


    const void *addr(void) const {
      return &a_;
    }


  };




  /****************************************************************************
   * VMaskObj Expression Template 
   *
   * wrapper for a vector submask
   ****************************************************************************
   */
  template<class D>
  class VMaskObj :  public  VWrapperObj<D,VMaskObj<D> > {
  private:
    LAvector<D>& a_;
    const LAvector<unsigned int>* ii_;

  public:
#ifdef COOLL_CAREFUL
    VMaskObj(LAvector<D>& a, const LAvector<bool>& mask)
      : a_(a), ii_(new LAvector<unsigned int>(findtrue(mask)))
    { 
      //      settext_VMaskObj(*ii_,mask);
    }
#else
    VMaskObj(LAvector<D>& a, const LAvector<bool>& mask)
      : a_(a), ii_(new LAvector<unsigned int>(findtrue(mask)))
    { 
    }
#endif

    ~VMaskObj()
    { 
      delete  ii_;
    }

    inline const D data(unsigned int i) const{
      return a_[i];
    }
    inline  D& data(unsigned int i) {
      return a_[i];
    }

    inline const unsigned int index(unsigned int i) const{
      return (*ii_)[i];
    }

    inline VETypes vetype(void) const {
      return VE_VMaskObj;
    }

    inline unsigned int size(void) const {
      return ii_->size();
    }

    inline unsigned int asize(void) const {
      return a_.size();
    }

    template <class B>
    VMaskObj<D>& operator=(const B& b) { 
      return equals(b);
    }

    VMaskObj<D>& operator=(const VMaskObj<D>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_VMaskObj(a_.debugtxt(),ii_->debugtxt());
    }

    void outputglossary(void) const {
      outputglossary_VMaskObj(a_.objectID(),ii_->objectID(),debugtxt(),size());
    }

    bool mustcopy(const void *vaddr) const {
       return addrmatch(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(&a_);
    }


    const void *addr(void) const {
      return &a_;
    }

  };






  /****************************************************************************
   * VReconObj Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
  class VReconObj :  public  Vexpr<D,VReconObj<D> > {
  private:
    LAvector<D>& a_;

  public:
    VReconObj(LAvector<D>& a)
      : a_(a)
    { 
    }

    inline VETypes vetype(void) const {
      return VE_VReconObj;
    }

    template <class A>
    LAvector<D>& operator=(const VorE<D,A>& x) { 
      unsigned int N = x.size();
      
#ifdef COOLL_CAREFUL
      if ( N==badsize ){ 
	vbad_expr_in_reconassignment(a_.objectID(), x);
	return a_;
      }
#endif
      
      if ( x.addrmatch(&a_)) {    
#ifdef COOLL_CAREFUL
	LAvector<D> y(N,debugtxt());
#else
	LAvector<D> y(N);
#endif
	y = x.derived();
	a_.resize(N);
	a_ = y;
	return a_;
      } else {
	a_.resize(N);
	a_ = x.derived();
	return a_;
      }
    }

    LAvector<D>& operator=(const VReconObj<D>& b) { 

#ifdef COOLL_CAREFUL
      vbad_reconassignment(a_.objectID(), b);
#endif
      return a_;
    }

    std::string debugtxt(void) const {
      return  a_.debugtxt() +".resize()";
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
       return addrmatch(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(&a_);
    }



  };






  /****************************************************************************
   * VBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class VBinOp : public  Vexpr<D,VBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;

  public:
    VBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
    }

    inline const D operator[](const unsigned int i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline unsigned int size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }

    inline VETypes vetype(void) const {
      return VE_VBinOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_LAvector) 
	sa = "(" + sa + ")";
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_LAvector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
      b_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return (a_.mustcopy(vaddr)) || (b_.mustcopy(vaddr));
    }


    bool addrmatch(const void *vaddr) const {
      return (a_.addrmatch(vaddr)) || (b_.addrmatch(vaddr));
    }


  };







  /****************************************************************************
   * VecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class VecOpScal : public Vexpr<D,VecOpScal<D,A,OP> > {

  private:
    const A& a_;
    D val_;

  public:
    VecOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline const D operator[](const unsigned int i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline unsigned int size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VecOpScal;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_LAvector) 
	sa = "(" + sa + ")";
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return a_.addrmatch(vaddr);
    }



  };





  /****************************************************************************
   * ScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class ScalOpVec : public Vexpr<D,ScalOpVec<D,B,OP> > {

  private:
    D val_;
    const B& b_;

  public:
    ScalOpVec(const D a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const D operator[](const unsigned int i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline unsigned int size(void) const {
      return b_.size();
    }

    inline VETypes vetype(void) const {
      return VE_ScalOpVec;
    }

    std::string debugtxt(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_LAvector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      b_.outputglossary();
    }
    bool mustcopy(const void *vaddr) const {
      return b_.mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return b_.addrmatch(vaddr);
    }


  };




  /****************************************************************************
   * VFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class VFuncOp  : public  Vexpr<D,VFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
  
  public:
    VFuncOp(const A& a) : a_(a) { }


    inline const D operator[](const unsigned int i) const
    { return FUNC::apply(a_[i]); }

    inline unsigned int size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VFuncOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }
    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return a_.addrmatch(vaddr);
    }


  };











};

#endif