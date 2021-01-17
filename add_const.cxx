// add_const.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  using type1 = cmb::add_const<int>::type;
  using type2 = cmb::add_const_t<int>;

  std::cout <<   "cmb::is_same_v<int const, type1> = "
            <<    cmb::is_same_v<int const, type1> // = 1
            << "\ncmb::is_same_v<int const, type2> = "
            <<    cmb::is_same_v<int const, type2> // = 1
            << std::endl;
}