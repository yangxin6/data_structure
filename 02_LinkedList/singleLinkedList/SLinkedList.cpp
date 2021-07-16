//
// Created by 杨鑫 on 2021/7/15.
// 1) 单链表反转
// 2) 链表中环的检测
// 3) 两个有序的链表合并
// 4) 删除链表倒数第 n 个结点
// 5) 求链表的中间结点
//

#include <iostream>
#include "SLinkedList.h"

void printNode(SNode *node);

SNode *find(SNode *head, int value);

// 判空
bool is_empty(SNode *head) {
    return head->next == nullptr;
}

// 插入
void insert_next(SNode *head, SNode *prev, SNode *elem) {
    // 节点不能为空
    if (!prev)
        return;
    // 查找prev是否存在
    SNode *p = head->next;
    while (p) {
        if (p == prev)
            break;
        p = p->next;
    }
    if (p == nullptr) {
        std::cout << "改节点不存在与链表中" << std::endl;
        return;
    }
    elem->next = prev->next;
    prev->next = elem;
    head->value++;
}

// 删除（删除要先找到该节点的前前驱结点, 不能删除头结点）
void del(SNode *head, SNode *elem) {
    if (!elem || !head)
        return;
    SNode *pre = head->next;
    while (pre->next->value != elem->value) {
        pre = pre->next;
    }
    pre->next = elem->next;
    elem->next = nullptr;
    head->value--;
    delete elem;
}

// 打印链表
void print(SNode *head) {
    int idx = 0;
    SNode *tmp = head;
    std::cout << "linkNode所有节点：" << std::endl;
    while (tmp) {
        std::cout << idx++ << "--" << tmp->value << std::endl;
        tmp = tmp->next;
    }
}

// 打印某个节点
void printNode(SNode *node) {
    std::cout << "value: " << node->value << std::endl;
}

// 带头节点的单链表 长度len记录在头结点的value中
SNode *linkedListCreate(int len, int step) {
    SNode *head = new SNode{len, nullptr};
    SNode *p = head;
    for (int i = 1; i <= len; ++i) {
        p->next = new SNode{i*step, nullptr};
        p = p->next;
    }
    return head;
}

// 找到 value 的节点，并返回对应节点的地址
SNode *find(SNode *head, int value) {
    SNode *p = head->next;
    while (p) {
        if (p->value == value)
            break;
        p = p->next;
    }
    if (p == nullptr) {
        std::cout << "改节点不存在与链表中" << std::endl;
        return nullptr;
    }
    return p;
}

/*

int main() {

//    SNode node0 = SNode{0, nullptr};
    // 测试生成独立节点
    // 此种方式创建的结构体 不属于 new 和 malloc 动态分配，不能用 delete 和 free 进行释放
//    SNode node0 = {0, nullptr};
//    SNode *p = &node0;
//    delete &node0;
//    SNode *node0 = new SNode{0, nullptr};
//    SNode *node1 = new SNode{1, nullptr};
//    SNode *node2 = new SNode{2, nullptr};
//    SNode *node3 = new SNode{3, nullptr};
//    SNode *node4 = new SNode{4, nullptr};
//    SNode *node5 = new SNode{5, nullptr};
//    SNode *node6 = new SNode{6, nullptr};


    //如果在 main 函数里面用 new ，在删除里面调用 delete 删除对应节点，节点还未被回收，只有当main函数执行完之后，才会被回收

    SNode *node0 = new SNode{0, nullptr};
    SNode *node1 = new SNode{1, nullptr};
    SNode *node2 = new SNode{2, nullptr};
    SNode *node3 = new SNode{3, nullptr};
    SNode *node4 = new SNode{4, nullptr};
    SNode *node5 = new SNode{5, nullptr};
    SNode *node6 = new SNode{6, nullptr};
    // 插入头
    insert_next(&list, &list, node0);
    // 插入某个节点（插入重复节点会造成链表异常）
    insert_next(&list, node0, node1);
    insert_next(&list, node0, node2);
    insert_next(&list, node1, node3);
    insert_next(&list, node3, node4);
    insert_next(&list, node3, node5);
    insert_next(&list, node1, node6);


    // 创建链表
    SNode *list = linkedListCreate(6);
    // 打印
    print(list);

    // 插入
    SNode *node3 = find(list, 3);
    SNode *node7 = new SNode{7, nullptr};
    insert_next(list, node3, node7);
    print(list);
    // 删除
    del(list, node3);
    print(list);
    std::cout << "地址：" << node3 << " value:" << node3->value << std::endl;
    return 0;
}
*/