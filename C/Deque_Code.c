#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Deque{
    Node* head;
    Node* tail;
}Deque;

void init_Deque(Deque *D){
    D->head = NULL;
    D->tail= NULL;
}

void input_head(Deque *D, int x){
    Node *new  = (Node *)malloc(sizeof (Node));
    if(D->head == NULL){
        D->head = new;
        D->tail = new;
        new->data = x;
        new->next = NULL;
        new->prev = NULL;
        return;
    }

    D->head->next = new;
    new->prev = D->head;
    new->next = NULL;
    new->data = x;
    D->head = new;
}

void input_tail(Deque *D, int x){
    Node *new  = (Node *)malloc(sizeof (Node));
    if(D->tail == NULL){
        D->tail = new;
        D->head = new;
        new->data = x;
        new->next = NULL;
        new->prev = NULL;
        return;
    }

    D->tail->prev = new;
    new->next = D->tail;
    new->prev = NULL;
    new->data = x;
    D->tail = new;
}

int output_head(Deque *D){

    if(D->head == NULL){
        printf("The Deque is Empty!\n");
        return -1;
    }
    Node* p;
    p = D->head;
    int res = D->head->data;

    D->head = D->head->prev;
    D->head->next = NULL;
    free(p);

    return res;
}

int output_tail(Deque *D){

    if(D->tail == NULL){
        printf("The Deque is Empty!\n");
        return -1;
    }
    Node* p;
    p = D->tail;
    int res = D->tail->data;

    D->tail = D->tail->next;
    D->tail->prev = NULL;
    free(p);

    return res;
}

void print_Deque(Deque *D){
    if(D->head == NULL || D->tail == NULL){
        printf("The Deque is Empty!\n");
        return;
    }

    Node *p;
    p = D->head;
    while(p != D->tail){
        printf("%d-->", p->data);
        p = p->prev;
    }
    printf("%d", p->data);
}

void remove_values(Deque *D, int value){
    Node* p, *tmp;
    p = D->head;

    while(p != NULL){
        if(p->data == value){
            if(p->next == NULL){
                D->head = p->prev;
                D->head->next = NULL;
            }

            else if(p->prev == NULL){
                D->tail = p->next;
                D->tail->prev = NULL;
            }

            else{
                p->next->prev = p->prev;
                p->prev->next = p->next;
            }

            tmp = p;
            p = p->prev;
            free(tmp);
        }

        else{
            p = p->prev;
        }

    }
}

void terminate_deque(Deque *D){
    Node *p = D->head;
    Node *tmp;
    D->head =  NULL;
    D->tail =  NULL;

    while(p != NULL){
        tmp = p;
        p = p->prev;
        free(tmp);
    }
}
