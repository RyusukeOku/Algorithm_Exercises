
#include <stdio.h>
#include <stdlib.h>

//ノードを定義
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//単方向連結リスト用のノードを定義
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); //メモリを確保
    newNode->data = data; //データを初期化
    newNode->next = NULL; //ポインタの初期化
    return newNode;
}

// Stackの先頭に要素を追加する
void push(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Stackの先頭から要素を削除し、その値を返す
int pop(Node** head) {
    if (*head == NULL) {
        printf("underflow");
        return -1;
    }
    Node* temp = *head;
    int popped = temp->data;
    *head = temp->next;
    free(temp);
    return popped;
}

//Search
int find(Node* head, int data) {
    Node* current = head;//最初の要素から探索を始める
    int position = 0;
    while (current != NULL) {
        if (current->data == data) {
            return position;//dataと等しくなったときのpositionを返す
        }
        current = current->next;
        position++;
    }
    return -1;
}

// Stackの内容を表示する
void showStack(Node** head) {
    Node* current = *head;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* S = NULL; // Stackの初期化
    int sw, n;

    while(1) {
        printf("0:push 1:pop 2:exit \n:");
        scanf("%d", &sw);
        switch(sw) {
            case 0:
                printf("pushする数: ");
                scanf("%d", &n);
                push(&S, n);
                showStack(&S);
                break;
                
            case 1: 
                printf("%d\n", pop(&S));
                showStack(&S);
                break;

            case 2: 
                exit(0); 
                break;
        }
    }
    return 0;
}
