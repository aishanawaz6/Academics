[org 0x0100]
jmp start
factorial:
push bp
mov bp,sp
push cx
mov cx,ax
sub cx,1

l1: cmp cx,1
jz done
mul cx
dec cx
call l1

done:
pop cx
pop bp
ret

start :
mov ax,5
push ax
call factorial

mov ax,4c00h
int 0x21