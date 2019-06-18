package NapakalakiGame;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 *
 * @author manjaro
 */

public class CardDealer {

      private static final CardDealer instance = new CardDealer();
      private ArrayList<Treasure> unusedTreasures ;
      private ArrayList<Treasure> usedTreasures ;
      private ArrayList<Monster> unusedMonster ;
      private ArrayList<Monster> usedMonster ;

      private ArrayList<Cultist> unusedCultist;
      private ArrayList<Cultist> usedCultist;


   public static CardDealer getInstance() {
      return instance;
  }


  private CardDealer(){

      unusedMonster = new ArrayList();
      usedMonster = new ArrayList();
      unusedTreasures = new ArrayList();
      usedTreasures = new ArrayList();
      unusedCultist = new ArrayList();
      usedCultist = new ArrayList();
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

       BadConsequence badConsequence1 = new SpecificBadConsequence("Pierdes tu armadura\n visible y otra oculta.", 0 , new ArrayList(Arrays.asList(TreasureKind.ARMOR)),
                new ArrayList(Arrays.asList(TreasureKind.ARMOR)));
         Prize prize1 = new Prize(2,1);
         unusedMonster.add(new Monster("Byakhees de bonanza", 8, badConsequence1, prize1));

         BadConsequence badConsequence2 = new SpecificBadConsequence("Embobados con el lindo primigenio\n te descartas de tu casco visible.", 0 , new ArrayList(Arrays.asList(TreasureKind.HELMET)),
                 new ArrayList(Arrays.asList()) );
         Prize prize2 = new Prize(1,1);
         unusedMonster.add(new Monster("Tenochtitlan", 2, badConsequence2, prize2));

         BadConsequence badConsequence3 = new SpecificBadConsequence("EL primordial bostezo contagioso.\n Pierdes el calzado visible.", 0 , new ArrayList(Arrays.asList(TreasureKind.SHOES)),
                 new ArrayList(Arrays.asList()) );
         Prize prize3 = new Prize(1,1);
         unusedMonster.add(new Monster("El sopor de Dunwich", 2, badConsequence3, prize3));

         BadConsequence badConsequence4 = new SpecificBadConsequence("Te atrapan para llevarte a la fiesta\n y te dejan caer en mitad del vuelo.\n Descarta 1 mano visible  y 1 mano oculta.",
                 0 , new ArrayList(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList(Arrays.asList(TreasureKind.ONEHAND)) );
         Prize prize4 = new Prize(4,1);
         unusedMonster.add(new Monster("Angeles de la noche ibicenca", 14 , badConsequence4, prize4));

         BadConsequence badConsequence5 = new NumericBadConsequence("Pierdes todos tus tesoros visibles.", 0 , 5, 0 );
         Prize prize5 = new Prize(3,1);
         unusedMonster.add(new Monster("El gorron en el umbral", 10 , badConsequence5, prize5));

         BadConsequence badConsequence6 = new SpecificBadConsequence("Pierdes la armadura visible.", 0 ,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),
               new ArrayList(Arrays.asList()));
         Prize prize6 = new Prize(3,1);
         unusedMonster.add(new Monster("H.P. Munchcraft", 6 , badConsequence6, prize6));

         BadConsequence badConsequence7 = new SpecificBadConsequence("Sientes bichos bajo la ropa.\n Descarta tu armadura visible.", 0 ,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),
                 new ArrayList(Arrays.asList()));
         Prize prize7 = new Prize(1,1);
         unusedMonster.add(new Monster("Necrofago", 2 , badConsequence7, prize7));

         BadConsequence badConsequence8 = new NumericBadConsequence("Pierdes 5 niveles\n y 3 tesoros visibles.",5 ,3, 0 );
         Prize prize8 = new Prize(4,2);
         unusedMonster.add(new Monster("El rey de rosa", 13 , badConsequence8, prize8));

         BadConsequence badConsequence9 = new NumericBadConsequence("Toses los pulmones\n y pierdes 2 niveles.",2 ,0, 0 );
         Prize prize9 = new Prize(1,1);
         unusedMonster.add(new Monster("Flecher", 2 , badConsequence9, prize9));

