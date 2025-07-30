
#include <stdio.h>
#include <stdlib.h>

// 二分探索木のノードを定義
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 新しいノードを作成
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 二分探索木にノードを挿入
Node* insert(Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// 最小値を持つノードを探す
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// 二分探索木からノードを削除
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Modified search function to output node position
Node* search(Node* root, int data, int node_position) {
    if (root == NULL) {
        printf("Node %d: Not Found\n", node_position);
        return NULL;
    }
    printf("Node %d: %d\n", node_position, root->data);
    if (root->data == data)
        return root;

    if (root->data < data)
        return search(root->right, data, 2 * node_position + 1);

    return search(root->left, data, 2 * node_position);
}


// 二分探索木を表示 (In-order traversal)
void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, data;

    while(1) {
        printf("操作を選択してください (1: 挿入, 2: 削除, 3: 表示, 4: 探索, 0: 終了):");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("挿入する値: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("削除する値: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                display(root);
                printf("\n");
                break;
            case 4:
                printf("探索する値: ");
                scanf("%d", &data);
                Node* found = search(root, data, 1);
                if (found != NULL)
                    printf("%d は二分探索木にあります\n", data);
                else
                    printf("%d は二分探索木にありません\n", data);
                break;
            case 0:
                printf("プログラムを終了します。\n");
                return 0;
            default:
                printf("無効な選択です。\n");
        }
    }

    return 0;
}
