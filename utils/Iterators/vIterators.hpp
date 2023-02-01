#ifndef VITERATORS_HPP
#define VITERATORS_HPP

#include "IteratorTraits.hpp"

namespace ft
{
    template <class T>
    class VectorIterator
    {
    public:
        typedef T iterator_type;
        typedef typename ft::Iterator_traits<T*>::pointer pointer;
        typedef typename ft::Iterator_traits<pointer>::iterator_category iterator_category;
        typedef typename ft::Iterator_traits<pointer>::value_type value_type;
        typedef typename ft::Iterator_traits<pointer>::difference_type difference_type;
        typedef typename ft::Iterator_traits<pointer>::reference reference;

        VectorIterator() : ptr(nullptr) {}

        template <class Iter>
        VectorIterator(const VectorIterator<Iter> &vec_it) : ptr(vec_it.base()) {}

        explicit VectorIterator(pointer x) : ptr(x) {}
        pointer base() const { return ptr; }

        template <class Iter>
        VectorIterator &operator=(const VectorIterator<Iter> &vec_it)
        {
            ptr = vec_it.base();
            return *this;
        }
        
        reference operator*() const { return *ptr; }
        pointer operator->() const { return &(operator*()); }
        reference operator[](difference_type n) const { return (ptr[n]); }
        VectorIterator &operator++()
        {
            ++ptr;
            return *this;
        }
        VectorIterator operator++(int)
        {
            VectorIterator tmp = *this;
            ++ptr;
            return tmp;
        }
        VectorIterator &operator--()
        {
            --ptr;
            return *this;
        }
        VectorIterator operator--(int)
        {
            VectorIterator tmp = *this;
            --ptr;
            return tmp;
        }
        VectorIterator operator+(difference_type n) const { return VectorIterator(ptr + n); }
        VectorIterator &operator+=(difference_type n)
        {
            ptr += n;
            return *this;
        }
        VectorIterator operator-(difference_type n) const { return VectorIterator(ptr - n); }
        VectorIterator &operator-=(difference_type n)
        {
            ptr -= n;
            return *this;
        }
    protected:
        pointer ptr;
    };

    template <class Iterator>
    bool operator==(const VectorIterator<Iterator> &lhs, const VectorIterator<Iterator> &rhs)
    {
        return lhs.base() == rhs.base();
    }
    template <class Iterator>
    bool operator!=(const VectorIterator<Iterator> &lhs, const VectorIterator<Iterator> &rhs)
    {
        return lhs.base() != rhs.base();
    }
    template <class Iterator>
    bool operator<(const VectorIterator<Iterator> &lhs, const VectorIterator<Iterator> &rhs)
    {
        return lhs.base() < rhs.base();
    }
    template <class Iterator>
    bool operator<=(const VectorIterator<Iterator> &lhs, const VectorIterator<Iterator> &rhs)
    {
        return lhs.base() <= rhs.base();
    }
    template <class Iterator>
    bool operator>(const VectorIterator<Iterator> &lhs, const VectorIterator<Iterator> &rhs)
    {
        return lhs.base() > rhs.base();
    }
    template <class Iterator>
    bool operator>=(const VectorIterator<Iterator> &lhs, const VectorIterator<Iterator> &rhs)
    {
        return lhs.base() >= rhs.base();
    }
    template <class Iterator>
    VectorIterator<Iterator> operator+(typename VectorIterator<Iterator>::difference_type n, const VectorIterator<Iterator> &vec_it)
    {
        return VectorIterator<Iterator>(vec_it.base() + n);
    }
    template <class Iterator>
    typename VectorIterator<Iterator>::difference_type operator-(const VectorIterator<Iterator> &lhs, const VectorIterator<Iterator> &rhs)
    {
        return lhs.base() - rhs.base();
    }
}

#endif