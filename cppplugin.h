#ifndef CPPPLUGIN_H
#define CPPPLUGIN_H

#include <QObject>

class CppPlugin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString stringHello READ stringHello WRITE setString)

public:
    CppPlugin(QObject *parent = 0);

    QString stringHello() const;
    void setString(const QString &string);

private:
    QString mStringHello;
};

#endif // CPPPLUGIN_H
