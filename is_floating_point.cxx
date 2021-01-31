// is_floating_point.cxx

#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout <<   "cmb::is_floating_point<void>::value = "
            <<    cmb::is_floating_point<void>::value // = 0
            << "\ncmb::is_floating_point_v<double>    = "
            <<    cmb::is_floating_point_v<double>    // = 1
            << std::endl;
}