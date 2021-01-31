#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::rank<int>::value  = "
            <<    cmb::rank<int>::value  // = 0
            << "\ncmb::rank_v<int[2][5]> = "
            <<    cmb::rank_v<int[2][5]> // = 2
            << std::endl;
}