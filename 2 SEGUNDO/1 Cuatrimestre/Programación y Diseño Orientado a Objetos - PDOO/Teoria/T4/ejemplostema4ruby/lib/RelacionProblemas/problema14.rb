#encoding: utf-8
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

class Cuadro 
  attr_accessor  :titulo, :pintor, :annio
  def initialize (titulo, pintor, annio)
    @titulo=titulo
    @pintor=pintor
    @annio=annio
  end
end

c1= Cuadro.new('Arlequin', 'Picasso', 1917)
puts c1.instance_variables
puts c1.kind_of?(Cuadro)
puts c1.methods(false)
m1 = c1.method(:annio)
puts m1.call

Cuadro.class_eval do 
        def style(estilo)
            @estilo = estilo
        end
end

puts c1.style('cubismo')

Cuadro.class_eval do 
  def borrarAnnio
      remove_instance_variable(:@annio)
  end                      
end
 
c1.borrarAnnio 
puts c1.instance_variables

c1.instance_eval do 
  def museo(museo)
      @museo = museo
  end
end

c1.museo('Barcelona')
puts c1.inspect

c2=Cuadro.new('Las Meninas', 'Velazquez', 1656)
puts c2.autor
puts c2.annio
puts c2.museo('Prado')