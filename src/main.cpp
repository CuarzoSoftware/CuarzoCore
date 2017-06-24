#include "sio4.h"
#include "includes.h"

int main(int argc, char *argv[])
{

    /* SiO4 */

    /* Encargado de conectar todas las aplicaciones del sistema, a través de sockets.
     * Muestra el fondo de escritorio.
     * Controla las configuraciones del sistema.
     * Inicia el salva pantallas
     * El uso de resources es temporal, luego se reemplazará con QSettings para acceder a los archivos necesarios desde diversos directorios.
     * Etc.
    */

    /* INSTRUCCIONES */

    /* Para que todo funcione correctamente
     * se debe ubicar en el directorio /usr/bin/
     * junto al resto de los programas de CuarzoOS.
    */

    //Ajusta la densidad de pixeles
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR","1");

    QApplication a(argc, argv);

    //Identificador para QSettings
    a.setOrganizationName("CuarzoSoftware");
    a.setApplicationName("SiO4");

    //Soporte para pantallas retina
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    //a.setAttribute(Qt::AA_EnableHighDpiScaling);

    SiO4 core;
    return a.exec();
}
