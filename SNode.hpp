#ifndef SNODE_HPP
#define SNODE_HPP

template<typename T>
class SNode {
private:
    T element{};
    SNode<T>* next;
public:
    // Constructor.
    explicit SNode(T element);

    // Pre: -
    // Post: returns a pointer to the next node.
    SNode<T>* get_next();

    // Pre: -
    // Post: changes the pointer to the next pointer.
    void set_next(SNode<T>* new_next);

    // Pre: -
    // Post: returns the stored element.
    T get_element();

    // Destructor.
    ~SNode();
};

template<typename T>
SNode<T>::SNode(T element) {
    this->element = element;
    next = nullptr;
}

template<typename T>
SNode<T> *SNode<T>::get_next() {
    return next;
}

template<typename T>
void SNode<T>::set_next(SNode<T> *new_next) {
    next = new_next;
}

template<typename T>
T SNode<T>::get_element() {
    return element;
}

template<typename T>
SNode<T>::~SNode() {
    next = nullptr;
}

#endif //SNODE_HPP