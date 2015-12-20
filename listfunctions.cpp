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
    int listId = 0;
    QString listString = "";

    struct listNode *currentNode = listNodeHead;
    while (currentNode != NULL) {
        listId++;
        listString += QString::number(listId);
        listString += ". ";
        listString += "<b>";
        listString += currentNode->listNodeData;
        listString += "</b>";
        listString += " - ";
        listString += currentNode->listNodeTime.toString();
        listString += "<br>";

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
 * @param inputData
 */
void addRecord(struct listNode **listNodeHead, QString inputData) {
    struct listNode *newNode = new listNode;
    QDateTime dateTime;

    newNode->listNodeData = inputData;
    newNode->listNodeTime = dateTime.currentDateTime();
    newNode->listNodeNext = *listNodeHead;
    *listNodeHead = newNode;
}

/**
 * Appends the record to the existing list
 *
 * @brief appendRecord
 * @param listNodeHead
 * @param inputData
 */
void appendRecord(struct listNode **listNodeHead, QString inputData) {
    struct listNode *currentNode = *listNodeHead;
    struct listNode *newNode = new listNode;

    newNode->listNodeData = inputData;
    newNode->listNodeNext = NULL;

    if (currentNode == NULL) {
        *listNodeHead = newNode;
    }
    else {
        while (currentNode->listNodeNext != NULL) {
            currentNode = currentNode->listNodeNext;
        }
        currentNode->listNodeNext = newNode;
    }
}

//void deleteRecord(struct listNode *listNodeHead, int recordId) {
//    struct listNode *currentNode = listNodeHead;
//    int currentNodeId = 0;

//    while (currentNode) {
//        currentNodeId++;

//        if (currentNodeId == recordId) {
//            delete currentNode;
//        }
//        currentNode = currentNode->listNodeNext;
//    }

//    listNodeHead = NULL;
//}
void deleteRecord(struct listNode **listNodeHead, int recordId) {
    struct listNode *currentNode = *listNodeHead;
    struct listNode *nextNode = NULL;
    QString nodeData;
    int currentNodeId = 0;

    while (currentNode) {
        currentNodeId++;
        if (currentNodeId == recordId) {
            nextNode = (*listNodeHead)->listNodeNext; //Revise from here!
            nodeData = (*listNodeHead)->listNodeData;
            delete *listNodeHead;
            *listNodeHead = nextNode;
            break;
        }

        currentNode = currentNode->listNodeNext;
    }

}

/**
 * Deletes all the records from the existing list
 *
 * @brief deleteAllRecords
 * @param listNodeHead
 */
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
