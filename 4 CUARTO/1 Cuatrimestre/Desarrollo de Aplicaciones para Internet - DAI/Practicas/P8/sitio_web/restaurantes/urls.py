
# restaurantes/urls.py

from django.conf.urls import url
from django.urls import path

from . import views

urlpatterns = [
  url(r'^index$', views.index, name='index'), # No se le pone / al principio porque la pones en el urls.py general
  url(r'^buscar/$', views.buscar, name='buscar'),
  url(r'^buscarajax/$', views.buscarajax, name='buscarajax'),
  url(r'^buscarajax2/$', views.buscarajax2, name='buscarajax2'),

  path(r'buscarget/<pagina>/<busqueda>', views.buscarget, name='buscarget'),

  
  url(r'^add$', views.add, name='add'),
  url(r'^modificar$', views.modificar, name='modificar'),

  url(r'^platos', views.platos, name='platos'), 
  url(r'^buscarplatos$', views.buscarplatos, name='buscarplatos'), 
  url(r'^addplatos$', views.addplatos, name='addplatos'), 
  url(r'^modplatos$', views.modplatos, name='modplatos'), 

  url(r'^login$', views.login, name='login'),
  url(r'^logou$', views.logout, name='logout'),
  url(r'^signup$', views.signup, name='signup'),
  
]
