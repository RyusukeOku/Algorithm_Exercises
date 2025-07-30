#include <stdio.h>
#define TABLE_SIZE 499 //TABLE_SIZE は素数を選ぶことで衝突を減らすことができる

//ハッシュノードの定義
struct hashNode
{
    int key;
    int value;
    struct hashNode* next;
};

//ハッシュテーブルを定義
struct hashNode* hashTable[TABLE_SIZE];

//ハッシュテーブルを初期化
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

/* ハッシュ関数の定義 */
int hashCode(int key)
{
    return key % TABLE_SIZE;
}

//insert
void insert(struct hashNode* hashTable[], int key, int value) {
    int index = hashCode(key);
    struct hashNode* newNode = (struct hashNode*) malloc(sizeof(struct hashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

//search
struct hashNode* search(struct hashNode* hashTable[], int key) {
    int index = hashCode(key);
    struct hashNode* currentNode = hashTable[index];

    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    return NULL;
}

//delete
void delete(struct hashNode* hashTable[], int key) {
    int index = hashCode(key);
    struct hashNode* node = hashTable[index];
    struct hashNode* prev = NULL;

    while (node != NULL) {
        if (node->key == key) {
            if (prev == NULL) {
                // Node to delete is the first node in the list
                hashTable[index] = node->next;
            } else {
                // Node to delete is in the middle or end
                prev->next = node->next;
            }
            free(node); // Free memory
            return;
        }
        prev = node;
        node = node->next;
    }
    printf("Key not found in hash table\n");
}

//ハッシュテーブルを表示
void printHashTable(struct hashNode* hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct hashNode* node = hashTable[i];
        while (node != NULL) {
            printf("(%d, %d) -> ", node->key, node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    //初期化
    initHashTable();

    //例として4つのキーを挿入
    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 3, 30);
    insert(hashTable, 4, 40);

    //ハッシュテーブルを表示
    printf("Hash Table after insertions:\n");
    printHashTable(hashTable);

    //キーを削除
    delete(hashTable, 3);

    //削除後のテーブルを表示
    printf("Hash Table after deletion:\n");
    printHashTable(hashTable);

    return 0;
}
