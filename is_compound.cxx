#include <iostream>
#include <type_traits.hxx>


// Arbitrary type
struct A { };


int main()
{
  std::cout <<   "cmb::is_compound<void>::value = "
            <<    cmb::is_compound<void>::value // = 0
            << "\ncmb::is_compound_v<A>         = "
            <<    cmb::is_compound_v<A>         // = 1
            << std::endl;
}