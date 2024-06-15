[org 0x0100]

mov ax,0000000000000100b
mov bx,ax
mov ax,0000000000000010b
mov cx,0

start:
shr bx,1
jnc con
mul cx
add [result],ax

con:
add cx,1b
cmp cx,0000000000010000b
jnz start

mov bx,0001010101010101b
mov cx,0
mov ax,1b
mov dx,[result]

start2:
shl ax,1
add cx,1
cmp cx,dx
jnz start2

xor bx,ax

mov ax,0x4c00
int 21h

result : dw 0