         BadConsequence badConsequence10 = new DeathBadConsequence("Estos monstruos resultan\n bastante superficiales y te aburren mortalmente\n. Estas muerto.",true);
         Prize prize10 = new Prize(2,1);
         unusedMonster.add(new Monster("Los hondos", 8 , badConsequence10, prize10));

         BadConsequence badConsequence11 = new NumericBadConsequence("Pierdes 2 niveles y\n 2 tesoros ocultos." ,2 ,2 ,0 );
         Prize prize11 = new Prize(2,1);
         unusedMonster.add(new Monster("Semillas Cthulhu", 4 , badConsequence11, prize11));

         BadConsequence badConsequence12 = new SpecificBadConsequence("Te intentas escaquear.\n Pierdes una mano visible." ,0 ,new ArrayList(Arrays.asList(TreasureKind.ONEHAND)) ,
                 new ArrayList(Arrays.asList()));
         Prize prize12 = new Prize(2,1);
         unusedMonster.add(new Monster("Dameargo",1 , badConsequence12, prize12));

         BadConsequence badConsequence13 = new NumericBadConsequence("Da mucho asquito.\n Pierdes 3 niveles." ,3 ,0 ,0 );
         Prize prize13 = new Prize(1,1);
         unusedMonster.add(new Monster("Pollipolipo volante",3 , badConsequence13, prize13));

         BadConsequence badConsequence14 = new DeathBadConsequence("No le hace gracia que pronuncien\n mal su nombre. Estas muerto." ,true );
         Prize prize14 = new Prize(3,1);
         unusedMonster.add(new Monster("Yskhtihyssg-Goth",12 , badConsequence14, prize14));

         BadConsequence badConsequence15 = new DeathBadConsequence("La familia te atrapa. Estas muerto." ,true );
         Prize prize15 = new Prize(4,1);
         unusedMonster.add(new Monster("Familia Feliz",1 , badConsequence15, prize15));

