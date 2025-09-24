
#include <iostream>
using namespace std;

typedef bool (*CompareFunc)(int, int);
bool asc(int a, int b);
bool desc(int a, int b);

#ifndef Linkedlist_h
#define Linkedlist_h
#include "HangHoa.h"
#include "Node.h"

template <typename T> class Linkedlist : HangHoa {
  private:
    Node<T> *pHead;
    Node<T> *pTail;
    int size;

  public:
    Linkedlist();
    ~Linkedlist();
    int getSize() const;
    Linkedlist(const Linkedlist &other);
    void addFirst(const T &data);
    void addLast(const T &data);
    template <typename KeyType>
    bool addAfter(const KeyType &targetKey, const T &newData);
    void add(const T &data);
    void deleteFirst();
    void deleteLast();
    template <typename KeyType>
    bool deletebyCond(bool (*condition)(const T &, const string &),
                      const string &Key);
    bool remove(T &data);
    Node<T> *getHead() const;
    Node<T> *getTail() const;
    void sort(CompareFunc compare);
    template <typename U>
    friend ostream &operator<<(ostream &os, const Linkedlist<U> &list);
};
#endif
