#include "principal.h"
#include "ui_principal.h"
#include "dialog.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    inicializarDatos();


    connect(ui->actionAcerca_de, SIGNAL(triggered(bool)),
            this, SLOT(ayuda()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::agregarImpresora()
{
    //Obteniendo Datos de la interfaz
    int index = ui->inMarca->currentIndex();
    Marca *p =m_impresoras.at(index);
    Impresoras d;
    QString modelo=ui->inModelo->text();
    QString serie=ui->inSerie->text();
    QString tipo;
    if(ui->inColor->isChecked()){
        tipo="Color";
    }else{
        tipo="B/N";
    }
    float contador=ui->inContador->value();
    int precioCompra=ui->inPrecio->text().toInt();
    int cantidad=ui->inCantidad->value();

    //Calcular total
    float total=cantidad * d.precioCompra();

    //Agregar datos a la tabla
    int posicion=ui->outImpresoras->rowCount();
    ui->outImpresoras->insertRow(posicion);
    ui->outImpresoras->setItem(posicion,0,new QTableWidgetItem(QString::number(cantidad)));
    ui->outImpresoras->setItem(posicion,1,new QTableWidgetItem(p->marca()));
    ui->outImpresoras->setItem(posicion,2,new QTableWidgetItem(d.modelo()));
    ui->outImpresoras->setItem(posicion,2,new QTableWidgetItem(d.serie()));
    ui->outImpresoras->setItem(posicion,3,new QTableWidgetItem(d.tipo()));
    ui->outImpresoras->setItem(posicion,4,new QTableWidgetItem(QString::number(contador)));
    ui->outImpresoras->setItem(posicion,5,new QTableWidgetItem(QString::number(precioCompra)));



    //Limpiar datos
    ui->inModelo->setText("");
    ui->inContador->setValue(0);
    ui->inColor->setChecked(true);
    ui->inPrecio->setText("$");

    calcular(total);


}
void Principal::inicializarDatos()
{


    inicializarWidgets();
}


void Principal::inicializarWidgets()
{
    //Marcas
    ui->inMarca->addItem("Ricoh");
    ui->inMarca->addItem("Xerox");
    ui->inMarca->addItem("Lexmark");
    ui->inMarca->addItem("Kyocera");

    //Predeterminados
    ui->inModelo->setText("");
    ui->inContador->setValue(0);
    ui->inColor->setChecked(true);
    ui->inPrecio->setText("$");

    QStringList cabecera = {"Cantidad", "Marca", "Modelo", "Contador", "Tipo", "Precio" };
        ui->outImpresoras->setColumnCount(6);
        ui->outImpresoras->setHorizontalHeaderLabels(cabecera);
    //Eventos
        connect(ui->cmdIngresar, SIGNAL(clicked(bool)),
                this, SLOT(agregarImpresora()));


}

void Principal::calcular(float total)
{
    m_total += total;
    ui->outTotal->setText(QString::number(total));
}



void Principal::ayuda()
{
    Dialog ventana;
    ventana.setModal(true);
    ventana.exec();
}





