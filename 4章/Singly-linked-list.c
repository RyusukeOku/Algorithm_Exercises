#include <stdio.h>
#include <stdlib.h>

//ノードを定義
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//単方向連結リスト用のノードを定義
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//メモリを確保
    newNode->data = data;//データを初期化
    newNode->next = NULL;//ポインタの初期化
    return newNode;
}

//Insert
void insertAt(Node** head, int data, int position) {
    //新しいノードの作成
    Node* newNode = createNode(data);
    //先頭に挿入する場合
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* current = *head;
    //指定位置まで移動
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    //指定された位置が範囲内にあるかどうか判定
    if (current == NULL) {
        printf("指定された位置はリストの範囲外です。\n");
    } else {
        newNode->next = current->next;
        current->next = newNode;//ノードの挿入
    }
}

//Delete
void deleteAt(Node** head, int position) {
    if (*head == NULL) {
        printf("リストは空です。\n");//L.headにデータがないとき空であることを通知
        return;
    }
    Node* temp = *head;
    //先頭ノードの削除
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    //指定の位置まで移動
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    //指定された位置が範囲内かどうか判定
    if (temp == NULL || temp->next == NULL) {
        printf("指定された位置はリストの範囲外です。\n");
        return;
    }
    //ノードの削除
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
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
