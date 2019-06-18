# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
  require_relative 'direccion.rb'
  require_relative 'persona.rb'
  d1= Direccion.new("Calle del Agua", 58, "18888", "Murcia")

  p1 = Persona.new("Juan", 30, d1)
  p2 = Persona.newCopia(p1)
  puts p1.nombre
  p2.nombre = "Luis"   
  puts p1.nombre

  puts "La ciudad de #{p2.nombre} es #{ p2.direccion.ciudad}"
  p2.direccion.ciudad = "Huelva"
  puts "La ciudad de #{p1.nombre} es #{ p1.direccion.ciudad}"
  puts "La ciudad de #{p2.nombre} es #{ p2.direccion.ciudad}" 