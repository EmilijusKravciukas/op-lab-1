#pragma once

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Vector {
    public:
        using value_type = T;
        using size_type = size_t;
        using iterator = T*;
        using const_iterator = const T*;

        Vector() : _size(0), _capacity(1), _data(new T[_capacity]) {}

        explicit Vector(size_type count) : _size(count), _capacity(count), _data(new T[count]) {
            std::fill(_data, _data + _size, T());
        }

        Vector(std::initializer_list<T> init) 
            : _size(init.size()), _capacity(init.size()), _data(new T[_capacity]) {
            std::copy(init.begin(), init.end(), _data);
        }

        ~Vector() {
            delete[] _data;
        }

        Vector(const Vector& other) : _size(other._size), _capacity(other._capacity), _data(new T[other._capacity]) {
            std::copy(other._data, other._data + other._size, _data);
        }

        Vector(Vector&& other) noexcept : _size(other._size), _capacity(other._capacity), _data(other._data) {
            other._size = 0;
            other._capacity = 0;
            other._data = nullptr;
        }

        Vector& operator=(const Vector& other) {
            if (this != &other) {
                delete[] _data;
                _size = other._size;
                _capacity = other._capacity;
                _data = new T[_capacity];
                std::copy(other._data, other._data + other._size, _data);
            }
            return *this;
        }

        Vector& operator=(Vector&& other) noexcept {
            if (this != &other) {
                delete[] _data;
                _size = other._size;
                _capacity = other._capacity;
                _data = other._data;
                other._size = 0;
                other._capacity = 0;
                other._data = nullptr;
            }
            return *this;
        }

        void push_back(const T& value) {
            if (_size >= _capacity) {
                _resize(_capacity * 2);
            }
            _data[_size++] = value;
        }

        void pop_back() {
            if (_size > 0) {
                --_size;
            } else {
                throw std::out_of_range("Vector is empty");
            }
        }

        T& operator[](size_type index) {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }

        const T& operator[](size_type index) const {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }

        T& back() {
            if (_size == 0) {
                throw std::out_of_range("Vector is empty");
            }
            return _data[_size - 1];
        }

        const T& back() const {
            if (_size == 0) {
                throw std::out_of_range("Vector is empty");
            }
            return _data[_size - 1];
        }

        size_type size() const {
            return _size;
        }

        size_type capacity() const {
            return _capacity;
        }

        bool empty() const {
            return _size == 0;
        }

        iterator begin() {
            return _data;
        }

        const_iterator begin() const {
            return _data;
        }

        iterator end() {
            return _data + _size;
        }

        const_iterator end() const {
            return _data + _size;
        }

        iterator erase(iterator pos) {
            if (pos < begin() || pos >= end()) {
                throw std::out_of_range("Iterator out of range");
            }
            std::copy(pos + 1, end(), pos);
            --_size;
            return pos;
        }

        iterator erase(iterator first, iterator last) {
            if (first < begin() || last > end() || first >= last) {
                throw std::out_of_range("Invalid iterator range");
            }
            std::copy(last, end(), first);
            _size -= (last - first);
            return first;
        }

        void shrink_to_fit() {
            if(_size < _capacity) {
                _capacity = _size;
            }
        }

    private:
        size_type _size;
        size_type _capacity;
        T* _data;

        void _resize(size_type new_capacity) {
            T* new_data = new T[new_capacity];
            std::copy(_data, _data + _size, new_data);
            delete[] _data;
            _data = new_data;
            _capacity = new_capacity;
        }
};