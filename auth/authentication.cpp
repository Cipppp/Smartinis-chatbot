#include "./authentication.h"
#include "./ui_authentication.h"
#include <QMessageBox>
#include <QPixmap>
#include "../data/model/chatbot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/logo.png");
    int width = ui->pictureLabel->width();
    int height = ui->pictureLabel->height();
    ui->pictureLabel->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "admin" && password == "admin")
    {
        QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}


