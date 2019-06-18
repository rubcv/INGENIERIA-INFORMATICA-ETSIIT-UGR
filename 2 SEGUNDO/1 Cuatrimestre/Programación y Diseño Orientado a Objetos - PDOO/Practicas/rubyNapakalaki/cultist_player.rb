
class CultistPlayer < Player

  attr_accessor :total_cultist_players , :my_cultist_card


     def initialize(p, c)
       copia(p)
       @my_cultist_card = c

     end


    def get_combat_level

        sol = get_combat_level
        sol = sol * 1.20
        sol = sol + @my_cultist_card.get_gained_levels * @total_cultist_players

      sol

    end

    protected :get_combat_level

    def get_oponent_level(m)
       m.get_combat_level_against_cultist_player

    end

    protected :get_oponent_level

    def should_convert

      sol =false

      sol
    end

    protected :should_convert

     def giveMeATreasure

       pos_aleatorio = Random.rand(0..(@visible_treasures.length-1))
       res = @visible_treasures.at(pos_aleatorio)

       res
     end

     private :giveMeATreasure

    def canYouGiveMeATreasure

      res = false

      if @visible_treasures.length > 0

          res = true

      res
      end
    end

    private :canYouGiveMeATreasure

    def  getTotalCultistPlayers

        @total_cultist_players

    end


end
