#include <iostream>
#include <initializer_list>
#include "list.h"

template <typename T>
void SinglyList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr; 
}

template <typename T> 
SinglyList<T>::SinglyList() {
    head = nullptr;
    tail = head;
}

template <typename T> 
SinglyList<T>::SinglyList(T value) {
    head = new Node(value);
    head->value = value;
}

template <typename T> 
SinglyList<T>::SinglyList(const SinglyList<T>& other) : head(nullptr) {
    Node* current = head;
    while (current != nullptr) {
        Node* node = new Node(current->value);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        current = current->next;
    }
}

template <typename T> 
SinglyList<T>::SinglyList(SinglyList<T>&& other) noexcept : head(other.head), tail(other.tail){
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T> 
SinglyList<T>::SinglyList(const std::initializer_list<T>& init) {
    head = new Node(*init.begin());
    Node* tmp = head;
    for (auto it = init.begin() + 1; it != init.end(); ++it) {
        tmp->next = new Node(*it);
        tmp = tmp->next;
        tail = tmp;
    }
}

template <typename T> 
SinglyList<T>::~SinglyList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
SinglyList<T>::Node::Node(T init_value) : value{init_value}, next{nullptr} {}

template <typename T> 
SinglyList<T>::Node::Node(const SinglyList::Node& other_node) : value{other_node.value}, next{nullptr} {}

template <typename T>  
SinglyList<T>& SinglyList<T>::operator=(const SinglyList<T>& other) {
    if (&other != this) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>  
SinglyList<T>& SinglyList<T>::operator=(SinglyList<T>&& other) noexcept{
    if (&other != this) {
        clear();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

template <typename T> 
bool SinglyList<T>::operator!=(const SinglyList<T>& obj) const {
    if (size() != obj.size()) {
        return true;
    }
    Node* current1 = head;
    Node* current2 = obj.head;

    while (current1 != nullptr and current2 != nullptr) {
        if (current1->value != current2->value) {
            return true;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return false;
}

template <typename T>
bool SinglyList<T>::operator==(const SinglyList<T>& obj) const {
    if (size() != obj.size()) {
        return false;
    }
    Node* current1 = head;
    Node* current2 = obj.head;

    while (current1 != nullptr and current2 != nullptr) {
        if (current1->value != current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}


template <typename T>
bool SinglyList<T>::operator>(const SinglyList<T>& obj) const {
    Node* current1 = head;
    Node* current2 = obj.head;
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->value > current2->value) {
            return true;
        } 
        else if (current1->value < current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return (current1 == nullptr && current2 != nullptr);
}

template <typename T>
bool SinglyList<T>::operator<(const SinglyList<T>& obj) const {
    Node* current1 = head;
    Node* current2 = obj.head;
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->value < current2->value) {
            return true;
        } 
        else if (current1->value > current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return (current1 == nullptr && current2 != nullptr);
}

template <typename T> 
SinglyList<T> SinglyList<T>::operator+(const SinglyList<T>& obj) const {
    SinglyList<T> result(*this);
    Node* current = obj.head;
    while (current != nullptr) {
        result.push_back(current->value);
        current = current->next;
    }
    return result;
}

template <typename T>
bool SinglyList<T>::operator>=(const SinglyList<T>& obj) const {
    Node* current1 = head;
    Node* current2 = obj.head;
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->value >= current2->value) {
            return true;
        } else if (current1->value < current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return (current1 == nullptr && current2 != nullptr);
}

template <typename T>
bool SinglyList<T>::operator<=(const SinglyList<T>& obj) const {
    Node* current1 = head;
    Node* current2 = obj.head;
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->value <= current2->value) {
            return true;
        } 
        else if (current1->value > current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return (current1 == nullptr && current2 != nullptr);
}

template <typename T> 
SinglyList<T> SinglyList<T>::operator+=(const SinglyList<T>& obj) const {
    Node* current = obj.head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
    return *this;
}

template <typename T>  
int SinglyList<T>::size() const {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template <typename T>  
void SinglyList<T>::push_back(T value){
    Node* node = new Node(value);

    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

template <typename T>  
void SinglyList<T>::push_front(T value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->next = head;
        head = node;
    }
}

template <typename T>  
void SinglyList<T>::pop_back() {
    if (head == nullptr) {
        return;
    }
    else if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* current = head;
        while (current != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
}

template <typename T>  
void SinglyList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* current = head;
        head = current->next;
        delete current;
        current = nullptr;
    }
}

template <typename T> 
bool SinglyList<T>::search(T value) {
    Node* tmp = head;
    while (tmp != nullptr) {
        if (tmp->value == value) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template <typename T>  
void SinglyList<T>::insert(int position, T value) {
    if (position < 0 || position >= size()) {
        return;
    }
    if (position == 0) {
        push_front(value);
    }
    else if (position == size()) {
        push_back(value);
    }
    else {
        Node* node = new Node(value);
        Node* current = head;
        for (int i {0}; i < position - 1; ++i) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

template <typename T>  
void SinglyList<T>::del(int position) {
    if (position < 0 or position >= size()) {
        return;
    }
    if (position == 0) {
        pop_front();
    }
    else if (position == size() - 1) {
        pop_back();
    }
    else {
        Node* current = head;
        for (int i {0}; i < position - 1; ++i) {
            current = current->next;
        }
        Node* tmp = current->next;
        current->next = tmp->next;
        delete tmp;
    }
}

template <typename T>  
void SinglyList<T>::insert(int position, const SinglyList<T>& other) {
    if (position < 0 or position > size()) {
        return;
    }
    if (other.size() == 0) {
        return;
    }
    if (position == 0) {
        Node* current = other.head;
        while (current != nullptr) {
            push_front(current->value);
            current = current->next;
        }
    }
    else if (position == size()) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }
    else {
        Node* current = head;
        for (int i {0}; i < position - 1; ++i) {
            current = current->next;
        }
        Node* other_head = other.head;
        while (other_head != nullptr) {
            Node* node = new Node(other_head->value);
            node->next = current->next;
            current->next = node;
            current= node;
            other_head = other_head->next;
        }
    }
}

template <typename T>  
void SinglyList<T>::reverse() {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }
}

template <typename T> 
T SinglyList<T>::getMiddle() {
    Node* fast = head;
    Node* slow = head;
    while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

template <typename T>
typename SinglyList<T>::Node* SinglyList<T>::iterator::operator->() const {
    return newnode;
}

template <typename T>
const typename SinglyList<T>::iterator SinglyList<T>::iterator::operator++(int) {
    iterator old = *this;
    newnode = newnode->next;
    return old;
}

template <typename T>
bool SinglyList<T>::iterator::operator!=(const SinglyList<T>::iterator& iter) const {
    return newnode != iter.newnode;
}

template <typename T> 
typename SinglyList<T>::iterator SinglyList<T>::begin() const{
    return iterator(head);
}

template <typename T> 
typename SinglyList<T>::iterator SinglyList<T>::end() const {
    return iterator(tail);
}

template <typename T>  
void SinglyList<T>::remove_if(SinglyList<T>::iterator start, SinglyList<T>::iterator end, bool (func)(T)) {
    Node* prev = nullptr;
    Node* current = start.newnode;
    while (current != nullptr && current != end.newnode) {
        if (func(current->value)) {
            Node* tmp = current;
            current = current->next;
            if (prev != nullptr) {
                prev->next = current;
                if (tmp == tail) {
                    tail = prev;
                }
            } else {
                head = current;
                if (tmp == tail) {
                    tail = nullptr;
                }
            }
            delete tmp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}
