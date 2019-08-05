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

Node *getNodeByValue(Node *head, int value);

Node *delNodeByIndex(Node *head, int index);

Node *delNodeByNode(Node *head, Node *p);

int length(Node *head);

void printL(Node *head);

Node *ReverseInLoop(Node *head);

Node *ReserveInRecursion(Node *head);


#endif //DATASTRUCTURE_LINKEDLIST_H
