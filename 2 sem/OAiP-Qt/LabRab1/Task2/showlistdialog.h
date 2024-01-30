#ifndef SHOWLISTDIALOG_H
#define SHOWLISTDIALOG_H

#include <QDialog>

class ShowListDialog : public QDialog
{
    Q_OBJECT
public:
    ShowListDialog(const QList<QString> data, QWidget *parent = nullptr);

private:
    QPushButton *acceptButton, *rejectButton;
};

#endif // SHOWLISTDIALOG_H
