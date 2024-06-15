[org 0x0100]
jmp start

scrollup:
push bp
mov bp,sp
push ax
push cx
push si
push di
push es
push ds

mov ax,80
mul byte[bp+4] ;80*number of rows to shift
mov si,ax
push si
shl si,1
mov cx,2000
sub cx,ax
mov ax,0xb800
mov es, ax
mov ds,ax
xor di,di
cld 
rep movsw
mov ax,0x720
pop cx
rep stosw

pop ds
pop es
pop di
pop si
pop cx
pop ax
pop bp
ret 2

scrolldown:
push bp
mov bp,sp
push es
push ds
push cx
push ax
push si
push di

mov ax,80
mul byte[bp+4]
push ax
shl ax,1
mov si,3998
sub si,ax
mov cx,2000
sub cx,ax
mov ax,0xb800
mov es,ax
mov ds,ax
mov di,3998
std
rep movsw
mov ax,0x0720
pop cx
rep stosw

pop di
pop si
pop ax
pop cx
pop ds
pop es
pop bp

ret 2

delay:
push cx
mov cx, 100 ; change the values  to increase delay time
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
loopit:
mov ax,3
push ax
call scrolldown
call delay
mov ax,3
push ax
call scrollup
call delay
jmp loopit
mov ax,0x4c00
int 0x21