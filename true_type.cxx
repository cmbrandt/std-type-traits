#include <iostream>
#include <type_traits.hxx>


int main()
{
  std::cout << "cmb::true_type = "
            <<  cmb::true_type() // = 1
            << std::endl;
}