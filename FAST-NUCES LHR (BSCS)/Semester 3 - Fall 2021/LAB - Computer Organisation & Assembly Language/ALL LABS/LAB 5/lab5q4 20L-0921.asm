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

delay:
push cx
mov cx, 60 ; change the values  to increase delay time
delay_loop1:
push cx
mov cx, 0xFFFF
delay_loop2:
loop delay_loop2
pop cx
loop delay_loop1
pop cx
ret

start:
call clrscreen
mov cx,3
mov dx,0
mov bx,0
Loop1:
;print
mov ax,1 ;COLOUR
add ax,dx
push ax
mov ax, 2 ;top x1
push ax
mov ax,10 ;left y1
push ax
mov ax,5;bottom x2
add ax,bx
push ax
mov ax,13; right y2
add ax,bx
push ax
call PrintRectangle
call delay
call clrscreen
add dx,1
add bx,5
loop Loop1

mov ax,0x4c00
int 21h
