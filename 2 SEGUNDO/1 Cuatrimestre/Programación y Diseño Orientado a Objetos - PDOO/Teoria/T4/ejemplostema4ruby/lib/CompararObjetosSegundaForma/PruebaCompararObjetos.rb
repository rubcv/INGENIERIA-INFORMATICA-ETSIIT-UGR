#encoding: utf-8
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
  
  require_relative 'persona.rb'
 
  p1 = Persona.new("Juan", 30)
  p2 = Persona.new("Miguel",30)  
  p3 = Persona.new("Juan",20)
  
  puts "p1 es mayor que p2 : #{p1 <=> p2} "
  puts "p1 es mayor que p3 : #{p1 <=> p3} "
  puts "p3 es mayor que p2 : #{p3 <=> p2} " 