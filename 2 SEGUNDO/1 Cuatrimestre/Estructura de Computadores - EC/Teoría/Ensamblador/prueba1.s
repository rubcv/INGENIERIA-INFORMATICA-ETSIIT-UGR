#===[Equivalencia en C]============
# int a = 2, b = 3, r;
# r = a + b;

.data # initialized global data
a: .long 2 # int a = 2;
b: .long 3 # int b = 3;

.bss # uninitialized global data
.comm r, 4, 4 # int r;

.text # code segment
.global main # So the OS can call 'main'

main:   # main(){
  movl a, %eax # a -> eax (l de long (32 bits))
  addl b, %eax # b + eax -> eax (l de long (32 bits))
  movl %eax, r # eax -> r (l de long (32 bits))

  # LINUX EXIT
  # movl $0, %ebx # Return 0 (the usual)
  movl r, %ebx # Return r (lowest byte)
  movl $1, %eax
  int $0x80



  Lineas 1-3:
Este es nuestro primer programa que suma 2+3.
Aquı́ tenemos el código equivalente en C. El ’#’ indica que el resto de la linea es un comentario.

  Lineas 5-7:
El bloque ’data’ contiene las variables que declaramos e
inicializamos. En este caso a = 2 y b = 3

  Lineas 9-10:
El bloque 'bss' contiene las variables que declaramos pero
no inicializamos. En este caso la variable 'r' de 4 bytes (long (32 bits))
alineada a 4 bytes

  Linea 12:
El bloque 'text' contiene las instrucciones del programa

  Linea 13:
Un programa siempre empieza haciendo publica la etiqueta 'main'
para que pueda ser invocada por el S.O

  Linea 15:
La etiqueta 'main', donde empieza el programa

  Linea 16:
Copiamos 'a' al registro 'eax'

  Linea 17:
Sumamos (addl) 'b' (long) con el contenido del registro 'eax'
y el resultado lo guardamos en 'eax'. Ahora 'eax' contiene 'a + b'

  Linea 18:
Copiamos el contenido de 'eax' a la variable 'r'

  Linea 20:
El programa ya ha acabado y ahora debemos retornar el control al S.O.

  Linea 21:
Normalmente se copia un '0' al registro 'ebx'.
Aqui esta comentado

  Linea 22:
Copiamos el resultado de la ejecucion (la variable 'r')
al registro 'ebx'

  Linea 23:
Copiamos un '1' al registro 'eax'

  Linea 24:
LLamamos a la interrupcion '0x80' (80 hexadecimal).
Esta interrupcion hace que en el caso de que el registro 'eax'
valga 1, termina la ejecucion del programa devolviendo el contenido
del registro 'ebx' al S.O

- COMPILAR Y EJECUTAR -

Se compila con gcc prueba1.s -o prueba1
Se ejecuta con ./prueba1

No aparece nada en la terminal, para ver el resultado
ejecutar: echo $?
Esto hace que el S.O muestre lo que ha devueto el ultimo programa,
que en este caso se ha programado para que sea 'r' lo que devuelve
Este mecanismo de salida se puede sustituir por 'printf'




- OPCIONES DE ORDENES -
mov origen, destino
Operaciones entre operandos del mismo tipo:
 l (movl, addl, ...): long. Como int en C (32 bits)
 w (movw, addw, ...): word. (16 bits)
 b (movb, addb, ...): byte. Como char en C (8 bits)


Reescalar a uno de mayor tamaño:

  movz[bw|bl|wl] op1, op2 (Extiende ceros, para numeros positivos)
  movs[bw|bl|wl] op1, op2 (Extiende el signo, para numeros negativos)

 - TIPOS DE OPERADORES -
 Inmediatos (Constante): '$100'  (El numero 100)
 Registros: '%eax' (El registro eax)
 Memoria (Normal): '(%eax)' (Contenido de la posicion de memoria guardada en eax)
 Memoria (Desplazamiento): '8(%ebp)' (Valor resultante de sumar 8 al contenido de la direccion
                                      del registro ebp)
                          ’movl 8( %ebp), %edx’ (Lee el long contenido en la posición de memoria
                          ebp+8 y la copia al registro edx)

                          El desplazamiento puede ser con constante (8), o con variable (donde
                            empieze la variable)

  Memoria (Indexado): (Vectores)

  IMP: Solo un operando en memoria, movl (%eax), (%ebx) <- ERROR
       O una variable, addl a, b <- ERROR
                       addl (%eax), a <- ERROR


  - SINTAXIS -
  IA32    C
  $1      1     El numero 1
   1     &1     La direccion de memoria 1
   i      i     El valor de la variable i
  $i     &i     Posicion de memoria donde esta la variable i
  %eax   eax    Valor guardado en el registro eax
(%eax)  *eax    Valor de la posicion de memoria guardada en eax


  - OPERACIONES ARITMETICAS -
  Instruccion           Operacion
add[bwl] op1, op2     op2 = op2 + op1
sub[bwl] op1, op2     op2 = op2 - op1
inc[bwl] op1             op1++
dec[bwl] op1             op1--
neg[bwl] op1          op1 = -op1
imul[bwl] op1, op2    op2 = op1 * op2 (op2 debe ser registro)
