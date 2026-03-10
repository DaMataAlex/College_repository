#exercicio que calcula a distancia entre dois pontos

.data

x1: 	.asciiz "Digite o valor x do primeiro par ordenado: "
y1: 	.asciiz "Digite o valor y do primeiro par ordenado: "
x2: 	.asciiz "Digite o valor x do segundo par ordenado: "
y2: 	.asciiz "Digite o valor y do segundo par ordenado: "
str1: 	.asciiz "A distância entre os dois pontos é: "
nl:	.asciiz "\n"

.text

mtc1 $zero, $f1
cvt.s.w $f1, $f1	# cria 0.0 em f1

li $v0, 4		#imprimindo a primeira string
la $a0, x1
syscall

li $v0, 6		#lendo x1
syscall
add.s $f2, $f0, $f1	# guarda x1

li $v0, 4		#imprimindo a segunda string
la $a0, y1
syscall

li $v0, 6		#lendo y1
syscall
add.s $f3, $f0, $f1	# guarda y1

li $v0, 4		#imprimindo a terceira string
la $a0, x2
syscall

li $v0, 6		#lendo x2
syscall
add.s $f4, $f0, $f1	# guarda x2

li $v0, 4		#imprimindo a quarta string
la $a0, y2
syscall

li $v0, 6		#lendo y2
syscall
add.s $f5, $f0, $f1	# guarda y2

sub.s $f6, $f4, $f2	#fazendo a operação (x2 - x1)^2
mul.s $f6, $f6, $f6

sub.s $f7, $f5, $f3	#fazendo a operação (y2 - y1)^2
mul.s $f7, $f7, $f7

add.s $f8, $f6, $f7	#somando os resultados das duas operações anteriores

sqrt.s $f9, $f8		#tirando a raíz quadrada do resultado

li $v0, 4		#imprimindo uma quebra de linha
la $a0, nl
syscall

li $v0, 4		#imprimindo texto final
la $a0, str1
syscall

li $v0, 2		#imprimindo o resultado
add.s $f12, $f9, $f1
syscall

li $v0, 4		#imprimindo quebra de linha
la $a0, nl
syscall

li $v0, 4		#imprimindo a última quebra de linha
la $a0, nl
syscall
