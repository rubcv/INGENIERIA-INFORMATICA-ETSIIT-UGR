class DeathBadConsequence < NumericBadConsequence

  attr_accessor :death


  def initialize(text)
    super(text,0,0,0)
    @death = true
  end

  def adjust_to_fit_treasure_list(v, h)
      bad_cons = DeathBadConsequence.new('')
      bad_cons
  end

end
