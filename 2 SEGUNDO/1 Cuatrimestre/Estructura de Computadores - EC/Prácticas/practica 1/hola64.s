.data
msg:    .string "¡hola, mundo!\n"
tam:    .quad . - msg

.text
        .global _start

write:  mov   $1, %rax    # write
        mov   $1, %rdi    # stdout
        mov   $msg, %rsi  # texto
        mov   tam,  %rdx  # tamaño
        syscall           # llamada a write
        ret

exit:   mov   $60,  %rax  # exit
        xor   %rdi, %rdi  # 0
        syscall           # llamada a exit
        ret		  # El ret sobra, la ejecucion termina antes

_start: call  write       # llamada a función
        call  exit        # llamada a función

