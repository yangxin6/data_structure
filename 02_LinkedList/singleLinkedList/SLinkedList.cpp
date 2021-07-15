//
// Created by 杨鑫 on 2021/7/15.
// 1) 单链表反转
// 2) 链表中环的检测
// 3) 两个有序的链表合并
// 4) 删除链表倒数第 n 个结点
// 5) 求链表的中间结点
//

#include <iostream>

// 单链表节点
struct listNode {
    int value;
    struct listNode *next;
};

void printNode(listNode *node);

listNode *find(listNode *head, int value);

// 判空
bool is_empty(listNode *head) {
    return head->next == nullptr;
}

// 插入
void insert_next(listNode *head, listNode *prev, listNode *elem) {
    // 节点不能为空
    if (!prev)
        return;
    // 查找prev是否存在
    listNode *p = head->next;
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
void del(listNode *head, listNode *elem) {
    if (!elem || !head)
        return;
    listNode *pre = head->next;
    while (pre->next->value != elem->value) {
        pre = pre->next;
    }
    pre->next = elem->next;
    elem->next = nullptr;
    head->value--;
    delete elem;
}

// 打印链表
void print(listNode *head) {
    int idx = 0;
    listNode *tmp = head;
    std::cout << "linkNode所有节点：" << std::endl;
    while (tmp) {
        std::cout << idx++ << "--" << tmp->value << std::endl;
        tmp = tmp->next;
    }
}

// 打印某个节点
void printNode(listNode *node) {
    std::cout << "value: " << node->value << std::endl;
}

// 带头节点的单链表 长度len记录在头结点的value中
listNode *linkedListCreate(int len) {
    listNode *head = new listNode{len, nullptr};
    listNode *p = head;
    for (int i = 1; i <= len; ++i) {
        p->next = new listNode{i, nullptr};
        p = p->next;
    }
    return head;
}

// 找到 value 的节点，并返回对应节点的地址
listNode *find(listNode *head, int value) {
    listNode *p = head->next;
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

//    listNode node0 = listNode{0, nullptr};
    // 测试生成独立节点
    // 此种方式创建的结构体 不属于 new 和 malloc 动态分配，不能用 delete 和 free 进行释放
//    listNode node0 = {0, nullptr};
//    listNode *p = &node0;
//    delete &node0;
//    listNode *node0 = new listNode{0, nullptr};
//    listNode *node1 = new listNode{1, nullptr};
//    listNode *node2 = new listNode{2, nullptr};
//    listNode *node3 = new listNode{3, nullptr};
//    listNode *node4 = new listNode{4, nullptr};
//    listNode *node5 = new listNode{5, nullptr};
//    listNode *node6 = new listNode{6, nullptr};


    //如果在 main 函数里面用 new ，在删除里面调用 delete 删除对应节点，节点还未被回收，只有当main函数执行完之后，才会被回收

    listNode *node0 = new listNode{0, nullptr};
    listNode *node1 = new listNode{1, nullptr};
    listNode *node2 = new listNode{2, nullptr};
    listNode *node3 = new listNode{3, nullptr};
    listNode *node4 = new listNode{4, nullptr};
    listNode *node5 = new listNode{5, nullptr};
    listNode *node6 = new listNode{6, nullptr};
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
    listNode *list = linkedListCreate(6);
    // 打印
    print(list);

    // 插入
    listNode *node3 = find(list, 3);
    listNode *node7 = new listNode{7, nullptr};
    insert_next(list, node3, node7);
    print(list);
    // 删除
    del(list, node3);
    print(list);
    std::cout << "地址：" << node3 << " value:" << node3->value << std::endl;
    return 0;
}
*/