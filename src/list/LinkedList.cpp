//
// Created by mingmeng on 2019/7/11.
//
/**
* cstdio是将stdio.h的内容用C++头文件的形式表示出来。
* stdio.h是C标准函数库中的头文件，即：standard buffered input&output。
*提供基本的文字的输入输出流操作（包括屏幕和文件等）。
*/

/**
*conio是Console Input/Output（控制台输入输出）的简写，其中定义了通过控制台进行数据输入和数据输出的函数，
*主要是一些用户通过按键盘产生的对应操作，比如getch()()函数等等。
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

struct Node {
    int data;
    Node *next;
};

// 创建单链表
Node *creat() {
    Node *head, *p;
    head = new Node;
    p = head;

    int x, cycle = 1;
    while (cycle) {
        cout << "Please input the data for single linker : ";
        cin >> x;

        if (x != 0) {
            Node *s = new Node;
            s->data = x;
            cout << "Input data : " << x << endl;

            p->next = s;
            p = s;
        } else {
            cycle = 0;
            cout << "Input done! " << endl;
        }
    }

    head = head->next;
    p->next = NULL;
    //cout << "\nFirst data of single linker is " << head->data << endl;

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
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
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
    Node *temp;
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
