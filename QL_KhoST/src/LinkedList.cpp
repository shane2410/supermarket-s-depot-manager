#include "../include/LinkedList.h"
#include "../include/HangHoa.h"

template <typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> bool asc(int a, int b) { return a > b; }
template <typename T> bool desc(int a, int b) { return a < b; }
template <typename T>
LinkedList<T>::LinkedList() : pHead(nullptr), pTail(nullptr) {}

template <typename T> LinkedList<T>::~LinkedList() {
    while (pHead != nullptr) {
        deleteFirst();
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other)
    : pHead(nullptr), pTail(nullptr) {
    pHead = nullptr;
    pTail = nullptr;
    for (Node<T> *current = other.pHead; current != nullptr;
         current = current->pNext) {
        addLast(current->data);
    }
}

template <typename T> void LinkedList<T>::addFirst(const T &data) {
    Node<T> *newNode = new Node(data);
    if (pHead == nullptr) {
        pHead = pTail = newNode;
    } else {
        newNode->pNext = pHead;
        pHead = newNode;
    }
}

template <typename T> void LinkedList<T>::addLast(const T &data) {
    Node<T> *newNode = new Node(data);
    if (pHead == nullptr) {
        pHead = pTail = newNode;
    } else {
        pTail->pNext = newNode;
        pTail = newNode;
    }
}

template <typename T>
template <typename KeyType>
bool LinkedList<T>::addAfter(const KeyType &targetkey, const T &newData) {
    Node<T> *current = pHead;
    while (current != nullptr && current->data.getKey != targetkey) {
        current = current->pNext;
    }
    if (current != nullptr) {
        Node<T> *newNode = new Node(newData);
        newNode->pNext = current->pNext;
        current->pNext = newNode;
        if (current == pTail) {
            pTail = newNode;
        }
        return true;
    }
    return false;
}

template <typename T> void LinkedList<T>::add(const T &data) { addLast(data); }

template <typename T> void LinkedList<T>::deleteFirst() {
    if (pHead == nullptr)
        return;
    Node<T> *temp = pHead;
    pHead = pHead->pNext;
    delete temp;
    if (pHead == nullptr)
        pTail = nullptr;
}

template <typename T> void LinkedList<T>::deleteLast() {
    if (pHead == nullptr)
        return;
    if (pHead == pTail) {
        delete pHead;
        pHead = pTail = nullptr;
        return;
    }
    Node<T> *current = pHead;
    while (current->pNext != pTail) {
        current = current->pNext;
    }
    delete pTail;
    pTail = current;
    pTail->pNext = nullptr;
}

template <typename T>
bool LinkedList<T>::deletebyCond(bool (*condition)(const T &, const string &),
                                 const string &Key) {
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
        } else {
            prev->pNext = current->pNext;
        }
        if (current->pNext == nullptr)
            pTail = prev;
    }
    delete current;
    size--;
    return true;
}
template <typename T> bool LinkedList<T>::remove(T &data) {
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
template <typename T> void LinkedList<T>::sort(CompareFunc compare) {
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

template <typename T>
ostream &operator<<(ostream &os, const LinkedList<T> &list) {
    //  maHH, tenHH, donViTinh, giaNhap, giaBan, soLuongTon, maNCC, ngaySanXuat,
    //  hanSuDung
    int getw[] = {12, 30, 12, 15, 15, 10, 12, 12, 12};
    const int TOTAL_WIDTH =
        getw[0] + getw[1] + getw[2] + getw[4] + getw[5] + getw[8] + 19;
    if (list.pHead == nullptr) {
        os << "Danh sach hang hoa rong." << endl;
        return os;
    }

    os << string(TOTAL_WIDTH, '-') << endl;
    os << "| " << left << setw(getw[0]) << "Ma HH"
       << " | " << setw(getw[1]) << "Ten Hang Hoa"
       << " | " << setw(getw[2]) << "DVT"
       << " | " << right << setw(getw[4]) << "Gia Ban (VND)"
       << " | " << setw(getw[5]) << "SL Ton"
       << " | " << left << setw(getw[8]) << "Han Su Dung"
       << " |" << endl;
    os << string(TOTAL_WIDTH, '-') << endl;

    Node<T> *current = list.pHead;
    while (current != nullptr) {
        HangHoa hh = current->data;
        os << "| " << left << setw(getw[0]) << hh.getMaHH() << " | ";

        string padding = "| " + string(getw[0], ' ') + " | ";

        HangHoa::printWrappedString(os, hh.getTenHH(), getw[1], padding);

        os << " | " << setw(getw[2]) << hh.getDonViTinh() << " | " << right
           << setw(getw[4]) << fixed << setprecision(0) << hh.getGiaBan()
           << " | " << setw(getw[5]) << hh.getSoLuongTon() << " | " << left
           << setw(getw[8]) << hh.getHanSuDung() << " |" << endl;

        current = current->pNext;
    }

    os << string(TOTAL_WIDTH, '-') << endl;

    return os;
}