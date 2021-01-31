#include <iostream>
#include <type_traits.hxx>


// Arbitrary type
struct A { };


int main() 
{
  std::cout <<   "cmb::is_fundamental<A>::value = "
            <<    cmb::is_fundamental<A>::value // = 0
            << "\ncmb::is_fundamental_v<int>    = "
            <<    cmb::is_fundamental_v<int>    // = 1
            << std::endl;
}