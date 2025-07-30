#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 要素を表す構造体
typedef struct {
    int data;    // 整数データ
    float key;   // 優先度（float）
} Element;

// ヒープを表す構造体
typedef struct {
    Element *array; // 要素の配列
    int size;       // 現在のヒープのサイズ
    int capacity;   // ヒープの容量
} PriorityQueue;

// ヒープの初期化
PriorityQueue* initializePriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (Element*)malloc(capacity * sizeof(Element));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void max_heapify(PriorityQueue* pq, int i) {
    int l, r, largest;
    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if ((l < pq->size) && (pq->array[l].key > pq->array[i].key)) {
        largest = l;
    }

    if ((r < pq->size) && (pq->array[r].key > pq->array[largest].key)) {
        largest = r;
    }

    if (largest != i) {
        int temp = pq->array[i].key;
        pq->array[i].key = pq->array[largest].key;
        pq->array[largest].key = temp;
        max_heapify(pq, largest);
    }
}

//Increase-key
void increaseKey(Element a[], int i, float key) {
    if (key < a[i].key) {
        printf("新しいキーは現在のキーより小さい");
    }

    a[i].key = key;
    int parent = (i - 1) / 2; //親ノードの番号は子ノードの番号を2で割ったときの商

    if (parent >= 0)
    {
        if (a[i].key > a[parent].key)
        {
            int temp = a[i].key;
            a[i].key = a[parent].key;
            a[parent].key = temp;
            increaseKey(a, parent, key);
        }
    }
}

//Extract-Max
Element extractMax(PriorityQueue* pq) {
    if (pq->size < 1) {
        printf("ヒープアンダーフロー");
    }

    Element max = pq->array[0];
    pq->array[0].key = pq->array[pq->size - 1].key;

    pq->size = pq->size - 1;

    max_heapify(pq, 0);

    return max;
}

//Insert
void insert(PriorityQueue* pq, Element e) {
    if (pq->size == pq->capacity) {
        printf("挿入ができません\n");
        return;
    }
    pq->size = pq->size + 1;
    pq->array[pq->size].key = INT_MIN;
    pq->array[pq->size - 1].key = e;

    increaseKey(pq, pq->size - 1, e);
}

//Maximum
Element maximum(PriorityQueue* pq) {
    return pq->array[0];
}

// ヒープの解放
void freePriorityQueue(PriorityQueue* pq) {
    free(pq->array);
    free(pq);
}

int main() {
    // 優先度付きキューの使用
    PriorityQueue* pq = initializePriorityQueue(10);

    // Insert
    Element e1 = {1, 5.0};
    Element e2 = {2, 3.0};
    Element e3 = {3, 7.0};

    insert(pq, e1);
    insert(pq, e2);
    insert(pq, e3);

    // Maximum
    Element max = maximum(pq);
    printf("Maximum: %d (Key: %f)\n", max.data, max.key);

    // Extract-Max
    Element extractedMax = extractMax(pq);
    printf("Extracted Maximum: %d (Key: %f)\n", extractedMax.data, extractedMax.key);

    // Increase-Key
    increaseKey(pq, 1, 8.0);

    // Maximum after Increase-Key
    max = maximum(pq);
    printf("Maximum after Increase-Key: %d (Key: %f)\n", max.data, max.key);

    // ヒープの解放
    freePriorityQueue(pq);

    return 0;
}