#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "impresoras.h"
#include "marca.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
public slots:
    void agregarImpresora();
    void ayuda();


private:
    Ui::Principal *ui;
    QList<Marca*> m_impresoras;
    void inicializarDatos();
    void inicializarWidgets();


    float m_total;

    void calcular(float);
};
#endif // PRINCIPAL_H
