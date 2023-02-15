#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

    template <class T, class Container = ft::vector<T> >
    class stack {
    public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;
    private:
        container_type _ctnr;

    public:
        explicit stack(const container_type &ctnr = container_type()) : _ctnr(ctnr) {};
        ~stack() {
            this->_ctnr.clear();
            for (size_type i = 0; i < this->_ctnr.size(); ++i)
                this->_ctnr.pop_back();
        };
        stack& operator=(const stack &rhs) {
            if (this != &rhs)
                this->_ctnr = rhs._ctnr;
            return *this;
        };
        // Element access
        reference top() {return _ctnr.back();};
        const_reference top() const {return _ctnr.back();};
        container_type ctnr() const {return _ctnr;};
        // Capacity
        bool empty() const {return _ctnr.empty();};
        size_type size() const {return _ctnr.size();};
        // Modifiers
        void push(const value_type &val) {_ctnr.push_back(val);};
        void pop() {_ctnr.pop_back();};
        void swap(stack &x) {
            container_type tmp = x._ctnr;
            x._ctnr = this->_ctnr;
            this->_ctnr = tmp;
        };
    };
    template <class T, class Container>
    void swap(stack<T, Container> &x, stack<T, Container> &y) {
        x.swap(y);
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.ctnr() == rhs.ctnr();
    };
    template <class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.ctnr() != rhs.ctnr();
    };
    template <class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.ctnr() < rhs.ctnr();
    };
    template <class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.ctnr() <= rhs.ctnr();
    };
    template <class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.ctnr() > rhs.ctnr();
    };
    template <class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.ctnr() >= rhs.ctnr();
    }

};

#endif
