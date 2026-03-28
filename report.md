# 1. Max/Min Heap

## 解題說明

作業要求實作一個類似以下的程式，用於定義最小優先權佇列 MinPQ。

然後繼承該抽象類別的 C++ 類別 MinHeap，實作 MinPQ 的所有函式。

每個函數的複雜度應與 MaxPQ 中對應函數的複雜度相同。

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

## 解題想法

### 1️⃣ 先定義一個抽象類別 MinPQ，具備以下操作：

  。 IsEmpty()：判斷是否為空
    
  。 Top()：取得最小元素
    
  。 Push()：插入元素
    
  。 Pop()：刪除最小元素

### 2️⃣ MinHeap 實作



建立 MinHeap 類別，繼承 MinPQ，並用陣列模擬二元樹

儲存方式

  。 使用陣列 heap[ ]

  。 index 從 1 開始

  。 關係：

      父節點：i / 2
    
      左子節點：2 * i
    
      右子節點：2 * i + 1

### 3️⃣ 插入（Push)

  1. 將新元素放在最後
  2. 與父節點比較
  3. 若較小則交換

### 4️⃣ 刪除（Pop）

 1. 用最後一個元素取代根節點
 2. 與較小的子節點比較
 3. 若較大則交換並往下調整

### 5️⃣ 取得最小值（Top）
  
  直接回傳 heap[1]

### 6️⃣ 測試方式

在 main() 中：

  。 插入數值（30, 10, 20, 5)
  
  。 印出 Heap
  
  。 取得最小值
  
  。 刪除後再印結果

## Min Heap 程式實作

以下為主程式

```cpp
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
```

## 效能分析

### 時間複雜度

|操作	    | 時間複雜度  |
|---------|------------|
|Push	    |**O(log n)**|
|Pop	    |**O(log n)**|
|Top	    |**O(1)**    |
|IsEmpty	|**O(1)**    |

### 空間複雜度

以資料數量 n 表示：O(n)


### 效能量測

。 Push 與 Pop 皆為排序中的「上浮」與「下沉」，時間複雜度均為 O(log n)。

。 隨資料量增加，耗時呈現對數增長。

。 Top 與 IsEmpty 操作耗時極低，可視為 O(1)。

。 空間複雜度為 O(n)，主要由固定大小的陣列儲存元素所佔。

## 測試與驗證

### 輸入

    

### 輸出

    

## 申論及開發報告

### 心得討論

在這份程式中，我實作了最小堆（MinHeap），並透過 Push、Pop 及 Top 等操作，觀察堆的運作過程。透過這次實作，我體會到二元堆積維持最小值在根節點的原理，以及 Push 與 Pop 的操作如何確保每次堆都是最小堆結構。從測試結果可以看出，Push 與 Pop 會自動調整元素順序，使最小值永遠保持在頂端，操作流程直觀且高效。此外，Print 函式幫助我理解堆中元素的實際排列方式，對理解堆排序與優先隊列有很大幫助。

### 總結

總之，MinHeap 是一個高效、結構明確的資料結構，適合需要快速取得最小值的情境。在本程式中，Push 與 Pop 操作正確維護了堆序，使 Top 能立即回傳最小元素。透過實作與測試，我不僅加深了對二元堆積運作原理的理解，也了解了優先隊列的基本操作與特性，為排序、排程或演算法問題打下了良好的基礎。

# 2. Binary Search Tree

## 解題說明



## 解題想法



## Min Heap 程式實作

以下為主程式

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int x) {
    if (!root) return new Node{x, nullptr, nullptr};
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* del(Node* root, int k) {
    if (!root) return nullptr;
    if (k < root->data)
        root->left = del(root->left, k);
    else if (k > root->data)
        root->right = del(root->right, k);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* m = findMin(root->right);
        root->data = m->data;
        root->right = del(root->right, m->data);
    }
    return root;
}

void in(Node* root) {
    if (root) {
        in(root->left);
        cout << root->data << " ";
        in(root->right);
    }
}

int main() {
    int a[] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    for (int n : a) {
        Node* root = nullptr;
        for (int i = 0; i < n; i++)
            root = insert(root, rand());
        cout << n << " " << height(root) / log2(n) << endl;
    }

    Node* root = nullptr;
    int b[] = {50,30,70,20,40,60,80,100,10,120,90,110};
    for (int x : b)
        root = insert(root, x);
    in(root); cout << endl;
    root = del(root, 50);
    in(root); cout << endl;
}
```

## 效能分析

### 時間複雜度



### 空間複雜度



### 效能量測



## 測試與驗證

### 輸入

    

### 輸出

    

## 申論及開發報告

### 心得討論


### 總結

