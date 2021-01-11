// true_type.cxx

#include <iostream>
#include "include/type_traits.hxx"

int main()
{

  std::cout << "\ncmb::integral_constant<5>::value = "
            << cmb::integral_constant<5>::value
            << std::endl;
}