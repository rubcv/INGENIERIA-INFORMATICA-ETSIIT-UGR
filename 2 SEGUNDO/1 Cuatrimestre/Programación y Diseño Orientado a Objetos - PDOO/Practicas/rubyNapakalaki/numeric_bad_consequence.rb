
class NumericBadConsequence < Bad_consequence


    attr_accessor :nVisibleTreasures , :nHiddenTreasures

  def initialize(text, levels , nVisible, nHidden)
     super(text, levels)
     @nVisibleTreasures = nVisible
     @nHiddenTreasures = nHidden

  end


    def is_dead
      res = false

      res
    end

    def substract_visible_treasure(t)
      @nVisibleTreasures = @nVisibleTreasures-1
    end

   def substract_hidden_treasure(t)

       @nHiddenTreasures = @nHiddenTreasures -1
   end

    def setnVisibleTreasures(n)

        @nVisibleTreasures = n
    end

    def setnHiddenTreasures(n)

        @nHiddenTreasures = n
    end

    def getnVisibleTreasures
       @nVisibleTreasures
    end

    def getnHiddenTreasures
        @nHiddenTreasures
    end

    def is_empty
       res = false
         if @text == "" and @levels == 0 and @nVisibleTreasures == 0 and @nHiddenTreasures == 0
                    res = true
         end

       res

    end

    def adjust_to_fit_treasure_list(v, h)

         visibles=0
         ocultos=0
         tam_v = v.length
         tam_h = h.length

         if @nVisibleTreasures <= tam_v
               visibles = @nVisibleTreasures

         else

            if tam_v < @nVisibleTreasures
                          visibles = tam_v
           end
         end

         if @nHiddenTreasures <= tam_h
                        ocultos = @nHiddenTreasures

         else

            if tam_h < @nHiddenTreasures
                       ocultos = tam_h
            end
         end

          res = NumericBadConsequence.new("",getLevels,visibles,ocultos)

    res
   end

    def to_s

      "#{@text} Pierdes: #{@levels} niveles #{@nVisibleTreasures} tesoros visibles y #{@nHiddenTreasures} tesoros ocultos"
    end

end
