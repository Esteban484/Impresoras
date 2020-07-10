#include "impresoras.h"

Impresoras::Impresoras(QObject *parent) : QObject(parent)
{
    m_cantidad=0;
    m_marca=" ";
    m_modelo=" ";
    m_serie= " ";
    m_tipo= ' ';
    m_contador= 0;
    m_precioCompra=0;

}

Impresoras::Impresoras(int cantidad,QString marca, QString modelo, QString serie, char tipo, float contador, int precioCompra)
{
    m_cantidad=cantidad;
    m_marca=marca;
    m_modelo=modelo;
    m_serie=serie;
    m_tipo=tipo;
    m_contador=contador;
    m_precioCompra=precioCompra;

}

int Impresoras::cantidad() const
{
    return m_cantidad;
}

QString Impresoras::marca() const
{
    return m_marca;
}

QString Impresoras::modelo() const
{
    return m_modelo;
}

QString Impresoras::serie() const
{
    return m_serie;
}

char Impresoras::tipo()const
{
    return m_tipo;
}

float Impresoras::contador()const
{
    return m_contador;
}

int Impresoras::precioCompra()const
{
    return m_precioCompra;
}
