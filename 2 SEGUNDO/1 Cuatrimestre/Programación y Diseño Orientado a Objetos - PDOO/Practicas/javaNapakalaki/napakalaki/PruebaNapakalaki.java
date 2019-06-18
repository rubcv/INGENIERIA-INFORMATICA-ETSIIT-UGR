/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.ArrayList;
import java.util.Arrays;




/**
 *
 * @author manjaro
 */
public final class PruebaNapakalaki{
        public static ArrayList<Monster> monstruos = new ArrayList<Monster>();

        public ArrayList<Monster> ConsultaNivel(){
           ArrayList<Monster> consultanivel = new ArrayList<Monster>();

           for(Monster m: monstruos){
               if(m.getCombatLevel() > 10){
                   consultanivel.add(m);
               }
            }
           return consultanivel;
        }

        public ArrayList<Monster> ConsultaPerdidaNivel(){
            ArrayList<Monster> perdidanivel = new ArrayList<Monster>();

            for(Monster m: monstruos){
                if((((m.getBC()).getLevels()) > 0) && (m.getBC().getnVisibleTreasures() == 0) && (m.getBC().getnHiddenTreasures() == 0) && (m.getBC().getVisibleTreasures().isEmpty()) && (m.getBC().getHiddenTreasures().isEmpty())){
                    perdidanivel.add(m);
                }
            }
            return perdidanivel;
         }



        public ArrayList<Monster> ConsultaGananciaNivel(){
            ArrayList<Monster> ganancianivel = new ArrayList<Monster>();

            for(Monster m: monstruos){
                if(m.getPremio().getLevels() > 1){
                    ganancianivel.add(m);
                }
            }
            return ganancianivel;
         }


        public ArrayList<Monster> ConsultaPerdidaTesoro(TreasureKind tesoro){
            ArrayList<Monster> perdidatesoro = new ArrayList<Monster>();

            for(Monster m: monstruos){
                if(!(m.getBC().getHiddenTreasures()).contains(tesoro) && !(m.getBC().getVisibleTreasures()).contains(tesoro)){
                } else {
                    perdidatesoro.add(m);
                }
            }
            return perdidatesoro;
         }



    /**
     * @param args the command line arguments
     */
     public void pruebaMetodos() {

        // DECLARACION DE MONSTRUOS

        // EL REY ROSADO
        BadConsequence bc1 = new BadConsequence("Pierdes 5 niveles y 3 tesoros visibles", 5, 3, 0);
        Prize p1 = new Prize(4,2);
        monstruos.add(new Monster("El rey de rosado", 13, bc1, p1));

        // ANGELES DE LA NOCHE IBICENCA || DEMONIOS DE MAGALUF
        BadConsequence bc2 = new BadConsequence("Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND)));
        Prize p2 = new Prize(4,1);
        monstruos.add(new Monster("Demonios de Magaluf", 14, bc2, p2));


        // BYANKHEES DE BONANZA

        BadConsequence bc3 = new BadConsequence("Pierdes tu armadura visible y otra oculta", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)),  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)));
        Prize p3 = new Prize(2, 1);
        monstruos.add(new Monster("Byankhees de bonanza", 8, bc3, p3));


        // TENOCHTITLAN

        BadConsequence bc4 = new BadConsequence("Embobados con el lindo primigenio te descartas de tu casco visible", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.HELMET)), new ArrayList<TreasureKind>());
        Prize p4 = new Prize(1,1);
        monstruos.add(new Monster("Tenochtitlan", 2, bc4, p4));

        // EL SOPOR DE DUNWICH

        BadConsequence bc5 = new BadConsequence("El primordial bostezo contagioso. Pierdes el calzado visible", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.SHOES)), new ArrayList<TreasureKind>());
        Prize p5 = new Prize(1,1);
        monstruos.add(new Monster("El sopor de Dunwich", 2, bc5, p5));

        // EL GORRON EN EL UMBRAL

        BadConsequence bc6 = new BadConsequence("Pierdes todos tus tesoros visibles", 0, 5, 0);
        Prize p6 = new Prize(3,1);
        monstruos.add(new Monster("El gorron en el umbral", 13, bc6, p6));

        // H.P. MUNCHCRAFT

        BadConsequence bc7 = new BadConsequence("Pierdes la armadura visible", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)), new ArrayList<TreasureKind>());
        Prize p7 = new Prize(2,1);
        monstruos.add(new Monster("H.P. Munchcraft", 6, bc7, p7));

        // NECROFAGO

        BadConsequence bc8 = new BadConsequence("Sientes bichos bajo la ropa. Descarta la armadura visible", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)), new ArrayList<TreasureKind>());
        Prize p8 = new Prize(1,1);
        monstruos.add(new Monster("Necrofago", 13, bc8, p8));

        // FLECHER

        BadConsequence bc9 = new BadConsequence("Toses los pulmones y pierdes 2 niveles", 2, 0, 0);
        Prize p9 = new Prize(1,1);
        monstruos.add(new Monster("Flecher", 2, bc9, p9));

        // LOS HONDOS

        BadConsequence bc10 = new BadConsequence("Estos monstruos resultan bastante superficiales y te aburren mortalmente. Estas muerto", true);
        Prize p10 = new Prize(2,1);
        monstruos.add(new Monster("Los Hondos", 8, bc10, p10));

        // SEMILLAS CTHULHU

        BadConsequence bc11 = new BadConsequence("Pierdes 2 niveles y 2 tesoros ocultos", 2, 0, 2);
        Prize p11 = new Prize(2,1);
        monstruos.add(new Monster("Semillas Cthulhu", 4, bc11, p11));


        // DAMEARGO

        BadConsequence bc12 = new BadConsequence("Te intentas escaquear. Pierdes una mano visible", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList<TreasureKind>());
        Prize p12 = new Prize(2,1);
        monstruos.add(new Monster("Dameargo", 1, bc12, p12));

        // POLLIPOLIPO VOLANTE

        BadConsequence bc13 = new BadConsequence("Da mucho asquito. Pierdes 3 niveles", 3, 0, 0);
        Prize p13 = new Prize(2,1);
        monstruos.add(new Monster("Pollipolipo volante", 3, bc13, p13));

        // YSKHTIHYSSG-GOTH

        BadConsequence bc14 = new BadConsequence("No le hace gracia que pronuncien mal su nombre. Estas muerto", true);
        Prize p14 = new Prize(3,1);
        monstruos.add(new Monster("Yskhtihyssg-Goth", 14, bc14, p14));

        // FAMILIA FELIZ

        BadConsequence bc15 = new BadConsequence("La familia te atrapa. Estas muerto", true);
        Prize p15 = new Prize(3,1);
        monstruos.add(new Monster("Familia Feliz", 1, bc15, p15));

        // ROBOGGOTH

        BadConsequence bc16 = new BadConsequence("La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible", 2,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.BOTHHANDS)), new ArrayList<TreasureKind>());
        Prize p16 = new Prize(2,1);
        monstruos.add(new Monster("Roboggoth", 8, bc16, p16));

        // EL ESPIA SORDO

        BadConsequence bc17 = new BadConsequence("Te asusta en la noche. Pierdes un casco visible", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.HELMET)), new ArrayList<TreasureKind>());
        Prize p17 = new Prize(1,1);
        monstruos.add(new Monster("El espia sordo", 5, bc17, p17));

        // TONGUE

        BadConsequence bc18 = new BadConsequence("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles", 2, 5, 0);
        Prize p18 = new Prize(2,1);
        monstruos.add(new Monster("Tongue", 19, bc18, p18));

        // BICEFALO

        BadConsequence bc19 = new BadConsequence("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos", 3,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND, TreasureKind.BOTHHANDS )), new ArrayList<TreasureKind>());
        Prize p19 = new Prize(2,1);
        monstruos.add(new Monster("Bicefalo", 21, bc19, p19));



        // ----------------------------------------------------------------------------------------------------------




        /* --------------------------------------------- Prueba Napakalaki --------------------------------------------- */








              // -------------------------------------------------------------
                // Player uno = new Player(), dos = new Player();
                //
                // BadConsequence bc = new BadConsequence("Hola", 3, 2, 2);
                // Prize p = new Prize(1,1);
                // Monster monstruo = new Monster("Monstruo-prueba", 5, bc, p);
                //
                // uno.applyPrize(monstruo);

              // -------------------------------------------------------------








