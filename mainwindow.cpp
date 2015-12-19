#include "mainwindow.h"
#include "listfunctions.h"
#include "ui_mainwindow.h"

struct listNode *proceduralList;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_displayListButton_clicked() {
    if (!getListLength(proceduralList)) {
        ui->label->setText("Empty list");
    }
    else {
        ui->label->setText(displayList(proceduralList));
    }
}

//void MainWindow::labelDisplayList() {
//    if (!getListLength(proceduralList)) {
//        ui->label->setText("Empty list");
//    }
//    else {
//        ui->label->setText(displayList(proceduralList));
//    }
//}

void MainWindow::on_newListButton_clicked() {
    struct listNode *proceduralList = createList();
    ui->listSelectComboBox->setEnabled(true);
    ui->mainLabel->setText("List created");
    on_displayListButton_clicked();
}

void MainWindow::on_addRecordButton_clicked() {
//    struct listNode *proceduralList = createList();
//    ui->listMainLineEdit->setText(QString::number(getListLength(*proceduralList))); // To be removed

    if(ui->listMainLineEdit->text() != "") {
        ui->listWidget->addItem(ui->listMainLineEdit->text());

        ui->listMainLineEdit->setText("");

        ui->idListWidget->addItem(QString::number(ui->listWidget->count()));
    }
//    ui->listWidget->count();
    addRecord(&proceduralList, "First record");

    ui->mainLabel->setText("Item added");
    on_displayListButton_clicked();
}

void MainWindow::on_appendRecordButton_clicked() {
    if(ui->listMainLineEdit->text() != "") {
        ui->listWidget->insertItem(0, ui->listMainLineEdit->text());

        ui->listMainLineEdit->setText("");

        ui->idListWidget->addItem(QString::number(ui->listWidget->count()));
    }

    ui->mainLabel->setText("Item appended");
}

void MainWindow::on_deleteRecordButton_clicked() {
//    ui->deleteRecordLineEdit->setText(QString::number(ui->listWidget->currentRow()));
    int selectedRowId = ui->listWidget->currentRow();
    delete ui->listWidget->takeItem(selectedRowId);
    delete ui->idListWidget->takeItem(selectedRowId);

    ui->mainLabel->setText("Record deleted");
}


void MainWindow::on_deleteAllButton_clicked() {
    int i = 0;
    while (ui->listWidget->item(i)) {
        delete(ui->listWidget->takeItem(i));
        delete ui->idListWidget->takeItem(i);
    }

    deleteAllRecords(&proceduralList);

    ui->mainLabel->setText("All items deleted");
}


