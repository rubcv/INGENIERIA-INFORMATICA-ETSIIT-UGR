# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
 
class Persona
  attr_reader  :edad, :nombre 
  
  def initialize(nombre,edad)
    @nombre= nombre
    @edad = edad 
  end
  def <=>per
    @edad<=>per.edad
  end
  # criterio de orden el nombre
#  def <=> per
#    @nombre <=> per.nombre
#  end
end
