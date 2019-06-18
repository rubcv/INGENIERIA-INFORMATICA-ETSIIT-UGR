# encoding: utf-8

# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require 'singleton'
require_relative 'napakalaki.rb'
require_relative 'Command.rb'

module Test

class GameTester

  include Singleton

  public
  def play(aGame, numberOfPlayers)

    @game = aGame
    names = getPlayerNames(numberOfPlayers)
    @game.initGame(names)

    begin #Mientras dure la partida
      currentPlayer=@game.getCurrentPlayer()
      begin #Mientras el jugador se decide a conocer al monstruo
        puts "******* ******* ******* ******* ******* ******* *******"
        puts "\n\n Turno de: " + currentPlayer.to_s()
        command = getCommandBeforeKnowingMonster()
        command = processCommand(command, currentPlayer)
      end while (command != Command::Exit && command != Command::ShowMonster)
      if (command == Command::ShowMonster) then
        begin #Mientras el jugador se decida a combatir
          puts "******* ******* ******* ******* ******* ******* *******"
          puts "\n\n Turno de: " + currentPlayer.to_s()
          command = getCommandBeforeFighting()
          command = processCommand(command, currentPlayer)
        end while (command != Command::Exit && command != Command::Combat)
        if (command == Command::Combat) then
          combatResult = @game.developCombat()
          case combatResult
            when NapakalakiGame::CombatResult::WINGAME then
              puts "\n\n       " + currentPlayer.getName()
              puts "\n\n HAS GANADO LA PARTIDA"
              #break está implícito
            when NapakalakiGame::CombatResult::WIN then
              puts "\n\n Ganaste el combate"
            when NapakalakiGame::CombatResult::LOSEANDCONVERT then
              puts "\n\n Pierdes y te conviertes en Sectario"
            when NapakalakiGame::CombatResult::LOSE then
              puts "\n\n Has perdido el combate, te toca cumplir el mal rollo"
           end #case
           if (combatResult != NapakalakiGame::CombatResult::WINGAME) then
            begin #Hasta que se avance de turno
              puts "******* ******* ******* ******* ******* ******* *******"
              puts "\n\n Turno de: " + currentPlayer.to_s()
              if currentPlayer.canISteal then
                command = getCommandAfterFighting()
              else
                command = getCommandAfterFightingNoSteal()
              end
              command = processCommand(command, currentPlayer)
            end while (command != Command::Exit && command != Command::NextTurnAllowed)
          else
            command = Command::Exit;
          end #if WINANDWINGAME
        end #if COMBAT
      end #if SHOWMOnSTER
    end while (command != Command::Exit) #mientras dure la partida

  end

  private

  def getCommandAfterFighting()
      commands = [Command::ShowMonster, Command::ShowVisibleTreasure, Command::ShowHiddenTreasure,
      Command::DiscardVisibleTreasure, Command::DiscardHiddenTreasure, Command::DiscardAll,
      Command::MakeTreasureVisible, Command::StealTreasure, Command::NextTurn, Command::Exit]
      manageMenu("Opciones antes de pasar turno", commands)
  end

  def getCommandAfterFightingNoSteal()
      commands = [Command::ShowMonster, Command::ShowVisibleTreasure, Command::ShowHiddenTreasure,
      Command::DiscardVisibleTreasure, Command::DiscardHiddenTreasure, Command::DiscardAll,
      Command::MakeTreasureVisible, Command::NextTurn, Command::Exit]
      manageMenu("Opciones antes de pasar turno", commands)
  end

  def getCommandBeforeFighting ()
      commands = [Command::ShowMonster, Command::ShowVisibleTreasure, Command::ShowHiddenTreasure,
      Command::Combat, Command::Exit]
      manageMenu("Opciones antes de combatir", commands)
  end

  def getCommandBeforeKnowingMonster ()
      commands = [Command::ShowMonster,Command::ShowVisibleTreasure, Command::ShowHiddenTreasure,
      Command::MakeTreasureVisible,  Command::Exit]
      manageMenu("Opciones antes de conocer al monstruo", commands)
  end

  def getPlayerNames (numberOfPlayers)
    names = Array.new
    for i in 1..numberOfPlayers
      puts "Escribe el nombre del jugador #{i}: "
      names << gets.chomp
    end
    names
  end

  def getTreasure (howMany)

    validInput = true
    option = Command::GoBack.menu
    puts "\n Elige un tesoro: "
    capture = gets.chomp

    begin #tratar la excepcion
      option = Integer(capture)
      if (option < Command::GoBack.menu || option > howMany) then #no se ha escrito un entero en el rango permitido
        validInput = false
      end
    rescue Exception => e
      validInput = false
    end

    if (! validInput) then
      inputErrorMessage()
      return -2  # Muestra de nuevo el menu y pide otra entrada
    end
    option
  end

  def inputErrorMessage ()
    puts "\n\n ERROR !!! \n\n Selección errónea. Inténtalo de nuevo.\n\n"
  end

  def manageDiscardTreasures (visible, aPlayer)

    begin #Se descartan tesoros hasta que se vuelve al menÃº anterior
      if visible then
        howMany = showTreasures("Elige tesoros visibles para descartar", aPlayer.getVisibleTreasures(), true)
      else
        howMany = showTreasures("Elige tesoros ocultos para descartar", aPlayer.getHiddenTreasures(), true)
      end
      option = getTreasure (howMany)
      if (option > -1) then
        if visible then
          @game.discardVisibleTreasure ([aPlayer.getVisibleTreasures().at(option)])
        else
          @game.discardHiddenTreasure ([aPlayer.getHiddenTreasures().at(option)])
        end
      end
    end while (option != -1)
  end

  def manageMakeTreasureVisible (aPlayer)

    begin #Se hacen tesoros visibles hasta que se vuelve al menÃº anterior
      howMany = showTreasures("Elige tesoros para intentar hacerlos visibles", aPlayer.getHiddenTreasures(), true)
      option = getTreasure (howMany);
      if (option > -1) then
        aPlayer.makeTreasureVisible (aPlayer.getHiddenTreasures()[option])
      end
    end while (option != -1)
  end

  def manageMenu (message, menu)
    menuCheck = Hash.new #Para comprobar que se hace una selecciÃ³n vÃ¡lida
    menu.each do |c|
      menuCheck [c.menu] = c
    end
    begin #Hasta que se hace una selecciÃ³n vÃ¡lida
      validInput = true
      option = Command::GoBack.menu
      puts ("\n\n------- ------ ------ ------ ------ ------ ------")
      puts "**** " + message + " ****\n"
      menu.each do |c| #se muestran las opciones del menÃº
        puts "#{c.menu}" + " : " + c.text
      end
      puts "\n Elige una opción: "
      capture = gets.chomp
      begin
        option = Integer(capture)
        if (! menuCheck.has_key?(option)) #No es un entero entre los vÃ¡lidos
          validInput = false
        end
      rescue Exception => e  #No se ha introducido un entero
        validInput = false
      end

      if (! validInput) then
        inputErrorMessage()
      end
    end while (! validInput)
    menuCheck[option]
  end

  def processCommand (command, aPlayer)
    case command
      when Command::Exit then
        puts "exit"
      when Command::Combat then
        puts "combat"
