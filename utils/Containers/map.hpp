#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <iostream>
#include "../std_functions/pair.hpp"
#include "../Iterators/ReverseIterator.hpp"


namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map{
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const Key, T> value_type;
            typedef Alloc allocator_type;
            typedef Compare key_compare;
            typedef typename Alloc::reference reference;
            typedef typename Alloc::const_reference const_reference;
            typedef typename Alloc::pointer pointer;
            typedef typename Alloc::const_pointer const_pointer;
            typedef typename Alloc::difference_type difference_type;
            typedef typename Alloc::size_type size_type;

            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                friend class map<key_type, mapped_type, key_compare, allocator_type>;
                protected:
                    key_compare comp;
                    value_compare(key_compare c) : comp(c) {}
                public:
                    bool operator()(const value_type &x, const value_type &y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
        
    };
}


#endif