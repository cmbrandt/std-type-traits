// false_type.cxx

#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout << "cmb::false_type = "
            <<  cmb::false_type() // = 0
            << std::endl;
}