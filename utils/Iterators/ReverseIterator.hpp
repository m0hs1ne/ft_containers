#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft
{
    template <class Iterator>
    class ReverseIterator
    {
    protected:
        Iterator _current;

    public:
        typedef Iterator iterator_type;
        typedef typename ft::Iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename ft::Iterator_traits<iterator_type>::value_type value_type;
        typedef typename ft::Iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename ft::Iterator_traits<iterator_type>::pointer pointer;
        typedef typename ft::Iterator_traits<iterator_type>::reference reference;

        ReverseIterator() : _current(nullptr) {}
        template <class Iter>
        ReverseIterator(const ReverseIterator<Iter> &rev_it) : _current(rev_it.base()) {}
        explicit ReverseIterator(iterator_type x) : _current(x) {}
        iterator_type base() const { return _current; }
        template <class Iter>
        ReverseIterator &operator=(const ReverseIterator<Iter> &rev_it)
        {
            _current = rev_it.base();
            return *this;
        }
        reference operator*() const
        {
            Iterator tmp = _current;
            return *--tmp;
        }
        pointer operator->() const { return &(operator*()); }
        reference operator[](difference_type n) const { return (_current[-n - 1]); }
        ReverseIterator &operator++()
        {
            --_current;
            return *this;
        }
        ReverseIterator operator++(int)
        {
            ReverseIterator tmp = *this;
            --_current;
            return tmp;
        }
        ReverseIterator &operator--()
        {
            ++_current;
            return *this;
        }
        ReverseIterator operator--(int)
        {
            ReverseIterator tmp = *this;
            ++_current;
            return tmp;
        }
        ReverseIterator operator+(difference_type n) const { return ReverseIterator(_current - n); }
        ReverseIterator &operator+=(difference_type n)
        {
            _current -= n;
            return *this;
        }
        ReverseIterator operator-(difference_type n) const { return ReverseIterator(_current + n); }
        ReverseIterator &operator-=(difference_type n)
        {
            _current += n;
            return *this;
        }
    };

    template <class Iterator>
    bool operator==(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs)
    {
        return lhs.base() == rhs.base();
    }
    template <class Iterator>
    bool operator!=(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs)
    {
        return lhs.base() != rhs.base();
    }
    template <class Iterator>
    bool operator<(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs)
    {
        return lhs.base() > rhs.base();
    }
    template <class Iterator>
    bool operator<=(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs)
    {
        return lhs.base() >= rhs.base();
    }
    template <class Iterator>
    bool operator>(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs)
    {
        return lhs.base() < rhs.base();
    }
    template <class Iterator>
    bool operator>=(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs)
    {
        return lhs.base() <= rhs.base();
    }
    template <class Iterator>
    ReverseIterator<Iterator> operator+(typename ReverseIterator<Iterator>::difference_type n, const ReverseIterator<Iterator> &rev_it)
    {
        return ReverseIterator<Iterator>(rev_it.base() - n);
    }
    template <class Iterator>
    typename ReverseIterator<Iterator>::difference_type operator-(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs)
    {
        return rhs.base() - lhs.base();
    }
}

#endif