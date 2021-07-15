//
// Created by 杨鑫 on 2021/7/15.
//
#include <iostream>

// 单链表节点
struct LNode {
    int value;
    struct LNode *next;
};

LNode *getLNodeByValue(LNode *head, int value);

bool existLNode(LNode *head, LNode *elem);

// 获取elem的前驱节点
LNode *getPrev(LNode *head, LNode *elem);

// 循环链表的创建
LNode *CreateLoopLinkedList(int len) {
    LNode *head = new LNode{0, nullptr};
    LNode *p = head;
    for (int i = 1; i < len; ++i) {
        p->next = new LNode{i, nullptr};
        p = p->next;
    }
    p->next = head;
    return head;
}

// 插入
void l_insert_next(LNode *head, LNode *prev, LNode *elem) {
    if (!head)
        return;
    // 判断 prev 是否存在
    if (!existLNode(head, prev)) {
        return;
    }
    // 插入
    elem->next = prev->next;
    prev->next = elem;
}

// 打印循环链表
void print(LNode *head) {
    LNode *tmp = head;
    std::cout << "LoopLinkedList所有节点：" << std::endl;
    do {
        std::cout << tmp->value << ",";
        tmp = tmp->next;
    } while (tmp != head);
    std::cout << std::endl;
}

// 打印节点
void printLNode(LNode *elem) {
    std::cout << "value：" << elem->value << " next：" << elem->next << std::endl;
}

// 获取 value 的节点，并返回对应节点的地址
LNode *getLNodeByValue(LNode *head, int value) {
    if (head->value == value) {
        return head;
    } else {
        LNode *p = head;
        do {
            if (p->value == value) {
                break;
            }
            p = p->next;
        } while (p != head);
        if (p == head) {
            std::cout << "value: " << value << "不存在于 循环链表中" << std::endl;
        }
        return p;
    }
}

// 检查 elem 是否存在于 循环链表 head 中
bool existLNode(LNode *head, LNode *elem) {
    if (head == elem) {
        return true;
    } else {
        LNode *p = head;
        do {
            if (p == elem) {
                break;
            }
            p = p->next;
        } while (p != head);
        if (p == head) {
            std::cout << "elem 不存在于 循环链表中" << std::endl;
            return false;
        } else {
            return true;
        }
    }
}

// 删除
void del(LNode *head, LNode *elem) {
    // 判断 elem 是否存在
    if (!existLNode(head, elem)) {
        return;
    }
    // 找到前驱节点
    LNode *prev = getPrev(head, elem);
    prev->next = elem->next;
    delete elem;
}

// 获取elem的前驱节点
LNode *getPrev(LNode *head, LNode *elem) {
    LNode *p = head;
    do {
        if (p->next == elem) {
            break;
        }
        p = p->next;
    } while (p != head);
    if (p == head) {
        std::cout << "elem 不存在于 循环链表中" << std::endl;
        return nullptr;
    } else {
        return p;
    }

}

/*
int main() {
    // 创建
    LNode *list = CreateLoopLinkedList(6);
    print(list);
    // 插入
    LNode node8 = LNode{8, nullptr};
    LNode *node3 = getLNodeByValue(list, 3);
    printLNode(node3);
    l_insert_next(list, node3, &node8);
    print(list);
    // 删除
    del(list, node3);
    print(list);
    return 0;
}
*/