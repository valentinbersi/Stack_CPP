#ifndef STACK_HPP
#define STACK_HPP

#include <exception>
#include "SNode.hpp"

class EmptyException : public std::exception {
public:
    const char *what() const noexcept override {
            return "The stack is empty.";
    }
};

template<typename T>
class Stack {
private:
    SNode<T> *last_node;
    size_t _size;

    const size_t EMPTY = 0;

public:
    // Constructor.
    Stack();

    // Copy constructor
    Stack(const Stack<T> &stack);

    // Assignment operator
    [[nodiscard]] Stack<T> &operator=(const Stack<T> &stack);

    // Pre: -
    // Post: adds the element at the end of the stack.
    void add(T new_element);

    // Pre: the stack can´t be empty.
    // Post: removes the last element and returns it.
    T remove();

    // Pre: the stack can´t be empty.
    // Post: returns the last element in the stack.
    [[nodiscard]] T last();

    // Pre: -
    // Post: returns the number of elements in the stack.
    [[nodiscard]] size_t size();

    // Pre: -
    // Post: returns true if the stack is empty.
    [[nodiscard]] bool empty();

    // Destructor.
    ~Stack();
};

template<typename T>
Stack<T>::Stack() {
    last_node = nullptr;
    _size = EMPTY;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &stack) {
    last_node = nullptr;
    _size = EMPTY;

    Stack<T> aux;
    SNode<T> *current_node = stack.last_node;

    while(current_node){
        aux.add(current_node->get_element());
        current_node = current_node->get_next();
    }

    while (!aux.empty()) {
        add(aux.remove());
    }
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &stack) {
    Stack<T> aux1(stack);

    last_node = nullptr;
    _size = EMPTY;

    Stack<T> aux2;
    SNode<T> *current_node = aux1.last_node;

    while(current_node){
        aux2.add(current_node->get_element());
        current_node = current_node->get_next();
    }

    while (!aux2.empty()) {
        add(aux2.remove());
    }

    return *this;
}

template<typename T>
void Stack<T>::add(T new_element) {
    if (size() == EMPTY) {
        last_node = new SNode<T>(new_element);

    } else {
        auto *new_node = new SNode<T>(new_element);
        last_node->set_next(new_node);
        last_node = new_node;
    }

    _size++;
}

template<typename T>
T Stack<T>::remove() {
    if (empty()) throw EmptyException();

    SNode<T> *removed_node = last_node;
    last_node = removed_node->get_next();
    T removed_element = removed_node->get_element();
    delete removed_node;
    _size--;
    return removed_element;
}

template<typename T>
T Stack<T>::last() {
    if (empty()) throw EmptyException();

    return last_node->get_element();
}

template<typename T>
size_t Stack<T>::size() {
    return _size;
}

template<typename T>
bool Stack<T>::empty() {
    return _size == EMPTY;
}

template<typename T>
Stack<T>::~Stack<T>() {
    while (!empty()) {
        remove();
    }
}

#endif //STACK_HPP
