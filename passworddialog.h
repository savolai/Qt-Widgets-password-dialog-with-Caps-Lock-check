#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class PasswordDialog;
}

class PasswordDialog : public QDialog {
    Q_OBJECT

public:
    explicit PasswordDialog(QWidget* parent = 0);
    ~PasswordDialog();

private slots:

    void on_lineEdit_textChanged(const QString& arg1);

    bool getCapsLockOn();

    void checkCapsLock();

private:
    const QString correctPassword = "password";
    Ui::PasswordDialog* ui;
    QPushButton* okButton;
    bool initComplete = false;

    bool checkPassword(QString inputPassword);

protected:
    bool event(QEvent* e) override;
protected slots:
};

#endif // PASSWORDDIALOG_H
