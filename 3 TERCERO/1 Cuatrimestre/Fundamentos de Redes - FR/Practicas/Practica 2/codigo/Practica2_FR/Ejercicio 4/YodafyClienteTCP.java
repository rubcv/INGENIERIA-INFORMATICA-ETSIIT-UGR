//
// YodafyServidorIterativo
// (CC) jjramos, 2012
//

package codigo;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.InetAddress;

public class YodafyClienteTCP {

	public static void main(String[] args) {
		
		byte []buferEnvio;
		byte []buferRecepcion=new byte[256];
		int bytesLeidos=0;
		
		// Nombre del host donde se ejecuta el servidor:
		String host="localhost";
		// Puerto en el que espera el servidor:
		int port=8989;
		
		// Socket para la conexión TCP
		Socket socketServicio=null;

		Socket socket;

		DatagramSocket socketClienteUDP = null;
		int puerto = 888;
		InetAddress direccion = null;
		DatagramPacket paquete = null;



		try{
			socketClienteUDP = new DatagramSocket(puerto);
		}catch(IOException e){
			System.out.println("Error: no se pudo atender el puerto " + puerto);
		}

		

		

		try {

			direccion = InetAddress.getByName("localhost");

		//	// Creamos un socket que se conecte a "hist" y "port":
		//	//////////////////////////////////////////////////////
		//	// socketServicio= ... (Completar)
		//	//////////////////////////////////////////////////////			
		//	try{
		//		socketServicio = new Socket(host, port);
		//	}catch(UnknownHostException e){
		//		System.err.println("Error: Equipo desconocido\n");
		//	}



		//	InputStream inputStream = socketServicio.getInputStream();
		//	OutputStream outputStream = socketServicio.getOutputStream();
			
			// Si queremos enviar una cadena de caracteres por un OutputStream, hay que pasarla primero
			// a un array de bytes:
			buferEnvio="Al monte del volcán debes ir sin demora".getBytes();
			
			// Enviamos el array por el outputStream;
			//////////////////////////////////////////////////////
			// ... .write ... (Completar)
			//////////////////////////////////////////////////////
			

			paquete = new DatagramPacket(buferEnvio, buferEnvio.length, direccion, puerto);

			socketClienteUDP.send(paquete);


			paquete = new DatagramPacket(buferRecepcion, buferRecepcion.length);

			socketClienteUDP.receive(paquete);
			
			String cadenaRecibida = new String(paquete.getData());
			







			//outputStream.write(buferEnvio, 0, buferEnvio.length);

			//PrintWriter outputPrinter = new PrintWriter(outputStream, true);
			//outputPrinter.println(buferEnvio);




			// Aunque le indiquemos a TCP que queremos enviar varios arrays de bytes, sólo
			// los enviará efectivamente cuando considere que tiene suficientes datos que enviar...
			// Podemos usar "flush()" para obligar a TCP a que no espere para hacer el envío:
			//////////////////////////////////////////////////////
			// ... .flush(); (Completar)
			//////////////////////////////////////////////////////
			
			//outputStream.flush();

			// Leemos la respuesta del servidor. Para ello le pasamos un array de bytes, que intentará
			// rellenar. El método "read(...)" devolverá el número de bytes leídos.
			//////////////////////////////////////////////////////
			// bytesLeidos ... .read... buferRecepcion ; (Completar)
			//////////////////////////////////////////////////////
			
			//bytesLeidos = inputStream.read(buferRecepcion);


			//BufferedReader inputReader = new BufferedReader(new InputStreamReader(inputStream));
			//String cadenaRecibida = inputReader.readLine();



			// MOstremos la cadena de caracteres recibidos:
			System.out.println("Recibido: " + cadenaRecibida + "\n");
			//for(int i=0;i<bytesLeidos;i++){
			//	System.out.print((char)buferRecepcion[i]);
			//}
			
			// Una vez terminado el servicio, cerramos el socket (automáticamente se cierran
			// el inpuStream  y el outputStream)
			//////////////////////////////////////////////////////
			// ... close(); (Completar)
			//////////////////////////////////////////////////////
			
			socketClienteUDP.close();

			// Excepciones:
		//} catch (UnknownHostException e) {
		//	System.err.println("Error: Nombre de host no encontrado.");
		} catch (IOException e) {
			System.err.println("Error de entrada/salida al abrir el socket.");
		}
	}
}
