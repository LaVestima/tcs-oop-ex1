#ifndef LISTFUNCTIONS
#define LISTFUNCTIONS

#include <QMainWindow>
#include <QListWidget>
#include <QDateTime>

struct listNode {
    QString data;
    QDateTime time;
    struct listNode* next;
};

QString displayList(struct listNode *);

listNode* createList();

int getListLength(struct listNode *);

void addRecord(struct listNode **, QString);

void appendRecord(struct listNode **, QString);

void deleteRecord(struct listNode **, int);

int findRecord(struct listNode *, QString);

void deleteAllRecords(struct listNode **);

#endif // LISTFUNCTIONS

