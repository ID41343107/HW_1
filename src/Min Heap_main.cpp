#include <iostream>
using namespace std;

template <class T>
class MinPQ {
public:
    virtual ~MinPQ() {}
    virtual bool IsEmpty() const = 0;
    virtual const T& Top() const = 0;
    virtual void Push(const T&) = 0;
    virtual void Pop() = 0;
};

template <class T>
class MinHeap : public MinPQ<T> {
private:
    T heap[10000];
    int size;

public:
    MinHeap() { size = 0; }
    bool IsEmpty() const {
        return size == 0;
    }
    const T& Top() const {
        return heap[1];
    }
    void Push(const T& x) {
        heap[++size] = x;
        int i = size;
        while (i > 1 && heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }
    void Pop() {
        heap[1] = heap[size--];
        int i = 1;
        while (2 * i <= size) {
            int child = 2 * i;
            if (child + 1 <= size && heap[child + 1] < heap[child])
                child++;
            if (heap[i] <= heap[child]) break;
            swap(heap[i], heap[child]);
            i = child;
        }
    }
    void Print() {
        for (int i = 1; i <= size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap<int> h;
    h.Push(30);
    h.Push(10);
    h.Push(20);
    h.Push(5);
    cout << "目前: ";
    h.Print();
    cout << "Top (Min): " << h.Top() << endl;
    h.Pop();
    cout << "之後 : ";
    h.Print();
    return 0;
}
