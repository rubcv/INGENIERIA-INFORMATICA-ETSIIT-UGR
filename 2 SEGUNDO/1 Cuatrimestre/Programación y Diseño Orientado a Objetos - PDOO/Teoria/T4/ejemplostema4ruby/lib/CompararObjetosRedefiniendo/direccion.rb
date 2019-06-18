# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

class Direccion
  attr_reader :calle, :numero, :codigoPostal
  attr_accessor :ciudad
  def initialize(calle, numero, cp, ciudad)
    @calle = calle
    @numero = numero
    @codigoPostal = cp
    @ciudad = ciudad    
  end 
 
end
