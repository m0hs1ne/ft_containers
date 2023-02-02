#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../Iterators/ReverseIterator.hpp"
#include "../Iterators/vIterators.hpp"
#include "../std_functions/std_functions.hpp"
#include <memory>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class Vector
    {
    public:
        typedef Allocator allocator_type;
        typedef typename allocator_type::value_type value_type;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef ft::VectorIterator<value_type> iterator;
        typedef ft::VectorIterator<const value_type> const_iterator;
        typedef ft::ReverseIterator<iterator> reverse_iterator;
        typedef ft::ReverseIterator<const_iterator> const_reverse_iterator;

    private:
        allocator_type _alloc;
        pointer _data;
        size_type _size;
        size_type _capacity;

    public:
        // Constructors
        explicit Vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _data(nullptr), _size(0), _capacity(0) {}
        explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _data(nullptr), _size(0), _capacity(0)
        {
            assign(n, val);
        }
        template <class InputIterator>
        Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : _alloc(alloc), _data(nullptr), _size(0), _capacity(0)
        {
            assign(first, last);
        }
        Vector(const Vector &x) : _alloc(x._alloc), _data(NULL), _size(0), _capacity(0)
        {
            assign(x.begin(), x.end());
        }
        // Destructor
        ~Vector()
        {
            clear();
            if (_data)
                _alloc.deallocate(_data, _capacity);
            _capacity = 0;
        }
        // Assignment operator
        Vector &operator=(const Vector &x)
        {
            if (this != &x)
                assign(x.begin(), x.end());
            return *this;
        }
        // Iterators
        iterator begin()
        {
            return iterator(_data);
        }
        const_iterator begin() const
        {
            return const_iterator(_data);
        }
        iterator end()
        {
            return iterator(_data + _size);
        }
        const_iterator end() const
        {
            return const_iterator(_data + _size);
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        // Capacity
        size_type size() const
        {
            return _size;
        }
        size_type max_size() const
        {
            return _alloc.max_size();
        }
        void resize(size_type n, value_type val = value_type())
        {
            if (n == 0)
            {
                clear();
                return;
            }
            if (n > _size)
            {
                if (n > _capacity)
                {
                    if (_capacity * 2 > n)
                        reserve(_capacity * 2);
                    else
                        reserve(n);
                }
                for (size_type i = _size; i < n; i++)
                    push_back(val);
                _size = n;
            }
            else if (n < _size)
            {
                for (size_type i = n; i < _size; i++)
                    _alloc.destroy(_data + i);
                _size = n;
            }
        }
        size_type capacity() const
        {
            return _capacity;
        }
        bool empty() const
        {
            return _size == 0;
        }
        void reserve(size_type n)
        {
            if (n > _capacity)
            {
                pointer tmp = _alloc.allocate(n);
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(tmp + i, _data[i]);
                    _alloc.destroy(_data + i);
                }
                _alloc.deallocate(_data, _capacity);
                _data = tmp;
                _capacity = n;
            }
        }

        // Element access
        reference operator[](size_type n)
        {
            return _data[n];
        }
        const_reference operator[](size_type n) const
        {
            return _data[n];
        }
        reference at(size_type n)
        {
            if (n >= _size)
                throw std::out_of_range("out of range");
            return _data[n];
        }
        const_reference at(size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("out of range");
            return _data[n];
        }
        reference front()
        {
            return _data[0];
        }
        const_reference front() const
        {
            return _data[0];
        }
        reference back()
        {
            return _data[_size - 1];
        }
        const_reference back() const
        {
            return _data[_size - 1];
        }
        value_type *data()
        {
            return _data;
        }
        const value_type *data() const
        {
            return _data;
        }

        // Modifiers
        void assign(size_type n, const value_type &val)
        {
            size_type tmp = _capacity;
            clear();
            _capacity = tmp;
            if (_capacity < n)
                reserve(n);
            _data = _alloc.allocate(_capacity);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_data + _size++, val);
        }

        template <class Iter>
        void assign(Iter first, Iter last,
                    typename ft::enable_if<!ft::is_integral<Iter>::value && std::__is_random_access_iterator<Iter>::value, Iter>::type * = 0)
        {
            if(first == last)
            {
                _size = 0;
                return;
            }
            size_type tmp = _capacity;
            clear();
            _capacity = tmp;
            if (first > last)
                throw std::length_error("vector");
            if (_capacity < (size_type)(last - first))
                reserve(last - first);
            _data = _alloc.allocate(_capacity);
            for (Iter it = first; it != last; it++)
                _alloc.construct(_data + _size++, *it);
        }

        void clear()
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_data + i);
            _data = NULL;
            _size = 0;
            _capacity = 0;
        }

        void push_back(const value_type &val)
        {
            if (_size == _capacity)
            {
                if (_capacity == 0)
                    reserve(1);
                else
                    reserve(_capacity * 2);
            }
            _alloc.construct(_data + _size++, val);
        }

        // Allocator
        allocator_type get_allocator() const
        {
            return _alloc;
        }
    };
}

#endif