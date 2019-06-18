import java.util.Random ;

// *********************************************************************
// clase hebra que al ejecutarse se duerme repetidas veces en un bucle

class Dormilona implements Runnable 
{ 
  // -------------------------------------------------------------------
  // variables de instancia
   
  int vueltas = 0 ; // número de veces que duerme (0 == infinitas) 
  int siesta  = 0 ; // tiempo máximo que duerme cada vez
  public Thread thr ; // objeto hebra encapsulado        

  // -------------------------------------------------------------------
  // constructor
   
  public Dormilona( String p_nombre, int p_vueltas, int p_siesta ) 
  { 
    siesta  = p_siesta ;
    vueltas = p_vueltas ;
    thr     = new Thread( this, p_nombre ) ; 
  }
  
  // -------------------------------------------------------------------
  // método ejecutado concurrentemente por la hebra
  // duerme un número finito de veces (o infinitas si ese número es 0)
   
  public void run()
  { 
    try
    { 
      Random random = new Random(); // crea generador de números aleatorios
      // dormir un numero de veces igual a "vueltas"
      for ( int i=0 ; i < vueltas || vueltas == 0 ; i++ )
      { 
        // imprimir nombre
        System.out.println( "Vuelta no."+i+", de " +thr.getName());
        // duerme un tiempo aleatorio entre 0 y siesta-1 milisegundos
        if ( siesta > 0 ) 
          Thread.sleep( random.nextInt( siesta ) );
      }
    }
    catch( InterruptedException e )
    { 
       System.out.println( Thread.currentThread().getName()+
                              ": me fastidiaron la siesta!");
    }
  } // fin 'run'
  
} // fin de la clase 'Dormilona'

// *********************************************************************
// clase con el método 'main' (crea y lanza las hebras tipo 'Dormilona')

class Principal2
{
  public static void main( String[] args ) 
  { 
    try
    { 
      if ( args.length < 3 )
      { System.out.println( "falta num_hebras, t_max_siesta, vueltas" );
        System.exit( 1 );
      }
      int nHebras = Integer.parseInt( args[0] );
      int siesta  = Integer.parseInt( args[1] );
      int vueltas = Integer.parseInt( args[2] );
    
      System.out.println( "nHebras = "+nHebras+", vueltas = "+vueltas+
                            ", tsiesta = "+siesta );
      //.... 
      //....
            
      Dormilona[] vhd = new Dormilona[nHebras] ; // crea vector de hebras
      
      for ( int i =0 ; i < nHebras ; i++ ) 
      { String nombre = "Dormilona no."+i ;
        vhd[i] = new Dormilona(nombre,vueltas,siesta); // crear hebra i.
        vhd[i].thr.start();                        // comienza su ejec.
      }
      // la hebra principal duerme durante un segundo
      Thread.sleep( 1000 );
      System.out.println( "main(): he terminado de dormir" );
      
      // esperar a que terminen todas las hebras creadas
      for( int i = 0 ; i < nHebras ; i++ )
        vhd[i].thr.join();  
    } 
    catch( InterruptedException e ) 
    { 
      System.out.println( "main(): me fastidiaron la siesta!" );
    }
  }
}
 
