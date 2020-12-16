/**
 * Created by PANCHAO on 2020/12/11.
 * 顺序表静态分配
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} ContiguousList;

/**
 * 初始化表
 * 构造一个空的线性表L,分配内存空间
 * @param L
 */
void InitList(ContiguousList *L) {
    L->length = 0;
}

/**
 * 销毁操作
 * 销毁线性表，并释放线性表L所占用的内存空间
 * @param L
 */
void DestroyList(ContiguousList *L) {
    L->length = 0;
}

/**
 * 插入操作
 * 在表L中的第i个位置上插入指定元素e
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(ContiguousList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    if (L->length >= MaxSize) {
        return false;
    }
    for (int j = L->length; j >= i; --j) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

/**
 * 删除操作
 * 删除表L中的第i个位置的元素，并用e返回删除元素的值
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListDelete(ContiguousList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; ++j) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

/**
 * 按值查找操作
 * 在表L中查找具有给定关键字值的元素，并返回其位序
 * @param L
 * @param e
 * @return
 */
int LocateElem(ContiguousList *L, ElemType e) {
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

/**
 * 按位查找操作
 * 获取表L中第i个位置的元素的值
 * @param L
 * @param i
 * @return
 */
ElemType GetElem(ContiguousList *L, int i) {
    return L->data[i - 1];
}

/**
 * 表长度
 * 返回线性表L的长度，即L中数据元素的个数
 * @param L
 * @return
 */
int Length(ContiguousList *L) {
    return L->length;
}

/**
 * 输出操作
 * 按前后顺序输出线性表L的所有元素的值
 * @param L
 */
void PrintList(ContiguousList *L) {
    printf("[");
    for (int i = 0; i < L->length; ++i) {
        if (i == L->length - 1) {
            printf("%d", L->data[i]);
        } else {
            printf("%d,", L->data[i]);

        }
    }
    printf("]\n");
}

/**
 * 判空操作
 * 若L为空表，则返回true,否则返回false
 * @param L
 * @return
 */
bool Empty(ContiguousList *L) {
    return L->length < 1;
}

int main() {
    ContiguousList L;
    //初始化线性表
    InitList(&L);
    for (int i = 0; i < 10; ++i) {
        ListInsert(&L, 1, i);
    }
    //打印线性表
    PrintList(&L);
    printf("线性表长度%d，最大长度%d\n", Length(&L), MaxSize);
    //删除元素
    int e;
    ListDelete(&L, 5, &e);
    //打印线性表
    PrintList(&L);
    printf("删除第5个元素[%d]\n", e);
    //按值查找
    int value = 9;
    int index = LocateElem(&L, value);
    printf("查找元素[%d]的位序为[%d]\n", value, index);
    //按位查找
    index = 4;
    value = GetElem(&L, index);
    printf("查找位序[%d]的元素[%d]\n", index, value);
    printf("线性表是否为空[%d]\n", Empty(&L));
    //销毁线性表
    DestroyList(&L);
    printf("线性表是否为空[%d]\n", Empty(&L));
    return 0;
}
