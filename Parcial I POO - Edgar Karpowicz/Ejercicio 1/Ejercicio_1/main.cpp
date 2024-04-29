// Edgar Mario Karpowicz
// Programación Orientada a Objetos
// Parcial - Ejercicio 1

#include <QApplication>
#include <acceso.h> // Incluye la Librería de acceso.h que tiene nuestra Clase que vamos a instanciar para iniciar el Código.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Acceso login; // Instancia la Clase de Acceso de acceso.h, no le hacemos login->show(),
                  // ya que la Clase debe realizar una serie de preparaciones antes de poder mostrarse
                  // en este caso, el Procedimiento principal es descargar la Imágen de Fondo. Por ende no se muestra hasta que se obtiene la Imágen de Fondo de la WEB.
    return a.exec();
}
