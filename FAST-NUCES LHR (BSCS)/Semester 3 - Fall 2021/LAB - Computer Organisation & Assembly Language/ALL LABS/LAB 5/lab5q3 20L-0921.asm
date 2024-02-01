[org 0x0100]
jmp start

clrscreen:
push es
push ax
push di
mov ax,0xb800
mov es,ax
mov di,0
nl:
mov word[es:di],0x0720
add di,2
cmp di,4000
jne nl

pop di
pop ax
pop es
ret 

PrintRectangle:
push bp
mov bp,sp
push es
push ax
push bx
push cx
push dx

mov ax,0xb800
mov es,ax


loopm:  ; main loop
mov al,80
mul byte[bp+8]
add ax,[bp+10]
shl ax,1
mov di,ax
mov cx,[bp+4]
mov ax,[bp+6]
sub cx,ax
mov al,0x2A ; ascii of *
mov ah,[bp+12] ; attribute

nl2:
mov word[es:di],ax
add di,2
loop nl2

add word[bp+8],1 ; y coordinate changes by 1 till y1 equals y2
mov dx,[bp+8]
cmp dx,[bp+4]
jnz loopm


pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 10 ;5*2=10

start:
call clrscreen
mov ax,4 ; RED COLOUR
push ax
mov ax, 2 ;top x1
push ax
mov ax,10 ;left y1
push ax
mov ax,5;bottom x2
push ax
mov ax,13; right y2
push ax
call PrintRectangle


mov ax,0x4c00
int 21h
