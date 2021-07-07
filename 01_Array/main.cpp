#include <iostream>

struct array {
    int len;
    int used;
    int *arr;
};

// 动态扩容的数组
int dynamic_expansion(array *a) {
    std::cout << "输入数组的长度" << std::endl;
    std::cin >> a->len;
    if (a->len <= 0)
        return -1;

    a->arr = new int[a->len];
    std::cout << "请输入数字 或者 输入 -1 推出输入" << std::endl;
    int tmp = 0;
    while (std::cin >> tmp) {
        if (tmp == -1)
            break;
        if (a->used < a->len) {
            a->arr[a->used] = tmp;
            a->used++;
            std::cout << "请输入数字 或者 输入 -1 推出输入" << std::endl;
        } else {
            // 扩容
            std::cout << "===数组长度超出限制，扩容===" << std::endl;
            int *p = new int[a->len * 2];
            for (int j = 0; j < a->len; ++j) {
                p[j] = a->arr[j];
            }
            delete[] a->arr;
            a->arr = p;
            a->arr[a->used] = tmp;
            a->used++;
            a->len *= 2;
            std::cout << "请输入数字 或者 输入 -1 推出输入" << std::endl;
        }
    }
}

// 打印数组
void print(array *a) {
    std::cout << "输出数组：" << std::endl;
    for (int j = 0; j < a->used; ++j) {
        std::cout << a->arr[j] << ",";
    }
    std::cout << std::endl;
}

// 有序数组 动态增删改操作
// 增
int insert(array *a, int index, int element) {
    if (index > a->used)
        return -1;
    if (a->used < a->len) {
        for (int i = a->used; i >= index; --i) {
            a->arr[i + 1] = a->arr[i];
        }
        a->arr[index] = element;
        a->used++;
    } else {
        // 动态扩容
        int *p = new int[a->len * 2];
        for (int j = 0; j < index; ++j) {
            p[j] = a->arr[j];
        }
        p[index] = element;
        for (int i = index; i < a->used; ++i) {
            p[i + 1] = a->arr[i];
        }
        delete[] a->arr;
        a->arr = p;
        a->used++;
        a->len *= 2;
    }
}

// 删
int del(array *a, int index) {
    if (index > a->used)
        return -1;
    for (int i = index; i < a->used; ++i) {
        a->arr[i] = a->arr[i + 1];
    }
    a->used--;
}

// 改
int change(array *a, int index, int value) {
    if (index > a->used)
        return -1;
    a->arr[index] = value;
}

// 查
int index(array *a, int index) {
    if (index > a->used)
        return -1;
    return a->arr[index];
}

// 比较函数
bool compare(int a, int b) {
    return a < b;
}

// 两个有序数组合并
int merge(array *a, array *b) {
    if (a->used + b->used > a->len) {
        int *p = new int[a->used + b->used];
        for (int j = 0; j < a->used; ++j) {
            p[j] = a->arr[j];
        }
        delete[] a->arr;
        a->arr = p;
        a->len = a->used + b->used;
    }

    int p_a = a->used - 1;
    int p_b = b->used - 1;
    int p = a->used + b->used - 1;
    while ((p_a >= 0) && (p_b >= 0)) {
        if (a->arr[p_a] < b->arr[p_b]) {
            a->arr[p--] = b->arr[p_b--];
        } else {
            a->arr[p--] = a->arr[p_a--];
        }
    }
    a->used = a->used + b->used;
}

int main() {
    // 动态扩容的数组
//    array a = {0,0, nullptr};
//    dynamic_expansion(&a);
//    print(&a);
    // 有序数组 动态增删改操作
    array b = {5, 5, new int[5]};
    b.arr[0] = 1;
    b.arr[1] = 2;
    b.arr[2] = 3;
    b.arr[3] = 4;
    b.arr[4] = 5;
    print(&b);
    // 插入
    insert(&b, 0, 10);
    print(&b);

    // 删除
    del(&b, 3);
    print(&b);

    // 改
    change(&b, 1, 7);
    print(&b);

    // 查
    int value = index(&b, 1);
    std::cout << value << std::endl;

    // 两个有序数组合并
    array c = {5, 3, new int[5]};
    b.arr[0] = 1;
    b.arr[1] = 2;
    b.arr[2] = 3;
    array d = {3, 3, new int[3]};
    d.arr[0] = 2;
    d.arr[1] = 4;
    d.arr[2] = 7;
    merge(&c, &d);
    print(&c);
    return 0;
}
