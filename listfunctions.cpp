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
        listString += currentNode->data;
        listString += "</b>";
        listString += " - ";
        listString += currentNode->time.toString();
        listString += "<br>";

        currentNode = currentNode->next;
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
        currentNode = currentNode->next;
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

    newNode->data = inputData;
    newNode->time = dateTime.currentDateTime();
    newNode->next = *listNodeHead;
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
    QDateTime dateTime;

    newNode->data = inputData;
    newNode->time = dateTime.currentDateTime();
    newNode->next = NULL;

    if (currentNode == NULL) {
        *listNodeHead = newNode;
    }
    else {
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

int findRecord(struct listNode *listNodeHead, QString inputData) {
    struct listNode *currentNode = listNodeHead;
    int currentNodeId = 0;

    while (currentNode) {
        currentNodeId++;
        if (currentNode->data == inputData) {
            return currentNodeId;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

/**
 * Deletes the record with the selected id
 *
 * @brief deleteRecord
 * @param listNodeHead
 * @param recordId
 */
void deleteRecord(struct listNode **listNodeHead, int recordId) {
    struct listNode *currentNode = *listNodeHead;
    struct listNode *nextNode = NULL;
    QString nodeData;
    int currentNodeId = 0;

    if (recordId == 1) {
        nextNode = (*listNodeHead)->next;
        nodeData = (*listNodeHead)->data;
        delete *listNodeHead;
        *listNodeHead = nextNode;
    }
    else {
        while (currentNode) {
            currentNodeId++;

            if (currentNodeId == recordId - 1) {
                nextNode = currentNode->next->next;
                nodeData = currentNode->next->data;
                delete currentNode->next;
                currentNode->next = nextNode;
                break;
            }

            currentNode = currentNode->next;
        }
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
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    *listNodeHead = NULL;
}
