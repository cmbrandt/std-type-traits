// conditional.cxx

#include <iostream>
#include <typeinfo>
#include "include/type_traits.hxx"


int main()
{
  using type1 = cmb::conditional<true,  int, double>::type;
  using type2 = cmb::conditional<false, int, double>::type;

  using type3 = cmb::conditional_t<true,  int, double>;
  using type4 = cmb::conditional_t<false, int, double>;

  std::cout <<   "type1 = " << typeid(type1).name() // = i
            << "\ntype2 = " << typeid(type2).name() // = d
            << "\ntype3 = " << typeid(type3).name() // = i
            << "\ntype4 = " << typeid(type4).name() // = d
            << std::endl;
}