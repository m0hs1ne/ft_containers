#ifndef BSTTREE_HPP
#define BSTTREE_HPP

#include <memory>
#include <iostream>
#include "../std_functions/pair.hpp"
#include <algorithm>

namespace ft
{

    template <class T, class Compare>
    class BSTtree
    {
    public:
        typedef size_t size_type;
        typedef T value_type;
        typedef value_type *pointer;
        typedef value_type const *const_pointer;
        typedef value_type &reference;
        typedef value_type const &const_reference;

        struct Node
        {
            value_type value;
            Node *left;
            Node *right;
            Node *parent;

            Node(const_reference val = value_type()) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
            Node(const Node &other) : value(other.value), left(other.left), right(other.right), parent(other.parent) {}
        };
        typedef Node *node_pointer;

    protected:
        node_pointer _root;
        node_pointer _end;
        node_pointer _begin;
        Compare _comp;

        void unBound(node_pointer node)
        {
            if (!node)
                return;
            node->parent = nullptr;
            node->left = nullptr;
            node->right = nullptr;
        }

        void makeBound(void)
        {
            _begin = new Node();
            _end = _begin;
            _root = _end;
        }

        void repairBounds(void)
        {
            node_pointer tmp = _root;
            while (tmp->left)
                tmp = tmp->left;
            _begin = tmp;
            tmp = _root;
            while (tmp->right)
                tmp = tmp->right;
            tmp->right = _end;
            _end->parent = tmp;
        }

        template <class T>
        node_pointer findNode(T const &val, node_pointer node)
        {
            while (node && node != _end)
            {
                if (_comp(val, node->value))
                    node = node->left;
                else if (_comp(node->value, val))
                    node = node->right;
                else
                    return node;
            }
            return nullptr;
        }

        void insertNodeAt(node_pointer node, node_pointer newNode)
        {
            while (node)
            {
                if (_comp(newNode->value, node->value))
                {
                    if (node->left)
                        node = node->left;
                    else
                    {
                        node->left = newNode;
                        newNode->parent = node;
                        return;
                    }
                }
                else
                {
                    if (node->right)
                        node = node->right;
                    else
                    {
                        node->right = newNode;
                        newNode->parent = node;
                        return;
                    }
                }
            }
            _root = newNode;
            newNode->parent = nullptr;
            newNode->left = nullptr;
            newNode->right = nullptr;
            _begin = newNode;
        }

        void copyNodeRecursively(node_pointer *des, node_pointer src, node_pointer end)
        {
            if (!src)
                return;
            *des = new Node(*src);
            if (src->left)
            {
                copyNodeRecursively(&((*des)->left), src->left, end);
                (*des)->left->parent = *des;
            }
            if (src->right && src->right != end)
            {
                copyNodeRecursively(&((*des)->right), src->right, end);
                (*des)->right->parent = *des;
            }
        }

        node_pointer eraseNode(node_pointer node)
        {
            if (!node)
                return nullptr;
            node_pointer tmp = node;
            // no children
            if (!node->left && !node->right)
            {
                if (node == _root)
                {
                    _root = _begin = _end;
                    unBound(_end);
                }

                if (node->parent)
                {
                    if (node->parent->left == node)
                        node->parent->left = nullptr;
                    else
                        node->parent->right = nullptr;
                }
                tmp = node->parent;
                delete node;
            }
            // one child (right)
            else if (!node->left)
            {
                if (node->parent)
                {
                    if (node->parent->left == node)
                        node->parent->left = node->right;
                    else
                        node->parent->right = node->right;
                }
                node->right->parent = node->parent;
                if (node == _root)
                    _root = node->right;
                tmp = node->right;
                delete node;
            }
            // one child (left)
            else if (!node->right)
            {
                if (node->parent)
                {
                    if (node->parent->left == node)
                        node->parent->left = node->left;
                    else
                        node->parent->right = node->left;
                }
                node->left->parent = node->parent;
                if (node == _root)
                    _root = node->left;
                tmp = node->parent;
                delete node;
            }
            // two children
            else
            {
                node_pointer tmp1 = node->right;
                while (tmp1 && tmp1->left != nullptr)
                    tmp1 = tmp1->left;
                if (node->parent)
                {
                    if (node->parent->left == node)
                        node->parent->left = tmp1;
                    else
                        node->parent->right = tmp1;
                }
                tmp1->parent = node->parent;
                node->value.value_type::~value_type();
                new (&node->value) value_type(tmp1->value);
                if (node == this->m_root)
                    this->m_root = node;
                node->right = erase_node(node->right);
                tmp = node;
            }
            return (tmp);
        }

        void deleteNodeRecursively(node_pointer node)
        {
            if (!node)
                return;
            deleteNodeRecursively(node->left);
            deleteNodeRecursively(node->right);
            delete node;
        }

    public:
        BSTtree() : _root(nullptr), _comp() { makeBound(); }
        BSTtree(Compare const &comp) : _root(nullptr), _comp(comp) { makeBound(); }
        BSTtree(BSTtree const &other) : _root(other._root), _comp(other._comp)
        {
            makeBound();
            copy(other);
        }
        virtual ~BSTtree()
        {
            makeEmpty();
            delete (_end);
        }

        Tree &operator=(Tree const &other)
        {
            if (_root != _end)
                makeEmpty();
            _comp = other._comp;
            copy(other);
            return *this;
        }

        void copy(Tree const &other)
        {
            if (other._root == other._end)
                return;
            _root = new Node(*other._root);
            if (other._root->left)
            {
                copyNodeRecursively(&(_root->left), other._root->left, other._end);
                _root->left->parent = _root;
            }
            if (other._root->right && other._root->right != other._end)
            {
                copyNodeRecursively(&(_root->right), other._root->right, other._end);
                _root->right->parent = _root;
            }
            repairBounds();
        }
    };
};

#endif