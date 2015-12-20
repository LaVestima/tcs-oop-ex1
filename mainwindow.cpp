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

/**
 * @brief MainWindow::on_displayListButton_clicked
 */
void MainWindow::on_displayListButton_clicked() {
    if (!getListLength(proceduralList)) {
        ui->textBrowser->setText("<center><b>Empty list</b></center>");
    }
    else {
        ui->textBrowser->setText(displayList(proceduralList));
    }
}

/**
 * @brief MainWindow::on_newListButton_clicked
 */
void MainWindow::on_newListButton_clicked() {
    struct listNode *proceduralList = createList();
    ui->listSelectComboBox->setEnabled(true);
    ui->mainLabel->setText("List created");
    on_displayListButton_clicked();
}

/**
 * @brief MainWindow::on_addRecordButton_clicked
 */
void MainWindow::on_addRecordButton_clicked() {
    if(ui->listMainLineEdit->text() != "") {
        ui->listWidget->addItem(ui->listMainLineEdit->text());

        addRecord(&proceduralList, ui->listMainLineEdit->text());

        ui->listMainLineEdit->setText("");

        ui->idListWidget->addItem(QString::number(ui->listWidget->count()));

        ui->mainLabel->setText("Item added");
        ui->responseLineEdit->setText("Item added");
        ui->textBrowser->setText("Item added");

        on_displayListButton_clicked();
    }
}

/**
 * @brief MainWindow::on_appendRecordButton_clicked
 */
void MainWindow::on_appendRecordButton_clicked() {
    if(ui->listMainLineEdit->text() != "") {
        ui->listWidget->insertItem(0, ui->listMainLineEdit->text());

        appendRecord(&proceduralList, ui->listMainLineEdit->text());

        ui->listMainLineEdit->setText("");

        ui->idListWidget->addItem(QString::number(ui->listWidget->count()));
    }

    ui->mainLabel->setText("Item appended");
    on_displayListButton_clicked();
}

/**
 * @brief MainWindow::on_deleteRecordButton_clicked
 */
void MainWindow::on_deleteRecordButton_clicked() {
    int selectedRowId = ui->listWidget->currentRow();
    delete ui->listWidget->takeItem(selectedRowId);
    delete ui->idListWidget->takeItem(selectedRowId);

    int recordId = ui->recordDeleteIdLineEdit->text().toInt();
    deleteRecord(&proceduralList, recordId);

    ui->mainLabel->setText("Record deleted");
}

/**
 * @brief MainWindow::on_deleteAllButton_clicked
 */
void MainWindow::on_deleteAllButton_clicked() {
    int i = 0;
    while (ui->listWidget->item(i)) {
        delete ui->listWidget->takeItem(i) ;
        delete ui->idListWidget->takeItem(i);
    }

    deleteAllRecords(&proceduralList);

    ui->mainLabel->setText("All items deleted");
}


