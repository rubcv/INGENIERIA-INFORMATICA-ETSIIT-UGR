#encoding: utf-8

class Bad_consequence
  attr_accessor :text ,:levels



  def initialize (t, l)
    @text = t
    @levels = l
  end


  def to_s()
    "Texto: #{@text} Niveles perdidos: #{@levels} "
  end

  def setLevels(l)

    @levels = l

  end

  def is_empty

    empty = false
         if @text == "" and @levels == 0
              empty = true
         end
    empty

  end

  def getLevels
    @levels
  end

  def getText
    @text
  end

  def substract_visible_treasure(t)
    raise NotImplementedError.new
  end

  def substract_hidden_treasure(t)
    raise NotImplementedError.new
  end

  def is_dead
    raise NotImplementedError.new
  end

  def setnVisibleTreasures(n)
      raise NotImplementedError.new
  end

  def setnHiddenTreasures(n)
      raise NotImplementedError.new
  end

  def getnVisibleTreasures
      raise NotImplementedError.new
  end

  def getnHiddenTreasures
      raise NotImplementedError.new
  end




  def adjust_to_fit_treasure_list(v, h)
      raise NotImplementedError.new

  end

end
