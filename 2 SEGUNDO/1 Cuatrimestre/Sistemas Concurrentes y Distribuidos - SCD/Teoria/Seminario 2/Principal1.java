import java.util.Random ;

// *********************************************************************
// clase tipo hebra que al ejecutarse duerme infinitas veces

class TipoHebra implements Runnable // opcionalmente: extends ....
{ 
  // -------------------------------------------------------------------
  // variables de instancia

  long siesta  ;      // tiempo que duerme la hebra
  public Thread thr ; // objeto hebra encapsulado
  
  // -------------------------------------------------------------------
  // constructor
  
  public TipoHebra( String nombre, long siesta ) 
  { this.siesta = siesta;
    thr = new Thread( this, nombre );
  }
  
  // -------------------------------------------------------------------
  // método ejecutado de forma concurrente por la hebra:
  // duerme infinitas veces en un bucle.
  
  public void run() 
  { 
    try
    { 
      while ( true ) 
      { System.out.println( "Hola, soy "+thr.getName() );
        if ( siesta > 0 ) 
          Thread.sleep( siesta );  
      }
    }
    catch ( InterruptedException e ) 
    { 
      System.out.println( "me fastidiaron la siesta!" );
    }
  }
}

// *********************************************************************
// clase con el método 'main' (crea y lanza la hebra 'TipoHebra')

class Principal1 
{
  public static void main( String[] args ) throws InterruptedException 
  {
    if ( args.length < 1 )
    {  System.out.println( "Error: falta valor de 'siesta'" );
       System.exit(1);
    }
    long siesta = Long.parseLong( args[0] ) ;
    TipoHebra obj = new TipoHebra("hebra 'obj'", siesta); // crear hebra
    
    obj.thr.start();     // lanzar hebra
    Thread.sleep( 100 ); // la hebra principal duerme 1/10 sec.
    obj.thr.join();      // esperar a que termine la hebra
  }
}

// *********************************************************************

