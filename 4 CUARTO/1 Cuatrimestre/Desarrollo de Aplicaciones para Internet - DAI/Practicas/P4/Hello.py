from flask import Flask, session, redirect, url_for, request
from flask import render_template
from pickleshare import *
from pymongo import MongoClient
from flask_pymongo import PyMongo

# mongoimport --db database --collection restaurantes --file database.json 



app = Flask(__name__)
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'

app.config['MONGO_DBNAME'] = 'database'
app.config["MONGO_URI"] = "mongodb://localhost:27017/database"

mongo = PyMongo(app)

@app.route('/')
def hello_world():
    
    pag = render_template('login.html')
    return pag



@app.route('/modificar_restaurante' , methods=['GET', 'POST'])
def modificar_restaurante():
    
    if request.form['nombre']:
        nombre = session['nombre_res'] 
        nombre_nuevo = request.form['nombre']

        restaurante = mongo.db.restaurantes.find_one({"name" : nombre})
            
        # Realizar la insercion donde coincida el id
        if restaurante:
            mongo.db.restaurantes.update_one({
                '_id': restaurante['_id']
            }, {'$set': {
                'name' : nombre_nuevo
                
                }
            }, upsert=False) # Upsert = False para que si no lo encuentra no lo cree nuevo

            return render_template('restaurantes.html', modificado = True)

    return render_template('login.html')

@app.route('/add_restaurante' , methods=['GET', 'POST'])
def add_restaurante():
    
    if request.form['nombre_n'] and request.form['id_n'] and request.form['location_n_x'] and request.form['location_n_y']:
        nombre = request.form['nombre_n']
        idR  = request.form['id_n']
        location_x = request.form['location_n_x']        
        location_y = request.form['location_n_y']        

        # Crear el restaurante
        mongo.db.restaurantes.insert({"_id" : idR,"location":{"coordinates":[location_x,location_y],"type":"Point"}, "name" : nombre})


        return render_template('restaurantes.html', insertado = True)
    else:
        return render_template('restaurantes.html', insertado_error = False)



@app.route('/restaurante' , methods=['GET', 'POST'])
def restaurante():
        
    if request.form['nombre_buscar']:
        nombre = request.form['nombre_buscar']

        restaurante = mongo.db.restaurantes.find({"name" : {'$regex' : nombre} }).limit(10).sort([("name", 1)])

        if not restaurante:
            restaurantes = mongo.db.restaurantes.distinct('name') 
            
            for cadena in restaurantes:
                if nombre in cadena:                    
                    restaurante = mongo.db.restaurantes.find({"name" : cadena})
            

            

        if restaurante:
        #   nombre_res = restaurante["name"]
        #    location_res = restaurante["location"]["coordinates"]
        #    id_res = restaurante["_id"]
        #    session['nombre_res'] = nombre_res
            return render_template('restaurantes.html', encontrado = True, restaurante = restaurante)# nombre_res = nombre_res, location_res = location_res, id_res = id_res)
        else:
            return render_template('restaurantes.html', encontrado = False, error = True)

    return render_template('login.html')




@app.route('/buscar_restaurante' , methods=['GET', 'POST'])
def buscar_restaurante():
       
    return render_template('restaurantes.html', encontrado = False, error = False)



@app.route('/login' , methods=['GET', 'POST'])
def login():
    db = PickleShareDB('database')

    if request.form['loginusername'] and request.form['loginpass']:
     
        if request.form['loginusername'] in db:
            session['usuario'] = request.form['loginusername']
            session['p0'] = ''
            session['p1'] = ''
            session['p2'] = ''
            return render_template('login.html', usuario = session['usuario'])
    
    return render_template('login.html', error = True)

@app.route('/registro' , methods=['GET', 'POST'])
def registro():
    db = PickleShareDB('database')

    if request.form['username'] and request.form['nombre'] and request.form['email'] and request.form['pass']:
        nombre = request.form['username']
        db[nombre] = [request.form['nombre'], request.form['email'], request.form['pass']]

    return render_template('login.html')

@app.route('/actualizar' , methods=['GET', 'POST'])
def actualizar():
    db = PickleShareDB('database')

    if request.form['username'] and request.form['nombre'] and request.form['email'] and request.form['pass']:
        borrar = session['usuario']
        del db[borrar]
        nombre = request.form['username']
        db[nombre] = [request.form['nombre'], request.form['email'], request.form['pass']]

    return render_template('login.html')


@app.route('/pag1')
def pag1():
    session['p2'] = session['p1']
    session['p1'] = session['p0']
    session['p0'] = 'pag1'
    return render_template('pag1.html', usuario = session['usuario'], pag1 = session['p0'], pag2 = session['p1'], pag3 = session['p2'])

@app.route('/pag2')
def pag2():
    session['p2'] = session['p1']
    session['p1'] = session['p0']
    session['p0'] = 'pag2'
    return render_template('pag2.html', usuario = session['usuario'], pag1 = session['p0'], pag2 = session['p1'], pag3 = session['p2'])

@app.route('/pag3')
def pag3():
    session['p2'] = session['p1']
    session['p1'] = session['p0']
    session['p0'] = 'pag3'
    return render_template('pag3.html', usuario = session['usuario'], pag1 = session['p0'], pag2 = session['p1'], pag3 = session['p2'])

@app.route('/close')
def close():
    session['usuario'] = None
    session['paginas'] = ['', '', '']
    return render_template('login.html')

@app.route('/modificar')
def modificar():
    db = PickleShareDB('database')
    username = session['usuario']
    nombre = db[username][0]
    email = db[username][1]
    passw = db[username][2]

    return render_template('modificar.html', usuario = session['usuario'], user = username, nombre = nombre, email = email, passw = passw)

if __name__ == '__main__':
    app.debug = True
    app.run(host='0.0.0.0')
