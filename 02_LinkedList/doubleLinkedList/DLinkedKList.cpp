//
// Created by 杨鑫 on 2021/7/15.
//

#include <iostream>

// 双链表节点
struct DNode {
    int value;
    DNode *prev;
    DNode *next;
};

// 双链表的创建
// 循环链表的创建
DNode *createDLinkedList(int len) {
    DNode *head = new DNode{len, nullptr, nullptr};
    DNode *p = head;
    for (int i = 1; i <= len; ++i) {
        p->next = new DNode{i, nullptr, nullptr};
        p->next->prev = p;
        p = p->next;
    }
    return head;
}

// 打印
void print(DNode *head) {
    int idx = 0;
    DNode *tmp = head;
    std::cout << "linkNode所有节点：" << std::endl;
    while (tmp) {
        if (tmp->prev && tmp->next) {
            std::cout << idx++ << "--" << tmp->value << " prev:" << tmp->prev->value << " next:" << tmp->next->value
                      << std::endl;
        } else if (tmp->prev && !tmp->next) {
            std::cout << idx++ << "--" << tmp->value << " prev:" << tmp->prev->value << std::endl;
        } else if (!tmp->prev && tmp->next) {
            std::cout << idx++ << "--" << tmp->value << " next:" << tmp->next->value << std::endl;
        }
        tmp = tmp->next;
    }
}

// 检查 elem 是否存在于 双向链表 head 中
bool isExist(DNode *head, DNode *elem) {
    DNode *p = head->next;
    while (p) {
        if (p == elem) {
            break;
        }
        p = p->next;
    }
    if (p == nullptr) {
        std::cout << "elem 不存在于 双向链表中" << std::endl;
        return false;
    } else {
        return true;
    }
}


// 插入
void insert_d_next(DNode *head, DNode *prev, DNode *elem) {
    if (!head)
        return;
    // 检查 prev 是否存在 head 中
    if (!isExist(head, prev))
        return;
    elem->next = prev->next;
    elem->next->prev = elem;
    elem->prev = prev;
    prev->next = elem;
    head->value++;
}

// 删除
void del(DNode *head, DNode *elem) {
    if (!elem || !head)
        return;
    // 检查 elem 是否存在 head 中
    if (!isExist(head, elem))
        return;
    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
}

// 找到 value 的节点，并返回对应节点的地址
DNode *find(DNode *head, int value) {
    DNode *p = head->next;
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
    // 创建
    DNode *list = createDLinkedList(6);
    print(list);
    // 插入
    DNode node9 = DNode{9, nullptr, nullptr};
    DNode *node2 = find(list, 2);
    insert_d_next(list, node2, &node9);
    print(list);
    // 删除
    del(list, node2);
    print(list);
}
*/