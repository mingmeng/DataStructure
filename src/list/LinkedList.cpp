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

using namespace std;

struct node {
    int data;
    node *next;
};

// 创建单链表
node *creat() {
    node *head, *p;
    head = new node;
    p = head;

    int x, cycle = 1;
    while (cycle) {
        cout << "Please input the data for single linker : ";
        cin >> x;

        if (x != 0) {
            node *s = new node;
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
int length(node *head) {
    int n = 0;
    node *p = head;

    while (p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

// 单链表打印
void printL(node *head) {
    node *p = head;

    cout << "Single Linker data is " << endl;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 单链表插入
node *insert(node *head, int num) {
    node *p0, *p1, *p2;
    p1 = head;

    p2 = new node;
    p0 = new node; // 插入节点
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
node *del(node *head, int num) {
    node *p1, *p2;
    p2 = new node;
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
node *ReverseInLoop(node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    node *reverse = NULL;
    node *cur = head;
    while (cur != NULL) {
        node *temp = cur;
        cur = cur->next;
        temp->next = reverse;
        reverse = temp;
    }
    return reverse;
}

//递归实现单链表转置
node *ReserveInRecursion(node *head) {
    node *temp;
    if (head == NULL || head->next == NULL) {
        return head;
    } else {
        temp = ReserveInRecursion(head->next);
        temp->next = head;
        head->next = NULL;
    }
    return head;
}

//测试代码
//int main() {
//    cout << "***create the single list***" << endl;
//    node *head = creat();
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
//    cout << "**** delete the node ****" << endl;
//    cout << "Please input the data for deleting operate : ";
//    int outData;
//    cin >> outData;
//    head = del(head, outData);
//    printL(head);
//    cout << endl;
//
//    return 0;
//}
