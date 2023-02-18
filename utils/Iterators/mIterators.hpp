#ifndef MITERATORS_HPP
#define MITERATORS_HPP

#include "IteratorTraits.hpp"

namespace ft{
    template <class T,class N>
    class MapIterator
    {
        public:
            typedef T value_type;
            typedef N node_type;
            typedef node_type* node_pointer;
            typedef value_type& reference;
            typedef value_type* pointer;
            typedef value_type const& const_reference;
            typedef value_type const* const_pointer;
            typedef std::ptrdiff_t difference_type;
        protected:
            node_pointer _node;

            void prev()
            {
                if (_node->left)
                {
                    _node = _node->left;
                    while (_node->right)
                        _node = _node->right;
                }
                else
                {
                    _node = _node->parent;
                }
            }

            void next()
            {
                if (_node->right)
                {
                    _node = _node->right;
                    while (_node->left)
                        _node = _node->left;
                }
                else
                {
                    node_pointer tmp = _node;
                    _node = _node->parent;
                    while (_node && _node->right == tmp)
                    {
                        tmp = _node;
                        _node = _node->parent;
                    }
                }
            }
        
        public:
            MapIterator() : _node(nullptr) {}
            MapIterator(node_pointer node) : _node(node) {}
            MapIterator(MapIterator const &other) : _node(other._node) {}
            virtual ~MapIterator() {}

            node_pointer getNode() const { return _node; }

            MapIterator &operator=(MapIterator const &other)
            {
                _node = other._node;
                return *this;
            }

            reference operator*() { return _node->value; }
            const_reference operator*() const { return _node->value; }
            pointer operator->() { return &_node->value; }
            const_pointer operator->() const { return &_node->value; }
            MapIterator &operator++()
            {
                next();
                return *this;
            }
            MapIterator operator++(int)
            {
                MapIterator tmp(*this);
                next();
                return tmp;
            }
            MapIterator &operator--()
            {
                prev();
                return *this;
            }
            MapIterator operator--(int)
            {
                MapIterator tmp(*this);
                prev();
                return tmp;
            }
            MapIterator &operator+=(int n)
            {
                if (n > 0) {
                    for (int i = 0; i < n; i++)
                        next();
                }
                else {
                    for (int i = n; i > 0; i--)
                        prev();
                }
                return *this;
            }
            MapIterator operator+(int n) const
            {
                MapIterator tmp(*this);
                return tmp += n;
            }
            MapIterator &operator-=(int n)
            {
                operator+=(-n);
                return *this;
            }
            MapIterator operator-(int n) const
            {
                MapIterator tmp(*this);
                return tmp -= n;
            }
            bool operator==(MapIterator const &other) const
            {
                return _node == other._node;
            }
            bool operator!=(MapIterator const &other) const
            {
                return _node != other._node;
            }
            bool operator<(MapIterator const &other) const
            {
                return _node < other._node;
            }
            bool operator<=(MapIterator const &other) const
            {
                return _node <= other._node;
            }
            bool operator>(MapIterator const &other) const
            {
                return _node > other._node;
            }
            bool operator>=(MapIterator const &other) const
            {
                return _node >= other._node;
            }
            
    };

}



#endif