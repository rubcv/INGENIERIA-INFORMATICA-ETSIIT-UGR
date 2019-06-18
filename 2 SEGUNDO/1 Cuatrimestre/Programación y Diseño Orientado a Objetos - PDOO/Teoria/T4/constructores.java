class A {
  private int x;
  private int y;
  public A(int a,int b) { x=a; y=b;}
  public A(A a) { x=a.x; y=a.y; }
}

class B extends A {
private int z;
public B(int a,int b,int c) { super(a,b); z=c; }
public B(B b){ super(b); z=b.z; }

}

class main{
  public static void main(String args[]){
    A a = new A(1,2);
    B b = new B(2,3,4);
    System.out.print("Fin main\n");
  }
}
