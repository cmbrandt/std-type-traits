#include <iostream>
#include <type_traits.hxx>


int main()
{
  using type1 = cmb::decay<int[5]>::type;
  using type2 = cmb::decay_t<int const&&>;

  std::cout <<   "cmb::is_same_v<int, type1> = "
            <<    cmb::is_same_v<int, type1> // = 0
            << "\ncmb::is_same_v<int, type2> = "
            <<    cmb::is_same_v<int, type2> // = 1
            << std::endl;
}