#        puts "pulsa enter para seguir"
#        gets
      when  Command::ShowMonster then
        puts "\n------- ------- ------- ------- ------- ------- ------- "
        puts "El monstruo actual es:\n\n" + @game.getCurrentMonster().to_s()
#        puts "pulsa enter para seguir"
#        gets
      when Command::ShowVisibleTreasure then
        showTreasures("Esta es tu lista de tesoros visibles", aPlayer.getVisibleTreasures(), false)
#        puts "pulsa enter para seguir"
#        gets
      when Command::ShowHiddenTreasure then
        showTreasures("Esta es tu lista de tesoros ocultos", aPlayer.getHiddenTreasures(), false)
#        puts "pulsa enter para seguir"
#        gets
      when Command::MakeTreasureVisible then
        manageMakeTreasureVisible (aPlayer)
#        puts "pulsa enter para seguir"
#        gets
      when Command::DiscardVisibleTreasure then
        manageDiscardTreasures(true, aPlayer)
#        puts "pulsa enter para seguir"
#        gets
      when Command::DiscardHiddenTreasure then
        manageDiscardTreasures(false, aPlayer)
#        puts "pulsa enter para seguir"
#        gets
      when Command::DiscardAll then
        aPlayer.discardAllTreasures
      when Command::StealTreasure then
        aTreasure = aPlayer.stealTreasure;
        if aTreasure == nil
          puts "\n\n No has podido robar nada \n\n"
        else
          puts "\n\n Has robado este tesoro: \n\n #{aTreasure.to_s}"
        end
      when Command::NextTurn then
        if ! @game.nextTurn() then
          puts "\n\n ERROR \n"
          puts "No cumples las condiciones para pasar de turno."
          puts "O bien tienes más de 4 tesoros ocultos"
          puts "O bien te queda mal rollo por cumplir"
        else
          command = Command::NextTurnAllowed
        end
#        puts "pulsa enter para seguir"
#        gets
    end
    command
  end

  def showTreasures (message, treasures, menu)
    optionMenu = Command::GoBack.menu

    puts "\n------- ------- ------- ------- ------- ------- -------"
    puts message
    if menu then
      puts "\n #{Command::GoBack.menu} : " + Command::GoBack.text
    end
    treasures.each do |t|
      optionMenu = optionMenu + 1
      if (menu)
         puts "\n" + optionMenu.to_s() + ":" + t.to_s()
      else
         puts "\n" + t.to_s()
      end

    end
    optionMenu
  end

 end #clase
end #modulo
