#ifndef LISTFUNCTIONS
#define LISTFUNCTIONS

#include <QMainWindow>
#include <QListWidget>

struct listNode {
    QString listNodeData;
//    QDateTime
    struct listNode* listNodeNext;
};

listNode* createList();

int getListLength(struct listNode);

int addRecord();

#endif // LISTFUNCTIONS

