#exercício de somar duas variáveis INTEIRAS definidas pelo usuário
.data

str1: 		    .asciiz "Digite um valor inteiro: "
str2: 		    .asciiz "Digite um segundo valor inteiro: "
soma: 		    .asciiz "Soma das variáveis: "
subtracao: 	    .asciiz "Subtração das variáveis: "
multiplicacao: 	.asciiz "Multiplicação das variáveis: "
divisao: 	    .asciiz "Divisão das variáveis: "
nl:		        .asciiz "\n"

.text

li $v0, 4		    #printando a primeira string
la $a0, str1
syscall

li $v0, 5		    #escaneando o valor da primeira variável
syscall
add $t1, $v0, $zero

li $v0, 4		    #printando a segunda string
la $a0, str2
syscall

li $v0, 5		    #escaneando o valor da segunda variável
syscall
add $t2, $v0, $zero

li $v0, 4		    #printando quebra de linha pra dar uma identada no programa
la $a0, nl
syscall

li $v0, 4		    #printando a mensagem de soma
la $a0, soma
syscall

add $t0, $t1, $t2	#adicionando no t0 a soma das variáveis, e depois printando t0
li $v0, 1
add $a0, $t0, $zero
syscall

li $v0, 4		    #printando quebra de linha
la $a0, nl
syscall

li $v0, 4		    #printando a mensagem de subtração
la $a0, subtracao
syscall

sub $t0, $t1, $t2	#adicionando no t0 a subtração das variáveis, e depois printando t0
li $v0, 1
add $a0, $t0, $zero
syscall

li $v0, 4		    #printando quebra de linha
la $a0, nl
syscall

li $v0, 4		    #printando a mensagem de multiplicação
la $a0, multiplicacao
syscall

mul $t0, $t1, $t2	#adicionando no t0 a multiplicação das variáveis, e depois printando t0
li $v0, 1
add $a0, $t0, $zero
syscall

li $v0, 4		    #printando quebra de linha
la $a0, nl
syscall

li $v0, 4		    #printando a mensagem de divisao
la $a0, divisao
syscall

div $t1, $t2		#adicionando no t0 a divisao das variáveis, e depois printando t0
mflo $t0
li $v0, 1
add $a0, $t0, $zero
syscall

li $v0, 4		    #printando quebra de linha
la $a0, nl
syscall
