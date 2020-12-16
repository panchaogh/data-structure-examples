/**
 * Created by PANCHAO on 2020/12/11.
 * 单链表实现(不带头节点)
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 初始化表
 * 构造一个空的线性表L,分配内存空间
 * @param L
 */
void InitList(LinkList *L) {
    *L = NULL;
}

/**
 * 销毁操作
 * 销毁线性表，并释放线性表L所占用的内存空间
 * @param L
 */
void DestroyList(LinkList *L) {
    if (*L != NULL) {
        LNode *p = *L;
        while (p != NULL) {
            *L = (*L)->next;
            free(p);
            p = *L;
        }
    }
}

/**
 * 插入操作
 * 在表L中的第i个位置上插入指定元素e
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(LinkList *L, int i, ElemType e) {
    if (i < 1) {
        return false;
    }
    if (*L == NULL && i != 1) {
        return false;
    }
    if (i == 1) {
        LNode *p = *L;
        *L = (LNode *) malloc(sizeof(LNode));
        (*L)->data = e;
        (*L)->next = p;
        return true;
    }
    int j = 1;
    LNode *p = *L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
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
bool ListDelete(LinkList *L, int i, ElemType *e) {
    if (i < 1) {
        return false;
    }
    int j = 1;
    LNode *p = *L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode *q = p->next;

    return true;
}

/**
 * 按值查找操作
 * 在表L中查找具有给定关键字值的元素，并返回其位序
 * @param L
 * @param e
 */
int LocateElem(LinkList *L, ElemType e) {
    return 0;
}

/**
 * 按位查找操作
 * 获取表L中第i个位置的元素的值
 * @param L
 * @param i
 * @return
 */
LNode *GetElem(LinkList *L, int i) {
    int j = 1;

    LNode *p = (*L)->next;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 表长度
 * 返回线性表L的长度，即L中数据元素的个数
 * @param L
 * @return
 */
int Length(LinkList *L) {
    return 0;
}

/**
 * 输出操作
 * 按前后顺序输出线性表L的所有元素的值
 * @param L
 */
void PrintList(LinkList *L) {
    LNode *p = *L;
    printf("[");
    while (p != NULL) {
        printf("%d", p->data);
        p = p->next;
        if (p != NULL) {
            printf(",");
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
bool Empty(LinkList *L) {
    return *L == NULL;
}

int main() {
    LinkList L;
    InitList(&L);
    for (int i = 0; i < 10; ++i) {
        ListInsert(&L, 1, i);
    }
    PrintList(&L);
    DestroyList(&L);
    return 0;
}