from pydantic import BaseModel, Field
from typing import Optional

class Usuario(BaseModel):
    id: Optional[str] = Field(default_factory=str, alias="_id")
    nombre: str
    apellido: str
    edad: int = Field(gt=0)
    email: str