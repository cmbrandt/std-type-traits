#include <iostream>
#include <type_traits.hxx>


int main() 
{
  std::cout <<   "cmb::is_reference<int>::value = "
            <<    cmb::is_reference<int>::value // = 0
            << "\ncmb::is_reference_v<int&>     = "
            <<    cmb::is_reference_v<int&>     // = 1
            << std::endl;
}