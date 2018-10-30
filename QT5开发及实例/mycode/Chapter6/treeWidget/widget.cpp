#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();
    connect(ui->treeWidget, &QTreeWidget::itemChanged,
            this, &Widget::treeItemChanged);
}

void Widget::init()
{
    ui->treeWidget->clear();
    // 第一个分组
    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                     Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem1_1 = new QTreeWidgetItem(group1);
    subItem1_1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem1_1->setText(0, "subItem1_1");
    subItem1_1->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem1_2 = new QTreeWidgetItem(group1);
    subItem1_2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem1_2->setText(0, "subItem1_2");
    subItem1_2->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem1_3 = new QTreeWidgetItem(group1);
    subItem1_3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem1_3->setText(0, "subItem1_3");
    subItem1_3->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem1_4 = new QTreeWidgetItem(group1);
    subItem1_4->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem1_4->setText(0, "subItem1_4");
    subItem1_4->setCheckState(0, Qt::Unchecked);

    // 第二个分组
    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "group2");
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                     Qt::ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem2_1 = new QTreeWidgetItem(group2);
    subItem2_1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem2_1->setText(0, "subItem2_1");
    subItem2_1->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem2_2 = new QTreeWidgetItem(group2);
    subItem2_2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem2_2->setText(0, "subItem2_2");
    subItem2_2->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem2_3 = new QTreeWidgetItem(group2);
    subItem2_3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem2_3->setText(0, "subItem2_3");
    subItem2_3->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem2_4 = new QTreeWidgetItem(group2);
    subItem2_4->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |
                       Qt::ItemIsSelectable);
    subItem2_4->setText(0, "subItem2_4");
    subItem2_4->setCheckState(0, Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem *item, int column)
{
    QString itemText = item->text(0);
    // 选中时
    if (Qt::Checked == item->checkState(0))
    {
        QTreeWidgetItem *parent = item->parent();
        int count = item->childCount();
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                // 子节点也选中
                item->child(i)->setCheckState(0, Qt::Checked);
            }
        }
        else
        {
            // 是子节点
            updateParentItem(item);
        }
    }
    else if (Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
                item->child(i)->setCheckState(0, Qt::Unchecked);
        }
        else
            updateParentItem(item);
    }
}

void Widget::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if (NULL == parent)
        return;

    // 选中的子节点个数
    int selectedCount = 0;
    int childCount = parent->childCount();
    for (int i = 0; i < childCount; i++)
    {
        QTreeWidgetItem *childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked)
            selectedCount++;
    }

    if (selectedCount <= 0)     // 未选中状态
        parent->setCheckState(0, Qt::Unchecked);
    else if (selectedCount > 0 && selectedCount < childCount)   // 部分选中
        parent->setCheckState(0, Qt::PartiallyChecked);
    else if (selectedCount == childCount)   // 选中状态
        parent->setCheckState(0, Qt::Checked);
}

Widget::~Widget()
{
    delete ui;
}
