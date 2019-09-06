//
// Created by mingmeng on 2019/8/18.
//
#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;

BiTree construct(int *preOrder, int *midOrder, int len) {
    if (preOrder == NULL || midOrder == NULL || len <= 0)
        return NULL;

    //先根遍历（前序遍历）的第一个值就是根节点的键值
    int rootKey = preOrder[0];
    BiTNode *root = new BiTNode;
    root->data = rootKey;
    root->lChild = root->rChild = NULL;
    if (len == 1 && *preOrder == *midOrder)//只有一个节点
        return root;

    //在中根遍历（中序遍历）中找到根节点的值
    int *rootMidOrder = midOrder;
    int leftLen = 0; //左子树节点数
    while (*rootMidOrder != rootKey && rootMidOrder <= (midOrder + len - 1)) {
        ++rootMidOrder;
        ++leftLen;
    }
    if (*rootMidOrder != rootKey)//在中根序列未找到根节点,输入错误
        return NULL;

    if (leftLen > 0) { //构建左子树
        root->lChild = construct(preOrder + 1, midOrder, leftLen);
    }
    if (len - leftLen - 1 > 0) { //构建右子树
        root->rChild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    }
    return root;
}

//前序遍历
void preOrder(BiTNode *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->lChild);
        preOrder(root->rChild);
    }
}

//中序遍历
void midOrder(BiTNode *root) {
    if (root != NULL) {
        midOrder(root->lChild);
        cout << root->data << " ";
        midOrder(root->rChild);
    }
}

//后序遍历
void postOrder(BiTNode *root) {
    if (root != NULL) {
        postOrder(root->lChild);
        postOrder(root->rChild);
        cout << root->data << " ";
    }
}

//非递归中序遍历
//这里用到的栈直接使用了stl11里的stack
void midOrder2(BiTNode *root) {
    stack<BiTNode *> s;
    BiTNode *p = root;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lChild;
        } else {
            p = s.top();
            cout << p->data << " ";
            s.pop();
            p = p->rChild;
        }
    }
}

//前序遍历 非递归实现
void preOrder2(BiTNode *root) {
    stack<BiTNode *> s;
    BiTNode *p = root;
    while (p || !s.empty()) {
        if (p) {
            cout << p->data << " ";
            s.push(p);
            p = p->lChild;
        } else {
            p = s.top();
            s.pop();
            p = p->rChild;
        }
    }
}

void postOrder2(BiTNode *root)     //非递归后序遍历
{
    stack<BiTNode *> s;
    BiTNode *cur;                      //当前结点
    BiTNode *pre = NULL;                 //前一次访问的结点
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        if ((cur->lChild == NULL && cur->rChild == NULL) ||
            (pre != NULL && (pre == cur->lChild || pre == cur->rChild))) {
            cout << cur->data << "";  //如果当前结点没有孩子结点或者孩子节点都已被访问过
            s.pop();
            pre = cur;
        } else {
            if (cur->rChild != NULL)
                s.push(cur->rChild);
            if (cur->lChild != NULL)
                s.push(cur->lChild);
        }
    }
}

void levelOrder(BiTNode *root) {
    queue<BiTNode *> q;
    BiTNode *p;
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->lChild)
            q.push(p->lChild);
        if (p->rChild)
            q.push(p->rChild);
    }
}

//二叉树测试代码
void binaryTreeTest() {
    int preOrders[6] = {1, 2, 4, 6, 3, 5};
    int midOrders[6] = {2, 6, 4, 1, 3, 5};
    BiTree t = construct(preOrders, midOrders, sizeof(preOrders) / sizeof(preOrders[0]));

    cout << "preorder:" << endl;
    preOrder(t);
    cout << endl;

    cout << "preorder2:" << endl;
    preOrder2(t);
    cout << endl;

    cout << "midorder:" << endl;
    midOrder(t);
    cout << endl;

    cout << "midorder2:" << endl;
    midOrder2(t);
    cout << endl;

    cout << "postorder:" << endl;
    postOrder(t);
    cout << endl;

    cout << "postorder2:" << endl;
    postOrder(t);
    cout << endl;

    cout << "postorder2:" << endl;
    postOrder2(t);
    cout << endl;

    cout << "level order:" << endl;
    levelOrder(t);
    cout << endl;
}


