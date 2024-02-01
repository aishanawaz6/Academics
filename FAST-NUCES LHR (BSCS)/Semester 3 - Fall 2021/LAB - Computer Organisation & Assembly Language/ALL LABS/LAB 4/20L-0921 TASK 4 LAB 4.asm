[org 0x0100]

jmp start
power:
push bp
mov bp,sp
push bx
push cx
mov cx,ax

l1:
mul cx
dec bx
cmp bx,1
jnz l1

pop cx
pop bx
pop bp

ret 4

start:
mov ax,3
mov bx,2
push ax
push bx
call power



mov ax,0x4c00
int 21h