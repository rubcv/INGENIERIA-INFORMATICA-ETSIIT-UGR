# -*- coding: utf-8 -*-

import socket, select, string, sys, base64

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def prompt(usuario) :
    sys.stdout.write(bcolors.OKBLUE + '<' + usuario + '> ' + bcolors.ENDC)
    sys.stdout.flush()


if __name__ == "__main__":


    # Pedimos el host y el puerto
    if(len(sys.argv) < 2) :
        print bcolors.WARNING + 'Escribe : ' + sys.argv[0] + ' <host> <puerto (por defecto el 8080)>' + bcolors.ENDC
        sys.exit()

    host = sys.argv[1]

    if len(sys.argv) == 2:
        port = 8080
    else:
        port = int(sys.argv[2])

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(2)

    # Intentamos hacer la conexion
    try :
        s.connect((host, port))
    except :
        print bcolors.FAIL + '[Error 400]: No se ha podido hacer la conexion' + bcolors.ENDC
        sys.exit()

    print bcolors.OKGREEN + 'Conectado a ' + host + ' en el puerto ' + str(port) + '\nEscribe \exit para salir' + bcolors.ENDC

    usuario = raw_input(bcolors.HEADER + "Escribe un nombre de usuario\n" + bcolors.ENDC)

    prompt(usuario) # Cada usuario tiene su propio alias

    while 1:
        socket_list = [sys.stdin, s]

        # Obtener la lista de sockets
        read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])

        for sock in read_sockets:
            #Mensaje del servidor
            if sock == s:
                data = sock.recv(4096)
                if not data :
                    print bcolors.FAIL + '\n[Error 500] Desconectado del servidor' + bcolors.ENDC
                    sys.exit()
                else :
                    #print data
                    sys.stdout.write(data)
                    prompt(usuario)

            #Enviar mensaje escrito por el usuario
            else :
                msg = sys.stdin.readline()
                msg = usuario + ' ' + msg
                
                encoded = base64.b64encode(msg)
                s.send(encoded)

                if '\exit' in msg:
                    sys.exit(0)
                    
                prompt(usuario)
