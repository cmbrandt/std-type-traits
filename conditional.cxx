#include <iostream>
#include <typeinfo>
#include <type_traits.hxx>


int main()
{
  using type1 = cmb::conditional<false,  int, double>::type;
  using type2 = cmb::conditional_t<true, int, double>;

  std::cout <<   "type1 = " << typeid(type1).name() // = d
            << "\ntype2 = " << typeid(type2).name() // = i
            << std::endl;
}