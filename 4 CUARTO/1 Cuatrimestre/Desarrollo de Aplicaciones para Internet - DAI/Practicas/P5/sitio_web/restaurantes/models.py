from django.db import models
from pymongo import MongoClient

# Create your models here.

client = MongoClient()
db = client.database.restaurantes # base de datos & coleccion

