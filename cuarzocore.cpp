#include "cuarzocore.h"

//Constructor

CuarzoCore::CuarzoCore()
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

CuarzoCore::~CuarzoCore()
{

}

//Inicia los demás componentes gráficos

void CuarzoCore::startUI()
{

    //Inicia Compton ( Display Manager )
    QProcess::startDetached("compton -CG");

    //Inicia Crystals ( Window Manager )
    QProcess::startDetached(QApplication::applicationDirPath() + "/../CR/Crystals");
}

void CuarzoCore::resolutionChanged()
{
    //Usar pantalla completa
    setGeometry(QApplication::desktop()->geometry());
}
