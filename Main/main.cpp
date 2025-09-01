#include <iostream>
#include <utility>
template<typename T>
class Node{
public:
    T value;
    Node* next;
};
template<typename T>
class LinkedList{
public:
    void is_empty() const {
        if (first == nullptr)
            std::cout<<"list is empty"<<std::endl;
        else
            std::cout<<"list is full"<<std::endl;
    }
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
    LinkedList(const LinkedList& other) {
      this->first=other.first;
      this->last=other.last;
  }
    LinkedList& operator=(const LinkedList& other) {
      if (this!=&other) {
          delete this->first;
          delete this->last;
          this->first=other.first;
          this->last=other.last;
      }
      return *this;
  }
  void push_back(const T value_)
    {
      Node<T>* tmp = new Node<T>();
      if (first==nullptr) {
          tmp->value = value_;
          tmp->next = nullptr;
          first = tmp;
          last = tmp;
      }
      tmp->value = value_;
      tmp->next = nullptr;
      last->next=tmp;
      last = tmp;
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
      auto tmp = new Node<T>();
      tmp->value = value_;
      tmp->next = first;
      first = tmp;
  }
    void pop_front() {
      auto tmp = first->next;
      delete first;
      first = tmp;
  }
    [[nodiscard]] size_t front() const {
      return first->value;
  }
    [[nodiscard]] size_t back() const {
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
    }
private:
Node<T>* first;
Node<T>* last;
};
int main()
{
    LinkedList list={"gho","sdka","sakk"};
    list.p
    list.display();

return 0;
}