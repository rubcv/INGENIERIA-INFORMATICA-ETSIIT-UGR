#encoding: utf-8
=begin
  Para permitir uso de tildes
=end
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative "treasure.rb"
require_relative "monster.rb"
require_relative "treasure_kind.rb"
require_relative "combat_result.rb"
require_relative "dice.rb"
require_relative "prize.rb"
require_relative "card_dealer.rb"
require_relative "bad_consequence.rb"
require_relative "napakalaki.rb"
require_relative "player.rb"

module Napakalaki


class PruebaNapakalaki

=begin


  def self.main #Definir main como metodo para luego llamarlo

    @@monsters = Array.new


    # EL REY DE ROSADO

    p1 = Prize.new(4,2)
    bC1 = BadConsequence.newLevelNumberOfTreasures("Pierdes 5 niveles y 3 tesoros visibles", 5, 3, 0)
    @@monsters << Monster.new("El rey de rosado", 13, p1, bC1)


    # DEMONIOS DE MAGALUF

    p2 = Prize.new(4,1)
    bC2 = BadConsequence.newLevelSpecificTreasures("Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 oculta", 0, [TreasureKind::ONEHAND], [TreasureKind::ONEHAND])
    @@monsters << Monster.new("Demonios de Magaluf", 14, p2, bC2)


    # BYANKHEES DE BONANZA

    p3 = Prize.new(2,1)
    bC3 = BadConsequence.newLevelSpecificTreasures("Pierdes tu armadura visible y otra oculta", 0, [TreasureKind::ARMOR], [TreasureKind::ARMOR])
    @@monsters << Monster.new("Byankhees de bonanza", 8, p3, bC3)


    # TENOCHTITLAN

    p4 = Prize.new(1,1)
    bC4 = BadConsequence.newLevelSpecificTreasures("Embobados con el lindo primigenio te descartas de tu casco visible", 0, [TreasureKind::HELMET], nil)
    @@monsters << Monster.new("Tenochtitlan", 2, p4, bC4)


    # EL SOPOR DE DUNWICH

    p5 = Prize.new(1,1)
    bC5 = BadConsequence.newLevelSpecificTreasures("El primordial bostezo contagioso. Pierdes el calzado visible", 0, [TreasureKind::SHOES], nil)
    @@monsters << Monster.new("El sopor de Dunwich", 2, p5, bC5)


    # EL GORRON EN EL UMBRAL

    p6 = Prize.new(3,1)
    bC6 = BadConsequence.newLevelNumberOfTreasures("Pierdes todos tus tesoros visibles", 0, 5, 0)
    @@monsters << Monster.new("El gorron en el umbral", 13, p6, bC6)


    # H.P. MUNCHCRAFT

    p7 = Prize.new(2,1)
    bC7 = BadConsequence.newLevelSpecificTreasures("Pierdes la armaudura visible", 0, [TreasureKind::ARMOR], nil)
    @@monsters << Monster.new("H.P. Munchcraft", 6, p7, bC7)


    # NECROFAGO

    p8 = Prize.new(1,1)
    bC8 = BadConsequence.newLevelSpecificTreasures("Sientes bichos bajo la ropa. Descarta la armadura visible", 0, [TreasureKind::ARMOR], nil)
    @@monsters << Monster.new("Necrofago", 13, p8, bC8)


    # FLECHER

    p9 = Prize.new(1,1)
    bC9 = BadConsequence.newLevelNumberOfTreasures("Toses los pulmones y pierdes 2 niveles", 2, 0, 0)
    @@monsters << Monster.new("Flecher", 2, p9, bC9)


    # LOS HONDOS

    p10 = Prize.new(2,1)
    bC10 = BadConsequence.newDeath("Estos monstruos resultan bastante superficiales y te aburren mortalmente. Estas muerto")
    @@monsters << Monster.new("Los Hondos", 8, p10, bC10)

    # SEMILLAS CTHULHU

    p11 = Prize.new(2,1)
    bC11 = BadConsequence.newLevelNumberOfTreasures("Pierdes 2 niveles y 2 tesoros ocultos", 2, 0, 2)
    @@monsters << Monster.new("Semillas Cthulhu", 4, p11, bC11)


    # DAMEARGO

    p12 = Prize.new(2,1)
    bC12 = BadConsequence.newLevelSpecificTreasures("Te intentas escaquear. Pierdes una mano visible", 0, [TreasureKind::ONEHAND], nil)
    @@monsters << Monster.new("Dameargo", 1, p12, bC12)


    # POLLIPOLIPO VOLANTE

    p13 = Prize.new(2,1)
    bC13 = BadConsequence.newLevelNumberOfTreasures("Da mucho asquito. Pierdes 3 niveles", 3, 0, 0)
    @@monsters << Monster.new("Pollipolipo volante", 3, p13, bC13)


    # YSKHTIHYSSG-GOTH

    p14 = Prize.new(3,1)
    bC14 = BadConsequence.newDeath("No le hace gracia que pronuncien mal su nombre. Estas muerto")
    @@monsters << Monster.new("Yskhtihyssg-Goth", 14, p14, bC14)


    # FAMILIA FELIZ

    p15 = Prize.new(3,1)
    bC15 = BadConsequence.newDeath("La familia te atrapa. Estas muerto")
    @@monsters << Monster.new("Familia feliz", 1, p15, bC15)


    # ROBOGGOTH

    p16 = Prize.new(2,1)
    bC16 = BadConsequence.newLevelSpecificTreasures("La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible", 2, [TreasureKind::BOTHHANDS], nil)
    @@monsters << Monster.new("Roboggoth", 8, p16, bC16)


    # EL ESPIA SORDO

    p17 = Prize.new(1,1)
    bC17 = BadConsequence.newLevelSpecificTreasures("Te asusta en la noche. Pierdes un casco visible", 0, [TreasureKind::HELMET], nil)
    @@monsters << Monster.new("El espia sordo", 5, p17, bC17)


    # TONGUE

    p18 = Prize.new(2,1)
    bC18 = BadConsequence.newLevelNumberOfTreasures("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles", 2, 5, 0)
    @@monsters << Monster.new("Tongue", 19, p18, bC18)


    # BICEFALO

    p19 = Prize.new(2,1)
    bC19 = BadConsequence.newLevelSpecificTreasures("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos", 3, [TreasureKind::ONEHAND, TreasureKind::BOTHHANDS], nil)
    @@monsters << Monster.new("Bicefalo", 21, p19, bC19)



    # NIVEL COMBATE > 10

    def self.combatsup10
      clvl = Array.new
      @@monsters.each do |m|
        if m.combatLevel > 10
          clvl << m
        end
      end

      for i in 0...clvl.length
         puts clvl[i].to_s
      end
    end


    # BADCONSEQUENCE SOLO PERDIDA DE NIVEL

    def self.perdidanivel
      plvl = Array.new
      @@monsters.each do |m|
        if m.bC.levels > 0 && m.bC.nVisibleTreasures == 0 && m.bC.nHiddenTreasures == 0 && m.bC.specificVisibleTreasures == nil && m.bC.specificHiddenTreasures == nil
          plvl << m
        end
      end

      for i in 0...plvl.length
         puts plvl[i].to_s
      end
    end


    # PRIZE CON GANANCIA DE NIVEL SUPERIOR A 1

     def self.ganancianivel
      glvl = Array.new
      @@monsters.each do |m|
        if m.prize.level > 1
          glvl << m
        end
      end

      for i in 0...glvl.length
         puts glvl[i].to_s
      end
    end

    # PERDIDA DE TESORO ESPECIFICO

    def self.perdidatesoro(uno)
      res = Array.new
      @@monsters.each do |m|
        if m.bC.specificVisibleTreasures == uno || m.bC.specificHiddenTreasures == uno
          res << m
        end
      end

      for i in 0...res.length
         puts res[i].to_s
      end
    end



