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

    template <class iter1,class iter2>
    bool operator==(const VectorIterator<iter1> &lhs, const VectorIterator<iter2> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class iter1,class iter2>
    bool operator!=(const VectorIterator<iter1> &lhs, const VectorIterator<iter2> &rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <class iter1,class iter2>
    bool operator<(const VectorIterator<iter1> &lhs, const VectorIterator<iter2> &rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class iter1,class iter2>
    bool operator<=(const VectorIterator<iter1> &lhs, const VectorIterator<iter2> &rhs)
    {
        return lhs.base() <= rhs.base();
    }

    template <class iter1,class iter2>
    bool operator>(const VectorIterator<iter1> &lhs, const VectorIterator<iter2> &rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <class iter1,class iter2>
    bool operator>=(const VectorIterator<iter1> &lhs, const VectorIterator<iter2> &rhs)
    {
        return lhs.base() >= rhs.base();
    }

    template <class iter1,class iter2>
    typename VectorIterator<iter1>::difference_type operator-(const VectorIterator<iter1> &lhs, const VectorIterator<iter2> &rhs)
    {
        return lhs.base() - rhs.base();
    }

    template <class iter>
    VectorIterator<iter> operator+(typename VectorIterator<iter>::difference_type n, const VectorIterator<iter> &rhs)
    {
        return VectorIterator<iter>(rhs.base() + n);
    }

}

#endif