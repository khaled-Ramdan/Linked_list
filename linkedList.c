#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *head = NULL;
void Append(int);
void insert_at_first(int);
void insert_at_any_position(int, int);
void delete_at_first(void);
void delete_at_last(void);
void delete_by_value(int);
void delete_by_position(int);
void research(int);
void Reverse(void);
void isempyt(void);
void display(void);
void main(void) {

    return;
}
void Append(int val) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)head = newnode;
    else {
        node *temp = head;
        while (temp->next != NULL)temp = temp->next;
        temp->next = newnode;
    }
    return;
}
void insert_at_first(int val) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    return;
}
void insert_at_any_position(int val, int pos) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    if (pos == 0){
        newnode->next = head;
        head = newnode;
        return;
    }
    node *temp = head;
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++)temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
    return;
}
void delete_at_first() {
    if (head == NULL)return;
    node *temp = head;
    head = head->next;
    free(temp);
    return;
}
void delete_at_last() {
    if (head == NULL)return;
    node *temp = head;
    if (head->next == NULL) {
        head = head->next;
        free(temp);
        return;
    }
    while (temp->next->next != NULL)temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return;
}
void delete_by_value(int val) {
    node *temp = head;
    if (head->data == val) {
        head = head->next;
        free(temp);
        return;
    }
    node *prev = NULL;
    while (temp != NULL && temp->data != val ) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)return;
    prev->next = temp->next;
    free(temp);
    return;
}
void delete_by_position(int pos) {
    node *temp = head;
    if (pos == 0) {
        head = head->next;
        free(temp);
        return;
    }
    node *prev = NULL;
    for (int i = 0; i < pos && temp!= NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)return;
    prev->next = temp->next;
    free(temp);
    return;
    // another method
    /*if (head == NULL)return;
    node *temp = head;
    if (pos == 0) {
        head = head->next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++)temp = temp->next;
    if (temp->next == NULL)return;
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return;*/
}
void research(int val) {
    if (head == NULL) {
        puts("It is Empty");
        return;
    }
    node *temp = head;
    while (temp != NULL && temp->data != val)temp = temp->next;
    if (temp == NULL)puts("Not Found");
    else puts("Found");
    return;
}
void Reverse() {
    node *curr = head, *prev = NULL;
    while (head->next != NULL) {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    head->next = prev;
    return;
}
void isempty() {
    if (head == NULL)puts("Empty");
    else puts("Not Empty");
    return;
}
void display() {
    node *temp = head;
    while (temp != NULL){
        printf ("%d\t", temp->data);
        temp = temp->next;
    }
    puts("");
    return;
}
