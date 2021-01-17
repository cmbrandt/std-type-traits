// enable_if.cxx

#include <iostream>
#include "include/type_traits.hxx"


// Test function
template <class T>
std::enable_if_t<cmb::is_arithmetic_v<T>, T>
times_two(T x)
{
  return x * 2;
}


int main()
{
  std::cout << "times_two(2) = " << times_two(5) << std::endl; // = 10
}