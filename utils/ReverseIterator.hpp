#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "../vIterators.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    protected:
        Iterator _current;

    public:
        typedef Iterator iterator_type;
        typedef typename Iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename Iterator_traits<Iterator>::value_type value_type;
        typedef typename Iterator_traits<Iterator>::difference_type difference_type;
        typedef typename Iterator_traits<Iterator>::pointer pointer;
        typedef typename Iterator_traits<Iterator>::reference reference;

        reverse_iterator() : _current() {}
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base()) {}
        explicit reverse_iterator(iterator_type x) : _current(x) {}
        iterator_type base() const { return _current; }
        template <class Iter>
        reverse_iterator &operator=(const reverse_iterator<Iter> &rev_it)
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
        reverse_iterator &operator++()
        {
            --_current;
            return *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --_current;
            return tmp;
        }
        reverse_iterator &operator--()
        {
            ++_current;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++_current;
            return tmp;
        }
        reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n); }
        reverse_iterator &operator+=(difference_type n)
        {
            _current -= n;
            return *this;
        }
        reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n); }
        reverse_iterator &operator-=(difference_type n)
        {
            _current += n;
            return *this;
        }
    };

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() == rhs.base();
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() != rhs.base();
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() > rhs.base();
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() >= rhs.base();
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() < rhs.base();
    }
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() <= rhs.base();
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return reverse_iterator<Iterator>(rev_it.base() - n);
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return rhs.base() - lhs.base();
    }
}

#endif