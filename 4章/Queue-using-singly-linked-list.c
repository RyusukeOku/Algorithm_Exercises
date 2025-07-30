
#include <stdio.h>
#include <stdlib.h>

// ノードを定義
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// キューを定義
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// 単方向連結リスト用のノードを作成
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// キューを初期化
void init(Queue* q) {
    q->front = q->rear = NULL;
}

// キューの末尾に要素を追加
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// キューの先頭から要素を削除し、その値を返す
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = q->front;
    int dequeued = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return dequeued;
}

// キューの内容を表示
void showQueue(Queue* q) {
    Node* current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue Q;
    init(&Q);
    int sw, n;

    while(1){
        printf("0: Enqueue 1: Dequeue 2: Exit\n:");
        scanf("%d", &sw);
        switch(sw) {
            case 0:
                printf("Enqueueする数: ");
                scanf("%d", &n);
                enqueue(&Q, n);
                showQueue(&Q);
                break;
                
            case 1: 
                printf("Dequeued: %d\n", dequeue(&Q));
                showQueue(&Q);
                break;
                
            case 2: 
                exit(0);
                break;
        }
    }

    return 0;
}
