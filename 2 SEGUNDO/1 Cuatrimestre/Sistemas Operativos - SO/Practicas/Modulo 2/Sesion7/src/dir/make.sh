#!/bin/bash



# ---- VARIABLES GLOBALES ------
ayuda="-h" # Opcion de la ayuda
opciones="-o" #Opciones disponibles
exp="exp" # Exportar el script a bin
alias="\"mk"\" # Alias del programa
nalias="mk"
#-----------------------------------------------------------------------------------------------------------
#--------------------------------------           AYUDA            ------------------------------------------
#-----------------------------------------------------------------------------------------------------------

_imprimir_ayuda(){
  echo ""
  echo "**********************************************************"
  echo "----------------------------------------------------------"
  echo "                  MK - No-MakeFile                       "
  echo "---------------------------------------------------------"
  echo "**********************************************************"
  echo ""
  echo "------------------------------"
  echo "Auto-compilador de directorio"
  echo "------------------------------"
  echo ""
  echo "Compila automaticamente todos los archivos (del tipo especificado)
que haya en un directorio"
  echo ""
  echo "--- USO ---"
  echo ""
  echo "Escribe $0 [formato]"
  echo "Donde [formato] es el formato de los archivos a compilar"
  echo "El formato puede ser: 'c', 'cpp', 'java' "
  echo ""
  echo "IMPORTANTE: No especificar el punto, ej: .cpp"
  echo ""
  echo "MK - No-MakeFile no comprueba si se tienen instaladas las herramientas correspondientes
para compilar en el sistema, luego es importante que el usuario se asegure
de que puede compilar los archivos del directorio de forma
independiente sin hacer uso de este script"
  echo ""
  echo "FUNCION EXPORTAR"
  echo ""
  echo "Escribe $0 $exp para instalar MK - No-MakeFile en el sistema"
  echo "Mas informacion escribiendo: $0 $exp
(Muestra ayuda de lo que hace y pide confirmacion, no instala directamente)"
  echo ""
}


#-----------------------------------------------------------------------------------------------------------
#--------------------------------------           USO            ------------------------------------------
#-----------------------------------------------------------------------------------------------------------


_uso(){
  echo ""
  echo "**********************************************************"
  echo "----------------------------------------------------------"
  echo "                  MK - No-MakeFile"
  echo "---------------------------------------------------------"
  echo "**********************************************************"
  echo ""
  echo "------------------------------"
  echo "Auto-compilador de directorio"
  echo "------------------------------"
  echo ""
  echo "Escribe $0 $ayuda para consultar ayuda"
  echo "Escribe $0 $opciones para ver las opciones"
  echo ""
}

#-----------------------------------------------------------------------------------------------------------
#--------------------------------------          FIN PROGRAMA      -----------------------------------------
#-----------------------------------------------------------------------------------------------------------

_fin(){
  echo ""
  echo ""
  echo "-------------- MK FINALIZADO ---------------"
  echo "-- Comprobar salida de la terminal para errores --"
  echo ""
}

#-----------------------------------------------------------------------------------------------------------
#--------------------------------------          OPCIONES          -----------------------------------------
#-----------------------------------------------------------------------------------------------------------

_imprimir_opciones(){
  opciones_disponibles=(c cpp java exp)

  num=1
  echo ""
  echo "OPCIONES DISPONIBLES:"
  for opcion in ${opciones_disponibles[@]}
  do
    echo "$num: Escribe: $0 ${opcion}"
    num=$(( $num + 1 ))
  done
  echo ""
  echo "Escribe: $0 $ayuda para mas informacion"
  echo ""
}


#-----------------------------------------------------------------------------------------------------------
#--------------------------------------           C/C++            ------------------------------------------
#-----------------------------------------------------------------------------------------------------------

_compilarC(){
  for file in $(ls)
  do
    nombre=$file
    if [[ $file == *.$formato ]]
    then
      nombre=`echo "$file" | cut -d'.' -f1` # Nos quedamos con el nombre (sin el formato)
      make $nombre
    fi
  done
}

#-----------------------------------------------------------------------------------------------------------
#--------------------------------------           JAVA            ------------------------------------------
#-----------------------------------------------------------------------------------------------------------

_compilarJava(){
  for file in $(ls)
  do
    nombre=$file
    if [[ $file == *.$formato ]]
    then
      nombre=`echo "$file" | cut -d'.' -f1` # Nos quedamos con el nombre (sin el formato)
      javac $nombre
    fi
  done
}

#-----------------------------------------------------------------------------------------------------------
#--------------------------------------           INSTALAR            ------------------------------------------
#-----------------------------------------------------------------------------------------------------------

_instalar(){
  echo ""
  if [[ $EUID != 0 ]]
  then
    echo ""
    echo "FALLO EN INSTALACION - No esta en modo superusuario"
    echo ""
    echo "Ejecute: sudo $0 $exp
  o
Ejecute:   sudo su && $0 $exp"
    echo ""
    exit
  fi

  echo "Instalando..."
    dir="/usr/bin/automakefile"
    sudo mkdir dir # Creacion de directorio del programa
    cp $0 dir # Copiamos el programa al directorio

  echo ""
  echo "Instalacion completada"
  echo ""
}




#-----------------------------------------------------------------------------------------------------------
#--------------------------------------           EXPORTAR            ------------------------------------------
#-----------------------------------------------------------------------------------------------------------
_exportar(){
  echo ""
  echo "EXPORTAR:"
  echo "Con esta opcion, instala el script en su carpeta personal
y crea el alias $alias de forma que en lugar de usar $0 [formato]
puede usar directamente: $nalias [formato]"
  echo ""
  echo "El programa mantiene el mismo funcionamiento, pero ahora no será necesario
desplazar el script al directorio de trabajo junto con los archivos a compilar"
  echo ""
  echo "En cuanto al uso, solo debera cambiar $0 por $nalias,
aunque ambos funcionaran igual"
  echo ""
  echo "IMPORTANTE: Debe estar en modo superusuario para instalar el script"
  echo ""
  echo "Desea continuar? (s/n)"

  read opc

  case $opc in
    s|S)
      _instalar ;;
    n|N)
      exit ;;
    *)
      echo "" ;
      echo "$opc opcion no valida" ;
      exit ;;
  esac
}
#-----------------------------------------------------------------------------------------------------------
#--------------------------------------           MAIN            ------------------------------------------
#-----------------------------------------------------------------------------------------------------------

# Comprobacion
if [[ $# -ne 1 ]]
then
  _uso # Llamamos a la funcion de uso
  exit # exit para asegurarnos de que el programa termina
fi

# Principal
if [[ $# -eq 1 ]]
then

  if [[ $1 == $ayuda ]]
  then
    _imprimir_ayuda # Llamamos a la funcion de imprimir la ayuda
    exit # exit para asegurarnos de que el programa termina
  elif [[ $1 == $opciones ]]
  then
    _imprimir_opciones # Llamamos a la funcion de imprimir laa opciones
    exit # exit para asegurarnos de que el programa termina
  fi

  if [[ $1 != $ayuda ]]
  then
    formato=$1
    case $formato in
      c|cpp)
        _compilarC ;
        _fin ;;
      java)
        _compilarJava ;
        _fin ;;
      exp)
        _exportar ;;
      *)
        _uso ;;
    esac
  fi
fi