#MAIN










# MAIN
    puts "----------------------------------------------------\n\n"
    puts "Monstruos con nivel de combate superior a 10" + "\n\n"
    PruebaNapakalaki.combatsup10
    puts "----------------------------------------------------\n\n"

    puts "BadConsequence solo perdida de nivel" + "\n\n"
    PruebaNapakalaki.perdidanivel
    puts "----------------------------------------------------\n\n"

    puts "Ganancia de nivel superior a 1" + "\n\n"
    PruebaNapakalaki.ganancianivel
    puts "----------------------------------------------------\n\n"

    puts "Perdida de un determinado tipo de tesoro" + "\n\n"
    puts TreasureKind::ARMOR
    puts"\n"
    PruebaNapakalaki.perdidatesoro([TreasureKind::ARMOR])
    puts "\n\n"
    puts TreasureKind::ONEHAND
    puts"\n"
    PruebaNapakalaki.perdidatesoro([TreasureKind::ONEHAND])
    puts "\n\n"
    puts TreasureKind::BOTHHANDS
    puts"\n"
    PruebaNapakalaki.perdidatesoro([TreasureKind::BOTHHANDS])
    puts "\n\n"
    puts TreasureKind::HELMET
    puts"\n"
    PruebaNapakalaki.perdidatesoro([TreasureKind::HELMET])
    puts "\n\n"
    puts TreasureKind::SHOES
    puts"\n"
    PruebaNapakalaki.perdidatesoro([TreasureKind::SHOES])
    puts"\n\n"
    puts "----------------------------------------------------\n\n"

# -------------------------------------------------------------------------------
end

PruebaNapakalaki.main #llamar a main

=end

end
end
