//
// Created by 杨鑫 on 2021/7/16.
//

#include <iostream>
#include "SLinkedList.h"

// 单链表反转 （就地反转法）
/*
 * h 1 2 3 4 5
 * h 2 1 3 4 5
 * h 3 2 1 4 5
 */
void reverse(SNode *head) {
    if (!head)
        return;
    SNode *s = head->next;
    SNode *p = s->next;
    while (p) {
        s->next = p->next;
        p->next = head->next;
        head->next = p;
        p = s->next;
    }
}

// 检测环（快慢指针）
bool checkCircle(SNode *head) {
    if (!head)
        return false;
    SNode *fast = head->next, *slow = head->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

// 有序链表合并 （循环）
SNode *mergeOrdered(SNode *head1, SNode *head2) {
    SNode *prev = head1;
    SNode *p1 = head1->next;
    SNode *p2 = head2->next;
    while (p1 && p2) {
        if (p1->value < p2->value) {
            prev->next = p1;
            p1 = p1->next;
        } else {
            prev->next = p2;
            p2 = p2->next;
        }
        prev = prev->next;
    }
    prev->next = p1 == nullptr ? p2 : p1;
    head1->value += head2->value;
    return head1;
}


// 有序链表合并（递归）（不带头节点）
SNode *mergeOrderedRecursion(SNode *list1, SNode *list2) {
    if (!list1) {
        return list2;
    } else if (!list2) {
        return list1;
    } else if (list1->value < list2->value) {
        list1->next = mergeOrderedRecursion(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeOrderedRecursion(list1, list2->next);
        return list2;
    }
}

// 有序链表合并（递归）（带头节点）
SNode *mergeOrderedRecursionWithHead(SNode *list1, SNode *list2) {
    list1->value += list2->value;
    list1->next = mergeOrderedRecursion(list1->next, list2->next);
    return list1;
}

// 求链表的中间结点（快慢指针）（不带头节点）（带头节点如果存储了链表的长度，则直接循环一半就可以找到）
SNode *findMiddleNode(SNode *list) {
    // 判空 || 只有一个节点
    if (!list || list->next == nullptr)
        return list;
    SNode *fast = list;
    SNode *slow = list;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// 删除链表中倒数第 k 个节点（不带头）
// 不采用亚节点，让判断条件为fast-next != nullptr 从而让 slow 指向 k 的前驱结点
SNode * delLast(SNode *head, int k) {
    SNode *fast = head;
    SNode *slow = head;
    while(k--){
        fast = fast->next;
    }
    // 删除的是头
    if(!fast)
        return head->next;

    while (fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
// 删除链表中倒数第 k 个节点（带头）
SNode * delLastWithHead(SNode *head, int k) {
    head = delLast(head, k);
    head->value--;
    return head;
}

int main() {
    SNode *list = linkedListCreate(6);
    print(list);
    // 反转
    reverse(list);
    print(list);
    // 环检测
    bool f = checkCircle(list);
    std::cout << f << std::endl;
    SNode *list1 = linkedListCreate(6);
    list1->next->next->next = list1->next;
    f = checkCircle(list1);
    std::cout << f << std::endl;

    // 有序链表合并 （循环）
    SNode *list_a = linkedListCreate(6, 1);
    SNode *list_b = linkedListCreate(8, 3);
    SNode *m = mergeOrdered(list_a, list_b);
    print(m);
    // 有序链表合并 （递归）
    SNode *list_a1 = linkedListCreate(6, 1);
    SNode *list_b1 = linkedListCreate(8, 3);
    SNode *n = mergeOrderedRecursionWithHead(list_a1, list_b1);
    print(n);
    // 找到中间节点
    SNode *list_M = linkedListCreate(7);
    print(list_M);
    SNode *mid = findMiddleNode(list_M->next);
    printNode(mid);
    // 删除倒数第K个节点
    print(list);
    delLastWithHead(list,2);
    print(list);
}