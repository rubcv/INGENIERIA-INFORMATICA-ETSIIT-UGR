def self.main
  begin divisor = 0
        resultado = 100/divisor
        puts "Resultado: " + resultado
  rescue Exception => ex
    puts "Error en division por 0"
  end
end

self.main
