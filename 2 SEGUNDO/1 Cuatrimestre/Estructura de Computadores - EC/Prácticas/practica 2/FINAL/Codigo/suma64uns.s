.section .data
lista:   .int  4294967295, 4294967295, 1, 2, 3, 4, 5, 6
         .int  0b111, 0b1000, 0b1001, 0b1010, 0b1011, 0b1100, 0b1101, 0b1110
         .int  017, 020, 021, 022, 023, 024, 025, 026
         .int  0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E


longlista:  .int    (.-lista)/4
resultado:  .quad   -1

.section .text
_start: .global _start
    mov     $lista, %ebx
    mov     $0, %edx
    mov     longlista, %ecx
    call    suma
    mov     %eax, resultado
    mov     %edx, resultado+4
    mov     $1, %eax
    mov     $0, %ebx
    int     $0x80

suma:
  push    %esi
  mov     $0, %eax
  mov     $0, %esi

bucle:
  add     (%ebx, %esi, 4), %eax
  jnc     acarreo
  inc     %edx

acarreo:
  inc     %esi
  cmp     %esi,%ecx
  jne     bucle
  pop     %esi
  ret
