#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

QueueNode* createQueueNode(Node* treeNode) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, Node* treeNode) {
    QueueNode* newQueueNode = createQueueNode(treeNode);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node* currentNode = dequeue(queue);
        printf("%d ", currentNode->data);

        if (currentNode->left != NULL) {
            enqueue(queue, currentNode->left);
        }
        if (currentNode->right != NULL) {
            enqueue(queue, currentNode->right);
        }
    }
    free(queue);
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter the values to insert into the BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Level Order Traversal of BST:\n");
    levelOrderTraversal(root);

    return 0;
}
