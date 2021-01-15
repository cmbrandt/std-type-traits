// test_helper_class.cxx

#include <iostream>
#include "test_helper_class.hxx"
#include "type_traits.hxx"


void test_helper_class()
{
  int fail = 0;

  fail = test_integral_constant(fail);
  fail = test_bool_constant(fail);
  fail = test_true_type(fail);
  fail = test_false_type(fail);

  if (fail == 0)
    std::cout << "\ntest_helper_class()            passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_helper_class()            had " << fail << " error(s)." << std::endl;
}



//
// Helper class tests

int test_integral_constant(int fail)
{

  return fail;
}



int test_bool_constant(int fail)
{

  return fail;
}



int test_true_type(int fail)
{

  return fail;
}



int test_false_type(int fail)
{

  return fail;
}