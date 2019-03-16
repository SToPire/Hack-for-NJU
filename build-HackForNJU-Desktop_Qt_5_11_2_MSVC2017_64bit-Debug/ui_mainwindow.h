/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *Calculate;
    QLabel *showGPA;
    QPushButton *selectAll;
    QRadioButton *nju;
    QRadioButton *std;
    QRadioButton *wes;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1209, 820);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-image: url(:/frame.jpg);"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 310, 761, 431));
        tableWidget->setStyleSheet(QStringLiteral("background:rgb(200, 190, 227,50%)"));
        Calculate = new QPushButton(centralWidget);
        Calculate->setObjectName(QStringLiteral("Calculate"));
        Calculate->setGeometry(QRect(900, 500, 141, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        Calculate->setFont(font);
        Calculate->setStyleSheet(QStringLiteral("background:url(:/4.jpg)"));
        showGPA = new QLabel(centralWidget);
        showGPA->setObjectName(QStringLiteral("showGPA"));
        showGPA->setGeometry(QRect(540, 260, 131, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe Print"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        showGPA->setFont(font1);
        showGPA->setStyleSheet(QLatin1String("background:url(:/3.jpg)\n"
""));
        selectAll = new QPushButton(centralWidget);
        selectAll->setObjectName(QStringLiteral("selectAll"));
        selectAll->setGeometry(QRect(160, 260, 131, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        selectAll->setFont(font2);
        selectAll->setStyleSheet(QStringLiteral("background:url(:/3.jpg)"));
        nju = new QRadioButton(centralWidget);
        nju->setObjectName(QStringLiteral("nju"));
        nju->setGeometry(QRect(900, 280, 131, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        nju->setFont(font3);
        nju->setStyleSheet(QStringLiteral("background:url(:/4.jpg)"));
        std = new QRadioButton(centralWidget);
        std->setObjectName(QStringLiteral("std"));
        std->setGeometry(QRect(900, 330, 131, 31));
        std->setFont(font3);
        std->setStyleSheet(QStringLiteral("background:url(:/4.jpg)"));
        wes = new QRadioButton(centralWidget);
        wes->setObjectName(QStringLiteral("wes"));
        wes->setGeometry(QRect(900, 380, 131, 31));
        wes->setFont(font3);
        wes->setStyleSheet(QStringLiteral("background:url(:/4.jpg)"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1209, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\213\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\213\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\345\255\246\345\210\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\210\220\347\273\251", nullptr));
        Calculate->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        showGPA->setText(QString());
        selectAll->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211/\345\217\215\351\200\211", nullptr));
        nju->setText(QApplication::translate("MainWindow", "\345\215\227\345\244\247\347\256\227\346\263\225", nullptr));
        std->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206\347\256\227\346\263\225", nullptr));
        wes->setText(QApplication::translate("MainWindow", "WES\347\256\227\346\263\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
