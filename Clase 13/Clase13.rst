Ejercicio 14 (continuación):
============================

- Este ejercicio viene de la clase 5, 7, 8 y 12.
- Implementar en AdminDB el uso de MD5 para las claves de los usuarios.
- Acondicionar para que el método utilizado sea el siguiente:

.. code-block:: c	
	
	/**
	 * Si el usuario y clave son crrectas, este metodo devuelve el nombre y 
	 * apellido en un QStringList.	           
	 */
	QStringList AdminDB::validarUsuario( QString tabla,	QString usuario, QString clave )  {

	    QStringList datosPersonales;

	    if ( ! db.isOpen() ) 
	        return datosPersonales;

	    QSqlQuery * query = new QSqlQuery( db );
	    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(), 
	                                                 QCryptographicHash::Md5 ).toHex();

	    query->exec( "SELECT nombre, apellido FROM " +
	                 tabla + " WHERE usuario = '" + usuario +
	                 "' AND clave = '" + claveMd5 + "'" );
	
	    while( query->next() )  {
	        QSqlRecord registro = query->record();

	        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
	        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
	    }

	    return datosPersonales;
	} 

- Además, definir un método en AdminDB para ejecutar un select a la base. El prototipo es el siguiente:

.. code-block:: c	
	
	/**
	 * @brief Método que ejecuta una consulta SQL a la base de datos que ya se encuentra conectado. 
	          Utiliza QSqlQuery para ejecutar la consulta, con el método next() se van extrayendo 
	          los registros que pueden ser analizados con QSqlRecord para conocer la cantidad de 
	          campos por registro.
	 * @param comando es una consulta como la siguiente: SELECT nombre, apellido, id FROM usuarios
	 * @return Devuelve un QVector donde cada elemento es un registro, donde cada uno de estos registros 
	           están almacenados en un QStringList que contiene cada campo de cada registro.	           
	 */
	QVector< QStringList > select( QString comando ); 

- Definir en Login una signal que se emita cada vez que un usuario se loguee exitosamente. La signal debe emitir el nombre de usuario.

.. code-block:: c	
	
	void signal_usuarioValidado( QString usuario ); 





