#!/bin/bash

# Actualizar database

python manage.py makemigrations

python manage.py migrate
