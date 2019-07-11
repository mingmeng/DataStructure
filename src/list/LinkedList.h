//
// Created by mingmeng on 2019/7/11.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H
struct node {
    int data;
    node *next;
};

node *creat();

int length(node *head);

void printL(node *head);

node *insert(node *head, int num);

node *del(node *head, int num);

node *ReverseInLoop(node *head);

node *ReserveInRecursion(node *head);

#endif //DATASTRUCTURE_LINKEDLIST_H
