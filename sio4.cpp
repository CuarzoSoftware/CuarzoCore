#include "sio4.h"

//Constructor

SiO4::SiO4()
{
    //Usar pantalla completa
    connect(QApplication::desktop(),SIGNAL(resized(int)),this,SLOT(resolutionChanged()));
    resolutionChanged();

    //Escala correctamente el wallpaper
    setScaledContents(true);

    //Asigna la imagen del wallpaper
    setPixmap(QPixmap(":/img/default.jpg"));

    //Muestra el fondo en pantalla ( Podriamos añadir una animación más adelante )
    show();

    //Inicia los componentes
    startUI();
}


//Destructor

SiO4::~SiO4()
{

}

//Inicia los demás componentes gráficos

void SiO4::startUI()
{

    //Inicia Compton ( Display Manager )
    QProcess::startDetached("compton -CG");

    //Inicia Crystals ( Window Manager )
    QProcess::startDetached(QApplication::applicationDirPath() + "/../Crystals/Crystals");
}

void SiO4::resolutionChanged()
{
    //Usar pantalla completa
    setGeometry(QApplication::desktop()->geometry());
}
