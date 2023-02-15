#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../Iterators/ReverseIterator.hpp"
#include "../Iterators/vIterators.hpp"
#include "../std_functions/std_functions.hpp"
#include <memory>
#include <algorithm>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
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
        explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _data(nullptr), _size(0), _capacity(0)
        {
        }
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _data(nullptr), _size(0), _capacity(0)
        {
            assign(n, val);
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : _alloc(alloc), _data(nullptr), _size(0), _capacity(0)
        {
            assign(first, last);
        }
        vector(const vector &x) : _alloc(x._alloc), _data(nullptr), _size(0), _capacity(0)
        {
            assign(x.begin(), x.end());
        }
        // Destructor
        ~vector()
        {
            clear();
            if (_data)
                _alloc.deallocate(_data, _capacity);
            _capacity = 0;
        }
        // Assignment operator
        vector &operator=(const vector &x)
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
            if (PTRDIFF_MAX < _alloc.max_size())
                return PTRDIFF_MAX;
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
                pointer newPointer;
                newPointer = _alloc.allocate(n);
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(newPointer + i, *(_data + i));
                    if (_data)
                        _alloc.destroy(_data + i);
                }
                if (_data)
                    _alloc.deallocate(_data, _capacity);
                _data = newPointer;
                _capacity = n;
            }
        }

        // Element access
        reference operator[](size_type n)
        {
            if (n >= _size)
                throw std::out_of_range("vector");
            return _data[n];
        }
        const_reference operator[](size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("vector");
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

        // Modifiers
        void assign(size_type n, const value_type &val)
        {
            clear();
            if (_capacity < n)
                reserve(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_data + _size++, val);
        }

        template <class Iter>
        void assign(Iter first, Iter last,
                    typename ft::enable_if<!ft::is_integral<Iter>::value && ft::is_random_access_iterator<Iter>::value, Iter>::type * = 0)
        {
            if (first == last)
            {
                clear();
                return;
            }
            clear();
            if (first > last)
                throw std::length_error("vector");
            if (_capacity < (size_type)(last - first))
                reserve(last - first);
            for (Iter it = first; it != last; it++)
                _alloc.construct(_data + _size++, *it);
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<ft::is_input_iterator<InputIterator>::value && !ft::is_random_access_iterator<InputIterator>::value, InputIterator>::type * = 0)
        {
            clear();
            for (; first != last; first++)
                push_back(*first);
        }

        void clear()
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_data + i);
            _size = 0;
        }

        void pop_back()
        {
            if (_size == 0)
                return;
            _alloc.destroy(_data + --_size);
        }

        iterator insert(iterator position, const value_type &val)
        {
            size_type i = 0;
            size_type j = 0;
            vector tmp(*this);
            size_type pos = position - begin();
            if (_size + 1 > capacity())
            {
                if (_capacity)
                    reserve(_capacity * 2);
                else
                    reserve(1);
            }
            clear();
            while (i < pos)
                _alloc.construct(_data + i++, tmp[j++]);
            _alloc.construct(_data + i++, val);
            _size = tmp.size() + 1;
            while (i < _size)
                _alloc.construct(_data + i++, tmp[j++]);
            return iterator(_data + pos);
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            if (!_size)
            {
                reserve(n);
                for (; n != 0; n--)
                    push_back(val);
            }
            else if (!n)
                return;
            else
            {
                size_type pos = position - begin();
                size_type old_size = size();
                if (_size + n > capacity())
                {
                    if (_size + n > _capacity * 2)
                        reserve(_size + n);
                    else
                        reserve(_capacity * 2);
                    position = iterator(_data + pos);
                }
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_data + _size + i, val);
                _size += n;
                iterator last = iterator(_data + old_size);
                if (pos != old_size)
                    last--;
                iterator end = iterator(_data + _size - 1);
                for (; last != position; last--, end--)
                    *end = *last;
                *end = *last;
                position += n;
                for (; last != position; last++)
                    *last = val;
            }
        }

         template <class InputIterator>
         void insert(iterator position, InputIterator first, InputIterator last,
                     typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
         {
             vector tmp;
             for (; first != last; first++)
                 tmp.push_back(*first);
             size_type pos = position - begin();
             size_type n = tmp.size();
             if (n)
             {
                 size_type old_size = size();
                 if (_size + n > capacity())
                 {
                     if (_size + n > _capacity * 2)
                         reserve(_size + n);
                     else
                         reserve(_capacity * 2);
                     position = iterator(_data + pos);
                 }
                 _size += n;
                 iterator last = iterator(_data + old_size);
                 if (pos != old_size)
                     last--;
                 iterator end = iterator(_data + _size - 1);
                 for (; last != position; last--)
                 {
                     if (end >= iterator(_data + old_size))
                         _alloc.construct(&(*end), *last);
                     else
                         *end = *last;
                     end--;
                 }
                 if (end >= iterator(_data + old_size))
                     _alloc.construct(&(*end), *last);
                 else
                     *end = *last;
                 position += n;
                 for (size_type i = 0; last != position; last++)
                 {
                     if (last >= iterator(_data + _size - n) && !(pos == old_size && _data + _size - 1 == &(*last)))
                         _alloc.construct(&(*last), tmp[i]);
                     else
                         *last = tmp[i];
                     i++;
                 }
             }
         }

        iterator erase(iterator position)
        {
            for (iterator it = position; it != end() - 1; ++it)
                *it = *(it + 1);
            pop_back();
            return (position);
        }

        iterator erase(iterator first, iterator last)
        {
            size_type n = last - first;
            for (iterator it = first; it != end() - n; ++it)
                *it = *(it + n);
            for (size_type i = 0; i < n; i++)
                pop_back();
            return (first);
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

        pointer get_data() const
        {
            return _data;
        }
        void swap(vector &x)
        {
            pointer tmp_data = _data;
            size_type tmp_size = _size;
            size_type tmp_capacity = _capacity;
            allocator_type tmp_alloc = _alloc;
            _data = x._data;
            _size = x._size;
            _capacity = x._capacity;
            _alloc = x._alloc;
            x._data = tmp_data;
            x._size = tmp_size;
            x._capacity = tmp_capacity;
            x._alloc = tmp_alloc;
        }
    };
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }
    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        size_t i = 0;
        while (i < lhs.size() && i < rhs.size())
        {
            if (lhs[i] < rhs[i])
                return true;
            else if (lhs[i] > rhs[i])
                return false;
            i++;
        }
        if (i == lhs.size() && i != rhs.size())
            return true;
        return false;
    }
    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return rhs < lhs;
    }
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }
};
#endif