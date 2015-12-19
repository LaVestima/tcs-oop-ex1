#ifndef LISTFUNCTIONS
#define LISTFUNCTIONS

#include <QMainWindow>
#include <QListWidget>

struct listNode {
    QString listNodeData;
//    QDateTime
    struct listNode* listNodeNext;
};

QString displayList(struct listNode *);

listNode* createList();

int getListLength(listNode *);

void addRecord(struct listNode **, QString);

void deleteAllRecords(struct listNode **);

#endif // LISTFUNCTIONS

