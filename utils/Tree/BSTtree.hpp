#ifndef BSTTREE_HPP
#define BSTTREE_HPP


#include <memory>
#include <iostream>
#include "../std_functions/pair.hpp"
#include <algorithm>


namespace ft{

    template <class T, class Compare>
    class BSTtree
    {
        public:
            typedef size_t size_type;
            typedef T value_type;
            typedef value_type* pointer;
            typedef value_type const* const_pointer;
            typedef value_type& reference;
            typedef value_type const& const_reference;

            struct Node
            {
                value_type value;
                Node *left;
                Node *right;
                Node *parent;

                Node(const_reference val=value_type()) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
                Node(const Node &other) : value(other.value), left(other.left), right(other.right), parent(other.parent) {}
            };
            typedef Node* node_pointer;
            protected:
            node_pointer _root;
            node_pointer _end;
            node_pointer _begin;
            Compare _comp;

            void _unBound(node_pointer node)
            {
                if(!node)
                    return;
                node->parent = nullptr;
                node->left = nullptr;
                node->right = nullptr;
            }
    };
}





#endif