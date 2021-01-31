#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::alignment_of<int>::value = "
            <<    cmb::alignment_of<int>::value // = 4
            << "\ncmb::alignment_of_v<double>   = "
            <<    cmb::alignment_of_v<double>   // = 8
            << std::endl;
}