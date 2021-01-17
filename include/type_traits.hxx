// type_traits.hxx

#ifndef TYPE_TRAITS_HXX
#define TYPE_TRAITS_HXX


namespace cmb {

//
// Declarations


// Helper class

template <class T, T v> struct integral_constant;

template <bool B>
  using bool_constant = cmb::integral_constant<bool, B>;
using true_type  = cmb::bool_constant<true>;
using false_type = cmb::bool_constant<false>;


// Primary type categories

template <class T> struct is_void;
template <class T> struct is_null_pointer;
template <class T> struct is_integral;
template <class T> struct is_floating_point;
template <class T> struct is_array;
template <class T> struct is_pointer;
template <class T> struct is_lvalue_reference;
template <class T> struct is_rvalue_reference;

template <class T>
  constexpr bool is_void_v             = cmb::is_void<T>::value;
template <class T>
  constexpr bool is_null_pointer_v     = cmb::is_null_pointer<T>::value;
template <class T>
  constexpr bool is_integral_v         = cmb::is_integral<T>::value;
template <class T>
  constexpr bool is_floating_point_v   = cmb::is_floating_point<T>::value;
template <class T>
  constexpr bool is_array_v            = cmb::is_array<T>::value;
template <class T>
  constexpr bool is_pointer_v          = cmb::is_pointer<T>::value;
template <class T>
  constexpr bool is_lvalue_reference_v = cmb::is_lvalue_reference<T>::value;
template <class T>
  constexpr bool is_rvalue_reference_v = cmb::is_rvalue_reference<T>::value;


// Composite type categories

template <class T> struct is_arithmetic;

template <class T>
  constexpr bool is_arithmetic_v = cmb::is_arithmetic;


// Type properties

template <class T> struct is_signed;
template <class T> struct is_copy_assignable;
template <class T> struct is_move_assignable;

//template <class T>
//  constexpr bool is_signed_v          = cmb::is_signed<T>::value;
//template <class T>
//  constexpr bool is_copy_assignable_v = cmb::is_copy_assignable<T>::value;
//template <class T>
//  constexpr bool is_move_assignable_v = cmb::is_move_assignable<T>::value;


// Type relationships

template <class T, class U> struct is_same;

template <class T, class U>
  constexpr bool is_same_v = cmb::is_same<T,U>::value;


// Const-volatile specifiers

template <class T> struct remove_const;
template <class T> struct remove_volatile;
template <class T> struct remove_cv;
//template <class T> struct add_const;
//template <class T> struct add_volatile;
//template <class T> struct add_cv;

template <class T>
  using remove_const_t    = typename cmb::remove_const<T>::type;
template <class T>
  using remove_volatile_t = typename cmb::remove_volatile<T>::type;
template <class T>
  using remove_cv_t       = typename cmb::remove_cv<T>::type;
//template <class T>
//  using add_const_t       = typename cmb::add_const<T>::type;
//template <class T>
//  using add_volatile_t    = typename cmb::add_volatile<T>::type;
//template <class T>
//  using add_cv_t          = typename cmb::add_cv<T>::type;

// Reference modifications
//template <class T> struct add_lvalue_reference;
//template <class T> struct add_rvalue_reference;

//template <class T>
//  using add_lvalue_reference_t = typename cmb::add_lvalue_reference;
//template <class T>
//  using add_rvalue_reference_t = typename cmb::add_rvalue_reference;


// Other transformations

template <bool B, class T = void>   struct enable_if;
template <bool B, class T, class F> struct conditional;

template <bool B, class T = void>
  using enable_if_t   = typename enable_if<B,T>::type;
template <bool B, class T, class F>
  using conditional_t = typename cmb::conditional<B,T,F>::type;

template <class...>
  using void_t = void;



//
// Definitions


// Helper metafunction(s)

template <class T> struct or_helper

// integral_constant

template <class T, T v>
struct integral_constant {

  static constexpr T value{v};

  using value_type = T;
  using type       = integral_constant;

