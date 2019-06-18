#encoding: utf-8

require_relative 'prize.rb'
require_relative 'bad_consequence.rb'

class Monster
  attr_accessor :name, :combat_level , :bad_consequence , :prize , :level_change_against_cultist_player

   def initialize(name, combat_level, bad_consequence, prize, ic)

    @name = name
    @combat_level= combat_level
    @bad_consequence = bad_consequence
    @prize = prize
    @level_change_against_cultist_player = ic

   end


   def self.copia(name, combat_level, bad_consequence, prize,ic)

      self.new(name, combat_level, bad_consequence, prize, ic)

   end

  def get_bad_consequence
    @bad_consequence
  end
  def get_combatlevel
    @combat_level
  end

  def get_levels_gained
    @prize.level
  end

  def get_treasures_gained
    @prize.treasures
  end

  def get_combat_level_against_cultist_player

        valor = get_combatlevel + @level_change_against_cultist_player
        valor
  end

  def to_s
    "\nNombre: #{@name}  Nivel de combate: #{@combat_level} \n#{@prize.to_s}  \n#{@bad_consequence.to_s}\n"
  end


 end
