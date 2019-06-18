class Gato implements Cloneable{
    private String name;

    Gato(String n){
      name = n;
    }

    @Override
    public boolean equals(Object o){ // Si no lo redefines hace lo que el operator ==
      Gato g = (Gato)o;

      return (name == g.name)? true : false;
    }

    @Override
    public Object clone() {
      Object o;
      try{
        o = super.clone();
        (Gato)o.atrib = atrib.clone(); // Se llama al clone de la clase del atributo aunque no este implementado
      }catch(Exception e){
        throw new Error();
      }

      finally{
        // Haces esto si o si salga o no la excepcion
      }

      return o;
    }

}

class main{
  public static void main(String args[]){
    Gato a = new Gato("a");
    Gato b = new Gato("b");

    if(a.equals(b)){
      System.out.print("Se llaman igual\n");
    }else{
      System.out.print("No se llaman igual\n");
    }

    b = (Gato)a.clone();
    System.out.print("Clone\n");
    if(a.equals(b)){
      System.out.print("Se llaman igual\n");
    }
  }
}
