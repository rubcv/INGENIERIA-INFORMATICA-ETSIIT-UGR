
// *********************************************************************
// clase que encapsula un contador entero

class Contador 
{
  // -------------------------------------------------------------------
  // variables de instancia
  
  private long valor;
  
  // -------------------------------------------------------------------
  // constructor

  public Contador( long inicial )  
  { valor = inicial ; 
  }
  
  // -------------------------------------------------------------------
  // ocupa la CPU durante cierto tiempo
  
  void retrasoOcupado() 
  { long tmp = 0 ;
    for( int i = 0 ; i < 100000 ; i++ ) 
      tmp = tmp*i-tmp+i ;
  }
  
  // -------------------------------------------------------------------
  // incrementa valor en 1 
  
  public synchronized void incrementa () 
  { long aux = valor ; // hace copia local del valor actual
    retrasoOcupado() ; // permite entrelazado cuando no se hace en EM
    valor = aux+1 ;    // escribe el valor compartido (incrementado)
  }
  
  // -------------------------------------------------------------------
  // devuelve el valor actual
  
  public synchronized long getvalor () 
  {  return valor;
  }
}

// *********************************************************************
// clase que usa una instancia de 'Contador' para contar múltiplos

class Hebra implements Runnable 
{ 
  // -------------------------------------------------------------------
  // variables de instancia
   
  int numero ;               // cuenta múltiplos de este número
  public Thread thr ;        // objeto encapsulado
  private Contador cont;     // contador de número de múltiplos

  // -------------------------------------------------------------------
  // constructor
  
  public Hebra( String nombre, int p_numero, Contador p_contador ) 
  { numero = p_numero; 
    cont   = p_contador;
    thr = new Thread( this, nombre );
  }
  
  // -------------------------------------------------------------------
  // método ejecutado concurrentemente por la hebra
  
  public void run () 
  { 
    for ( int i = 1 ; i <= 1000 ; i++ ) 
      if (i % numero == 0) 
        cont.incrementa();
  }
}

// *********************************************************************
// clase con la función principal del programa

class Multiplos 
{ 
  public static void main( String[] args ) 
  { 
    try 
    { 
      Contador contH = new Contador(0); // contador usado por la hebras
      Hebra[] vc = new Hebra[2] ; 
      
      // calcula e imprime el resultado usando dos hebras contadoras
      
      vc[0] = new Hebra( "Contador2 ", 2, contH);
      vc[1] = new Hebra( "Contador3 ", 3, contH);
      
      vc[0].thr.start(); vc[1].thr.start(); // lanza hebras
      vc[0].thr.join();  vc[1].thr.join();  // espera terminación
      
      System.out.println("Resultado hebras  : "+contH.getvalor());
      
      // calcula el resultado correcto contando múltiplos de forma secuencial
      
      long contV = 0 ;  // contador de verificacion 
      
      for ( int i = 1 ; i <= 1000 ; i++ )
      { 
        if ( i % 2 == 0 ) contV = contV + 1 ;
        if ( i % 3 == 0 ) contV = contV + 1 ;
      }
      System.out.println("Resultado correcto: " + contV);
    }
    catch (InterruptedException e) 
    { System.out.println ("ha ocurrido una excepcion.");
    }
  }
}

// *********************************************************************

