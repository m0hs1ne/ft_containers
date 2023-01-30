#ifndef STD_FUNCTIONS_HPP
#define STD_FUNCTIONS_HPP

namespace ft
{
    // equal
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    // enable_if
    template <bool B, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
    
    // is_integral
    template <class T>
    struct is_integral
    {
        static const bool value = false;
    };

    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const unsigned long long>
    {
        static const bool value = true;
    };

     template <>
    struct is_integral<const bool>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const signed char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const unsigned char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const wchar_t>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const unsigned short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const unsigned int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const unsigned long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<const long long>
    {
        static const bool value = true;
    };
}

#endif