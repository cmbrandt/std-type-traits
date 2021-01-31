#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::is_same<int, std::int32_t>::value = "
            <<    cmb::is_same<int, std::int32_t>::value // = 1
            << "\ncmb::is_same_v<int, std::int64_t>      = "
            <<    cmb::is_same_v<int, std::int64_t>      // = 0
            << std::endl;
}