#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::extent<int[]>::value   = "
            <<    cmb::extent<int[]>::value   // = 0
            << "\ncmb::extent_v<int[2][5], 1> = "
            <<    cmb::extent_v<int[2][5], 1> // = 5
            << std::endl;
}