#include <stdio.h>
#include <stdlib.h>
#define max 10

/* キューの定義 */
struct queue {
	int Q[max];/*キューを格納する配列*/
	int head, tail;/*top[Q], tail[Q]*/
};


// キューを初期化する関数
void init(struct queue *q) {
    for (int i = 0; i < max; i++) {
        q->Q[i] = 0; // Q配列を0で初期化
    }
    q->head = 0; // headを0に設定
    q->tail = 0; // tailを0に設定
}

void enqueue(struct queue *q, int i){
    if ((q->tail + 1) % max == q->head)
    {
        printf("overflow");/*容量を超えるとoverflow*/
    }
    else
    {
        q->Q[q->tail] = i;
        q->tail = (q->tail + 1) % max;
    }
}

int dequeue(struct queue *q){
    if (q->head == q->tail)
    {
        printf("underflow");/*Qが空だとunderflow*/
        return -1;
    }
    else
    {
        int x = q->Q[q->head];
        q->head = (q->head + 1) % max;
        return x;
    }
}

void showQueue(struct queue *q){
    printf("Queue: ");
    for (int i = q->head; i != q->tail; i = (i + 1) % max) {
        printf("%d ", q->Q[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int sw, n;
    
    struct queue Q;
    init(&Q);
    
    while(1){
        printf("0: Enqueue 1: Dequeue 2: Exit\n:");
        scanf("%d",&sw);
        switch(sw){
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
}