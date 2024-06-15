[org 0x0100]
mov bx,1011000110001001b
mov cx,0
mov dx,0

start:
shr bx,1
jnc noc
add cx,1

noc:
add dx,1
cmp dx,16
jnz start

mov ax,1010101110100101b
mov bx,0
start2:
xor ax,1
ror ax,1
add bx,1
cmp bx,cx
jnz start2


mov dx,0
start3:
rol ax,1
add dx,1
cmp dx,cx
jnz start3

mov ax,0x4c00
int 0x21