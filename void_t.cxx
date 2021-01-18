// void_t.cxx

#include <iostream>
#include "include/type_traits.hxx"


// Helper metafunction

// Base template
template <class, class = void>
struct has_member
: public cmb::false_type
{ };

// Partial specialization
template <class T>
struct has_member<T, cmb::void_t<decltype(T::member)>>
: public cmb::true_type
{ };


// Test struct
struct A {
  int member{0};
};


int main()
{
  std::cout <<   "has_member<int>::value = "
            <<    has_member<int>::value // = 0
            << "\nhas_member<A>::value   = "
            <<    has_member<A>::value   // = 1
            << std::endl;
}