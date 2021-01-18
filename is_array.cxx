// is_array.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  std::cout <<   "cmb::is_array<int>::value = "
            <<    cmb::is_array<int>::value // = 0
            << "\ncmb::is_array_v<int[]>    = "
            <<    cmb::is_array_v<int[]>    // = 1
            << std::endl;
}