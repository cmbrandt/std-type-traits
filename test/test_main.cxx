// test_main.cxx

#include <iostream>
#include "test_helper_class.hxx"
#include "test_primary_type_categories.hxx"
#include "test_type_relationships.hxx"
#include "test_const_volatile_specifiers.hxx"
#include "test_other_transformations.hxx"


int main()
{
  test_helper_class();
  test_primary_type_categories();
  test_type_relationships();
  //test_const_volatile_specifiers();
  test_other_transformations();

  std::cout << "\n\nend of test_main.cxx\n\n";
}