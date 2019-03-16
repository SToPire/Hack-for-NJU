#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
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
    ui->nju->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
vector<course> MainWindow::loadfile(FILE *fp)
{
    vector<course> courses;
    QTextStream in(fp);
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
    fclose(fp);
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
    if(ui->nju->isChecked())
    {
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
        ui->showGPA->setText(QString::number((sum/cre)/20.0,10,3)+"/5");
    }
    if(ui->std->isChecked())
    {
        set<int> si;
        for(int i=0;i<selectedItems.count();++i)
        {
            si.insert(selectedItems.at(i).row());
        }
        double sum=0.0;
        double cre=0.0;
        for(auto a:si)
        {
            if(courses[a].score>=90){
                sum+=4*courses[a].credit;
                cre+=courses[a].credit;
            }
            else if(courses[a].score>=80){
                sum+=3*courses[a].credit;
                cre+=courses[a].credit;
            }
            else if(courses[a].score>=70){
                sum+=2*courses[a].credit;
                cre+=courses[a].credit;
            }
            else if(courses[a].score>=60){
                sum+=courses[a].credit;
                cre+=courses[a].credit;
            }
            else{
                cre+=courses[a].credit;
            }
        }
        ui->showGPA->setText(QString::number((sum/cre),10,3)+"/4");
    }
    if(ui->wes->isChecked())
    {
        set<int> si;
        for(int i=0;i<selectedItems.count();++i)
        {
            si.insert(selectedItems.at(i).row());
        }
        double sum=0.0;
        double cre=0.0;
        for(auto a:si)
        {
            if(courses[a].score>=85){
                sum+=4*courses[a].credit;
                cre+=courses[a].credit;
            }
            else if(courses[a].score>=75){
                sum+=3*courses[a].credit;
                cre+=courses[a].credit;
            }
            else if(courses[a].score>=60){
                sum+=2*courses[a].credit;
                cre+=courses[a].credit;
            }
            else {
                sum+=courses[a].credit;
                cre+=courses[a].credit;
            }
        }
        ui->showGPA->setText(QString::number((sum/cre),10,3)+"/4");
    }
}

void MainWindow::on_selectAll_clicked()
{
    ui->tableWidget->selectAll();
}

void MainWindow::on_actionOpen_O_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("请选择文件"),
                                                     "D:",QString::fromLocal8Bit("文本文件(*txt *tsv)"));
    FILE *fp;
     fp=fopen(fileName.toStdString().c_str(), "r");
     ::courses=loadfile(fp);
     for(int i=0;i<courses.size();++i)
     {
         add_item(i,courses[i]);
     }
}

void MainWindow::on_actionDeveloper_D_triggered()
{
    QMessageBox::information(this, QString::fromLocal8Bit("关于本软件"), QString::fromLocal8Bit("本软件由赵逸凡、张子辰和肖庚洋合作完成\n"));
}

void MainWindow::on_actionInstructions_I_triggered()
{
    QMessageBox::information(this, QString::fromLocal8Bit("使用方法"), QString::fromLocal8Bit("请将成绩存入文本文件，并选择相关计算方法进行计算\n"));
}

void MainWindow::on_selectAll_2_clicked()
{
    ui->tableWidget->selectAll();
    int row=ui->tableWidget->rowCount();
    for(int i=0;i<row;++i)
        ui->tableWidget->selectRow(i);
}
