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

// 单链表插入
Node *insert(Node *head, int num) {
    Node *p0, *p1, *p2;
    p1 = head;

    p2 = new Node;
    p0 = new Node; // 插入节点
    p0->data = num;// 插入数据

    while (p0->data > p1->data && p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;// p0,p1和p2位置: p2->p1->p0
    }

    if (p0->data <= p1->data) {
        if (p1 == head) {// 头部前段插入 p0和p1位置: p0->p1->...
            head = p0;
            p0->next = p1;
        } else {// 插入中间节点 p0,p1和p2位置: p2-> p0 -> p1
            p2->next = p0;
            p0->next = p1;
        }
    } else {   // 尾部插入节点 p0,p1和p2位置: p2->p1->p0->NULL
        p1->next = p0;
        p0->next = NULL;
    }
    return head;
}


// 单链表删除
Node *del(Node *head, int num) {
    Node *p1, *p2;
    p2 = new Node;
    p1 = head;

    while (num != p1->data && p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;// p1和p2位置: p2->p1
    }

    if (num == p1->data) {
        if (p1 == head)// 删除头节点
        {
            head = p1->next;
            delete p1;
        } else {
            p2->next = p1->next;
            delete p1;
        }
    } else {
        cout << num << " could not been found in the current single linker!" << endl;
    }
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

//测试代码
//int main() {
//    cout << "***create the single list***" << endl;
//    Node *head = creat();
//    cout << endl;
//
//    cout << "***calculate the length of list***" << endl;
//    int n = length(head);
//    cout << "The length of input single linker is " << n << "." << endl;
//    cout << endl;
//
//    cout << "***print the list***" << endl;
//    printL(head);
//    cout << endl;
//
//    cout << "****insert the node****" << endl;
//    cout << "Please input the data for inserting operate : ";
//    int inData;
//    cin >> inData;
//    head = insert(head,inData);
//    printL(head);
//    cout << endl;
//
//    cout << "**** delete the Node ****" << endl;
//    cout << "Please input the data for deleting operate : ";
//    int outData;
//    cin >> outData;
//    head = del(head, outData);
//    printL(head);
//    cout << endl;
//
//    return 0;
//}
