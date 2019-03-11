#include "mainwindow.h"
#include "ui_mainwindow.h"
vector<course> courses;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ::courses=loadfile();
    for(int i=0;i<courses.size();++i)
    {
        add_item(i,courses[i]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
vector<course> MainWindow::loadfile()
{
    vector<course> courses;
    QFile coursefile("course.txt");
    if (!coursefile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Wrong", "\"course.txt\" is not found.\n", QMessageBox::Yes);
        return courses;
    }
    QTextStream in(&coursefile);
    in.setCodec("GBK");
    while(!in.atEnd())
    {
        course temp;
        QString line=in.readLine(); if(line.isEmpty()) break;
        temp.num=line.section(' ',0,0);
        temp.name=line.section(' ',1,1);
        temp.credit=line.section(' ',2,2).toInt();
        temp.score=line.section(' ',3).toInt();
        courses.push_back(temp);
    }
    coursefile.close();
    return courses;
}
void MainWindow::add_item(int i,course info)
{
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(info.num));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(info.name));
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(info.credit)));
    ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(info.score)));
}
void MainWindow::on_Calculate_clicked()
{
    QItemSelectionModel *selections=ui->tableWidget->selectionModel();
    QModelIndexList selectedItems=selections->selectedIndexes();
    set<int> si;
    for(int i=0;i<selectedItems.count();++i)
    {
        si.insert(selectedItems.at(i).row());
    }
    double sum=0.0;
    double cre=0.0;
    for(auto a:si)
    {
        sum+=courses[a].credit*courses[a].score;
        cre+=courses[a].credit;
    }
    ui->showGPA->setText(QString::number((sum/cre)/20.0,10,3));
}