         BadConsequence badConsequence16 = new SpecificBadConsequence("La quinta directiva te atrapa\n y te obliga a perder 2 niveles\n y un tesoro de 2 manos visible." ,2 ,
              new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS)), new ArrayList(Arrays.asList()));
         Prize prize16 = new Prize(2,1);
         unusedMonster.add(new Monster("Robotggoth",8 , badConsequence16, prize16));

         BadConsequence badConsequence17 = new SpecificBadConsequence("Te asusta en la noche.\n Pierdes un casco visible" ,0 ,new ArrayList(Arrays.asList(TreasureKind.HELMET)),
                 new ArrayList(Arrays.asList()));
         Prize prize17 = new Prize(1,1);
         unusedMonster.add(new Monster("El espia sordo", 5 , badConsequence17, prize17));

         BadConsequence badConsequence18 = new NumericBadConsequence("Menudo susto te llevas.\n Pierdes 2 niveles y 5 tesoros visibles." ,2 ,5, 0);
         Prize prize18 = new Prize(1,1);
         unusedMonster.add(new Monster("Tongue" ,19 , badConsequence18, prize18));

         BadConsequence badConsequence19 = new SpecificBadConsequence("Te faltan manos para tanta cabeza.\n Pierdes 2 niveles y tus tesoros visibles de las manos." ,2 ,
                 new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS,TreasureKind.ONEHAND,TreasureKind.ONEHAND)),new ArrayList(Arrays.asList()));
         Prize prize19 = new Prize(1,1);
         unusedMonster.add(new Monster("Bicéfalo" ,21 , badConsequence19, prize19));



         BadConsequence badConsequence20 = new SpecificBadConsequence("Pierdes una mano visible" ,0 ,
                 new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList(Arrays.asList()));
         Prize prize20 = new Prize(3,1);
         unusedMonster.add(new Monster("El mal indecible impronunciable." ,10 , badConsequence20, prize20, -2));

         BadConsequence badConsequence21 = new NumericBadConsequence("Pierdes tus tesoros visibles. Jajaja" ,0 ,5,0);
         Prize prize21 = new Prize(2,1);
         unusedMonster.add(new Monster("Testigos Oculares." ,6 , badConsequence21, prize21, +2));

         BadConsequence badConsequence22 = new DeathBadConsequence("Hoy no es tu día de suerte. Mueres." ,true );
         Prize prize22 = new Prize(2,5);
         unusedMonster.add(new Monster("El gran cthulhu.  ",20 , badConsequence22, prize22,+4));

         BadConsequence badConsequence23 = new NumericBadConsequence("Tu gobierno te recorta dos niveles." ,2 ,0,0);
         Prize prize23 = new Prize(2,1);
         unusedMonster.add(new Monster("Serpiente político." ,8 , badConsequence23, prize23, -2));

         BadConsequence badConsequence24 = new SpecificBadConsequence("Pierdes tu casco y armadura visible.\n Pierdes tus manos ocultas." ,0 ,
                 new ArrayList(Arrays.asList(TreasureKind.HELMET,TreasureKind.ARMOR)),new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS,TreasureKind.ONEHAND,TreasureKind.ONEHAND)));
         Prize prize24  = new Prize(1,1);
         unusedMonster.add(new Monster("Felpuggoth." ,2 , badConsequence24, prize24, +5));


         BadConsequence badConsequence25 = new NumericBadConsequence("Pierdes dos niveles." ,2 ,0,0);
         Prize prize25 = new Prize(4,2);
         unusedMonster.add(new Monster("Shoggoth." ,16 , badConsequence25, prize25, -4));

         BadConsequence badConsequence26 = new NumericBadConsequence("Pintalabios negro. Pierdes dos niveles." ,2 ,0,0);
         Prize prize26 = new Prize(1,1);
         unusedMonster.add(new Monster("Lolitaggoth." ,2 , badConsequence26, prize26, +3));


  }

  private void initCultistCardDeck(){

      unusedCultist.add(new Cultist("Sectario", 1));
      unusedCultist.add(new Cultist("Sectario", 2));
      unusedCultist.add(new Cultist("Sectario", 1));
      unusedCultist.add(new Cultist("Sectario", 2));
      unusedCultist.add(new Cultist("Sectario", 1));
      unusedCultist.add(new Cultist("Sectario", 1));
  }

  private void shuffleCultist(){
    Collections.shuffle(unusedCultist);
  }

  private void shuffleTreasures(){
    Collections.shuffle(unusedTreasures);

  }
  private void shuffleMonsters(){
    Collections.shuffle(unusedMonster);
  }

  public Cultist nextCultist(){
    if(unusedCultist.isEmpty()){
      for(Cultist c : usedCultist){
        unusedCultist.add(c);
      }
      shuffleCultist();
    }

    Cultist auxiliar = this.unusedCultist.get(0);
    usedCultist.add(auxiliar);
    unusedCultist.remove(auxiliar);

    return auxiliar;
  }

  public Treasure nextTreasure(){

    if(unusedTreasures.isEmpty()){
      for(Treasure treasures : usedTreasures){
        unusedTreasures.add(treasures);
      }
      shuffleTreasures();
    }

    Treasure auxiliar = this.unusedTreasures.get(0);
    usedTreasures.add(auxiliar);
    unusedTreasures.remove(auxiliar);

    return auxiliar;
  }


  public Monster nextMonster(){

    if(unusedMonster.isEmpty()){

      for(Monster monster : usedMonster){
          unusedMonster.add(monster);
      }
      shuffleMonsters();
    }

    Monster aux = this.unusedMonster.get(0);
    usedMonster.add(aux);
    unusedMonster.remove(aux);

    return aux;
  }

  public void giveCultistBack(Cultist c){
      this.usedCultist.add(c);
  }

  public void giveTreasureBack(Treasure t){
      this.usedTreasures.add(t);
  }

  public void giveMonsterBack(Monster m){
      this.usedMonster.add(m);
  }

  public void initCards(){

      this.initTreasureCardDeck();
      this.initMonsterCardDeck();
      this.initCultistCardDeck();
      shuffleTreasures();
      shuffleMonsters();
      shuffleCultist();
  }

}
