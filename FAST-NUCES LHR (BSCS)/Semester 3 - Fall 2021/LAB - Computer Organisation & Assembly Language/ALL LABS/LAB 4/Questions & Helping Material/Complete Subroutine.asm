[org 0x0100]

JMP Start

MyArray: dw 1, 3, 10, 5, 6, 7, 1, 64, 3, 10

SumSubRoutine:

push AX
push BX
push CX
push bp

mov bp, sp
mov BX, [bp+12]

mov cx, [bp+10]

mov ax, 0

loop_:
    add ax, [BX]
	add BX, 2
	loop loop_
	
	mov word [bp+14], AX 
	
	
	pop bp ;restore the value of bp
	pop cx ;restore the value of cx
	pop bx ;restore the value of bx
	pop ax ;restore the value of ax
	
	ret 4 ;the ret instruction will pop the top most value from stack and put it in the ip, so the next instruction will be executed from the address popped from stack.
	      ; here 4 means that we will add 4 in sp, this is used to clear the 2 parameters passed to this routine (each parameter is of two bytes)
	


Start:

sub sp, 2 ;making room for return value
mov AX, MyArray
push AX ;address of MyArray will be pushed
push 10 ;size of MyArray will be pushed
call SumSubRoutine
Pop AX ;sum will be stored in AX

mov ax, 4c00h
int 0x21