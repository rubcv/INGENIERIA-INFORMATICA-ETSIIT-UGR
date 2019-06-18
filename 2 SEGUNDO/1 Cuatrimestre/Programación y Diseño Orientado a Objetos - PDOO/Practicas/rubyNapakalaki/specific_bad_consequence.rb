class SpecificBadConsequence < Bad_consequence

  attr_accessor :specificVisibleTreasures , :specificHiddenTreasures


  def initialize(text,levels,tVisible,tHidden)
        super(text, levels)
        @specificHiddenTreasures = tHidden
        @specificVisibleTreasures = tVisible
  end

  def getVisibleTreasures
       @specificVisibleTreasures
  end

  def getHiddenTreasures
       @specificHiddenTreasures
  end

  def to_s
    "#{@text} Pierdes: #{@levels} niveles #{@specificVisibleTreasures} tesoros visibles y #{@specificHiddenTreasures} tesoros ocultos"
  end

  def is_dead
       var = false
       var
  end

  def is_empty
       var = false
       if @text == "" and @levels == 0 and @specificVisibleTreasures.empty? and @specificHiddenTreasures.empty?
            var = true
         end

       var

  end

  def setnVisibleTreasures(n)
      raise NotImplementedError.new
  end

  def setnHiddenTreasures(n)
      raise NotImplementedError.new
  end

  def getnVisibleTreasures
      return 0
  end

  def getnHiddenTreasures
      return 0
  end

  def substract_visible_treasure(t)
      @specificVisibleTreasure.delete(t.type)
  end

  def substract_hidden_treasure(t)
      @specificHiddenTreasure.delete(t.type)
  end

def adjust_to_fit_treasure_list(v, h)
     visible = Array.new
     hidden = Array.new

        v.each do |t|

            if @specificVisibleTreasures.include?(t.type) == true
                visible << t.type
            end
        end


        h.each do |t|

            if @specificHiddenTreasures.include?(t.type) == true
                hidden << t.type
            end
        end

        bad_cons = SpecificBadConsequence.new('', @levels, visible, hidden)
        bad_cons
  end


end
