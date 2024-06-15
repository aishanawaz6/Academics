[org 0x0100]

jmp start

num1: dw 0x010
num2: dw 0x342
num3: dw 0x111
num4: dw 0x543

function:

 mov bp, sp
 mov cx, [bp+2]
 
 mov ax, [bp+4]
 
 mov si, 4
 
 loop_:
         mov bx, [SS:bp+si]
		 cmp ax, bx
		 jl great
		 
		 continue:
		    add si, 2
			
		    sub cx,1
			jnz loop_
		 
		 mov si, [bp+2]
		 add si, 2
		 shl si, 1
		 
		 
		 mov [SS:bp+si], ax
		 mov ax, 0
		 ret 8 ;what is this insruction doing?
		 
great:
mov ax, bx
jmp continue



start:

 sub sp, 2
 push word [num1]
 push word [num2]
 push word [num3]
 
 push 3
 
 
 call function
 
 
 pop AX ;what will be the value in AX? 
        ;What is the  sub routine doing? 
		;What changes will have to be done in the code so that it works when num4 is also passed as parameter?
 
 mov ax, 4c00h
 int 0x21