#include "./chatbotInterface.h"
#include "ui_chatbotinterface.h"
// Include the chatbot header file
#include "../data/model/chatbot.h"
    
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);    
}

SecDialog::~SecDialog()
{
    delete ui;
}

// create a push button event
void SecDialog::on_pushButton_clicked()
{
    // create a chatbot object
    Chatbot chatbot;
// get the text from the line edit
    QString text = ui->finalLabel->text();

    // get the response from the chatbot
    QString response = chatbot.generateResponse("hello");

    // set the response to the label
    ui->finalLabel->setText(response);
}




