# restaurantes/views.py


from django.shortcuts import render, HttpResponse, redirect
from django.http import HttpResponseRedirect
from .models import db, Plato
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



# TODO: No modifica los campos guardados de la  base de datos json, si modifica los restaurantes
# que he guardado yo en la base de datos


def modificar(request):
    
    
    if request.method == 'POST':
        ID = request.POST.get('id_mod')

        nombre_nuevo = request.POST.get('nombre_mod')

        # Modificar
                
        db.update_one({
                'id': ID
            }, {'$set': {
                'name' : nombre_nuevo,                        
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


#**********************************************************************
#                               PLATOS
#**********************************************************************

def platos(request):
    return render(request, 'platos.html')

def buscarplatos(request):
    if request.method == 'POST': 
                
        datos = request.POST.get('nombre_r')       

        if datos:
            

            iterador = Plato.platos.all().filter(nombre = datos)
                        

            context = {
                "platos": iterador
            }
            
            return render(request, 'platos.html', context)
        
    return render(request, 'platos.html') 
    

def addplatos(request):
    if request.method == 'POST':
        
        nombre = request.POST.get('nombre')
        tipo_cocina = request.POST.get('tipo_cocina')
        tiempo_prep = request.POST.get('tiempo_prep')
        precio = request.POST.get('precio')

        if nombre and tipo_cocina and tiempo_prep and precio:

            # Añadir
            
            res = Plato(nombre = nombre, tipoCocina = tipo_cocina, tiempoPreparacion = tiempo_prep, precio = precio)

            res.save()

            context = {
                "addok": "True"
            }
            return render(request, 'platos.html', context)
        
    context = {
            "error": "True"
        }

    return render(request, 'platos.html', context)




def modplatos(request):

    if request.method == 'POST':
        nombre = request.POST.get('nombre_mod')
        
                          
        # Modificar
        plato = Plato(nombre=nombre)

        tipo_mod = request.POST.get('tipo_mod')
        tiempo_mod = request.POST.get('tiempo_mod')
        precio_mod = request.POST.get('precio_mod')

        plato.tipoCocina = tipo_mod
        plato.tiempoPreparacion = tiempo_mod 
        plato.precio = precio_mod


        plato.save()


        context = {
            'modificado' : "True"
        }

        return render(request, 'platos.html', context)

    context = {
        'no_modificado' : "True"
    }

    return render(request, 'platos.html', context)

    

#**********************************************************************
#                               LOGIN
#**********************************************************************


def login(request):
    return HttpResponseRedirect("/accounts/login/")


def logout(request):
    return HttpResponseRedirect("/accounts/logout/")

def signup(request):
    return HttpResponseRedirect("/accounts/signup/")