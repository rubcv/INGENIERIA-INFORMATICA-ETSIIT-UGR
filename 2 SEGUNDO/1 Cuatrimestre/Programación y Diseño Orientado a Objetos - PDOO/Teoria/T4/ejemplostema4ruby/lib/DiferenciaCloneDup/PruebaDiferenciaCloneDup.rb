# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
  require_relative 'direccion.rb'
  require_relative 'persona.rb'
  
  d1= Direccion.new("Calle del Agua", 58, "18888", "Murcia")

  p1 = Persona.new("Juan", 30, d1)
  def p1.nombre
    "No tengo nombre"
  end
  def p1.apellido
    "sin apellido"
  end
  p2 =p1.dup 
  p3 = p1.clone
  
  puts "El nombre de p1 es : #{p1.nombre}"  
  puts "El nombre de p2 es : #{p2.nombre}"  
  puts  "El nombre de p3 es : #{p3.nombre}"  
  
  puts "El apellido de p1 es : #{p1.apellido}"  
  #puts "El apellido de p2 es : #{p2.apellido}"  # ERROR: p2 no tiene el método 'apellido'
  puts  "El apellido de p3 es : #{p3.apellido}"  