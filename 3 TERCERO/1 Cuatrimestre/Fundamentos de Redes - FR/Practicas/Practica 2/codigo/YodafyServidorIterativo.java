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
		
		try {
			// Abrimos el socket en modo pasivo, escuchando el en puerto indicado por "port"
			//////////////////////////////////////////////////
			// ...serverSocket=... (completar)
			//////////////////////////////////////////////////

			ServerSocket socketServidor;
			int puerto = 888;

			try{
				socketServidor = new ServerSocket(puerto);
			}catch(IOException e){
				System.out.println("Error: no se pudo atender en el puerto " + puerto);
			}



			// Mientras ... siempre!
			do {

				

					Socket socketConexion = null;

				try{
					socketConexion  = socketServidor.accept();
				}catch(IOException e){
					System.out.println("Error: no se pudo aceptar la conexion solicitada\n");
				}
				
				
				// Aceptamos una nueva conexión con accept()
				/////////////////////////////////////////////////
				// socketServicio=... (completar)
				//////////////////////////////////////////////////
				


				// Creamos un objeto de la clase ProcesadorYodafy, pasándole como 
				// argumento el nuevo socket, para que realice el procesamiento
				// Este esquema permite que se puedan usar hebras más fácilmente.
	//			ProcesadorYodafy procesador=new ProcesadorYodafy(socketServicio);
	//			procesador.procesa();
				
			} while (true);
			
		} catch (IOException e) {
			System.err.println("Error al escuchar en el puerto "+port);
		}

	}

}
