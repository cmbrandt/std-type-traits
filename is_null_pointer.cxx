#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::is_null_pointer<void>::value      = "
            <<    cmb::is_null_pointer<void>::value      // = 0
            << "\ncmb::is_null_pointer_v<std::nullptr_t> = "
            <<    cmb::is_null_pointer_v<std::nullptr_t> // = 1
            << std::endl;
}