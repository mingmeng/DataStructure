//
// Created by mingmeng on 2019/7/11.
//
#include <iostream>
#include "LinkedList.h"

using namespace std;

//使用create方法创建的链表数据
//自动化测试233
int data[6] = {0, 1, 2, 3, 4, 5};

// 尾插法创建单链表
Node *tailInsertCreate() {
    Node *head, *tail;
    head = new Node;
    tail = head;

    int i = 0;
    while (true) {
        if (i < sizeof(data) / sizeof(int)) {
            Node *s = new Node;
            s->data = data[i++];
            tail->next = s;
            tail = s;
        } else
            break;
    }

    head = head->next;
    tail->next = NULL;

    return head;
}

//头插法创建单链表
Node *headInsertCreate() {
    Node *head;
    head = new Node;//创建头结点 此时头节点仅仅作为头指针来进行使用 并非第一个结点
    int i = 0;

    while (true) {
        //此时数据使用的是来自全局变量数组的输入
        if (i < sizeof(data) / sizeof(int)) {
            Node *s = new Node;//创建临时结点存储数据
            s->data = data[i++];//输入数据
            s->next = head->next;//指针挪到头结点的下一个
            head->next = s;//将头指针挪到下一个
        } else
            break;
    }
    //头指针挪到第一个结点
    head = head->next;
    return head;
}

//返回第index位置的指针
// 1<=index<=length(list)
Node *getNode(Node *head, int index) {
    if (index == 1)
        return head;
    else if (index < 1) {
        cout << "illegal indices!" << endl;
        return NULL;
    } else {
        Node *n;
        n = head;
        int order = 1;
        while (order++ < index) {
            if (n->next == NULL) {
                cout << "illegal indices!" << endl;
                return NULL;
            }
            n = n->next;
        }
        return n;
    }
}

//按照值查找结点
Node *getNodeByValue(Node *head, int value) {
    Node *p;
    p = head;
    if (p == NULL)
        return NULL;
    while (p->next != NULL) {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return NULL;
}

// 单链表测长
int length(Node *head) {
    int n = 0;
    Node *p = head;

    while (p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

// 单链表打印
void printL(Node *head) {
    Node *p = head;

    cout << "Single Linker data is " << endl;
    int order = 1;
    while (p != NULL) {
        cout << order++ << ": " << p->data << endl;
        p = p->next;
    }
}

//后插
Node *backInsert(Node *head, int index, int d) {
    Node *n, *s;
    s = new Node;

    n = getNode(head, index);
    if (n == nullptr) {
        return head;
    }

    s->next = n->next;
    s->data = d;
    n->next = s;
    return head;
}

//前插
Node *preInsert(Node *head, int index, int d) {
    Node *n, *s;
    s = new Node;
    s->data = d;

    if (index == 1) {
        s->next = head;
        return s;
    } else {
        n = getNode(head, index - 1);
        if (n == nullptr) {
            return head;
        }
        s->next = n->next;
        n->next = s;
    }
    return head;
}

//索引值删除结点
Node *delNodeByIndex(Node *head, int index) {
    Node *n;
    n = getNode(head, index - 1);
    if (n != NULL)
        n->next = n->next->next;
    return head;
}

//索引值删除结点
Node *delNodeByNode(Node *head, Node *p) {
    p->data = p->next->data;
    p->next = p->next->next;
    return head;
}

//链表转置 循环方式
Node *ReverseInLoop(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node *reverse = NULL;
    Node *cur = head;
    while (cur != NULL) {
        Node *temp = cur;
        cur = cur->next;
        temp->next = reverse;
        reverse = temp;
    }
    return reverse;
}

//递归实现单链表转置
Node *ReserveInRecursion(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *newHead = ReserveInRecursion(head->next);

    head->next->next = head;
    head->next = NULL;
    return newHead;
}
