from pymongo import MongoClient
from fastapi import FastAPI
from contextlib import asynccontextmanager
from rutas import router

# client = MongoClient("mongodb://localhost:27017")
# db = client.get_database("usuarios")
# collection = db.get_collection("usuarios")
# app = FastAPI()

async def connectToDatabase():
    db = MongoClient("mongodb://localhost:27017")
    print(db)
    return db

@asynccontextmanager
async def lifespan(app: FastAPI):
    print("Se esta Iniciando!!")
    dbHost = await connectToDatabase()
    app.db = dbHost.local.usuarios
    yield
    print("Se esta Apagando!!")

app = FastAPI(lifespan=lifespan)
app.include_router(router)

@app.get("/")
async def root():
    return {"message": "Hola a Ingeniería Informatica"}

