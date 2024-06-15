[org 0x0100]
jmp start
clrscr:
push es
push ax
push cx
push di

mov ax, 0xb800
mov es,ax
xor di,di
mov ax,0x0720
mov cx,2000

cld
rep stosw
pop di
pop cx
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
push di
push si
push dx
mov ax,0xb800
mov es, ax



mov al,80
mul byte[bp+8]
add ax,[bp+10]
shl ax,1
mov di,ax

mov ax,[bp+6]
sub ax,[bp+18]
mov cx,ax

mov ah,0x4
mov al,'*'
cld
rep stosw

add byte[bp+8],1
mov al,80
mul byte[bp+8]
add ax,[bp+10]
shl ax,1
mov di,ax

mov ax,[bp+6]
sub ax,[bp+18]
mov cx,ax

mov ah,0x4
mov al,'*'
cld
rep stosw

add byte[bp+8],1
mov al,80
mul byte[bp+8]
add ax,[bp+10]
shl ax,1
mov di,ax

mov ax,[bp+6]
sub ax,[bp+18]
mov cx,ax

mov ah,0x4
mov al,'*'
cld
rep stosw
add byte[bp+8],1
mov al,80
mul byte[bp+8]
add ax,[bp+10]
shl ax,1
mov di,ax

mov ax,[bp+6]
sub ax,[bp+18]
mov cx,ax

mov ah,0x4
mov al,'*'
cld
rep stosw
add byte[bp+8],1
mov al,80
mul byte[bp+8]
add ax,[bp+10]
shl ax,1
mov di,ax

mov ax,[bp+6]
sub ax,[bp+18]
mov cx,ax

mov ah,0x4
mov al,'*'
cld
rep stosw
pop dx
pop si
pop di
pop cx
pop bx
pop ax
pop es
pop bp

ret 16

start:
call clrscr

mov ax,5 ; x1 top ; bp+18
push ax
mov ax,10 ; y1 ; bp+16
push ax
mov ax,10 ; x2 left ; bp+14
push ax
mov ax, 10; y2 ;bp+12

mov ax,5 ; x3 bottom ; bp+10
push ax
mov ax, 20; y3 ; bp+8
push ax

mov ax,10; x4 right ; bp+6
push ax
mov ax,20; y4 ;bp+4
push ax
call PrintRectangle

mov ax,0x4c00
int 21h