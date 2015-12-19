#include "mainwindow.h"
#include "listfunctions.h"
#include "ui_mainwindow.h"

/**
 * Displays all the elements of the existing list
 *
 * @brief displayList
 * @param listNodeHead
 * @return
 */
QString displayList(struct listNode *listNodeHead) {
    QString listString = "";

    struct listNode *currentNode = listNodeHead;
    while (currentNode != NULL) {
        listString += currentNode->listNodeData;
        listString += "\n";
        currentNode = currentNode->listNodeNext;
    }
    return listString;
}

/**
 * Creates a new empty list
 *
 * @brief createList
 * @return
 */
listNode* createList() {
    struct listNode *listNodeHead = new listNode;

    listNodeHead->listNodeData = 5;

    return listNodeHead;
}

/**
 * Returns the lenght of the existing list
 *
 * @brief getListLength
 * @param listNodeHead
 * @return
 */
int getListLength(struct listNode *listNodeHead) {
    struct listNode *currentNode = listNodeHead;
    int count = 0;
    while (currentNode != NULL) {
        count++;
        currentNode = currentNode->listNodeNext;
    }
    return count;
}

/**
 * Adds the record to the existing list
 *
 * @brief addRecord
 * @param listNodeHead
 * @param data
 */
void addRecord(struct listNode **listNodeHead, QString data) {
    struct listNode *newNode = new listNode;

    newNode->listNodeData = data;
    newNode->listNodeNext = *listNodeHead;
    *listNodeHead = newNode;
}

void deleteRecord() {

}

void deleteAllRecords(struct listNode **listNodeHead) {
    struct listNode *currentNode = *listNodeHead;
    struct listNode *nextNode;

    while(currentNode) {
        nextNode = currentNode->listNodeNext;
        delete currentNode;
        currentNode = nextNode;
    }
    *listNodeHead = NULL;
}
