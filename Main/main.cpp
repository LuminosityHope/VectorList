#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template<typename T>
class Vector {
public:
    Vector():data(nullptr),size(0),capacity(0){std::cout<<"Null"<<std::endl;}
    explicit Vector<T>(const size_t sz) //+
    {
        size=sz;
        capacity=size;
        data=new T[capacity];
    }
    Vector(const Vector& rhs) //+
    {
        size=rhs.size;
        capacity=rhs.capacity;
        data=new T[capacity];
        for (size_t i=0;i<size;i++)
        {
            new (data+i) T(rhs.data[i]);
        }
        std::cout<<"Vector copy constructor"<<std::endl;

    }
    Vector(const size_t sz,const T& value) { //+
        size=sz;
        capacity=size;
        data=new T[capacity];
        for (size_t i=0;i<size;i++) {
            new (data+i) T(value);
        }
        std::cout<<"Created Vector"<<std::endl;
    }
    void swap(Vector<T>& other) noexcept {
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        std::swap(data, other.data);
    }
    Vector& operator=(const Vector& rhs) { //
        Vector temp(rhs);
        swap(temp);
        std::cout<<"Operator assigned"<<std::endl;
        return *this;
    }
    Vector(Vector&& rhs) noexcept {
        swap(*this, rhs);
        rhs.size=0;
        rhs.capacity=0;
        rhs.data=nullptr;
        std::cout<<"Move constructor"<<std::endl;
    }
    Vector(std::initializer_list<T> il) {
        size=il.size();
        capacity=size;
        data=new T[capacity];
        for (size_t i=0;i<size;i++) {
            new (data+i) T(il.begin()[i]);
        }
        std::cout<<"initializer list"<<std::endl;
    }
    Vector& operator=(std::initializer_list<T> il) {

            Vector tmp(il);
            swap(*this,tmp);
            std::cout<<"copy init list"<<std::endl;
            return *this;
    }
    ~Vector() {
        for (size_t i=0;i<size;i++) {
            data[i].~T();
        }
        std::cout<<"destroy list"<<std::endl;
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
        T* newData=reinterpret_cast<T*>(new char[sz*sizeof(T)]);
        for (size_t i=0;i<size;i++) {
            new (newData+i) T(std::move(data[i]));
        }
        for (size_t i=0;i<size;i++) {
            data[i].~T();
        }
        delete [] reinterpret_cast<char*>(data);
        data=newData;
        capacity=sz;
    }
    void push_back(T&& value) {
        if (size==capacity) {
           reserve(capacity*2);
        }
        data[size]=T(std::move(value));
        size++;
    }
    void pop_back() {
        (data+size)->~T();
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
    void print() const {
            for (size_t i=0;i<size;i++) {
                std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    T* data;
    size_t size;
    size_t capacity;
};
int main() {
    Vector<int> hold={4,5,1,7,6,9,2,1};
    hold.push_back(6);
    std::cout<<"size:"<<hold.size_()<<" ";
    std::cout<<"cap:"<<hold.capacity_()<<std::endl;
    hold.print();
    hold.pop_back();
    hold.reserve(20);
    int m=hold.front();
    std::cout<<m<<std::endl;
    std::cout<<"size:"<<hold.size_()<<" ";
    std::cout<<"cap:"<<hold.capacity_()<<std::endl;
    hold.print();
return 0;
}