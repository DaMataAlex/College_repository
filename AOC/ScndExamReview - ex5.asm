.data

#iniciando todas as variáveis que serão utilizadas no problema

a:	.word	1
b:	.word	0
c:	.word	0
d:	.word	0
e:	.word	0
f:	.word	0
g:	.word	0
h:	.word	0

#iniciando algumas strings

stra:		.asciiz	"Valor de a: "
strb:		.asciiz "Valor de b: "
digitea:	.asciiz	"Digite o valor de a: "
digiteb:	.asciiz	"Digite o valor de b: "
digitec:	.asciiz	"Digite o valor de c: "
digited:	.asciiz	"Digite o valor de d: "
digitee:	.asciiz	"Digite o valor de e: "
digitef:	.asciiz	"Digite o valor de f: "
digiteg:	.asciiz	"Digite o valor de g: "
digiteh:	.asciiz	"Digite o valor de h: "
nl:		.asciiz	"\n"
a_:		.asciiz	"a)"
b_:		.asciiz	"b)"
c_:		.asciiz	"c)"
d_:		.asciiz	"d)"
e_:		.asciiz	"e)"
f_:		.asciiz	"f)"
g_:		.asciiz	"g)"
h_:		.asciiz	"h)"
i_:		.asciiz	"i)"
j_:		.asciiz	"j)"
k_:		.asciiz	"k)"
l_:		.asciiz	"l)"
m_:		.asciiz	"m)"

.text

#a)

li $v0, 4
la $a0, a_
syscall
la $a0, nl
syscall

la $t0, a
lw $t1, 0($t0)		#não precisava passar pra $t1 mas é bom que eu treino
li $t1, 0
sw $t1, 0($t0)

la $a0, stra
syscall
li $v0, 1
lw $a0, a
syscall

li $v0, 4
la $a0, nl
syscall
syscall

#b)
la $a0, b_
syscall
la $a0, nl
syscall

la $t0, b
lw $t1, 0($t0)
addi $t1, $zero, 42
sw $t1, 0($t0)

la $a0, strb
syscall
li $v0, 1
lw $a0, b
syscall

li $v0, 4
la $a0, nl
syscall
syscall

#c)
la $a0, c_
syscall

la $a0, nl
syscall

la $a0, digiteb
syscall

li $v0, 5
syscall
add $t1, $zero, $v0

li $v0, 4
la $a0, digitec
syscall

li $v0, 5
syscall
add $t2, $zero, $v0

li $v0, 4
la $a0, digited
syscall

li $v0, 5
syscall
add $t3, $zero, $v0

add $t0, $t1, $t2
sub $t4, $t2, $t3

div $t0, $t4
mflo $t1

la $t0, a
sw $t1, 0($t0)

li $v0, 4
la $a0, nl
syscall
la $a0, stra
syscall

li $v0, 1
lw $a0, a
syscall

li $v0, 4
la $a0, nl
syscall
syscall






