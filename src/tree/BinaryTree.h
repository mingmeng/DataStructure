//
// Created by mingmeng on 2019/8/18.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

typedef struct BiTNode {
    int data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;

void preOrder(BiTNode *root);

void midOrder(BiTNode *root);

void postOrder(BiTNode *root);

void binaryTreeTest();

void midOrder2(BiTNode *root);

void preOrder2(BiTNode *root);

void postOrder2(BiTNode *root);

void levelOrder(BiTNode *root);

BiTree construct(int *preOrder, int *midOrder, int len);

#endif //DATASTRUCTURE_BINARYTREE_H
