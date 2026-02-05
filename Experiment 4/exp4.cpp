#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int heapSize = 0;
int heap[MAX];

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insert(int val) {
    if (heapSize == MAX) {
        cout << "Heap full" << endl;
        return;
    }
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heapSize && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void deleteMin() {
    if (heapSize == 0) {
        cout << "Heap empty" << endl;
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

void deleteAt(int i) {
    if (i < 0 || i >= heapSize) {
        cout << "Invalid index" << endl;
        return;
    }

    heap[i] = heap[heapSize - 1];
    heapSize--;

    heapifyDown(i);
    heapifyUp(i);
}

void printHeap() {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printHeap();

    deleteAt(2);
    printHeap();

    deleteMin();
    printHeap();

    return 0;
}
