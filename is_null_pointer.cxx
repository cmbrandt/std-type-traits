// is_null_pointer.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  std::cout <<   "cmb::is_null_pointer<int>::value       = "
            <<    cmb::is_null_pointer<int>::value       // = 1
            << "\ncmb::is_null_pointer_v<std::nullptr_t> = "
            <<    cmb::is_null_pointer_v<std::nullptr_t> // = 0
            << std::endl;
}