#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::is_arithmetic<void>::value = "
            <<    cmb::is_arithmetic<void>::value // = 0
            << "\ncmb::is_arithmetic_v<float>     = "
            <<    cmb::is_arithmetic_v<float>     // = 1
            << std::endl;
}