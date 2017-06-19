#include "cuarzocore.h"

//Constructor

CuarzoCore::CuarzoCore()
{
    //Usar pantalla completa
    setGeometry(QApplication::desktop()->geometry());

    //Escala correctamente el wallpaper
    setScaledContents(true);

    //Asigna la imagen del wallpaper
    setPixmap(QPixmap(":/img/default.jpg"));

    //Muestra el fondo en pantalla ( Podriamos añadir una animación más adelante )
    show();
}


//Destructor

CuarzoCore::~CuarzoCore()
{

}

//Inicia los demás componentes gráficos

void CuarzoCore::startUI()
{

    //Inicia Crystals ( Window Manager )
    QProcess::startDetached("startx /usr/bin/./Crystals")

}
