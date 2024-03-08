#ifndef SINGLY_LIST
#define SINGLY_LIST

#include <iostream>
#include <initializer_list>

template<typename T> 
class SinglyList {
public:   
    SinglyList();
    explicit SinglyList(T value);
    SinglyList(const SinglyList<T>& other);
    SinglyList(SinglyList<T>&& other) noexcept;
    SinglyList(const std::initializer_list<T>& init_list);
    ~SinglyList();

public:  
    template<typename U> 
    friend std::ostream& operator<<(std::ostream& out, const SinglyList<U>& obj);
    SinglyList<T>& operator=(const SinglyList<T>& other);
    SinglyList<T>& operator=(SinglyList<T>&& other) noexcept;
    bool operator!=(const SinglyList<T>& obj) const;
    bool operator==(const SinglyList<T>& obj) const;
    bool operator>(const SinglyList<T>& obj) const;
    bool operator<(const SinglyList<T>& obj) const;
    bool operator>=(const SinglyList<T>& obj) const;
    bool operator<=(const SinglyList<T>& obj) const;
    SinglyList<T> operator+=(const SinglyList<T>& obj) const;
    SinglyList<T> operator+(const SinglyList<T>& obj) const;
public: 
    int size() const;
    void clear();
    void push_front(T value);
    void push_back(T value);
    void pop_back();
    void pop_front();
    bool search(T value);
    void insert(int position, T value);
    void del(int position);
    void insert(int position, const SinglyList<T>& list);
    void reverse();
    T getMiddle();
private:  
    struct Node {
        Node* next;
        T value;
        explicit Node(T init_value);
        Node(const Node& init_node);
    };
    Node* head;
    Node* tail;
public:  
    class iterator {
        typedef std::forward_iterator_tag iterator_category; 
        friend class SinglyList;
    public: 
        iterator() : newnode(nullptr) {}
        bool operator!=(const iterator& iter) const;
        T& operator*() const {
            return newnode->value;
        }
        Node* operator->() const;
        const iterator operator++(int);
    private:  
        explicit iterator(Node* new_ptr) : newnode(new_ptr) {}
        Node* newnode;
    };
public:  
    iterator begin() const;
    iterator end() const;
    void remove_if(iterator start, iterator end, bool (func)(T));
};

template<typename U>
std::ostream& operator<<(std::ostream& out, const SinglyList<U>& obj) {
    typename SinglyList<U>::Node* current = obj.head;
    while (current != nullptr) {
        out << current->value << " ";
        current = current->next;
    }
    out << std::endl;
    return out;
}

#include "list.hpp"

#endif