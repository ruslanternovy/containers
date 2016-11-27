#include <stdio.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

void run_reverse();
Node *reverse(Node *head);

int main()
{
    run_reverse();
    return 0;
}

void print(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void run_reverse() {
    Node node2 = {2, NULL};
    Node node1 = {1, &node2};
    Node node0 = {0, &node1};
    Node *head = &node0;

    print(head);
    head = reverse(head);
    print(head);
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *next;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

