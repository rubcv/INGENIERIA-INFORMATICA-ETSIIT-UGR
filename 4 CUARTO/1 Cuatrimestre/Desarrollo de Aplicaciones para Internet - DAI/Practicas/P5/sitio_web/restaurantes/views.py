# restaurantes/views.py

from django.shortcuts import render, HttpResponse, redirect
from django.http import HttpResponseRedirect
from .models import db
from django import forms

# Create your views here.

def index(request):
    return render(request, 'restaurantes.html')

def buscar(request):
    if request.method == 'POST': 
        
        #  mongoimport --db database --collection restaurantes --file database.json
        
        datos = request.POST.get('nombre')
       
        
        if datos:

            nombre = datos
            
            iterador = db.find({"name" : {'$regex' : nombre} }).limit(10).sort([("name", 1)])
            
            context = {
                "lista": iterador
            }
            
            return render(request, 'restaurantes.html', context)
        

    return render(request, 'restaurantes.html')

def add(request):


    if request.method == 'POST':
        nombre = request.POST.get('nombre')
        location_x = request.POST.get('location_x')
        location_y = request.POST.get('location_y')
        _id = request.POST.get('id')

        if nombre and location_x and location_y and _id:
            
            # Añadir 
            db.insert({"id" : _id,"location":{"coordinates":[location_x,location_y],"type":"Point"}, "name" : nombre})

            context = {
                "addok": "True"
            }
            return render(request, 'restaurantes.html', context)
        
        context = {
                "error": "True"
            }

    return render(request, 'restaurantes.html', context)

def modificar(request):
    
    if request.method == 'POST':
        ID = request.POST.get('id_mod')
        #ID_Guardado = db.find({"id" : ID})

        #print ("ID Introducido: " + ID)
        #print ("ID Guardado: " + ID_Guardado)

        #if ID_Guardado:

        nombre_nuevo = request.POST.get('nombre_mod')

        # Modificar

        db.update_one({
                    'id': ID
                }, {'$set': {
                    "name" : nombre_nuevo,                        
                    }
                })

        context = {
            'modificado' : "True"
        }

        return render(request, 'restaurantes.html', context)

    context = {
        'no_modificado' : "True"
    }

    return render(request, 'restaurantes.html', context)


