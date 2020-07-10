#ifndef IMPRESORAS_H
#define IMPRESORAS_H

#include <QObject>

class Impresoras : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString marca READ marca )
    Q_PROPERTY(QString modelo READ modelo )
    Q_PROPERTY(QString serie READ serie )
    Q_PROPERTY(char tipo READ tipo )
    Q_PROPERTY(float contador READ contador )
    Q_PROPERTY(int precioCompra READ precioCompra)
    Q_PROPERTY(int cantidad READ cantidad)
public:
    explicit Impresoras(QObject *parent = nullptr);
    Impresoras(int cantidad,QString marca,QString modelo,QString serie,char tipo,float contador,int precioCompra);

    //Gters
    int cantidad()const;
    QString marca()const;
    QString modelo()const;
    QString serie()const;
    char tipo()const;
    float contador()const;
    int precioCompra()const;



signals:

private:
    int m_cantidad;
    QString m_marca;
    QString m_modelo;
    QString m_serie;
    char m_tipo;
    float m_contador;
    int m_precioCompra;
};

#endif // IMPRESORAS_H
