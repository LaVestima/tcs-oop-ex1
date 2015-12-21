#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void labelDisplayList();

private slots:
    void on_addRecordButton_clicked();

    void on_appendRecordButton_clicked();

    void on_deleteRecordButton_clicked();

    void on_deleteAllButton_clicked();

    void on_newListButton_clicked();

    void on_displayListButton_clicked();

    void on_findRecordButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
