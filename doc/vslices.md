
# python-like access: negative indices, slices, lists in mātricks
_This document was automatically generated from file_ **`vslices.cpp`** (mātricks-v2.7).

## Element access
### Positive and negative indices
Similar to python, mātricks allows negative indices

v[-1] = v[N-1] = end element
v[-2] = v[N-2] = penultimate element
v[-N] = v[0]   = first element


**EXAMPLE 1**: Positive and negative indices
```C++
Vector<double> v( range<double>(0,10) );
const int N = v.size();
```

**Some expressions with results**
```C++
  v:  {0,1,2,3,4,5,6,7,8,9,10}; 
  N:  11; 
  v[0]:  0; 
  v[1]:  1; 
  v[N-1]:  10; 
  v[-1]:  10; 
  v[-2]:  9; 
  v[-N]:  0; 
```



**EXAMPLE 2**: Reverse a vector in place.
```C++
Vector<double> v( range<double>(0,10) );
```

**The result is**
```C++
  v:  {0,1,2,3,4,5,6,7,8,9,10}; 
```

```C++
for (int i = 0; i < v.size()/2; i++) std::swap(v[i],v[-i-1]);
```

**The result is**
```C++
  v:  {10,9,8,7,6,5,4,3,2,1,0}; 
```

### Access vector elements using a list of indices

* The list can be smaller than or greater or equal in length to the vector!


**EXAMPLE 3**: Access via a C++11 initializer_list
```C++
Vector<double> v( linspace<double>(0,1,11) );
v:  {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1}; 
Vector<index_type> vi( range<index_type>(0,10,2) );
vi:  {0,2,4,6,8,10}; 
```

**The result is**
```C++
  v:  {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1}; 
  vi:  {0,2,4,6,8,10}; 
```

## Slices
### The [start,end] slice


**EXAMPLE 4**: slice `v[start,end]`
```C++
Vector<double> v( range<double>(0,10) );
```

**Some expressions with results**
```C++
  v[seq(2,6)]:  {2,3,4,5,6}; 
```


[Table of Contents](README.md)