#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <utility>


namespace myvector {

template<typename T>
class Vector{
public:
    Vector():data(nullptr),size(0),capacity(0){}
    explicit Vector<T>(const size_t sz)
    {
        size=sz;
        capacity=size;
        data=new T[capacity];
    }
    Vector(const Vector& rhs)
    {
        size=rhs.size;
        capacity=rhs.capacity;
        data=new T[capacity];
        for (size_t i=0;i<size;i++) {
            new (data+i) T(rhs.data[i]);
        }

    }
    Vector(const size_t sz,const T& value) {
        size=sz;
        capacity=size;
        data=new T[capacity];
        for (size_t i=0;i<size;i++) {
            new (data+i) T(value);
        }
    }
    void swap(Vector<T>& other) noexcept {
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        std::swap(data, other.data);
    }
    Vector& operator=(const Vector& rhs) { //
        if (this != &rhs) {
            Vector temp(rhs);
            swap(temp);
        }
        return *this;
    }
    Vector(Vector&& rhs) noexcept {
        swap( rhs);
        rhs.size=0;
        rhs.capacity=0;
        rhs.data=nullptr;
    }
    Vector& operator=(Vector&& rhs)  noexcept {
        Vector temp(std::move(rhs));
        swap(temp);
        return *this;
    }
    Vector(std::initializer_list<T> il) {
        size=il.size();
        capacity=size;
        data=new T[capacity];
        for (size_t i=0;i<size;i++) {
            new (data+i) T(il.begin()[i]);
        }
    }
    Vector& operator=(std::initializer_list<T> il) {

            Vector tmp(il);
            swap(*this,tmp);
            return *this;
    }

    virtual ~Vector() {
        for (size_t i=0;i<size;i++) {
            data[i].~T();
        }
        delete[] data;
    }
    const T& operator[](size_t index) const {
        return data[index];
    }
    T& operator[](size_t index)  {
        return data[index];
    }

    const T& at(size_t index) const {
        if (index>=size) throw std::out_of_range("index out of range");
        return data[index];
    }
    T& at(size_t index)  {
        if (index>=size) throw std::out_of_range("index out of range");
        return data[index];
    }
    void reserve(const size_t sz) {
        if (sz<=capacity) {return;}
        T* newData=new T[sz];
        for (size_t i=0;i<size;i++) {
            new (newData+i) T(std::move(data[i]));
        }
        delete[] data;
        data=newData;
        capacity=sz;
    }
    template<class... Args >
        void emplace_back( Args&&... args ) {
        if (size==capacity) {
            reserve(capacity*2);
        }
        new (data+size) T(std::forward<Args>(args)...);
        size++;
    }
    void push_back(const T& value) {
      emplace_back(value);
    }
    void push_back(T&& value) {
        emplace_back(value);
    }

    void pop_back() {
        (data+size-1)->~T();
        size--;
    }
     const T& front() const {
        if (size==0) {
            throw std::out_of_range("empty list");
        }
        return data[0];
    }
    const T& back() const {
        if (size==0) {
            throw std::out_of_range("empty list");
        }
        return data[size-1];
    }

     [[nodiscard]] size_t  size_() const {
        return size;
    }
    [[nodiscard]] size_t  capacity_() const {
        return capacity;
    }

private:
    T* data;
    size_t size;
    size_t capacity;
};
}
#endif