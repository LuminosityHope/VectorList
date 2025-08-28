#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template<typename T>
class Vector {
public:
    Vector():data(nullptr),size(0),capacity(0){}
    explicit Vector(const size_t sz)
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
        for (size_t i=0;i<size;i++)
        {
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
    Vector& operator=(const Vector& rhs) {
        if (this!=&rhs) {
            size=rhs.size;
            capacity=rhs.capacity;
            data=new T[capacity];
            for (size_t i=0;i<size;i++)
            {
                new (data+i) T(rhs.data[i]);
            }
        }
        return *this;
    }
    Vector(Vector&& rhs) noexcept {
        size=rhs.size;
        capacity=rhs.capacity;
        data=new T[capacity];
        for (size_t i=0;i<size;i++) {
            new (data+i) T(std::move(rhs.data[i]));
        }
        rhs.size=0;
        rhs.capacity=0;
        rhs.data=nullptr;
    }
    Vector(std::initializer_list<T> il) {
        size=il.size();
        capacity=size;
        data=new T[capacity];
        for (size_t i=0;i<size;i++) {
            new (data+i) T(std::move(il.begin()[i]));
        }
    }
    Vector& operator=(std::initializer_list<T> il) {
        if (this!=&il) {
            size=il.size();
            capacity=size;
            data=new T[capacity];
            for (size_t i=0;i<size;i++) {
                new (data+i) T(std::move(il.begin()[i]));
            }
        }
        return *this;
    }
    ~Vector() {
        delete[] data;
    }
    const Vector& operator[](size_t index) const {
        return data[index];
    }

    [[nodiscard]]Vector& at(size_t index) const {
        if (index>=size) throw std::out_of_range("index out of range");
        return data[index];
    }
    void reserve(const size_t sz) {
        if (sz<=capacity) {return;}
        T* newdata=reinterpret_cast<T*>(new char(sz*sizeof(T)));
        for (size_t i=0;i<size;i++) {
            new (newdata+i) T(std::move(data[i]));
        }
        for (size_t i=0;i<size;i++) {
            data[i].~T();
        }
        delete [] reinterpret_cast<char*>(data);
        data=newdata;
        capacity=sz;
    }
    void push_back(T&& value) {
        if (size==capacity) {
            capacity*=2;
        }
        data[size++]=std::move(value);
    }
    void pop_back() {
        (data+size)->~T();
        size--;
    }

     [[nodiscard]] size_t  size_() const {
        return size;
    }
    [[nodiscard]] size_t  capacity_() const {
        return capacity;
    }
    void print() const {
        if (size>0) {
            for (size_t i=0;i<size;i++) {
                std::cout << data[i] << " ";
            }
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    }

private:
    T* data;
    size_t size;
    size_t capacity;
};
int main() {
    Vector<int> tmp;
    std::vector<int> v;
    tmp.reserve(2);
    v.reserve(10);
    tmp.push_back(4);
    std::cout<<v.size()<<" ";
    std::cout<<v.capacity()<<" ";
    std::cout<<"size:"<<tmp.size_()<<" ";
    std::cout<<"cap:"<<tmp.capacity_()<<std::endl;
    std::string test;
    tmp.print();
return 0;
}