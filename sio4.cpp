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
    //Donde "wallpaper" es la variable definida en "Includes"
    setPixmap(QPixmap(wallpaper));

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
    //Donde "compositor" es la variable declarada en "Includes"
    QProcess::startDetached(compositor);

    //Inicia Crystals ( Window Manager )
    //Donde "crystals" es la variable declarada en "Includes".
    QProcess::startDetached(crystals);
    //QProcess::startDetached(QApplication::applicationDirPath() + "/../Crystals/Crystals");
}

void SiO4::resolutionChanged()
{
    //Usar pantalla completa
    setGeometry(QApplication::desktop()->geometry());
}
