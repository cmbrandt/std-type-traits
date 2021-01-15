// test_type_relationships.cxx

#include <iostream>
#include "test_type_relationships.hxx"
#include "type_traits.hxx"


void test_type_relationships()
{
  int fail = 0;

  fail = test_is_same(fail);

  if (fail == 0)
    std::cout << "\ntest_type_relationships()      passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_type_relationships()      had " << fail << " error(s)." << std::endl;
}



//
// Type relationships tests

int test_is_same(int fail)
{

  return fail;
}