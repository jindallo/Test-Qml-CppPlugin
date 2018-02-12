#include "myclass.h"
#include <QDebug>

MyClass::MyClass()
{

}

void MyClass::cppSlot(const QString &msg)
{
    qDebug() << "Called the C++ slot with message: " << msg;
}
