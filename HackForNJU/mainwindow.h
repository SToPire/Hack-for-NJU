#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <QFile>
#include <QDebug>
#include <set>
#include <vector>
#include <fstream>
#include <QMessageBox>
using namespace std;

struct course{
    QString num;
    QString name;
    int credit;
    int score;
};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Calculate_clicked();
    vector<course> loadfile();
    void add_item(int i,course info);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
