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
template <class T> struct is_reference;
template <class T> struct is_arithmetic;
template <class T> struct is_fundamental;
template <class T> struct is_compound;

template <class T>
  constexpr bool is_reference_v   = cmb::is_reference<T>::value;
template <class T>
  constexpr bool is_arithmetic_v  = cmb::is_arithmetic<T>::value;
template <class T>
  constexpr bool is_fundamental_v = cmb::is_fundamental<T>::value;
template <class T>
  constexpr bool is_compound_v    = cmb::is_compound<T>::value;


// Type property queries
template <class T>                 struct alignment_of;
template <class T>                 struct rank;
template <class T, unsigned I = 0> struct extent;

template <class T>
  constexpr size_t alignment_of_v = cmb::alignment_of<T>::value;
template <class T>
  constexpr size_t rank_v         = cmb::rank<T>::value;
template <class T, unsigned I = 0>
  constexpr size_t extent_v       = cmb::extent<T,I>::value;


// Type relationships
template <class T, class U> struct is_same;

template <class T, class U>
  constexpr bool is_same_v = cmb::is_same<T,U>::value;


// Const-volatile specifiers
template <class T> struct remove_const;
template <class T> struct remove_volatile;
template <class T> struct remove_cv;
template <class T> struct add_const;
template <class T> struct add_volatile;
template <class T> struct add_cv;

template <class T>
  using remove_const_t    = typename cmb::remove_const<T>::type;
template <class T>
  using remove_volatile_t = typename cmb::remove_volatile<T>::type;
template <class T>
  using remove_cv_t       = typename cmb::remove_cv<T>::type;
template <class T>
  using add_const_t       = typename cmb::add_const<T>::type;
template <class T>
  using add_volatile_t    = typename cmb::add_volatile<T>::type;
template <class T>
  using add_cv_t          = typename cmb::add_cv<T>::type;


// Reference modifications
template <class T> struct remove_reference;
template <class T> struct add_lvalue_reference;
template <class T> struct add_rvalue_reference;

template <class T>
  using remove_reference_t     = typename cmb::remove_reference<T>::type;
template <class T>
  using add_lvalue_reference_t = typename cmb::add_lvalue_reference<T>::type;
template <class T>
  using add_rvalue_reference_t = typename cmb::add_rvalue_reference<T>::type;


// Other transformations
template <class T>                  struct decay;
template <class T>                  struct remove_cvref;
template <bool B, class T = void>   struct enable_if;
template <bool B, class T, class F> struct conditional;

//template <class T>
//  using decay_t        = typename cmb::decay<T>::type;
//template <class T>
//  using remove_cvref_t = typename cmb::remove_cvref<T>::type;
template <bool B, class T = void>
  using enable_if_t    = typename cmb::enable_if<B,T>::type;
template <bool B, class T, class F>
  using conditional_t  = typename cmb::conditional<B,T,F>::type;

template <class...>
  using void_t = void;



//
// Definitions

// integral_constant
template <class T, T v>
struct integral_constant {

  static constexpr T value{v};

  using value_type = T;
  using type       = integral_constant;

  constexpr operator   value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};


// non-public utility to detect referenceable types
namespace detail
{
  template <class T, class = void> struct is_referenceable
    : public cmb::false_type { };

  template <class T> struct is_referenceable<T, cmb::void_t<T&>>
    : public cmb::true_type { };

//  template <class T, class void>
//    constexpr bool is_referenceable_v = cmb::is_referenceable<T>::value;
}


// is_void
namespace detail
{
  template <class T> struct is_void_impl       : public cmb::false_type { };
  template <>        struct is_void_impl<void> : public cmb::true_type  { };
}

template <class T>
struct is_void
  : public cmb::detail::is_void_impl<cmb::remove_cv_t<T>> { };


// is_null_pointer
namespace detail
{
  template <class T> struct is_null_pointer_impl                 : public cmb::false_type { };
  template <>        struct is_null_pointer_impl<std::nullptr_t> : public cmb::true_type  { };
}

template <class T>
struct is_null_pointer
  : public cmb::detail::is_null_pointer_impl<cmb::remove_cv_t<T>> { };


// is_integral [note: wchar8_t is C++20]
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
}

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
}

template <class T>
struct is_floating_point
  : public cmb::detail::is_floating_point_impl<cmb::remove_cv_t<T>> { };


