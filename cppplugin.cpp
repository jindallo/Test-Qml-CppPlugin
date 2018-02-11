#include "cppplugin.h"

CppPlugin::CppPlugin(QObject *parent)
    : QObject(parent)
{
}

QString CppPlugin::stringHello() const
{
    return mStringHello;
}

void CppPlugin::setString(const QString &string)
{
    mStringHello = string;
}
