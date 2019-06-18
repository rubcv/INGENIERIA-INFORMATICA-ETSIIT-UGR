#encoding: utf-8

# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
  require_relative 'direccion.rb'
 
  begin
    d1= Direccion.new("Calle del Agua", 58, "18888", "Murcia")
    puts "constructor usado con valores correctos"
    d1.codigoPostal("123")
    puts "código incorrecto"
  rescue Exception => e
    puts e.message
  end 
   