//
// Created by mingmeng on 2019/7/11.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H
struct Node {
    int data;
    Node *next;
};

Node *tailInsertCreate();

Node *headInsertCreate();

Node *getNode(Node *head, int index);

Node *backInsert(Node *head, int index, int d);

Node *preInsert(Node *head, int index, int d);

int length(Node *head);

void printL(Node *head);

Node *insert(Node *head, int num);

Node *del(Node *head, int num);

Node *ReverseInLoop(Node *head);

Node *ReserveInRecursion(Node *head);


#endif //DATASTRUCTURE_LINKEDLIST_H
