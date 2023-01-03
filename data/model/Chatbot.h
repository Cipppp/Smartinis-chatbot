#ifndef CHATBOT_H
#define CHATBOT_H

#include <QObject>

class Chatbot : public QObject
{
    Q_OBJECT

public:
    explicit Chatbot(QObject *parent = nullptr);

signals:

public slots:
    QString generateResponse(const QString &message);
};

#endif // CHATBOT_H


