/********************************************************************************
** Form generated from reading UI file 'testclient.ui'
**
** Created: Sun Apr 15 00:45:44 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCLIENT_H
#define UI_TESTCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestClient
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *callButton;
    QPushButton *exitButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    QSpacerItem *spacerItem1;
    QLineEdit *difference;
    QLineEdit *sum;
    QLabel *label_6;
    QLabel *label_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout2;
    QSpacerItem *spacerItem2;
    QLineEdit *y;
    QLabel *label_4;
    QLineEdit *x;
    QLabel *label_3;
    QSpinBox *port;
    QLineEdit *host;

    void setupUi(QWidget *TestClient)
    {
        if (TestClient->objectName().isEmpty())
            TestClient->setObjectName(QString::fromUtf8("TestClient"));
        TestClient->resize(394, 230);
        gridLayout = new QGridLayout(TestClient);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(TestClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        label = new QLabel(TestClient);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        callButton = new QPushButton(TestClient);
        callButton->setObjectName(QString::fromUtf8("callButton"));
        callButton->setAutoDefault(true);
        callButton->setDefault(true);

        hboxLayout->addWidget(callButton);

        exitButton = new QPushButton(TestClient);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        hboxLayout->addWidget(exitButton);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 5);

        groupBox_2 = new QGroupBox(TestClient);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout1 = new QGridLayout(groupBox_2);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        spacerItem1 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem1, 2, 1, 1, 1);

        difference = new QLineEdit(groupBox_2);
        difference->setObjectName(QString::fromUtf8("difference"));
        difference->setReadOnly(true);

        gridLayout1->addWidget(difference, 1, 2, 1, 1);

        sum = new QLineEdit(groupBox_2);
        sum->setObjectName(QString::fromUtf8("sum"));
        sum->setReadOnly(true);

        gridLayout1->addWidget(sum, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout1->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout1->addWidget(label_5, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 2, 1, 3);

        groupBox = new QGroupBox(TestClient);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout2 = new QGridLayout(groupBox);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        spacerItem2 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout2->addItem(spacerItem2, 2, 1, 1, 1);

        y = new QLineEdit(groupBox);
        y->setObjectName(QString::fromUtf8("y"));

        gridLayout2->addWidget(y, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout2->addWidget(label_4, 1, 0, 1, 1);

        x = new QLineEdit(groupBox);
        x->setObjectName(QString::fromUtf8("x"));

        gridLayout2->addWidget(x, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout2->addWidget(label_3, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 2);

        port = new QSpinBox(TestClient);
        port->setObjectName(QString::fromUtf8("port"));
        port->setMaximum(65535);
        port->setMinimum(1);
        port->setValue(7777);

        gridLayout->addWidget(port, 0, 4, 1, 1);

        host = new QLineEdit(TestClient);
        host->setObjectName(QString::fromUtf8("host"));

        gridLayout->addWidget(host, 0, 1, 1, 2);


        retranslateUi(TestClient);

        QMetaObject::connectSlotsByName(TestClient);
    } // setupUi

    void retranslateUi(QWidget *TestClient)
    {
        TestClient->setWindowTitle(QApplication::translate("TestClient", "xmlrpc::Client example", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TestClient", "Port:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TestClient", "Host:", 0, QApplication::UnicodeUTF8));
        callButton->setText(QApplication::translate("TestClient", "Call", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("TestClient", "Exit", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("TestClient", "Return values:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TestClient", "difference:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TestClient", "sum:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TestClient", "Parameters:", 0, QApplication::UnicodeUTF8));
        y->setText(QApplication::translate("TestClient", "2", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TestClient", "y:", 0, QApplication::UnicodeUTF8));
        x->setText(QApplication::translate("TestClient", "1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TestClient", "x:", 0, QApplication::UnicodeUTF8));
        host->setText(QApplication::translate("TestClient", "localhost", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestClient: public Ui_TestClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCLIENT_H
