/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 *
 * @author manjaro
 */
public class CardDealer {
      private static CardDealer instance = null;
      private ArrayList<Treasure> unusedTreasures = new ArrayList<Treasure>();
      private ArrayList<Treasure> usedTreasures = new ArrayList<Treasure>();
      private ArrayList<Monster> unusedMonsters = new ArrayList<Monster>();
      private ArrayList<Monster> usedMonsters = new ArrayList<Monster>();


      private CardDealer(){

      }

      public static CardDealer getInstance(){
       if(instance == null){
         instance = new CardDealer();
        }
       return instance;
      }

      private void initTreasureCardDeck(){

              unusedTreasures.add(new Treasure("¡Si mi amo!", 4, TreasureKind.HELMET));
              unusedTreasures.add(new Treasure("Botas de investigación", 3, TreasureKind.SHOES));
              unusedTreasures.add(new Treasure("Capucha de Cthulhu", 3 , TreasureKind.HELMET));
              unusedTreasures.add(new Treasure("A prueba de babas", 2, TreasureKind.ARMOR));
              unusedTreasures.add(new Treasure("Botas de lluvia ácida", 1, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Casco minero", 2, TreasureKind.HELMET));
              unusedTreasures.add(new Treasure("Ametralladora ACME", 4, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Camiseta de la ETSIIT", 1, TreasureKind.ARMOR));
              unusedTreasures.add(new Treasure("Clavo de rail ferroviario", 3, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Cuchillo de sushi arcano", 2, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Fez alópodo", 3, TreasureKind.HELMET));
              unusedTreasures.add(new Treasure("Hacha prehistórica", 2, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("El aparato del Pr. Tesla", 4, TreasureKind.ARMOR));
              unusedTreasures.add(new Treasure("Gaita", 4, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Insecticida", 2, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Escopeta de 3 cañones", 4, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Garabato Mistico", 2, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("La rebeca metálica", 2, TreasureKind.ARMOR));
              unusedTreasures.add(new Treasure("Mazo de los antiguos", 3, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Lanzallamas", 4, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Necro-comicón", 1, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Necronomicón",5, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Linterna a 2 manos", 3, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Necro-gnomicón", 2, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Necrotelecom", 2, TreasureKind.HELMET));
              unusedTreasures.add(new Treasure("Mazo de los antiguos", 3, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Necro-playboycon", 3, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Porra preternatural", 2, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Shogulador", 1, TreasureKind.BOTHHANDS));
              unusedTreasures.add(new Treasure("Varita de atizamiento", 3, TreasureKind.ONEHAND));
              unusedTreasures.add(new Treasure("Tentácula de pega", 2, TreasureKind.HELMET));
              unusedTreasures.add(new Treasure("Zapato deja-amigos", 1, TreasureKind.SHOES));

    }
    private void initMonsterCardDeck(){


        // DECLARACION DE MONSTRUOS

        // EL REY ROSADO
        BadConsequence bc1 = new BadConsequence("Pierdes 5 niveles y 3 tesoros visibles", 5, 3, 0);
        Prize p1 = new Prize(4,2);
        unusedMonsters.add(new Monster("El rey de rosado", 13, bc1, p1));

        // ANGELES DE LA NOCHE IBICENCA || DEMONIOS DE MAGALUF
        BadConsequence bc2 = new BadConsequence("Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND)));
        Prize p2 = new Prize(4,1);
        unusedMonsters.add(new Monster("Demonios de Magaluf", 14, bc2, p2));


        // BYANKHEES DE BONANZA

        BadConsequence bc3 = new BadConsequence("Pierdes tu armadura visible y otra oculta", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)),  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)));
        Prize p3 = new Prize(2, 1);
        unusedMonsters.add(new Monster("Byankhees de bonanza", 8, bc3, p3));


        // TENOCHTITLAN

        BadConsequence bc4 = new BadConsequence("Embobados con el lindo primigenio te descartas de tu casco visible", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.HELMET)), new ArrayList<TreasureKind>());
        Prize p4 = new Prize(1,1);
        unusedMonsters.add(new Monster("Tenochtitlan", 2, bc4, p4));

        // EL SOPOR DE DUNWICH

        BadConsequence bc5 = new BadConsequence("El primordial bostezo contagioso. Pierdes el calzado visible", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.SHOES)), new ArrayList<TreasureKind>());
        Prize p5 = new Prize(1,1);
        unusedMonsters.add(new Monster("El sopor de Dunwich", 2, bc5, p5));

        // EL GORRON EN EL UMBRAL

        BadConsequence bc6 = new BadConsequence("Pierdes todos tus tesoros visibles", 0, 5, 0);
        Prize p6 = new Prize(3,1);
        unusedMonsters.add(new Monster("El gorron en el umbral", 13, bc6, p6));

        // H.P. MUNCHCRAFT

        BadConsequence bc7 = new BadConsequence("Pierdes la armadura visible", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)), new ArrayList<TreasureKind>());
        Prize p7 = new Prize(2,1);
        unusedMonsters.add(new Monster("H.P. Munchcraft", 6, bc7, p7));

        // NECROFAGO

        BadConsequence bc8 = new BadConsequence("Sientes bichos bajo la ropa. Descarta la armadura visible", 0, new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ARMOR)), new ArrayList<TreasureKind>());
        Prize p8 = new Prize(1,1);
        unusedMonsters.add(new Monster("Necrofago", 13, bc8, p8));

        // FLECHER

        BadConsequence bc9 = new BadConsequence("Toses los pulmones y pierdes 2 niveles", 2, 0, 0);
        Prize p9 = new Prize(1,1);
        unusedMonsters.add(new Monster("Flecher", 2, bc9, p9));

        // LOS HONDOS

        BadConsequence bc10 = new BadConsequence("Estos unusedMonsters resultan bastante superficiales y te aburren mortalmente. Estas muerto", true);
        Prize p10 = new Prize(2,1);
        unusedMonsters.add(new Monster("Los Hondos", 8, bc10, p10));

        // SEMILLAS CTHULHU

        BadConsequence bc11 = new BadConsequence("Pierdes 2 niveles y 2 tesoros ocultos", 2, 0, 2);
        Prize p11 = new Prize(2,1);
        unusedMonsters.add(new Monster("Semillas Cthulhu", 4, bc11, p11));


        // DAMEARGO

        BadConsequence bc12 = new BadConsequence("Te intentas escaquear. Pierdes una mano visible", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList<TreasureKind>());
        Prize p12 = new Prize(2,1);
        unusedMonsters.add(new Monster("Dameargo", 1, bc12, p12));

        // POLLIPOLIPO VOLANTE

        BadConsequence bc13 = new BadConsequence("Da mucho asquito. Pierdes 3 niveles", 3, 0, 0);
        Prize p13 = new Prize(2,1);
        unusedMonsters.add(new Monster("Pollipolipo volante", 3, bc13, p13));

        // YSKHTIHYSSG-GOTH

        BadConsequence bc14 = new BadConsequence("No le hace gracia que pronuncien mal su nombre. Estas muerto", true);
        Prize p14 = new Prize(3,1);
        unusedMonsters.add(new Monster("Yskhtihyssg-Goth", 14, bc14, p14));

        // FAMILIA FELIZ

        BadConsequence bc15 = new BadConsequence("La familia te atrapa. Estas muerto", true);
        Prize p15 = new Prize(3,1);
        unusedMonsters.add(new Monster("Familia Feliz", 1, bc15, p15));

        // ROBOGGOTH

        BadConsequence bc16 = new BadConsequence("La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible", 2,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.BOTHHANDS)), new ArrayList<TreasureKind>());
        Prize p16 = new Prize(2,1);
        unusedMonsters.add(new Monster("Roboggoth", 8, bc16, p16));

        // EL ESPIA SORDO

        BadConsequence bc17 = new BadConsequence("Te asusta en la noche. Pierdes un casco visible", 0,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.HELMET)), new ArrayList<TreasureKind>());
        Prize p17 = new Prize(1,1);
        unusedMonsters.add(new Monster("El espia sordo", 5, bc17, p17));

        // TONGUE

        BadConsequence bc18 = new BadConsequence("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles", 2, 5, 0);
        Prize p18 = new Prize(2,1);
        unusedMonsters.add(new Monster("Tongue", 19, bc18, p18));

        // BICEFALO

        BadConsequence bc19 = new BadConsequence("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos", 3,  new ArrayList<TreasureKind>(Arrays.asList(TreasureKind.ONEHAND, TreasureKind.BOTHHANDS )), new ArrayList<TreasureKind>());
        Prize p19 = new Prize(2,1);
        unusedMonsters.add(new Monster("Bicefalo", 21, bc19, p19));

        
      }

   private void shuffleTreasures(){
       Collections.shuffle(this.unusedTreasures);

    }

   private void shuffleMonster(){
       Collections.shuffle(this.unusedMonsters);

   }


     public Treasure nextTreasure(){
        if(unusedTreasures.isEmpty()){
            for(Treasure t : usedTreasures){
                unusedTreasures.add(t);
            }
        }

        shuffleTreasures();

        usedTreasures.clear();

        Treasure t = unusedTreasures.get(0);
        usedTreasures.add(t);
        unusedTreasures.remove(t);
        return t;
      }

     public Monster nextMonster(){
           if(unusedMonsters.isEmpty()){
            for(Monster m : usedMonsters){
                unusedMonsters.add(m);
            }
        }

        shuffleMonster();

        usedMonsters.clear();

        Monster m = unusedMonsters.get(0);
        usedMonsters.add(m);
        unusedMonsters.remove(m);
        return m;
     }

     public void giveTreasureBack(Treasure t){
          usedTreasures.add(t);
      }

      public void giveMonsterBack(Monster m){
          usedMonsters.add(m);
      }


      public void initCards(){
          // Llamar a los otros init
          this.initTreasureCardDeck();
          this.initMonsterCardDeck();
		  this.shuffleTreasures();
		  this.shuffleMonster();
	
      }

}
