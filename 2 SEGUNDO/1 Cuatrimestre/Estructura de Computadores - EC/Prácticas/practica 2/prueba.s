.section .data

salida: .asciiz "salida"
longsalida: .int .-salida

_start: .global _start
  mov $4, %ebx
  mov %ebx, %edx
  mov longsalida, %eax
  add %edx, %eax
  mov %eax, %ebx
  mov $1, %eax
  int 0x80
