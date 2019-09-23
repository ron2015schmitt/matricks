#ifndef VEXPRESSIONS_H
#define VEXPRESSIONS_H



namespace matricks {

  template <class A>
    inline Vector<index_type> findtrue( const TensorR<bool,A>& a );


  /****************************************************************************
   * VSubsetObj Expression Template 
   *
   * wrapper for a vector subset
   ****************************************************************************
   */
  template<class D>
    class VSubsetObj :  public  TExpressionRW<D,VSubsetObj<D> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>& ii_;
    const bool delete_ii_;
    VectorofPtrs *vptrs;
  public:

  VSubsetObj(Vector<D>& a, const Vector<index_type>& ii)
    : a_(a), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }
#if CPP11 == 1    
  VSubsetObj(Vector<D>& a, const std::initializer_list<index_type>& list)
    : a_(a), ii_(*(new Vector<index_type>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }
#endif // C++11
    
    ~VSubsetObj() {
      if (delete_ii_) delete &ii_;
      delete vptrs;
    }


    inline const D operator[](const index_type i) const{
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }
    inline  D& operator[](const index_type i) {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }


    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return ii_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VSubsetObj";
    }


    VSubsetObj<D>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class B>
      VSubsetObj<D>& operator=(const TensorR<D,B>& rhs) { 
      return this->equals(rhs);
    }

    VSubsetObj<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
    VSubsetObj<D>& operator=(const VSubsetObj<D>& b) { 
      return this->equals(b);
    }

    
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_VSubsetObj(a_.expression(),ii_.expression());
    }
#endif



  };







  /****************************************************************************
   * VJoinExpr Expression Template 
   *
   * expression for joining two TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VJoinExpr : public  TExpressionR<D,VJoinExpr<D,A,B> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  VJoinExpr(const A& a, const B& b)
    : a_(a), b_(b) { 

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      
    }

    ~VJoinExpr() {
      delete vptrs;
    }
    
    inline const D operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size() +b_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VJoinExpr";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VJoinExpr(a_.expression(),ii_.expression());
    }
#endif 

    
  };


  /****************************************************************************
   * VJoinObj Expression Template 
   *
   * expression for joining two TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VJoinObj : public  TExpressionRW<D,VJoinObj<D,A,B> > {

  private:
    A& a_;
    B& b_;
    VectorofPtrs *vptrs;

  public:


  VJoinObj(A& a, B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~VJoinObj() {
      delete vptrs;
    }


    inline const D operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
    inline  D& operator[](const index_type i) {
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }

    
    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size() +b_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VJoinObj";
    }

    VJoinObj<D,A,B>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class C>
      VJoinObj<D,A,B>& operator=(const TensorR<D,C>& rhs) { 
      printf2("VJoinObj<D,A,B>& operator=(const TensorR<D,C>& rhs)\n");
      return this->equals(rhs);
    }


    VJoinObj<D,A,B>& operator=(const D d) { 
      return this->equals(d);
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VJoinExpr(a_.expression(),ii_.expression());
    }
#endif 


  };


  


  /****************************************************************************
   * VSubMaskObj Expression Template 
   *
   * wrapper for a vector submask
   ****************************************************************************
   */
  template<class D>
    class VSubMaskObj :  public  TExpressionRW<D,VSubMaskObj<D> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>* ii_;
    VectorofPtrs *vptrs;

  public:


  VSubMaskObj(Vector<D>& a, const Vector<bool>& mask)
    : a_(a), ii_(new Vector<index_type>(findtrue(mask))) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }


    ~VSubMaskObj(){ 
      delete  ii_;
      delete vptrs;
    }

    inline const D operator[](const index_type i) const{
      index_type ind = (*ii_)[i];
      return a_[ind];
    }
    inline  D& operator[](const index_type i) {
      index_type ind = (*ii_)[i];
      return a_[ind];
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return ii_->size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VSubMaskObj";
    }


    VSubMaskObj<D>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class B>
      VSubMaskObj<D>& operator=(const TensorR<D,B>& rhs) { 
      return this->equals(rhs);
    }

    VSubMaskObj<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
    VSubMaskObj<D>& operator=(const VSubMaskObj<D>& b) { 
      return this->equals(b);
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VSubMaskObj(a_.expression(),ii_->expression());
    }
