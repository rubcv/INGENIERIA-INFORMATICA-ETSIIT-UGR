class Pasajero
    def calcularPuntos(distancia)
      #Calculo complejo
    end
end

class PasajeroVIP < Pasajero #Clase PasajeroVIP hereda de Pasajero
  def calcularPuntos(distancia)
    super*2         # Usa el mismo metodo dentro del que está pero de la clase padre
  end

  def calcularPuntos(distancia, esOro)
    if(esOro)
      puntos = super(distancia) * 3 # Usa el segundo parametro para comprobar y segun, usa el metodo de la clase padre con distancia
    else
      puntos = super(distancia) * 2
    end
    puntos
  end
end


# ----- MAIN -----

p1 = Pasajero.new
ptos = p1.calcularPuntos(2138) #Usa el 1º de la clase padre

p2 = PasajeroVIP.new
ptos2 = p2.calcularPuntos(132, true) #Usa el 2º de la subclase, comprueba el true y luego usa el de la clase padre con distancia
