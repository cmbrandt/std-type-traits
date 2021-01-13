// bool_constant.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  std::cout <<   "cmb::bool_constant<true>::value  = " // = 1
            <<    cmb::bool_constant<true>::value
            << "\ncmb::bool_constant<false>::value = " // = 0
            <<    cmb::bool_constant<false>::value << std::endl;
}