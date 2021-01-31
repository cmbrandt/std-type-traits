#include <iostream>
#include <type_traits.hxx>


int main()
{
  using type1 = cmb::add_volatile<int>::type;
  using type2 = cmb::add_volatile_t<int>;

  std::cout <<   "cmb::is_same_v<int volatile, type1> = "
            <<    cmb::is_same_v<int volatile, type1> // = 1
            << "\ncmb::is_same_v<int volatile, type2> = "
            <<    cmb::is_same_v<int volatile, type2> // = 1
            << std::endl;
}