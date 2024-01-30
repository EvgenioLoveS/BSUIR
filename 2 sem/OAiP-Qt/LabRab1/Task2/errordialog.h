#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class ErrorDialog : public QDialog
{
    Q_OBJECT

public:
    ErrorDialog(const QString& errorMessage, QWidget* parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("Error");
        QLabel* errorLabel = new QLabel(errorMessage);
        QPushButton* okButton = new QPushButton("OK");

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(errorLabel);
        layout->addWidget(okButton);
        setLayout(layout);

        connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    }
};

#endif // ERRORDIALOG_H
