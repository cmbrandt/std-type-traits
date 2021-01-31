// is_integral.cxx

#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::is_integral<void>::value = "
            <<    cmb::is_integral<void>::value // = 0
            << "\ncmb::is_integral_v<int>       = "
            <<    cmb::is_integral_v<int>       // = 1
            << std::endl;
}