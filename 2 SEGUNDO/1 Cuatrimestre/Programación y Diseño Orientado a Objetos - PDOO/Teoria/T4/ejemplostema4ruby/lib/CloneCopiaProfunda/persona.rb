# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'direccion.rb'
class Persona
  attr_reader  :edad, :direccion
  attr_accessor :nombre
  def initialize(nombre,edad,direccion)
    @nombre= nombre
    @edad = edad
    @direccion = direccion
  end
  def self.newCopia(pc)
    new(pc.nombre,pc.edad, Direccion.newCopia(pc.direccion))
  end
  def clone
    Persona.newCopia(self)
  end
end
