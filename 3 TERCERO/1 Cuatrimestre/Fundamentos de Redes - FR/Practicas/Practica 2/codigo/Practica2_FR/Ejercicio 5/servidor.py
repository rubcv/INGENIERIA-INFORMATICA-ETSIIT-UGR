# -*- coding: utf-8 -*-

import socket, select, base64, sys




# Enviar en broadcast a todos los miembros del grupo

def broadcast_data (sock, message):

    if '\exit' in message:
        socket.close()
        conectados.remove(socket)
    for socket in conectados:

        if socket != server_socket and socket != sock : # Distinto del que nos ha mandado el mensaje
            try :
                socket.send(message)
            except : # Si el cliente se cae pero el servidor sigue en funcionamiento
                socket.close()
                conectados.remove(socket)

if __name__ == "__main__":

    conectados = []
    buffer = 4096

    if len(sys.argv) == 1:
        puerto = 8080
    else:
        puerto = int(sys.argv[1])
    

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind(("0.0.0.0", puerto))
    server_socket.listen(20) # Hasta 20 usuarios


    conectados.append(server_socket)

    grupo = raw_input("Escribe el nombre del grupo\n")

    print "Se ha creado el grupo " + grupo + " en " + str(puerto)

    while 1:

        read_sockets,write_sockets,error_sockets = select.select(conectados,[],[])

        for sock in read_sockets:

            if sock == server_socket:

                sockfd, addr = server_socket.accept() # Ver los usuarios nuevos
                conectados.append(sockfd)
                cadena = "[100] El usuario (%s, %s) se ha unido al grupo " % addr
                cadena = cadena + grupo
                print cadena

                broadcast_data(sockfd, cadena + "\n") # Mandar la nueva conexion en broadcast

            #Ver si hay mensajes nuevos de algun cliente
            else:
                # Procesar el mensaje del cliente
                try:
                    data = sock.recv(buffer)
                    if data:
                        data = base64.b64decode(data)
                        nombre = data.split()
                        data = data.split(' ', 1)[1]
                        broadcast_data(sock, "\r" + '<' + nombre[0] + '> ' + data)

                except:
                    broadcast_data(sock, "[200] El cliente (%s, %s) está offline" % addr + '\n')
                    print "[200] El cliente (%s, %s) está offline" % addr + '\n'
                    sock.close()
                    conectados.remove(sock)
                    continue

    server_socket.close() # Cerramos el socket-server
