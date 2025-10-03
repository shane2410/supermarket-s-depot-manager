#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "HangHoa.h" // Add this line to include the HangHoa class definition
#include "Node.h"
#include <iomanip>
#include <iostream>
#include <string>

template <typename T> class LinkedList;
template <typename T> bool asc(int a, int b) { return a > b; }
template <typename T> bool desc(int a, int b) { return a < b; }
typedef bool (*CompareFunc)(int, int);

template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list);

template <typename T> class LinkedList {
  private:
    Node<T> *pHead;
    Node<T> *pTail;
    int size;

  public:
    LinkedList() : pHead(nullptr), pTail(nullptr), size(0) {}

    LinkedList(const LinkedList &other)
        : pHead(nullptr), pTail(nullptr), size(0) {
        for (Node<T> *current = other.pHead; current != nullptr;
             current = current->pNext) {
            addLast(current->data);
        }
    }

    ~LinkedList() {
        while (pHead != nullptr) {
            deleteFirst();
        }
    }

    int getSize() const { return size; }
    Node<T> *getHead() const { return pHead; }
    Node<T> *getTail() const { return pTail; }

    void addFirst(const T &data) {
        Node<T> *newNode = new Node<T>(data);
        if (pHead == nullptr) {
            pHead = pTail = newNode;
        } else {
            newNode->pNext = pHead;
            pHead = newNode;
        }
        size++;
    }

    void addLast(const T &data) {
        Node<T> *newNode = new Node<T>(data);
        if (pHead == nullptr) {
            pHead = pTail = newNode;
        } else {
            pTail->pNext = newNode;
            pTail = newNode;
        }
        size++;
    }

    void deleteFirst() {
        if (pHead == nullptr)
            return;
        Node<T> *temp = pHead;
        pHead = pHead->pNext;
        delete temp;
        if (pHead == nullptr)
            pTail = nullptr;
        size--;
    }

    void deleteLast() {
        if (pHead == nullptr)
            return;
        if (pHead == pTail) {
            delete pHead;
            pHead = pTail = nullptr;
        } else {
            Node<T> *current = pHead;
            while (current->pNext != pTail) {
                current = current->pNext;
            }
            delete pTail;
            pTail = current;
            pTail->pNext = nullptr;
        }
        size--;
    }
    bool remove(T &data) {
        if (pHead == nullptr)
            return false;
        if (pHead->data == data) {
            deleteFirst();
            return true;
        }
        Node<T> *prev = pHead;
        while (prev->pNext != nullptr && prev->pNext->data != data) {
            prev = prev->pNext;
        }
        if (prev->pNext != nullptr) {
            Node<T> *del = prev->pNext;
            prev->pNext = del->pNext;
            if (del == pTail) {
                pTail = prev;
            }
            delete del;
            return true;
        }
        return false;
    }

    bool deletebyCond(bool (*condition)(const T &, const std::string &),
                      const std::string &Key) {
        if (pHead == nullptr)
            return false;

        Node<T> *current = pHead;
        Node<T> *prev = nullptr;

        while (current != nullptr && !condition(current->data, Key)) {
            prev = current;
            current = current->pNext;
        }

        if (current == nullptr)
            return false;

        if (prev == nullptr) {
            pHead = current->pNext;
            if (pHead == nullptr) {
                pTail = nullptr;
            }
        } else {
            prev->pNext = current->pNext;
            if (current->pNext == nullptr) {
                pTail = prev;
            }
        }

        delete current;
        size--;
        return true;
    }

    void sort(CompareFunc compare) {
        if (pHead == nullptr)
            return;
        for (Node<T> *i = pHead; i != nullptr; i = i->pNext) {
            for (Node<T> *j = i->pNext; j != nullptr; j = j->pNext) {
                if (compare(i->data, j->data)) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    friend std::ostream &operator<< <>(std::ostream &os,
                                       const LinkedList<T> &list);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
    if (list.getHead() == nullptr) {
        os << "Danh sach rong.\n";
        return os;
    }
    int getw[] = {8, 20, 8, 12, 12, 8, 12, 9, 9};
    const int TOTAL_WIDTH =
        getw[0] + getw[1] + getw[2] + getw[4] + getw[5] + getw[8] + 26;
    if (list.pHead == nullptr) {
        os << "Danh sách hàng hóa rỗng." << endl;
        return os;
    }
    string padding = "| " + string(getw[0], ' ') + " | ";
    os << string(TOTAL_WIDTH, '-') << endl;
    os << "| " << left << setw(getw[0]) << "Mã HH" << " | ";

    HangHoa::printWrappedString(os, "Tên HH", getw[1], padding);

    os << " | " << setw(getw[2]) << "ĐVT" << " | " << right << setw(getw[4])
       << fixed << setprecision(0) << "Giá Bán" << " | " << setw(getw[5])
       << "SL Tồn" << " | " << right << setw(getw[8]) << "HSD" << " |" << endl;
    os << string(TOTAL_WIDTH, '-') << endl;

    Node<T> *current = list.pHead;
    while (current != nullptr) {
        HangHoa hh = current->data;
        os << "| " << left << setw(getw[0]) << hh.getMaHH() << " | ";

        HangHoa::printWrappedString(os, hh.getTenHH(), getw[1], padding);

        os << " | " << setw(getw[2]) << hh.getDonViTinh() << " | " << right
           << setw(getw[4]) << fixed << setprecision(0) << hh.getGiaBan()
           << " | " << setw(getw[5]) << hh.getSoLuongTon() << " | " << right
           << setw(getw[8]) << hh.getHanSuDung() << " |" << endl;

        current = current->pNext;
    }

    os << string(TOTAL_WIDTH, '-') << endl;

    return os;
}

#endif // LINKEDLIST_H