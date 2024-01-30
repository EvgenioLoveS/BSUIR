#include "showlistdialog.h"
#include <QGridLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>

ShowListDialog::ShowListDialog(const QList<QString> data, QWidget *parent)
    : QDialog(parent)
{
    QListWidget *listWidget = new QListWidget();
    listWidget->addItems(data);
    acceptButton = new QPushButton(tr("OK"));
    rejectButton = new QPushButton(tr("Cancel"));

    QGridLayout *formLayout = new QGridLayout();
    if (data.isEmpty())
        formLayout->addWidget(new QLabel(tr("No data")), 0, 0, 1, 2);
    else
        formLayout->addWidget(listWidget, 0, 0, 1, 2);
    formLayout->addWidget(rejectButton, 1, 0, 1, 1);
    formLayout->addWidget(acceptButton, 1, 1, 1, 1);

    setLayout(formLayout);

    connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(reject()));
}
