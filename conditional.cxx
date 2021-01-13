// conditional.cxx

#include <iostream>
#include <typeinfo>
#include "include/type_traits.hxx"


int main()
{
  using Type_one   = cmb::conditional<true,  int, double>::type;
  using Type_two   = cmb::conditional<false, int, double>::type;

  using Type_three = cmb::conditional_t<true,  int, double>;
  using Type_four  = cmb::conditional_t<false, int, double>;

  std::cout <<   "Type_one   = " << typeid(Type_one  ).name() // = i
            << "\nType_two   = " << typeid(Type_two  ).name() // = d
            << "\nType_three = " << typeid(Type_three).name() // = i
            << "\nType_four  = " << typeid(Type_four ).name() // = d
            << std::endl;
}