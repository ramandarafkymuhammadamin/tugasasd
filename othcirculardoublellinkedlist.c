#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Fungsi untuk menambahkan node ke dalam list
void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Fungsi untuk mencetak list
void printList(Node *head) {
    if (head == NULL) return;
    Node *current = head;
    do {
        printf("Address: %p, Data: %d\n", (void*)current, current->data);
        current = current->next;
    } while (current != head);
}

// Fungsi untuk mengurutkan list secara ascending
void sortList(Node **head) {
    if (*head == NULL) return;
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != *head && ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    int N, data;
    Node *head = NULL;

    // Input jumlah data
    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    // Input data dan masukkan ke dalam list
    printf("Masukkan data:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    // Cetak list sebelum pengurutan
    printf("List sebelum pengurutan:\n");
    printList(head);

    // Urutkan list
    sortList(&head);

    // Cetak list setelah pengurutan
    printf("List setelah pengurutan:\n");
    printList(head);

    return 0;
}
