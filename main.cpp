#include "cuarzocore.h"
#include "includes.h"

int main(int argc, char *argv[])
{

    /* CUARZO CORE */

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

    QApplication a(argc, argv);
    CuarzoCore core;
    return a.exec();
}
