#include "passworddialog.h"
#include "ui_passworddialog.h"
#include <QMessageBox>
#include <QPushButton>

#ifdef Q_OS_WIN32
#include <windows.h>
#else
#include <X11/XKBlib.h>
#undef KeyPress
#undef KeyRelease
#undef FocusIn
#undef FocusOut
// #undef those Xlib #defines that conflict with QEvent::Type enum
#endif
PasswordDialog::PasswordDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
    okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(false);
    QPushButton* cancelButton = ui->buttonBox->button(QDialogButtonBox::Cancel);
    if (correctPassword.isEmpty()) {
        ui->wrongPasswordLabel->setText(tr("<b>The password is unset, so access is prevented</b><br>"
                                           "Go to application settings to set the password."));
        ui->lineEdit->setEnabled(false);
    }

    ui->lineEdit->setEchoMode(QLineEdit::Password);

    initComplete = true;
    checkCapsLock();
}
/// SEE http://stackoverflow.com/questions/2968336/qt-password-field-warn-about-caps-lock
bool PasswordDialog::getCapsLockOn()
{
// platform dependent method of determining if CAPS LOCK is on
#ifdef Q_OS_WIN32 // MS Windows version
    return GetKeyState(VK_CAPITAL) == 1;
#else // X11 version (Linux/Unix/Mac OS X/etc...)
    Display* d = XOpenDisplay((char*)0);
    bool caps_state = false;
    if (d) {
        unsigned n;
        XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
        caps_state = (n & 0x01) == 1;
    }
    return caps_state;
#endif
}
void PasswordDialog::checkCapsLock()
{
    if (initComplete) {
        // if the password is already ok, caps lock is irrelevant
        if (!checkPassword(ui->lineEdit->text())) {
            ui->capsLockWarning->show();
            if (getCapsLockOn()) {
                ui->capsLockWarning->setText(tr("Warning: Caps Lock is on"));
            } else {
                ui->capsLockWarning->setText("");
            }
        } else {
            ui->capsLockWarning->hide();
        }
    }
}
bool PasswordDialog::event(QEvent* e)
{
    checkCapsLock();
    return QDialog::event(e);
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}
bool PasswordDialog::checkPassword(QString inputPassword)
{
    return (!correctPassword.isEmpty() && inputPassword == correctPassword);
}

void PasswordDialog::on_lineEdit_textChanged(const QString& arg1)
{
    if (checkPassword(arg1)) {
        okButton->setEnabled(true);
        ui->wrongPasswordLabel->setText(tr("<b>Password correct, press Ok to enter.</b>"));
        ui->capsLockWarning->setText("");

    } else {
        ui->wrongPasswordLabel->setEnabled(false);
        ui->wrongPasswordLabel->setText(tr("Password incorrect"));
        okButton->setEnabled(false);
    }
    checkCapsLock();
}
