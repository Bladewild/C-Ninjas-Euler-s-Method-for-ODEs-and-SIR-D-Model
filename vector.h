#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <initializer_list>

using std::string;
using std::ostream;
using std::cout;

template<typename T>
class vector;

template<typename T>
class Iter
{
public:
  Iter(const vector<T>* p_vec, int pos)
    : _pos(pos)
    , _p_vec(p_vec)
  { }

  // these three methods form the basis of an iterator for use with
  // a range-based for loop
  bool operator!= (const Iter& other) const
  {
    return _pos != other._pos;
  }

  // this method must be defined after the definition of vector<T>
  // since it needs to use it
  int operator* () const;

  const Iter& operator++ ()
  {
    ++_pos;
    // although not strictly necessary for a range-based for loop
    // following the normal convention of returning a value from
    // operator++ is a good idea.
    return *this;
  }

private:
  int _pos;
  const vector<T>* _p_vec;
};

template<typename T>
class vector
{
private:
  T* arr; // pointer to the first element of the underlying array
  int current_size;       // size of this myvec
  void init(int input_size);
  static T handleMath(char symbol,T left, T right);
  static vector<T> operatorhandler(const vector<T>& lhs, 
    const vector<T>& rhs, char& symbol);
public:

  vector(); // constructor
  vector(int size); // constructor
  vector(const T * input_array, const int input_size); // constructor
  vector(const vector<T>& otherVector);


  vector(std::initializer_list<T> l);

  int size() const;
  bool empty() const;

  /*!
    @Pre Assignment Operator T must be defined

  */
  void set(int i, T val);

  /*!
     @Pre Assignment Operator T must be defined

   */
  T get(int i) const;


  vector<T> operator-() const;

  template<typename U>
  friend ostream& operator << (ostream& os, const vector<U>& Obj);

  template<typename U>
  friend vector<U> operator+(const vector<U>& lhs, const vector<U>& rhs);
  template<typename U>
  friend vector<U> operator-(const vector<U>& lhs, const vector<U>& rhs);

  //dot operator
  template<typename U>
  friend U operator*(const vector<U>& lhs, const vector<U>& rhs);
  template<typename U>
  friend vector<U> operator*(const U & lhsScalar, const vector<U>& rhs);
  template<typename U>
  friend vector<U> operator*(const vector<U>& lhs, const U& rhsScalar);

  

  vector<T>& operator = (const vector<T>& source);


  ~vector();

  void resize(const int new_size);

  Iter<T> begin() const;

  Iter<T> end() const;
};

template<typename T>
int Iter<T>::operator* () const
{
  return _p_vec->get(_pos);
}




#include "vector.hpp"

/*
http://antonym.org/2014/02/c-plus-plus-11-range-based-for-loops.html
  */
  /*
  destructor
copy constructor
copy assignment operator

A parameterized constructor accepting a 1-dimensional std::initializer_list //done
A parameterized constructor accepting the size of the vector to create //done
Other appropriate constructors
A means of resizing and determining the size of the vector with resize and size functions //done
Appropriate functions such that range-based for loops can be used on your vector//in dev
Copy constructor/copy assignment operations //done
Element access with the [] operator
Addition, subtraction, scalar multiplication, and vector multiplication (dot product)
Unary minus
An apply function accepting a function and returning a new vector containing the result of the function when called on the elements of the calling object, and in which the function f must have the signature T f(T) (for template type T)
Stream operators for input/output of vector data - accepted input should be whitespace-delimited elements, and output should be single-space-delimited elements of the vector
*/

#endif