  constexpr operator   value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};


// is_void

namespace detail
{
  template <class T> struct is_void_impl       : public cmb::false_type { };
  template <>        struct is_void_impl<void> : public cmb::true_type  { };
} // namespace detail

template <class T>
struct is_void
: detail::is_void_impl<cmb::remove_cv_t<T>> { };


// is_null_pointer

namespace detail
{
  template <class T> struct is_null_pointer_impl                 : public cmb::false_type { };
  template <>        struct is_null_pointer_impl<std::nullptr_t> : public cmb::true_type  { };
} // namespace detail

template <class T>
struct is_null_pointer
: public cmb::detail::is_null_pointer_impl<cmb::remove_cv_t<T>> { };


// is_integral

namespace detail
{
  template <class T> struct is_integral_impl                     : public cmb::false_type { };
  template <>        struct is_integral_impl<bool>               : public cmb::true_type  { };
  template <>        struct is_integral_impl<char>               : public cmb::true_type  { };
  template <>        struct is_integral_impl<signed char>        : public cmb::true_type  { };
  template <>        struct is_integral_impl<unsigned char>      : public cmb::true_type  { };
  template <>        struct is_integral_impl<wchar_t>            : public cmb::true_type  { };
  template <>        struct is_integral_impl<char16_t>           : public cmb::true_type  { };
  template <>        struct is_integral_impl<char32_t>           : public cmb::true_type  { };
  template <>        struct is_integral_impl<short>              : public cmb::true_type  { };
  template <>        struct is_integral_impl<unsigned short>     : public cmb::true_type  { };
  template <>        struct is_integral_impl<int>                : public cmb::true_type  { };
  template <>        struct is_integral_impl<unsigned int>       : public cmb::true_type  { };
  template <>        struct is_integral_impl<long>               : public cmb::true_type  { };
  template <>        struct is_integral_impl<unsigned long>      : public cmb::true_type  { };
  template <>        struct is_integral_impl<long long>          : public cmb::true_type  { };
  template <>        struct is_integral_impl<unsigned long long> : public cmb::true_type  { };
} // namespace detail

template <class T>
struct is_integral
: public cmb::detail::is_integral_impl<cmb::remove_cv_t<T>> { };


// is_floating_point

namespace detail
{
  template <class T> struct is_floating_point_impl              : public cmb::false_type { };
  template <>        struct is_floating_point_impl<float>       : public cmb::true_type  { };
  template <>        struct is_floating_point_impl<double>      : public cmb::true_type  { };
  template <>        struct is_floating_point_impl<long double> : public cmb::true_type  { };
} // namespace detail

template <class T>
struct is_floating_point
: public cmb::detail::is_floating_point_impl<cmb::remove_cv_t<T>> { };


// is_array

template <class T>           struct is_array       : public cmb::false_type { };
template <class T, size_t N> struct is_array<T[N]> : public cmb::true_type  { };
template <class T>           struct is_array<T[]>  : public cmb::true_type  { };


// is_pointer

namespace detail
{
template <class T> struct is_pointer_impl     : public cmb::false_type { };
template <class T> struct is_pointer_impl<T*> : public cmb::true_type  { };
} // namespace detail

template <class T> struct is_pointer
: public cmb::detail::is_pointer_impl<cmb::remove_cv_t<T>> { };


// is_lvalue_reference

template <class T> struct is_lvalue_reference     : public cmb::false_type { };
template <class T> struct is_lvalue_reference<T&> : public cmb::true_type  { };


// is_rvalue_reference

template <class T> struct is_rvalue_reference      : public cmb::false_type { };
template <class T> struct is_rvalue_reference<T&&> : public cmb::true_type  { };


// is_signed

namespace detail
{
template <class T> struct is_signed_impl     : public cmb::false_type { };
template <class T> struct is_signed_impl<T*> : public cmb::true_type  { };
} // namespace detail

template <class T> struct is_signed
: public cmb::detail::is_signed_impl<cmb::remove_cv_t<T>> { };



// is_copy_assignable




// is_move_assignable




// is_same

template <class T, class U> struct is_same      : public cmb::false_type { };
template <class T>          struct is_same<T,T> : public cmb::true_type  { };


// remove_const

template <class T> struct remove_const          { using type = T; };
template <class T> struct remove_const<T const> { using type = T; };


// remove_volatile

template <class T> struct remove_volatile             { using type = T; };
template <class T> struct remove_volatile<T volatile> { using type = T; };


// remove_cv

template <class T> struct remove_cv                   { using type = T; };
template <class T> struct remove_cv<T const>          { using type = T; };
template <class T> struct remove_cv<T volatile>       { using type = T; };
template <class T> struct remove_cv<T const volatile> { using type = T; };


// enable_if




// conditional

template <bool B, class T, class F>
struct conditional { using type = T; };

template <class T, class F>
struct conditional<false, T, F> { using type = F; };


// void_t





} // namespace cmb


#endif