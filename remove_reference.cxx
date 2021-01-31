#include <iostream>
#include <type_traits.hxx>


int main()
{
  using type1 = cmb::remove_reference<int&>::type;
  using type2 = cmb::remove_reference_t<int&>;

  std::cout <<   "cmb::is_same_v<int, type1> = "
            <<    cmb::is_same_v<int, type1> // = 1
            << "\ncmb::is_same_v<int, type2> = "
            <<    cmb::is_same_v<int, type2> // = 1
            << std::endl;
}