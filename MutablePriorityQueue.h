#ifndef PROJECT2GRAPHS_MUTABLEPRIORITYQUEUE_H
#define PROJECT2GRAPHS_MUTABLEPRIORITYQUEUE_H

#include <vector>
#include <functional>

///This class contains information and implementation for a mutable priority queue.

template <class T>
class MutablePriorityQueue {
    std::vector<T *> H;
    void heapifyUp(unsigned i);
    void heapifyDown(unsigned i);
    inline void set(unsigned i, T * x);
    std::function<bool(const T*, const T*)> compare;
public:
    MutablePriorityQueue();
    void insert(T * x);
    T * extractMin();
    void decreaseKey(T * x);
    bool empty();
    bool contains(T *x);
};

// Index calculations
#define parent(i) ((i) / 2)
#define leftChild(i) ((i) * 2)

template <class T>
MutablePriorityQueue<T>::MutablePriorityQueue() {
    H.push_back(nullptr);
    compare = [](const T* a, const T* b) {
        return *a < *b;
    };
}

template <class T>
bool MutablePriorityQueue<T>::empty() {
    return H.size() == 1;
}

template <class T>
T* MutablePriorityQueue<T>::extractMin() {
    T* minElement = H[1];
    H[1] = H.back();
    H.pop_back();
    if (H.size() > 1) {
        heapifyDown(1);
    }
    minElement->queueIndex = 0;
    return minElement;
}


template <class T>
void MutablePriorityQueue<T>::insert(T *x) {
    H.push_back(x);
    decreaseKey(x);
}

template <class T>
void MutablePriorityQueue<T>::decreaseKey(T *x) {
    heapifyUp(x->queueIndex);
}

template <class T>
void MutablePriorityQueue<T>::heapifyUp(unsigned i) {
    T* x = H[i];
    while (i > 1 && compare(x, H[parent(i)])) {
        set(i, H[parent(i)]);
        i = parent(i);
    }
    set(i, x);
}

template <class T>
void MutablePriorityQueue<T>::heapifyDown(unsigned i) {
    T* x = H[i];
    while (true) {
        unsigned k = leftChild(i);
        if (k >= H.size())
            break;
        if (k + 1 < H.size() && compare(H[k + 1], H[k]))
            ++k; // right child of i
        if (!compare(H[k], x))
            break;
        set(i, H[k]);
        i = k;
    }
    set(i, x);
}


template <class T>
void MutablePriorityQueue<T>::set(unsigned i, T* x) {
    H[i] = x;
    x->queueIndex = i;
}

template <class T>
bool MutablePriorityQueue<T>::contains(T *x) {
    return x->queueIndex != 0;
}




#endif //PROJECT2GRAPHS_MUTABLEPRIORITYQUEUE_H
