#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

#endif //PROJECT_VECTOR_H
#include <iostream>

template<typename T>
class Vector {
public:
    Vector();

    explicit Vector(const size_t sz);

    Vector(const Vector& rhs);

    Vector(const size_t sz,const T& value);

    ~Vector();

    void swap(Vector<T>& other) noexcept ;

    Vector& operator=(const Vector& rhs);

    Vector(Vector&& rhs) noexcept;

    Vector& operator=(Vector&& rhs) noexcept;

    Vector(std::initializer_list<T> il);

    Vector& operator=(std::initializer_list<T> il) ;

    const T& operator[](size_t index) const ;

    T& operator[](size_t index);

    const T& at(size_t index) const;

    T& at(size_t index);

    void reserve(const size_t sz);

    void push_back(T&& value);

    void pop_back();

    const T& front() const;

    const T& back() const;

    [[nodiscard]] size_t  size_() const;

    [[nodiscard]] size_t  capacity_() const ;

    void print() const;
private:
    T* data;
    size_t size;
    size_t capacity;
};