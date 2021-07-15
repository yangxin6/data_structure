# 链表
- 单链表、循环链表、双向链表，增删

**tips:**

1. 此种方式创建的结构体 不属于 new 和 malloc 动态分配，不能用 delete 和 free 进行释放
```c++
listNode node0 = {0, nullptr};
listNode *p = &node0;
delete &node0;
```
2. 链表创建完之后，删除一个节点之后，为什么该节点还存在