// is_array
template <class T>           struct is_array       : public cmb::false_type { };
template <class T>           struct is_array<T[]>  : public cmb::true_type  { };
template <class T, size_t N> struct is_array<T[N]> : public cmb::true_type  { };


// is_pointer
namespace detail
{
  template <class T> struct is_pointer_impl     : public cmb::false_type { };
  template <class T> struct is_pointer_impl<T*> : public cmb::true_type  { };
}

template <class T> struct is_pointer
  : public cmb::detail::is_pointer_impl<cmb::remove_cv_t<T>> { };


// is_lvalue_reference
template <class T> struct is_lvalue_reference     : public cmb::false_type { };
template <class T> struct is_lvalue_reference<T&> : public cmb::true_type  { };


// is_rvalue_reference
template <class T> struct is_rvalue_reference      : public cmb::false_type { };
template <class T> struct is_rvalue_reference<T&&> : public cmb::true_type  { };


// is_reference
template <class T> struct is_reference      : public cmb::false_type { };
template <class T> struct is_reference<T&>  : public cmb::true_type  { };
template <class T> struct is_reference<T&&> : public cmb::true_type  { };


// is_arithmetic
template <class T> struct is_arithmetic
  : public cmb::integral_constant<bool, cmb::is_integral_v<T> or cmb::is_floating_point_v<T>> { };


// is_fundamental
template <class T> struct is_fundamental
  : public cmb::integral_constant<bool,
                                  cmb::is_arithmetic_v<T> or
                                  cmb::is_void_v<T> or
                                  cmb::is_null_pointer_v<T>> { };


// is_compound
template <class T> struct is_compound
  : public cmb::integral_constant<bool, not cmb::is_fundamental_v<T>> { };


// alignment_of
template <class T> struct alignment_of
  : public cmb::integral_constant<std::size_t, alignof(T)> { };


// rank
template <class T> struct rank
  : public cmb::integral_constant<std::size_t, 0> { };

template <class T> struct rank<T[]>
  : public cmb::integral_constant<std::size_t, 1 + cmb::rank_v<T>> { };

template <class T, std::size_t N> struct rank<T[N]>
  : public cmb::integral_constant<std::size_t, 1 + cmb::rank_v<T>> { };


// extent
template <class T, unsigned I> struct extent
  : public cmb::integral_constant<std::size_t, 0> { };

template <class T> struct extent<T[], 0>
  : public cmb::integral_constant<std::size_t, 0> { };

template <class T, unsigned I> struct extent<T[], I>
  : public cmb::extent<T, I-1> { };

template <class T, std::size_t N> struct extent<T[N], 0>
  : public cmb::integral_constant<std::size_t, N> { };

template <class T, std::size_t N, unsigned I> struct extent<T[N], I>
  : public cmb::integral_constant<std::size_t, cmb::extent_v<T, I-1>> { };


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


// add_const
template <class T> struct add_const { using type = T const; };


// add_volatile
template <class T> struct add_volatile { using type = T volatile; };


// add_cv
template <class T> struct add_cv { using type = T const volatile; };


// remove_reference
template <class T> struct remove_reference      { using type = T; };
template <class T> struct remove_reference<T&>  { using type = T; };
template <class T> struct remove_reference<T&&> { using type = T; };


// add_lvalue_reference
namespace detail
{
  template <class T, bool = cmb::detail::is_referenceable<T>::value>
    struct add_lvalue_reference_impl          { using type = T;  };

  template <class T>
    struct add_lvalue_reference_impl<T, true> { using type = T&; };
}

template <class T> struct add_lvalue_reference
  : public cmb::detail::add_lvalue_reference_impl<T> { };


// add_rvalue_reference
namespace detail
{
  template <class T, bool = cmb::detail::is_referenceable<T>::value>
    struct add_rvalue_reference_impl          { using type = T;   };

  template <class T>
    struct add_rvalue_reference_impl<T, true> { using type = T&&; };
}

template <class T> struct add_rvalue_reference
  : public cmb::detail::add_rvalue_reference_impl<T> { };


// enable_if
template <bool B, class T> struct enable_if          { };
template <class T>         struct enable_if<true, T> { using type = T; };


// conditional
template <bool B, class T, class F>
struct conditional { using type = T; };

template <class T, class F>
struct conditional<false, T, F> { using type = F; };

} // namespace cmb


#endif