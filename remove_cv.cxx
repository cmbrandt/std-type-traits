// remove_cv.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  using type1 = cmb::remove_const<const in>::type;

  using type2 = cmb::remove_const_t<const int>;

  std::cout <<   " = " << cmb::same_as_v<int, type1>
            << "\n = " << cmb::same_as_v<int, type2>
            << std::endl;
}