// is_void.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  std::cout <<   "cmb::is_void<void>::value = " << cmb::is_void<void>::value
            << "\ncmb::is_void_v<int>       = " << cmb::is_void_v<int>
            << std::endl;
}