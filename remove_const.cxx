// remove_same.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  using type1 = cmb::remove_const<const int>::type;

  using type2 = cmb::remove_const_t<const int>;

  std::cout <<   "cmb::same_as_v<int, type1> = " << cmb::is_same_v<int, type1> // = 1
            << "\ncmb::same_as_v<int, type2> = " << cmb::is_same_v<int, type2> // = 1
            << std::endl;
}