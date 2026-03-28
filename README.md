# Homework 1
## 1. Max/Min Heap
Write a C++ abstract class similar to ADT 5.2 for the ADT MinPQ, which defines a min priority queue. Now write a C++ class MinHeap that derives from this abstract class and implements all the virtual functions of MinPQ. The complexity of each function should be the same as that for the corresponding function of MaxНеар.

### ADT 5.2
```cpp
template <class T>
class MaxPQ {
public:
virtual MaxPQ() {}
// virtual destructor
virtual bool IsEmpty () const = 0;
// return true iff the priority queue is empty
virtual const T& Top () const = 0;
// return reference to max element
virtual void Push(const T&) = 0;
// add an element to the priority queue
virtual void Pop () = 0;
// delete element with max priority
};
```

## 2. Binary Search Tree

(a)  Write a program to start with an initially empty binary search tree and make n random insertions. Use a uniform random number generator to obtain the values to be inserted. Measure the height of the resulting binary search tree and divide this height by log2n. Do this for n = 100, 500, 1000, 2000, 3000,..., 10,000. Plot the ratio height log2n as a function of n. The ratio should be approximately constant (around 2). Verify that this is So.

(b)  Write a C++ function to delete the pair with key k from a binary search tree. What is the time complexity of your function?
