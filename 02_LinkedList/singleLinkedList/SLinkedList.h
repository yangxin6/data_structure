//
// Created by 杨鑫 on 2021/7/16.
//

#ifndef INC_02_LINKEDLIST_SLINKEDLIST_H
#define INC_02_LINKEDLIST_SLINKEDLIST_H
// 单链表节点
struct SNode {
    int value;
    struct SNode *next;
};

void printNode(SNode *node);
// 打印链表
void print(SNode *head);
// 带头节点的单链表 长度len记录在头结点的value中
SNode *linkedListCreate(int len, int step=1);

#endif //INC_02_LINKEDLIST_SLINKEDLIST_H
