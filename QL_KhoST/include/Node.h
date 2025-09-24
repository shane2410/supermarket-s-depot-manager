#ifndef Node_h
#define Node_h
template <typename T>

struct Node {
    T data;
    Node<T> *pNext;
    Node(const T &val) : data(val), pNext(nullptr) {}
};
#endif