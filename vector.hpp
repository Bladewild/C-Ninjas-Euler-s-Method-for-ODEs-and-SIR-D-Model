#pragma region Constructors

template <typename T>
vector<T>::vector() // constructor
{
  init(0);
}
template <typename T>
vector<T>::vector(int size) // constructor
{
  init(size);
}

//array of refernce not allowed
template <typename T>
vector<T>::vector(const T * input_array,const int input_size) // constructor
{
  init(input_size);
  std::copy(input_array, input_array + current_size, arr);
}
template<typename T>
vector<T>::vector(std::initializer_list<T> init_list) 
{
  int index = 0;
  init(init_list.size());
  for (auto& element : init_list)
  {
    arr[index] = element;
    index++;
  }
  cout << "constructed with a " << current_size << "-element list\n";
}

template<typename T>
vector<T>::vector(const vector<T> & otherVector)
{
  cout << "Copy Constructor"<<std::endl;
  cout << "Size: " << otherVector.current_size<< std::endl;
  init(otherVector.current_size);
  std::copy(otherVector.arr, otherVector.arr + otherVector.current_size, arr);
}

template<typename T>
void vector<T>::init(int input_size)
{
  if (input_size < 0)
  {
    cout << "input_size: "<<input_size << std::endl;
    throw std::invalid_argument(" cannot be to a negative number.");
  }
  current_size = input_size;
  arr = new T[current_size];
  cout << "CurrentSize:" << current_size<<std::endl;
  //arr is empty, remember to check

}



#pragma endregion

template <typename T>
int vector<T>::size() const
{
  return current_size;
}

template <typename T>
bool vector<T>::empty() const
{
  return (current_size <= 0) ? true : false;
}
template <typename T>
void vector<T>::resize(const int new_size)
{
  //do nothing is same size
  if (new_size != current_size)
  {
    if (new_size < 1)
    {
      throw std::invalid_argument("cannot set size given");
    }
    T* new_arr = new T[new_size];   // allocate a new array on the free store
    current_size = new_size;
    std::copy(arr, arr + new_size, new_arr);

    delete[] arr;                       // delete the old vector
    arr = new_arr;
  }

}

#pragma region Overloads

/*
  @ppre T must define - (unary operator)
*/

template<typename T>
vector<T> vector<T>::operator-() const
{
  //check if vector is empty;
  T* new_complementarr = new T[current_size];

  for (int i = 0; i < current_size; i++)
  {
    new_complementarr[i] = -(arr[i]);
  }

  return vector(new_complementarr,current_size);
}

template<typename T>
vector<T>& vector<T>::operator = (const vector<T>& source)
{
  if (this != &source)
  {
    std::copy(source.arr, source.arr + source.current_size, arr);
    current_size = source.current_size;
  }
  return *this;
}

template<typename T>
vector<T>::~vector()
{       // destructor
  delete[] arr;
}


template<typename T>
ostream& operator << (ostream& os, const vector<T>& Obj)
{

  for (auto x : Obj)
  {
    os << x << " ";
  }
  return os;
}

#pragma endregion
template <typename T>
void vector<T>::set(int i, T val)
{
  if (i < 0 || i >= current_size)
  {
    throw std::range_error(" cannot set out of bounds.");
  }
  arr[i] = val;
}

template <typename T>
T vector<T>::get(int i) const
{
  if (i < 0 || i >= current_size)
  {
    throw std::range_error(" cannot set out of bounds.");
  }
  return arr[i];
}
//iterators

template<typename T>
Iter<T> vector<T>::begin() const
{
  return Iter<T>(this, 0);
}

template<typename T>
Iter<T> vector<T>::end() const
{
  return Iter<T>(this, current_size);
}

