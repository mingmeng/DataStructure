//
// Created by mingmeng on 2019/8/18.
//
#include <iostream>
#include <cstdlib>

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


