.data
	msg: 		.asciiz 	"Resultado da soma: "
	first_num:	.asciiz 	"Digite o primeiro numero inteiro: "
	second_num: 	.asciiz 	"Digite o segundo numero inteiro: "
	nl:		.asciiz 	"\n"

.text
	li $v0, 4			#imprimindo first_num
	la $a0, first_num
	syscall
	
	li $v0, 5			#lendo o primeiro inteiro e salvando
	syscall
	add $t1, $v0, $zero
	
	li $v0, 4			#imprimindo second_num				
	la $a0, second_num		
	syscall
	
	li $v0 5			#lendo segundo inteiro e salvando
	syscall
	add $t2, $v0, $zero		
	
	li $v0, 4			#imprimindo quebra de linha
	la $a0, nl
	syscall

	jal soma			# chama a função soma

    	add $t0,$zero, $v0    		# guarda o resultado retornado

    	li $v0, 4        		# imprimir string
    	la $a0, msg
    	syscall

    	li $v0, 1        		# imprimir número
    	add $a0,$zero, $t0
    	syscall
    	
    	li $v0, 4			#quebra de linha
    	la $a0, nl
    	syscall

    	li $v0, 10       		# encerrar programa
    	syscall


soma:
    	add $v0, $t1, $t2   		# calcula a soma
    	jr $ra              		# volta para quem chamou