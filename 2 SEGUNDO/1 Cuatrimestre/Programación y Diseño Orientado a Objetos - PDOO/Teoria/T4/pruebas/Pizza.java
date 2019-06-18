import java.util.ArrayList;


@Override
public boolean equals(Object orig){
  /* Desarrollar */
}

class Pizza{
  private String nombre;
  private ArrayList<String> ingredientes = new ArrayList<String>();

  Pizza(String n){
    nombre = n;
  }



  Pizza(String n, ArrayList<String> ing){
      nombre = n;
      ingredientes = ing;
  }

  void incluirIngrediente(String ing){
    ingredientes.add(ing);
  }


  String getNombre(){
    return nombre;
  }

  ArrayList<String> getIng(){
    return ingredientes;
  }


  public String toString(){
    String res = "Es una Pizza " + nombre + " con ";
    for(String i : ingredientes)
    res += i + " ";

    res += "\n";
    return res;
  }



  public static void main(String[] args) {

    ArrayList<String> ing1  = new ArrayList<String>();
    ing1.add("tomaate");
    ing1.add("QUESO");

    ing1.add("tomaate");
    ing1.add("tomaate");
    ing1.add("tomaate");
    ing1.add("tomaate");




    Pizza p1 = new Pizza("MARGARITA", ing1);
    Pizza p2 = new Pizza("MARGARITA", ing1);
    Pizza p3 = new Pizza("MARGARITA", ing1);
    Pizza p4 = new Pizza("MARGARITA", ing1);


    System.out.println(p1 == p2); // Comparas identidad (Si son el mismo objeto)

    System.out.println(p1.toString() + "--------------\n" + p2.toString() + "--------------\n" + p3.toString() + "--------------\n" + p4.toString());

  }
}
