#pragma once
#include <iostream>
#include <utility>


template<typename T>
class Node {
public:
    T value;
    Node* next;
    explicit Node(T val) : value(val),  next(nullptr) {}
};
template<typename T>
class LinkedList{
public:
  explicit LinkedList():first(nullptr),last(nullptr){}
    LinkedList(const std::initializer_list<T> list):first(nullptr),last(nullptr) {
      for (auto it: list) {
          push_back(it);
      }
  }
    LinkedList(const size_t size, const T val)
    {
      this->first=nullptr;
      this->last=nullptr;
      for(size_t i=0;i<size;i++) {
          push_back(val);
      }
    }
    LinkedList(const LinkedList& other) : first(nullptr), last(nullptr) {
        Node<T>* tmp = other.first;
        while (tmp != nullptr) {
            push_back(tmp->value);
            tmp = tmp->next;
        }
    }
    LinkedList(LinkedList&& other)  noexcept : first(other.first), last(other.last) {
        other.first = nullptr;
        other.last = nullptr;
    }
    LinkedList& operator=(LinkedList&& other) {
        if (this != &other) {
            first = other.first;
            last = other.last;
            other.first = nullptr;
            other.last = nullptr;
        }
    }
    ~LinkedList() {
        clear();
    }
    LinkedList& operator=(const LinkedList& other) {
            if (this != &other) {
                clear();
                Node<T>* tmp = other.first;
                while (tmp != nullptr) {
                    push_back(tmp->value);
                    tmp = tmp->next;
                }
            }
            return *this;
        }

    void push_back(const T& value_)
    {
        emplace_back(value_);
    }
    void push_back(T&& value_) {
        emplace_back(value_);
    }
    template<class... Args>
    void emplace_back(Args&&...args)
    {
        Node<T>* tmp = new Node<T>(T(std::forward<Args>(args)...));
        if (first == nullptr) {
            first = last = tmp;
        } else {
            last->next = tmp;
            last = tmp;
        }
    }
    void pop_back() {
      Node<T>* tmp = first;
      while (tmp->next!=last) {
          tmp = tmp->next;
      }
      delete last;
      last = tmp;
      last->next = nullptr;
  }
    void push_front(const T value_) {
      auto tmp = new Node<T>(value_);
      tmp->value = value_;
      tmp->next = first;
      first = tmp;
  }
    void pop_front() {
      auto tmp = first->next;
      delete first;
      first = tmp;
  }
    [[nodiscard]] T front() const {
      return first->value;
  }
    [[nodiscard]] T back() const {
      return last->value;
  }
    void display() const
    {
      Node<T>* tmp = first;
      while (tmp!=nullptr) {
          std::cout << tmp->value << " ";
          tmp = tmp->next;
      }
        std::cout << std::endl;
     }
    void clear() {
        auto tmp = first;
        while (tmp!=nullptr) {
            first = tmp->next;
            delete tmp;
            tmp=first;
        }
        first=nullptr;
    }
    [[nodiscard]] size_t size() const {
        Node<T>* tmp = first;
        size_t size = 0;
        while (tmp!=nullptr){
            tmp=tmp->next;
            size++;
        }
        return size;
    }
private:
Node<T>* first;
Node<T>* last;
};
