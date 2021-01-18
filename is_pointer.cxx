// is_pointer.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  std::cout <<   "cmb::is_pointer<int>::value = "
            <<    cmb::is_pointer<int>::value // = 0
            << "\ncmb::is_pointer_v<int*>     = "
            <<    cmb::is_pointer_v<int*>     // = 1
            << std::endl;
}