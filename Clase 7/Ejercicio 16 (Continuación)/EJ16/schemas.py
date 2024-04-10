def individual_serializer(user) -> dict:
    return {
        "id": str(user["_id"]),
        "nombre": user["nombre"],
        "apellido": user["apellido"],
        "edad": user["edad"],
        "email": user["email"]
    }

def list_serial(users) -> list:
    return(individual_serializer(user) for user in users)