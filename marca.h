#ifndef MARCA_H
#define MARCA_H

#include <QObject>

class Marca : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString marca READ marca )
public:
    explicit Marca(QObject *parent = nullptr);
    Marca(QString marca);
    QString marca();

signals:

private:
   QString m_marca;

};

#endif // MARCA_H
