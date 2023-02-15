#ifndef STD_FUNCTIONS_HPP
#define STD_FUNCTIONS_HPP

#include "../Iterators/IteratorTraits.hpp"
#include "pair.hpp"

namespace ft
{

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

    template <class T, class U>
    struct is_same
    {
        static const bool value = false;
    };

    template <class T>
    struct is_same<T, T>
    {
        static const bool value = true;
    };

    template <class Iterator>
    struct is_random_access_iterator
    {
        static const bool value = ft::is_same<typename ft::Iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>::value;
    };

    template <class Iterator>
    struct is_input_iterator
    {
        static const bool value = ft::is_same<typename ft::Iterator_traits<Iterator>::iterator_category, std::input_iterator_tag>::value;
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

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        for (; first1 != last1; first1++, first2++)
            if (*first1 != *first2)
                return (false);
        return (true);
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        for (; first1 != last1; first1++, first2++)
            if (!pred(*first1, *first2))
                return (false);
        return (true);
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        for (; first1 != last1; first1++, first2++)
        {
            if (*first1 < *first2)
                return (true);
            else if (first2 == last2 || first1 > first2)
                return (false);
        }
        return (first2 != last2);
    }
}

#endif