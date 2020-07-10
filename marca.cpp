#include "marca.h"

Marca::Marca(QObject *parent) : QObject(parent)
{
    m_marca="";
}

Marca::Marca(QString marca)
{
    m_marca=marca;
}

QString Marca::marca()
{
    return m_marca;
}
