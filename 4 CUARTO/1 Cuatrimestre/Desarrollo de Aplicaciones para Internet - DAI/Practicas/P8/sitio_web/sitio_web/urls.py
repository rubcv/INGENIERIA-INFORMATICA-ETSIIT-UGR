"""sitio_web URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.conf.urls import include, url
from django.views.generic.base import RedirectView
from restaurantes import views

urlpatterns = [
    url(r'^$', RedirectView.as_view(url='restaurantes/')), # URL vacia redirecciona abajo
    url(r'^restaurantes/$', views.index, name='index'), # URL solo 'restaurantes/' devuelve index
    url(r'^restaurantes/', include('restaurantes.urls')),

    url(r'^admin/', admin.site.urls),

    #url(r'^login/', views.login, name='login'),
    url(r'^accounts/', include('allauth.urls')),
     
]
