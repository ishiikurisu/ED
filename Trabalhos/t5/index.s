	.file	"index.c"
	.section	.rodata
.LC0:
	.string	"!FLAG!"
	.text
	.globl	alerta
	.type	alerta, @function
alerta:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	alerta, .-alerta
	.section	.rodata
	.align 8
.LC1:
	.string	"ARQUIVO NAO ENCONTRADO!\nfaca um arquivo chamado \"amigos.txt\"\ne escreva uma lista de adjacencias como a seguir:\n\n\tjesus: joao, maria, pedro, mateus\n\tpedro: mateus, judas\n\tjudas: joao, maria\n"
	.text
	.globl	instrucoes
	.type	instrucoes, @function
instrucoes:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC1, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	instrucoes, .-instrucoes
	.globl	nova_lista
	.type	nova_lista, @function
nova_lista:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$40, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 32(%rax)
	movq	-8(%rbp), %rax
	movq	32(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movb	$108, 16(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	nova_lista, .-nova_lista
	.globl	adicionar_a_lista
	.type	adicionar_a_lista, @function
adicionar_a_lista:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L7
.L8:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L7:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L8
	movl	$0, %eax
	call	nova_lista
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	adicionar_a_lista, .-adicionar_a_lista
	.section	.rodata
.LC2:
	.string	"lista:"
.LC3:
	.string	"%s "
	.text
	.globl	escrever_lista
	.type	escrever_lista, @function
escrever_lista:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movl	$.LC2, %edi
	call	puts
	jmp	.L11
.L13:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L12
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rdx
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
.L12:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L11:
	cmpq	$0, -8(%rbp)
	jne	.L13
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	escrever_lista, .-escrever_lista
	.globl	presente_na_lista
	.type	presente_na_lista, @function
presente_na_lista:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	cmpq	$0, -40(%rbp)
	jne	.L15
	movl	$0, %eax
	jmp	.L16
.L15:
	jmp	.L17
.L20:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L18
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -12(%rbp)
.L18:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L17:
	cmpq	$0, -8(%rbp)
	je	.L19
	cmpl	$0, -12(%rbp)
	je	.L20
.L19:
	movl	-12(%rbp), %eax
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	presente_na_lista, .-presente_na_lista
	.globl	novo_grafo
	.type	novo_grafo, @function
novo_grafo:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$40, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 32(%rax)
	cmpq	$0, -32(%rbp)
	je	.L22
	movq	-8(%rbp), %rax
	movb	$101, 16(%rax)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L23
.L22:
	movq	-8(%rbp), %rax
	movb	$103, 16(%rax)
	movq	-8(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L23:
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L24
	movl	$0, %eax
	jmp	.L25
.L24:
	cmpq	$0, -24(%rbp)
	je	.L26
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	cltq
	movq	%rax, %rdi
	call	malloc
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
.L26:
	movq	-8(%rbp), %rax
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	novo_grafo, .-novo_grafo
	.section	.rodata
	.align 8
.LC4:
	.string	"es gibt schon eine connection\n"
	.text
	.globl	nova_conexao
	.type	nova_conexao, @function
nova_conexao:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L28
	cmpq	$0, -16(%rbp)
	je	.L28
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	jne	.L29
.L28:
	movl	$0, %eax
	jmp	.L30
.L29:
	jmp	.L31
.L32:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	cmpq	-16(%rbp), %rax
	jne	.L31
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$30, %edx
	movl	$1, %esi
	movl	$.LC4, %edi
	call	fwrite
	movq	-8(%rbp), %rax
	jmp	.L30
.L31:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L32
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L33
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	movq	-8(%rbp), %rax
	jmp	.L30
.L33:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	novo_grafo
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 32(%rax)
	movq	-8(%rbp), %rax
.L30:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	nova_conexao, .-nova_conexao
	.section	.rodata
.LC5:
	.string	"%s esta ligado a "
.LC6:
	.string	"nada "
	.text
	.globl	mostrar_conexoes
	.type	mostrar_conexoes, @function
mostrar_conexoes:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L35
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
.L35:
	jmp	.L36
.L37:
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L36:
	cmpq	$0, -8(%rbp)
	jne	.L37
	movl	$10, %edi
	call	putchar
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	mostrar_conexoes, .-mostrar_conexoes
	.globl	trocar_amigo
	.type	trocar_amigo, @function
trocar_amigo:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L39
.L42:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L40
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -20(%rbp)
.L40:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L39:
	cmpl	$0, -20(%rbp)
	jne	.L41
	cmpq	$0, -8(%rbp)
	jne	.L42
.L41:
	cmpq	$0, -8(%rbp)
	jne	.L43
	cmpl	$0, -20(%rbp)
	jne	.L43
	movl	$0, %eax
	jmp	.L44
.L43:
	movq	-16(%rbp), %rax
.L44:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	trocar_amigo, .-trocar_amigo
	.section	.rodata
.LC7:
	.string	"%c"
	.text
	.globl	identificar_amigos
	.type	identificar_amigos, @function
identificar_amigos:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movb	$32, -17(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L46
.L53:
	movl	$1, %edi
	call	malloc
	movq	%rax, -16(%rbp)
.L49:
	addl	$1, -24(%rbp)
	movl	-24(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	-56(%rbp), %rax
	movl	$.LC7, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	movl	-24(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L47
	subl	$1, -24(%rbp)
.L47:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc
	movq	%rax, -16(%rbp)
	movl	-24(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	je	.L48
	movl	-24(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$10, %al
	jne	.L49
.L48:
	movl	-24(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -17(%rbp)
	movl	-24(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-32(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	presente_na_lista
	testl	%eax, %eax
	jne	.L50
	movq	-16(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	novo_grafo
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	adicionar_a_lista
	jmp	.L51
.L50:
	movq	-32(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	trocar_amigo
	movq	%rax, -8(%rbp)
.L51:
	movq	-8(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	nova_conexao
.L46:
	cmpb	$44, -17(%rbp)
	je	.L52
	cmpb	$10, -17(%rbp)
	jne	.L53
.L52:
	movzbl	-17(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	identificar_amigos, .-identificar_amigos
	.globl	leitura_arquivo
	.type	leitura_arquivo, @function
leitura_arquivo:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, -12(%rbp)
	movq	$0, -24(%rbp)
	cmpq	$0, -48(%rbp)
	jne	.L56
	movl	$0, %eax
	call	nova_lista
	movq	%rax, -48(%rbp)
.L56:
	movl	$1, %edi
	call	malloc
	movq	%rax, -8(%rbp)
.L57:
	addl	$1, -12(%rbp)
	movl	-12(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movl	$.LC7, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc
	movq	%rax, -8(%rbp)
	movl	-12(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$58, %al
	jne	.L57
	movl	-12(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L58
	movq	-48(%rbp), %rax
	jmp	.L59
.L58:
	movq	-48(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	presente_na_lista
	testl	%eax, %eax
	jne	.L60
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	novo_grafo
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	adicionar_a_lista
	movq	%rax, -48(%rbp)
	jmp	.L61
.L60:
	movq	-48(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	trocar_amigo
	movq	%rax, -24(%rbp)
.L61:
	movq	-40(%rbp), %rdx
	movq	-24(%rbp), %rcx
	movq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	identificar_amigos
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, (%rax)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$10, %al
	jne	.L61
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	mostrar_conexoes
	movq	-48(%rbp), %rax
.L59:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	leitura_arquivo, .-leitura_arquivo
	.globl	descobrir_no_amigos
	.type	descobrir_no_amigos, @function
descobrir_no_amigos:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$-1, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L63
.L64:
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -16(%rbp)
	addl	$1, -4(%rbp)
.L63:
	cmpq	$0, -16(%rbp)
	jne	.L64
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	descobrir_no_amigos, .-descobrir_no_amigos
	.globl	preparar_loop
	.type	preparar_loop, @function
preparar_loop:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L67
.L68:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movl	$8, %edi
	call	malloc
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdx
	movl	.LC8(%rip), %eax
	movl	%eax, 4(%rdx)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	descobrir_no_amigos
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L67:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L68
	movq	-40(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	preparar_loop, .-preparar_loop
	.globl	influenciar
	.type	influenciar, @function
influenciar:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L71
	jmp	.L70
.L71:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L73
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	pxor	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -12(%rbp)
.L73:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L74
.L75:
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movss	4(%rax), %xmm0
	addss	-12(%rbp), %xmm0
	movd	%xmm0, %eax
	movq	-24(%rbp), %rdx
	movl	%eax, 4(%rdx)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L74:
	cmpq	$0, -8(%rbp)
	jne	.L75
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	nop
.L70:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	influenciar, .-influenciar
	.globl	distribuir_influencia
	.type	distribuir_influencia, @function
distribuir_influencia:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L77
.L78:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	influenciar
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L77:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L78
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	distribuir_influencia, .-distribuir_influencia
	.globl	ordenar_lista
	.type	ordenar_lista, @function
ordenar_lista:
.LFB18:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movl	$0, %eax
	call	nova_lista
	movq	%rax, -8(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L81
.L91:
	movl	.LC10(%rip), %eax
	movl	%eax, -28(%rbp)
	movq	$0, -24(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L82
.L90:
	jmp	.L83
.L85:
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -16(%rbp)
.L83:
	cmpq	$0, -16(%rbp)
	je	.L84
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L85
.L84:
	cmpq	$0, -16(%rbp)
	jne	.L86
	jmp	.L87
.L86:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movss	4(%rax), %xmm0
	ucomiss	-28(%rbp), %xmm0
	jbe	.L88
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	presente_na_lista
	testl	%eax, %eax
	jne	.L88
	movq	-48(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, -28(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
.L88:
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -16(%rbp)
.L82:
	cmpq	$0, -16(%rbp)
	jne	.L90
.L87:
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	adicionar_a_lista
	movq	%rax, -8(%rbp)
	addl	$1, -32(%rbp)
.L81:
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	descobrir_no_amigos
	cmpl	-32(%rbp), %eax
	jg	.L91
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	ordenar_lista, .-ordenar_lista
	.section	.rodata
.LC11:
	.string	"\t%s: %.2f\n"
	.text
	.globl	escrever_ranking
	.type	escrever_ranking, @function
escrever_ranking:
.LFB19:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L95
.L97:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L96
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movss	4(%rax), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC11, %edi
	movl	$1, %eax
	call	printf
.L96:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L95:
	cmpq	$0, -8(%rbp)
	jne	.L97
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	escrever_ranking, .-escrever_ranking
	.section	.rodata
.LC12:
	.string	"w"
.LC13:
	.string	"amigosED20141.txt"
.LC14:
	.string	"RANKING:\n"
	.text
	.globl	escrever_ranking_arquivo
	.type	escrever_ranking_arquivo, @function
escrever_ranking_arquivo:
.LFB20:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	$.LC12, %esi
	movl	$.LC13, %edi
	call	fopen
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	movl	$9, %edx
	movl	$1, %esi
	movl	$.LC14, %edi
	call	fwrite
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L99
.L101:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L100
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %ecx
	movq	-32(%rbp), %rax
	movss	4(%rax), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movl	$.LC11, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	fprintf
.L100:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
.L99:
	cmpq	$0, -8(%rbp)
	jne	.L101
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	escrever_ranking_arquivo, .-escrever_ranking_arquivo
	.section	.rodata
.LC15:
	.string	"ranking final:"
	.text
	.globl	gerar_ranking
	.type	gerar_ranking, @function
gerar_ranking:
.LFB21:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	ordenar_lista
	movq	%rax, -16(%rbp)
	movl	$10, %edi
	call	putchar
	movl	$.LC15, %edi
	call	puts
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	escrever_ranking
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	escrever_ranking_arquivo
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	gerar_ranking, .-gerar_ranking
	.section	.rodata
.LC16:
	.string	"r"
.LC17:
	.string	"amigos.txt"
	.text
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	$0, -8(%rbp)
	movl	$.LC16, %esi
	movl	$.LC17, %edi
	call	fopen
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L106
	movl	$0, %eax
	call	instrucoes
	movl	$1, %edi
	call	exit
.L106:
	jmp	.L107
.L108:
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	leitura_arquivo
	movq	%rax, -8(%rbp)
.L107:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	feof
	testl	%eax, %eax
	je	.L108
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	preparar_loop
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L109
	movl	$2, %edi
	call	exit
.L109:
	movl	$0, -12(%rbp)
	jmp	.L110
.L111:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	distribuir_influencia
	addl	$1, -12(%rbp)
.L110:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	descobrir_no_amigos
	cmpl	-12(%rbp), %eax
	jg	.L111
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	gerar_ranking
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC8:
	.long	1065353216
	.align 8
.LC9:
	.long	858993459
	.long	1072378675
	.align 4
.LC10:
	.long	0
	.ident	"GCC: (GNU) 4.9.0 20140604 (prerelease)"
	.section	.note.GNU-stack,"",@progbits
