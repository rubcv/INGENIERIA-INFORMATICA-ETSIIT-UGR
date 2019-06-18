.data                     # datos
msg:    .string "¡hola, mundo!\n"
tam:    .int . - msg

.text                     # código
        .globl _start     # empezar aquí

write:  movl  $4, %eax    # write
        movl  $1, %ebx    # salida estándar
        movl  $msg, %ecx  # cadena
        movl  tam, %edx   # longitud
        int   $0x80       # llamada a write
        ret               # retorno

exit:   movl  $1, %eax    # exit
        xorl  %ebx, %ebx  # 0
        int   $0x80       # llamada a exit

_start:
        call  write       # llamada a función
        call  exit        # llamada a función
