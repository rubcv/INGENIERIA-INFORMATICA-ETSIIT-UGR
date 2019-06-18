#encoding: utf-8

class Prize
  attr_accessor :treasures, :level;

  def initialize(treasures,level)
    @treasures=treasures
    @level=level
  end

  def to_s
    "Tesoros ganados: #{@treasures} \nNiveles ganados: #{@level}\n"

  end

end
