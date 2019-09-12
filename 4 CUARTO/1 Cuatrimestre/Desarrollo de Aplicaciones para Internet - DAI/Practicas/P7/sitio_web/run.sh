#!/bin/bash

# Arrancar la aplicacion
# Ver si funciona en localhost:8080
# Ver panel admin en localhost:8080/admin/

# Usuario admin creado: name = admin | root, pass = admin | root

cd ..
./copy.sh
cd sitio_web

#./update.sh

python3 manage.py runserver 0.0.0.0:5000
