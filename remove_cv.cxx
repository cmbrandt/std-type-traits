// remove_cv.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  using type1 = cmb::remove_cv<int const>::type;
  using type2 = cmb::remove_cv_t<int const>;

  using type3 = cmb::remove_cv<int volatile>::type;
  using type4 = cmb::remove_cv_t<int volatile>;

  using type5 = cmb::remove_cv<int const volatile>::type;
  using type6 = cmb::remove_cv_t<int const volatile>;

  std::cout <<   "cmb::same_as_v<int, type1> = " << cmb::is_same_v<int, type1> // = 1
            << "\ncmb::same_as_v<int, type2> = " << cmb::is_same_v<int, type2> // = 1
            << "\ncmb::same_as_v<int, type3> = " << cmb::is_same_v<int, type3> // = 1
            << "\ncmb::same_as_v<int, type4> = " << cmb::is_same_v<int, type4> // = 1
            << "\ncmb::same_as_v<int, type5> = " << cmb::is_same_v<int, type5> // = 1
            << "\ncmb::same_as_v<int, type6> = " << cmb::is_same_v<int, type6> // = 1
            << std::endl;
}