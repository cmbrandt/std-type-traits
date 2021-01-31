#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::is_void<int>::value = "
            <<    cmb::is_void<int>::value // = 0
            << "\ncmb::is_void_v<void>     = "
            <<    cmb::is_void_v<void>     // = 1
            << std::endl;
}