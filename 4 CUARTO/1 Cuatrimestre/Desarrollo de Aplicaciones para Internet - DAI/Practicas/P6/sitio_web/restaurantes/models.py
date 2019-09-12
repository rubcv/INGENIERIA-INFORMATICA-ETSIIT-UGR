from django.db import models
from pymongo import MongoClient

# Create your models here.

client = MongoClient()
db = client.database.restaurantes # base de datos & coleccion


# Creacion del modelo plato

class Plato(models.Model):
    platos = models.Manager()
    nombre = models.CharField(primary_key = True, max_length=200)
    tipoCocina = models.CharField(max_length=200)
    tiempoPreparacion = models.CharField(max_length=200)
    precio = models.IntegerField()

    def __str__(self):
        return self.nombre