/*
        // IMPRIMIR MONSTRUOS

        for(Monster m: monstruos){
           System.out.println();
           System.out.println(m.toString());
        }


        System.out.println("---------- FIN DE IMPRIMIR MONSTRUOS ----------");

        // PRUEBA DE MAIN
        System.out.println("----------------------------------------------");
        System.out.println("Prueba de consulta nivel > 10\n\n");
        PruebaNapakalaki pru = new PruebaNapakalaki();
        System.out.println((pru.ConsultaNivel()).toString());
        System.out.println("\n");

        System.out.println("----------------------------------------------");
        System.out.println("Prueba de consulta solo perdida de niveles\n\n");
        PruebaNapakalaki pru2 = new PruebaNapakalaki();
        System.out.println((pru2.ConsultaPerdidaNivel()).toString());
        System.out.println("\n");

        System.out.println("----------------------------------------------");
        System.out.println("Prueba de consulta ganancia de nivel > 1\n\n");
        PruebaNapakalaki pru3 = new PruebaNapakalaki();
        System.out.println((pru3.ConsultaGananciaNivel()).toString());
        System.out.println("\n");

        System.out.println("----------------------------------------------");
        System.out.println("Prueba de consulta de perdida de tesoro especifico\n\n");
        PruebaNapakalaki pru4 = new PruebaNapakalaki();

        System.out.println();
        System.out.println(TreasureKind.ARMOR);
        System.out.println((pru4.ConsultaPerdidaTesoro(TreasureKind.ARMOR)).toString());

        System.out.println();
        System.out.println(TreasureKind.ONEHAND);
        System.out.println((pru4.ConsultaPerdidaTesoro(TreasureKind.ONEHAND)).toString());

        System.out.println();
        System.out.println(TreasureKind.BOTHHANDS);
        System.out.println((pru4.ConsultaPerdidaTesoro(TreasureKind.BOTHHANDS)).toString());

        System.out.println();
        System.out.println(TreasureKind.HELMET);
        System.out.println((pru4.ConsultaPerdidaTesoro(TreasureKind.HELMET)).toString());

        System.out.println();
        System.out.println(TreasureKind.SHOES);
        System.out.println((pru4.ConsultaPerdidaTesoro(TreasureKind.SHOES)).toString());
        System.out.println("----------------------------------------------");
        System.out.println("\n\n");




      System.out.println("Empezamos la ejecución del programa");
      Prize pprueba = new Prize(7,8);
      BadConsequence bcprueba = new BadConsequence("BC1", 3, 2, 1);
      Monster Uno = new Monster("Monster", 20, bc1, p1);

      System.out.println(p1.getTreasures());
      System.out.println(p1.getLevels());
      System.out.println(Uno.getCombatLevel());
      System.out.println(Uno.toString());

*/
// --------------------------------------------------------------------------------------------------------
    }
}
