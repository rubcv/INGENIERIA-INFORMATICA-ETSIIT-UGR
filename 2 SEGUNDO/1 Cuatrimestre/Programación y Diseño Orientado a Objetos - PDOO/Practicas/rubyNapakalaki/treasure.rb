class Treasure

  attr_accessor :name, :bonus ,:type

  def initialize(nombre, bonus, kind)
    @name = nombre
    @bonus = bonus
    @type = kind
  end

  def get_type()
    @type
  end

  def to_s()
    "Nombre #{@name} Bonus #{@bonus} Type #{@type} \n"
  end
end
