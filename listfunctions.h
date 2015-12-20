#ifndef LISTFUNCTIONS
#define LISTFUNCTIONS

#include <QMainWindow>
#include <QListWidget>
#include <QDateTime>

struct listNode {
    QString listNodeData;
    QDateTime listNodeTime;
    struct listNode* listNodeNext;
};

QString displayList(struct listNode *);

listNode* createList();

int getListLength(struct listNode *);

void addRecord(struct listNode **, QString);

void appendRecord(struct listNode **, QString);

void deleteRecord(struct listNode **, int);

void deleteAllRecords(struct listNode **);

#endif // LISTFUNCTIONS

