
# restaurantes/urls.py

from django.conf.urls import url

from . import views

urlpatterns = [
  url('index', views.index, name='index'), # No se le pone / al principio porque la pones en el urls.py general
  url('buscar', views.buscar, name='buscar'),
  url('add', views.add, name='add'),
  url('modificar', views.modificar, name='modificar'),
  
]
