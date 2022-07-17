#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tabWidget->addTab(new QLabel("Tab1"), "Tab1");
    ui->tabWidget->addTab(new QLabel("Tab2"), "Tab2");
    ui->tabWidget->addTab(new QLabel("Tab3"), "Tab3");
    ui->tabWidget->addTab(new QLabel("Tab4"), "Tab4");

    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->setMovable(true);

    connect(ui->tabWidget, &FancyTabWidget::tabAddRequested, this, &Widget::addNewTab);
    connect(ui->tabWidget, &FancyTabWidget::tabCloseRequested, this, &Widget::closeTab);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addNewTab()
{
    ui->tabWidget->addTab(new QLabel("New Tab"), "New Tab");
}

void Widget::closeTab(int index)
{
    ui->tabWidget->widget(index)->deleteLater();
    ui->tabWidget->removeTab(index);
}