#endif 



  };






  /****************************************************************************
   * VReconObj Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
    class VReconObj :  public  TExpressionR<D,VReconObj<D> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    VectorofPtrs *vptrs;

  public:


  VReconObj(Vector<D>& a)
    : a_(a)
    { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~VReconObj() {
      delete vptrs;
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    // TODO:  not sure what to use for this
    inline size_type size(void) const {
      return a_->size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VReconObj";
    }

    template <class A>
      Vector<D>& operator=(const TensorR<D,A>& x) { 
      size_type N = x.size();
      if ( common(*this,x) ) {    
	Vector<D> y(N);

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

    Vector<D>& operator=(const VReconObj<D>& b) { 

      return a_;
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return  a_.expression() +".resize()";
    }
#endif 


  };








  /****************************************************************************
   * VRepExpr Expression Template 
   *
   * expression for repeating a TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A>
    class VRepExpr : public  TExpressionR<D,VRepExpr<D,A> > {

  private:
    const A& a_;
    const size_type m_;
    const size_type N_;
    VectorofPtrs *vptrs;

  public:


  VRepExpr(const A& a, const size_type m)
    : a_(a), m_(m), N_(a_.size()) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }


    ~VRepExpr() {
      delete vptrs;
    }


    inline const D operator[](const index_type i) const{
      index_type index = index_type(i % N_);
      printf3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return m_*a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VRepExpr";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VJoinExpr(a_.expression(),ii_.expression());
    }
#endif 

  };




  /****************************************************************************
   * VBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
    class VBinOp : public  TExpressionR<D,VBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  VBinOp(const A& a, const B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~VBinOp() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VBinOp";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      // use typeof or typeid isnteadof  the above
      return "";
    }
#endif 


  };


  /************************************************************
   *               Templates for Binary+scalar Operators 
   *
   * D = data type, e.g. double
   * A = either an Vector or a TExpressionR
   * B = either an Vector or a TExpressionR
   * N = int
   ************************************************************
   */

  template<class D, class A, class X>
    class VSeriesOp : public  TExpressionR<D,VSeriesOp<D,A,X> > {

  private:
    const A& a_;
    const X& x_;
    const int N_;
    const D x0_;
    VectorofPtrs *vptrs;
    
  public:


  VSeriesOp(const A& a, const X& x, const int N, const D x0)
    : a_(a), x_(x), N_(N), x0_(x0) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }
  VSeriesOp(const A& a, const X& x, const int N)
    : a_(a), x_(x), N_(N), x0_(0) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }

    ~VSeriesOp() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const {
      const D x = x_[i] - x0_;
      D sum = 0;
      // TODO: check a_.size >= N
      D xpow = 1;
      for (int n = 0; n <= N_ ; n++) {
	D an = a_[n];
	if (an!=D(0)) {
	  sum += an*xpow;
	}
	//	if (i==2) {
	//	  mdisp(x0_,x_[i],x,sum,xpow,N_,n,an);
	//	}
	xpow *= x;
      }
      return sum; 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return x_.size();
      // TODO: check a_.size >= N
    }

    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VSeriesOp";
    }
  

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      // TODO: get this working
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sx = x_.expression(); */
      /* if (x_.vetype() != VE_Vector)  */
      /* 	sx = "(" + sx + ")"; */
      /* std::string sN = display::printf2str("%d",N_); */
      return "";
    }
