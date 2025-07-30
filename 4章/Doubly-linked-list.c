
#include <stdio.h>
#include <stdlib.h>

// ノードを定義（双方向連結リスト用）
typedef struct Node {
    int data;
    struct Node* next; // 次のノードへのポインタ
    struct Node* prev; // 前のノードへのポインタ
} Node;

// 新しいノードを作成
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // メモリを確保
    newNode->data = data; // データを初期化
    newNode->next = NULL; // 次のポインタを初期化
    newNode->prev = NULL; // 前のポインタを初期化
    return newNode;
}

// Insert
void insertAt(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) { // 先頭に挿入する場合
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        Node* temp = *head;
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            return; // 指定位置がリストの範囲外の場合は挿入しない
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Delete
void deleteAt(Node** head, int position) {
    if (*head == NULL) {
        return; // リストが空の場合は何もしない
    }
    Node* temp = *head;
    if (position == 0) { // 先頭のノードを削除
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    } else {
        for (int i = 0; temp != NULL && i < position; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            return; // 指定位置がリストの範囲外の場合は削除しない
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
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

//リストを表示
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("操作を選択してください (1: 挿入, 2: 削除, 3: 表示, 4: 探索, 0: 終了): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("挿入する値と位置: ");
                scanf("%d %d", &value, &position);
                insertAt(&head, value, position);
                break;
            case 2:
                printf("削除する位置: ");
                scanf("%d", &position);
                deleteAt(&head, position);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("探索する値: ");
                scanf("%d", &value);
                position = find(head, value);
                if (position >= 0) {
                    printf("値 %d は位置 %d にあります。\n", value, position);
                } else {
                    printf("値 %d はリストにありません。\n", value);
                }
                break;
            case 0:
                printf("プログラムを終了します。\n");
                return 0;
            default:
                printf("無効な選択です。\n");
        }
    }
}