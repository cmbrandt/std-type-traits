// integral_constant.cxx

#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout << "cmb::integral_constant<int, 5>::value = "
            <<  cmb::integral_constant<int, 5>::value // = 5
            << std::endl;
}