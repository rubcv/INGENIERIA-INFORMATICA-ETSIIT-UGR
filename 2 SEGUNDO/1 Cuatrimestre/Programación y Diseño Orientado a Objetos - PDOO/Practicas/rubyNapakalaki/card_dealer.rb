
require_relative 'prize.rb'
require_relative 'bad_consequence.rb'
require_relative 'monster.rb'
require_relative 'treasure_kind.rb'
require_relative 'cultist.rb'

require 'singleton'
class CardDealer

  include Singleton
  attr_accessor :unused_treasures ,:used_treasures, :unused_monster ,:used_monster, :used_cultist, :unused_cultist

  def initialize

  end

  def self.get_instance
    self.instance
  end

  def init_treasure_card_deck
      @unused_treasures = Array.new
      @used_treasures = Array.new
      @unused_treasures << Treasure.new("¡Si mi amo!", 4, [TreasureKind::HELMET])
      @unused_treasures << Treasure.new("Botas de investigación", 3, [TreasureKind::SHOES])
      @unused_treasures << Treasure.new("Capucha de Cthulhu", 3, [TreasureKind::HELMET])
      @unused_treasures << Treasure.new("A prueba de babas", 2, [TreasureKind::ARMOR])
      @unused_treasures << Treasure.new("Botas de lluvia ácida", 1, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Casco minero", 2, [TreasureKind::HELMET])
      @unused_treasures << Treasure.new("Ametralladora ACME", 4, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Camiseta de la ETSIIT", 1, [TreasureKind::ARMOR])
      @unused_treasures << Treasure.new("Clavo de rail ferroviario", 3, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Cuchillo de sushi arcano", 2, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Fez alópodo", 3, [TreasureKind::HELMET])
      @unused_treasures << Treasure.new("Hacha prehistórica", 2, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("El aparato del Pr. Tesla", 4, [TreasureKind::ARMOR])
      @unused_treasures << Treasure.new("Gaita", 4, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Insecticida", 2, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Escopeta de 3 cañones", 4, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Garabato Mistico", 2, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("La rebeca metálica", 2, [TreasureKind::ARMOR])
      @unused_treasures << Treasure.new("Mazo de los antiguos", 3, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Lanzallamas", 4, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Necro-comicón", 1, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Necronomicón", 5, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Linterna a 2 manos", 3, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Necro-gnomicón", 2, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Necrotelecom", 2, [TreasureKind::HELMET])
      @unused_treasures << Treasure.new("Mazo de los antiguos", 3, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Necro-playboycon", 3, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Porra preternatural", 2, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Shogulador", 1, [TreasureKind::BOTHHANDS])
      @unused_treasures << Treasure.new("Varita de atizamiento", 3, [TreasureKind::ONEHAND])
      @unused_treasures << Treasure.new("Tentácula de pega", 2, [TreasureKind::HELMET])
      @unused_treasures << Treasure.new("Zapato deja-amigos", 1, [TreasureKind::SHOES])


  end
  private :init_treasure_card_deck

  def init_monster_card_deck
    @unused_monster = Array.new
    @used_monster = Array.new
    
     

    prize1 = Prize.new(2,1)

    bad_consequence1 = SpecificBadConsequence.new('Pierdes tu armadura visible y otra oculta.', 0 ,[TreasureKind::ARMOR],[TreasureKind::ARMOR])

    @unused_monster << Monster.new('Byakhees de bonanza', 8, bad_consequence1, prize1,0)

    

    prize2 = Prize.new(1,1)

    bad_consequence2 = SpecificBadConsequence.new('Embobados con el lindo primigenio te descartas de tu casco visible.', 0 ,[TreasureKind::HELMET],[])

    @unused_monster << Monster.new('Tenochtitlan', 2, bad_consequence2, prize2,0)

    

    prize3 = Prize.new(1,1)

    bad_consequence3 = SpecificBadConsequence.new('El primordial bostezo contagioso. Pierdes el calzado visible.', 0 ,[TreasureKind::SHOES],[])

    @unused_monster << Monster.new('EL sopor de Dunwich', 2, bad_consequence3, prize3,0)


    

    prize4 = Prize.new(4,1)

    bad_consequence4 = SpecificBadConsequence.new('Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta.', 0,
      [TreasureKind::ONEHAND],[TreasureKind::ONEHAND])

    @unused_monster << Monster.new('Angeles de la noche ibicenca', 14, bad_consequence4, prize4,0)

    

    prize5 = Prize.new(3,1)

    bad_consequence5 = NumericBadConsequence.new('Pierdes todos tus tesoros visibles.', 0 ,6,0)

    @unused_monster << Monster.new('El gorron en el umbral', 10, bad_consequence5, prize5,0)

    

    prize6 = Prize.new(2,1)

    bad_consequence6 = SpecificBadConsequence.new('Pierdes tu armadura visible.', 0, [TreasureKind::ARMOR],[])

    @unused_monster << Monster.new('H.P. Munchcraft', 6, bad_consequence6, prize6,0)

    

    prize7 = Prize.new(1,1)

    bad_consequence7 = SpecificBadConsequence.new('Sientes bichos bajo la ropa. Descartas la armadura visible.', 0, [TreasureKind::ARMOR],[])

    @unused_monster << Monster.new('Necrofago', 13, bad_consequence7, prize7,0)


    

    prize8 = Prize.new(4,2)

    bad_consequence8 = NumericBadConsequence.new('Pierdes 5 niveles y 3 tesoros visibles',5 , 3, 0)

    @unused_monster << Monster.new('El rey de rosa',13 , bad_consequence8 , prize8,0)

    

    prize9 = Prize.new(1,1)

    bad_consequence9 = NumericBadConsequence.new('Toses los pulmones y pierdes 2 niveles.',2 ,0, 0)

    @unused_monster << Monster.new('Flecher',2 , bad_consequence9 , prize9,0)

    

    prize10 = Prize.new(4,2)

    bad_consequence10 = DeathBadConsequence.new('Estos monstruos resultan bastantes superficiales y te aburren mortalmente. Estas muerto.')

    @unused_monster << Monster.new('Los hondos',8 , bad_consequence10 , prize10,0)

    

    prize11 = Prize.new(2,1)

    bad_consequence11 = NumericBadConsequence.new('Pierdes 2 niveles y 2 tesoros ocultos.',2 , 0, 2)

    @unused_monster << Monster.new('Semillas Cthulhu',4, bad_consequence11 , prize11,0)

    

    prize12 = Prize.new(2,1)

    bad_consequence12 = SpecificBadConsequence.new('Te intentas escaquear. Pierdes una mano visible.', 0, [TreasureKind::ONEHAND],[])

    @unused_monster << Monster.new('Dameargo',1, bad_consequence12 , prize12,0)

    

    prize13 = Prize.new(1,1)

    bad_consequence13 = NumericBadConsequence.new('Da mucho asquito. Pierdes 3 niveles.',3 , 0, 0)

    @unused_monster << Monster.new('Pollipolipo volante',3, bad_consequence13 , prize13,0)

    

    prize14 = Prize.new(3,1)

    bad_consequence14 = DeathBadConsequence.new('No le hace gracia que pronuncien mal su nombre. Estas muerto.')

    @unused_monster << Monster.new('Yskhtihyssg-Goth',12 , bad_consequence14 , prize14,0)

    

    prize15 = Prize.new(4,1)

    bad_consequence15 = DeathBadConsequence.new('La familia te atrapa. Estas muerto.')

    @unused_monster << Monster.new('Familia feliz',1 , bad_consequence15 , prize15,0)

    

    prize16 = Prize.new(2,1)

    bad_consequence16 = SpecificBadConsequence.new('La quinta directiva te obliga a perder 2 niveles y un tesoro de 2 manos visible.', 2, [TreasureKind::BOTHHANDS],[])

    @unused_monster << Monster.new('Roboggoth',8, bad_consequence16 , prize16,0)

    

    prize17 = Prize.new(1,1)

    bad_consequence17 = SpecificBadConsequence.new('Te asusta en la noche. Pierdes un casco visible.', 0, [TreasureKind::HELMET],[])

    @unused_monster << Monster.new('El espia sordo',5, bad_consequence17 , prize17,0)

    

    prize18 = Prize.new(1,1)

    bad_consequence18 = NumericBadConsequence.new('Menudo susto te llevas.Pierdes 2 niveles y 5 tesoros visibles.',2 , 5, 0)

    @unused_monster << Monster.new('Tongue',19, bad_consequence18 , prize18,0)

    

    prize19 = Prize.new(1,1)

    bad_consequence19 = SpecificBadConsequence.new('Te faltan manos para tanta cabeza. Pierdes todos tus tesoros visibles de las manos.', 0,
                            [TreasureKind::BOTHHANDS,TreasureKind::ONEHAND,TreasureKind::ONEHAND],[])

    @unused_monster << Monster.new('Bicefalo',21, bad_consequence19 , prize19,0)


    
       bad_consequence20 = SpecificBadConsequence.new('Pierdes una mano visible' ,0 ,
               [TreasureKind::ONEHAND],[])
       prize_20 = Prize.new(3,1)

      @unused_monster << Monster.new('El mal indecible impronunciable.' ,10 , bad_consequence20, prize_20, -2)

       
       bad_consequence21 =  NumericBadConsequence.new('Pierdes tus tesoros visibles. Jajaja',0 ,5,0)
       prize_21 = Prize.new(2,1)
       @unused_monster << Monster.new('Testigos Oculares.' ,6 , bad_consequence21, prize_21, +2)

       
       bad_consequence22 = DeathBadConsequence.new('Hoy no es tu dia de suerte. Mueres.')
       prize_22 = Prize.new(2,5)
       @unused_monster << Monster.new('El gran cthulhu.',20 , bad_consequence22, prize_22,+4)

       
       bad_consequence23 = NumericBadConsequence.new('Tu gobierno te recorta dos niveles.' ,2 ,0,0)
       prize_23 = Prize.new(2,1)
       @unused_monster << Monster.new('Serpiente politico.' ,8 , bad_consequence23, prize_23, -2)

       
       bad_consequence24 = SpecificBadConsequence.new('Pierdes tu casco y armadura visible. Pierdes tus manos ocultas.' ,0 ,
               [TreasureKind::HELMET,TreasureKind::ARMOR],[TreasureKind::BOTHHANDS,TreasureKind::ONEHAND,TreasureKind::ONEHAND])
       prize_24  = Prize.new(1,1)
       @unused_monster << Monster.new('Felpuggoth.' ,2 , bad_consequence24, prize_24, +5)

       
       bad_consequence25 = NumericBadConsequence.new('Pierdes dos niveles.' ,2 ,0,0)
       prize_25 = Prize.new(4,2)
       @unused_monster <<  Monster.new('Shoggoth.' ,16 , bad_consequence25, prize_25, -4)

       
       bad_consequence26 = NumericBadConsequence.new('Pintalabios negro. Pierdes dos niveles.' ,2 ,0,0)
       prize_26 = Prize.new(1,1)
       @unused_monster << Monster.new('Lolitaggoth.' ,2 , bad_consequence26, prize_26, +3)

    

  end

  private :init_monster_card_deck



   def init_cultist_card_deck
    @unused_cultist = Array.new
    @unused_cultist << Cultist.new('Sectario', 1)
    @unused_cultist << Cultist.new('Sectario', 2)
    @unused_cultist << Cultist.new('Sectario', 1)
    @unused_cultist << Cultist.new('Sectario', 2)
    @unused_cultist << Cultist.new('Sectario', 1)
    @unused_cultist << Cultist.new('Sectario', 1)

    end

   private :init_cultist_card_deck


   def shuffle_cultist
    @unused_cultist = @unused_cultist.shuffle
   end

  def shuffle_treasures
    @unused_treasures = @unused_treasures.shuffle
  end

  def shuffle_monster
    @unused_monster = @unused_monster.shuffle
  end

  def next_cultist

      if @unused_cultist.empty?

        @used_cultist.each do |cultist|

          @unused_cultist<<cultist

        end

        shuffle_cultist
        @used_cultist.clear

      end

      cultist = @unused_cultist.at(0)

      @used_cultist<<cultist

      @unused_cultist.delete(cultist)
      cultist

  end

  def next_treasure

      if @unused_treasures.empty?

        @used_treasures.each do |treasure|

          @unused_treasures<<treasure

        end

        shuffle_treasures
        @used_treasures.clear

      end

      treasure = @unused_treasures.at(0)

      @used_treasures<<treasure

      @unused_treasures.delete(treasure)
      treasure

  end

  def next_monster
    if @unused_monster.empty?

        @used_monster.each do |monster|

          @unused_monster<<monster

        end

        shuffle_monster
        @used_monster.clear

      end

      monster = @unused_monster.at(0)

      @used_monster<<monster

      @unused_monster.delete(monster)
      monster

  end

  def give_cultist_back(cultist)
    @used_cultist<< cultist
  end

  def give_treasure_back(treasure)
    @used_treasures << treasure
  end

  def give_monster_back(monster)
    @used_monster << monster
  end

  def init_cards
    init_cultist_card_deck
    init_treasure_card_deck
    init_monster_card_deck
    shuffle_cultist
    shuffle_treasures
    shuffle_monster
  end

end
