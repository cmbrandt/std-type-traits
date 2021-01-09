// type_traits.hxx

#ifndef TYPE_TRAITS_HXX
#define TYPE_TRAITS_HXX


//
// Helper class

template <class T, T v>
struct integral_constant;

template <bool B>
using bool_constant = integral_constant<bool, B>;

using true_type  = bool_constant<true>;
using false_type = bool_constant<false>;


//
// Declarations




//
// ...


#endif