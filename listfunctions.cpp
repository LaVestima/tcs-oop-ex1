#include "mainwindow.h"
#include "listfunctions.h"
#include "ui_mainwindow.h"

listNode* createList() {
    struct listNode *listNodeHead = new listNode;

    listNodeHead->listNodeData = 5;

    return listNodeHead;
}

int getListLength(struct listNode listNodeHead) {
    struct listNode current = listNodeHead;
    int count = 0;
//    while (current->listNodeNext) {
//        count++;
//        current = current->listNodeNext;
//    }
    return count;
}

int addRecord() {
    return 0;
}
