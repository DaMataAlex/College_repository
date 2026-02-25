#exercício de somar duas variáveis já definidas no início do programa
.data

a: .word 4
b: .word 6
nl: .asciiz "\n"
msg1: .asciiz "Primeira váriavel: "
msg2: .asciiz "Segunda variável: "
str3: .asciiz "Resultado da soma: "

.text
#operações com as variáveis

la $t0, a		    #salvando em t0 o que tá guardado no a
lw $t1, 0($t0)		#salvando em t1 o que está em t0

la $t0, b		    #salvando em t0 o que tá guardado no b
lw $t2, 0($t0)		#salvando em t2 o que está guardado em t0

add $t3, $t2, $t1	#guardand em t3, a soma de t2 e t1

#parte de impressão
li $v0, 4		    #guardando em v0 qual operação será realizada pelo syscall
la $a0, msg1		#guardando em a0 o endereço da string msg1
syscall

li $v0, 1		    #guardando em v0 qual operação será realizada pelo syscall
add $a0, $t1, $zero	#guardando em a0 o valor de t3
syscall

li $v0, 4
la $a0, nl
syscall

la $a0, msg2
syscall

li $v0, 1
add $a0, $t2, $zero
syscall

li $v0, 4
la $a0, nl
syscall

la $a0, str3
syscall

li $v0, 1
add $a0, $t3, $zero
syscall

li $v0, 4
la $a0, nl
syscall