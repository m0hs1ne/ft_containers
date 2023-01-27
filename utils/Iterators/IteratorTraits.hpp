#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

namespace ft
{
    template <class Iterator>
    class Iterator_traits
    {
    public:
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    class Iterator_traits<T *>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class Iterator_traits<const T *>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class Iterator>
    class VectorIterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename Iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename Iterator_traits<Iterator>::value_type value_type;
        typedef typename Iterator_traits<Iterator>::difference_type difference_type;
        typedef typename Iterator_traits<Iterator>::pointer pointer;
        typedef typename Iterator_traits<Iterator>::reference reference;
    };
}
#endif