class Gato
  def initialize(n)
    @name = n
  end
end

def self.main
  Gato g = Gato.new
  puts "Main"
end

self.main
