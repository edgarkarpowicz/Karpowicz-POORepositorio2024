from fastapi import APIRouter
from model import User
from database import collection_name
from schemas import list_serial
from bson import ObjectId

router = APIRouter()

# GET Usuarios EndPoint - Conseguir todos los Usuarios en la Colección
@router.get("/")
async def get_user():
    users = list_serial(collection_name.find())
    return users

# POST Usuarios Endpoint - Agregar Usuarios a la Colección
@router.post("/")
async def post_user(user: User):
    collection_name.insert_one(dict(user))

# PUT Usuarios Endpoint - Modificar Usuarios según ID
@router.put("/{id}")
async def put_user(id: str, user: User):
    collection_name.find_one_and_update({"_id": ObjectId(id)}, {"$set": dict(user)})

# DELETE Usuarios Endpoint - Borrar Usuarios según ID
@router.delete("/{id}")
async def delete_user(id: str):
    collection_name.find_one_and_delete({"_id": ObjectId(id)})
