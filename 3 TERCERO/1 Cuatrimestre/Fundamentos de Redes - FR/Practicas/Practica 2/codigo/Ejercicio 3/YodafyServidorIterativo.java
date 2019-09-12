

package codigo;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;


//
// YodafyServidorIterativo
// (CC) jjramos, 2012
//
public class YodafyServidorIterativo {

	public static void main(String[] args) {
	
		// Puerto de escucha
		int port=8989;
		// array de bytes auxiliar para recibir o enviar datos.
		byte []buffer=new byte[256];
		// Número de bytes leídos
		int bytesLeidos=0;
		Socket socketConexion = null;
		

			// Abrimos el socket en modo pasivo, escuchando el en puerto indicado por "port"
			//////////////////////////////////////////////////
			// ...serverSocket=... (completar)
			//////////////////////////////////////////////////

			ServerSocket socketServidor = null;


			try{
				socketServidor = new ServerSocket(port);
			}catch(IOException e){
				System.out.println("Error: no se pudo atender en el puerto " + port);
			}



			// Mientras ... siempre!
			do {


				// Aceptamos una nueva conexión con accept()
				/////////////////////////////////////////////////
				// socketServicio=... (completar)
				//////////////////////////////////////////////////
				try{
					socketConexion = socketServidor.accept();
				}catch(IOException e){
					System.out.println("Error: no se pudo aceptar la conexion solicitada\n");
				}
				


				// Creamos un objeto de la clase ProcesadorYodafy, pasándole como 
				// argumento el nuevo socket, para que realice el procesamiento
				// Este esquema permite que se puedan usar hebras más fácilmente.
				ProcesadorYodafy procesador=new ProcesadorYodafy(socketConexion);
				procesador.procesa();
				
			} while (true);

	}

}


// Se ha eliminado el catch Exception ya que impedía compilar