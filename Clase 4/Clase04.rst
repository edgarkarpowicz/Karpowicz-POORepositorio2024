Ejercicio 8:
============

- En un Empty qmake Project
- Crear una función genérica que imprima por consola una descripción de cualquier objeto.
- El mensaje puede ser algo así: "Persona con nombre Lucrecia", "Poste con altura de 8 metros y 15 cm de diámetro".
- Probar esta función en main utilizando dos objetos de la clase Persona y dos objetos de la clase Poste.
- Incluir todo el código fuente en el archivo main.cpp.
- Pedirle al chat el código, interpretarlo y hacerlo funcionar.


Ejercicio 9:
============

- En un Empty qmake Project
- Crear una función genérica que imprima por consola sus valores ordenados
- Es decir, se le pasa un array con sus valores en cualquier orden, y la función genérica los imprime ordenados
- Que el prototipo sea: ``template < class T > void imprimir( T * v, int cantidad, bool mayor_a_menor );``
- Utilizar el método de ordenamiento por inserción
- Probar esta función en main utilizando dos arrays (int y float) y ordenar de mayor a menor y el otro al revés.

Ejercicio 10:
=============

- En un Empty qmake Project
- Crear una clase Jugador con atributos ``int velocidad``, ``int fuerza`` y ``std::string nombre``
- Usar constructor inicializando de la manera recomendada la velocidad en 0, fuerza en 0 y nombre "sin nombre" 
- Crear los métodos setter y getter para setear y obtener los valores de los atributos
- Incluir el destructor
- En la función main crear un ``std::vector< Jugador >`` e insertar 10 jugadores distintos
- Por último, publicar los datos de cada uno de los jugadores con ``std::cout``


Ejercicio 11:
=============

- En un Empty qmake Project
- En la función main crear un objeto de la clase QLabel, uno de QWidget, uno de QPushButton y uno de QLineEdit
- Invocar al método show() de cada uno de estos 4 objetos
- Notar que cada objeto se muestra independiente

Ejercicio 12:
=============

- En un Empty qmake Project
- En la función main crear un objeto de la clase QLabel y pegarle en el mismo objeto QLabel una imagen de alta resolución.
- Que la imagen se obtenga desde un archivo JPG del disco duro
- Mostrar el QLabel de forma maximizada y que la imagen no se deforme.
- Al cabo de 3 segundos, el QLabel y la aplicación se deberá cerrar

Aclaraciones:
=============

- Todos los ejercicios tienen que ser actualizados en un repositorio en GitHub en carpetas ejercicio01, ejercicio02, ...
- Contener todo lo necesario para poder compilarlo y ejecutarlo.
- Excluir los archivos y carpetas que no sean necesarios, como se el archivo con extensión .pro.user y la carpeta build-
- Enviar un mail a cesarosimani@gmail.com con la URL del repositorio.

