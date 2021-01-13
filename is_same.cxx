// is_same.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  std::cout <<   "cmb::is_same<int, std::int32_t>::value = "
            <<    cmb::is_same<int, std::int32_t>::value // = 1
            << "\ncmb::is_same<int, std::int64_t>::value = "
            <<    cmb::is_same<int, std::int64_t>::value // = 0
            << std::endl;

  std::cout << "\ncmb::is_same_v<int, std::int32_t> = "
            <<    cmb::is_same_v<int, std::int32_t> // = 1
            << "\ncmb::is_same_v<int, std::int64_t> = "
            <<    cmb::is_same_v<int, std::int64_t> // = 0
            << std::endl;
}