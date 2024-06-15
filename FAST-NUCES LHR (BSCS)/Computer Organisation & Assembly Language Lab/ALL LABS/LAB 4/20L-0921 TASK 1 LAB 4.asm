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
		 ret 8 ;what is this instruction doing? ans: it returns to main and first inc 2 then 8 in stack/sp returns sp to starting address from where it begain.the ret instruction will pop the top most value from stack and put it in the ip, so the next instruction will be executed from the address popped from stack.
	      ; here 8 means that we will add 8 in sp, this is used to clear the 4 parameters passed to this routine (each parameter is of two bytes)
			 
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
 
 
 pop AX ;what will be the value in AX? ans: 0
        ;What is the  sub routine doing? ans: finding the greatest value out of num1,num2,num3
	;What changes will have to be done in the code so that it works when num4 is also passed as parameter? ans: push 4 instead of 3
 
 mov ax, 4c00h
 int 0x21