from fastapi import APIRouter, Request, Body
from modelos import Usuario
from bson import ObjectId

router = APIRouter(prefix="", tags=['usuarios'])

@router.get("/")
async def getUser(request: Request)->list[Usuario]:
    db = request.app.db
    response = list(db.find({}))
    for item in response:
        item["_id"] = str(item["_id"])
    return response

@router.post("/")
async def addUser(request: Request, user: Usuario = Body(...)):
    db = request.app.db
    response = db.insert_one(user.model_dump())
    return {"id": str(response.inserted_id)}

@router.delete("/{id}")
async def deleteUser(request: Request, id):
    _id = ObjectId(id)
    db = request.app.db
    response = db.delete_one({"_id": _id})
    return {"deleted_count": response.deleted_count}

@router.put("/{id}")
async def updateUser(request: Request, id, user: Usuario = Body(...)):
    _id = ObjectId(id)
    db = request.app.db
    response = db.update_one({"_id": _id}, {"$set": user.model_dump()})
    return {"updated_count": response.modified_count}