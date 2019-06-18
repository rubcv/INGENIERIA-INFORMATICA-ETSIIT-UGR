
require 'singleton'

class Dice
  include Singleton

  def initialize

  end

  def self.get_instance
    Dice.instance
  end

  def next_number
    Random.rand(1...6)
  end

end
