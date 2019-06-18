require_relative "napakalaki.rb"
require_relative "GameTester.rb"

module NapakalakiGame

  class EjemploMain

      def prueba

       test = Test::GameTester.instance

       game = Napakalaki.instance

       test.play(game, 2);

      end

  end

    e = EjemploMain.new
    e.prueba()

end