#endif 


  };



  template<class D, class A, class B, class X, class OP1, class OP2>
    class VSeriesOp2 : public  TExpressionR<D,VSeriesOp2< D, A, B, X, OP1, OP2> > {

  private:
    const A& a_;
    const B& b_;
    const X& x_;
    const int N_;
    const D k1_;
    Vector<D>& k_;
    bool initialized;
    VectorofPtrs *vptrs;
    
  public:


  VSeriesOp2(const A& a, const A& b, const X& x, const int N, const D k1)
    : a_(a), b_(b), x_(x), N_(N), k1_(k1), k_(*(new Vector<D>(N))) {
      
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      vptrs->add(x_.getAddresses());
      vptrs->add(k_.getAddresses());
      
      for (int n = 0; n < N_ ; n++) {
	k_[n] = n*k1_;
      }
    }
    ~VSeriesOp2(){
      delete &k_;
      delete vptrs;
    }

    inline const D operator[](const index_type i) const {
      D sum = 0;
      // TODO: check a_.size >= N
      for (int n = 0; n < N_ ; n++) {
	D kx = k_[n]*x_[i];
	D an = a_[n];
	if (an != D(0)) {
	  sum += an*OP1::apply(kx);
	}
	D bn = b_[n];
	if (bn != D(0)) {
	  sum += bn*OP2::apply(kx);
	}
      }
      return sum; 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return x_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    static std::string classname(void)  {
      return "VSeriesOp2";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      // TODO: get this working
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sx = x_.expression(); */
      /* if (x_.vetype() != VE_Vector)  */
      /* 	sx = "(" + sx + ")"; */
      /* std::string sN = display::printf2str("%d",N_); */
      /* return OP1::expression(sx); */
      return "";
    }
#endif 


  };




  /****************************************************************************
   * VecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
    class VecOpScal : public TExpressionR<D,VecOpScal<D,A,OP> > {

  private:
    const A& a_;
    D val_;
    VectorofPtrs *vptrs;

  public:


  VecOpScal(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }

    ~VecOpScal() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VecOpScal";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sb = stream.str(); */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 





  };





  /****************************************************************************
   * ScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
    class ScalOpVec : public TExpressionR<D,ScalOpVec<D,B,OP> > {

  private:
    D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:



  ScalOpVec(const D a, const B& b)
    :  val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(b_.getAddresses());
    }
    ~ScalOpVec() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    static std::string classname(void)  {
      return "ScalOpVec";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sa = stream.str(); */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 



  };




  /****************************************************************************
   * VFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
    class VFuncOp  : public  TExpressionR<D,VFuncOp<D,A,FUNC> > {
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
  
  public:



  VFuncOp(const A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~VFuncOp() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }
    
    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VFuncOp";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };





  /****************************************************************************
   * VBoolBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
    class VBoolBinOp : public  TExpressionR<bool,VBoolBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  VBoolBinOp(const A& a, const B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&b_);
    }

    ~VBoolBinOp() {
      delete vptrs;
    }


    inline bool operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VBoolBinOp";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 

  };







  /****************************************************************************
   * BoolVecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
    class BoolVecOpScal : public TExpressionR<bool,BoolVecOpScal<D,A,OP> > {

  private:
    const A& a_;
    D val_;
    VectorofPtrs *vptrs;

  public:



  BoolVecOpScal(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~BoolVecOpScal() {
      delete vptrs;
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "BoolVecOpScal";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sb = stream.str(); */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 

  };





  /****************************************************************************
   * BoolScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
    class BoolScalOpVec : public TExpressionR<bool,BoolScalOpVec<D,B,OP> > {

  private:
    D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  BoolScalOpVec(const D a, const B& b)
    :  val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&b_);
    }

    ~BoolScalOpVec() {
      delete vptrs;
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    static std::string classname(void)  {
      return "BoolScalOpVec";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sa = stream.str(); */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 




  };




  /****************************************************************************
   * VBoolFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
    class VBoolFuncOp  : public  TExpressionR<bool,VBoolFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
  
  public:


  VBoolFuncOp(const A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~VBoolFuncOp() {
      delete vptrs;
    }

    inline bool operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VBoolFuncOp";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif 

  };









  /****************************************************************************
   * CVecOpScal Operator Template 
   *
   * complex vector = binfunc(ComplexOrRealVector,RealScalar) binary operators 
   ****************************************************************************
   */
  template<class D, class A, class OP>
    class CVecOpScal : public TExpressionR<std::complex<D>, CVecOpScal<D,A,OP> > {

  private:
    const A& a_;
    const D val_;
    VectorofPtrs *vptrs;

  public:


  CVecOpScal(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~CVecOpScal() {
      delete vptrs;
    }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "CVecOpScal";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sb = stream.str(); */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 



  };






  /****************************************************************************
   * CScalOpVec Operator Template 
   *
   * complex vector = binfunc(RealScalar,ComplexOrRealVector) binary operators 
   ****************************************************************************
   */
  template<class D, class B, class OP>
    class CScalOpVec : public TExpressionR<std::complex<D>,CScalOpVec<D,B,OP> > {
  private:
    const D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  CScalOpVec(const D a, const B& b)
    : val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&b_);
    }

    ~CScalOpVec() {
      delete vptrs;
    }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    static std::string classname(void)  {
      return "CScalOpVec";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sa = stream.str(); */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 


  };





  /****************************************************************************
   * VRealFromComplex Expression Template 
   *
   * used for accessing real/imag part of complex vector
   ****************************************************************************
   */
  template <class D, class OP>
    class VRealFromComplex : public  TExpressionRW<D,VRealFromComplex<D,OP> > {
  private:
    Vector<std::complex<D> >& a_;
    VectorofPtrs *vptrs;

  public:


  VRealFromComplex(Vector<std::complex<D> >& a)
    :   a_(a) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~VRealFromComplex() {
      delete vptrs;
    }

    inline const D operator[](index_type i) const{
      return OP::give(a_[i]);
    }
    inline D& operator[](index_type i) {
      return OP::give(a_[i]);
    }



    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VRealFromComplex";
    }


    template <class B>
      VRealFromComplex<D,OP>& operator=(const B& b) { 
      return equals(b);
    }

    template <class OP2>
      VRealFromComplex<D,OP>& operator=(const VRealFromComplex<D,OP2>& b) { 
      return equals(b);
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return a_.expression();
      //      return expression_VSliceObj(a_.expression(),start_,end_,step_);
    }
#endif 

  };




};  //namespace matricks

#endif 
