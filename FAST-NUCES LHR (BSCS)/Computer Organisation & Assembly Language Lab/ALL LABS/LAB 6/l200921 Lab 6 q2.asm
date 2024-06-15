[org 0x0100]
jmp start
m1: db 'Hi,You pressed a'
m2: db 'Hi,You pressed b'
m3: db 'Hi,You entered wrong credentials'
oldisr: dd 0
kbisr:
push ax
push es
mov ax,0xb800
mov es,ax
in al,0x60
cmp al,0x1e
jne nextcmp
call messageprint1
jmp nomatch

nextcmp:
cmp al,0x30
jne nomatch
call messageprint2
jmp nomatch

call messageprint3
nomatch:
pop es
pop ax
jmp far [cs:oldisr]

clrscreen:
push bp
mov bp,sp
push ax
push cx
push es

mov ax,0xb800
mov es,ax
mov ax,0x720
mov cx, 20000
xor di,di

loopc:
mov [es:di],ax
add di,2
loop loopc

pop es
pop cx
pop ax
pop bp
ret 


messageprint1:
push bp
mov bp,sp
push es
push ax
push bx
push cx
push dx
push di

mov ax,0xb800
mov es,ax
xor di,di
mov ah, 0x3
mov cx,16
mov bx, m1
loopthiss:
mov al,byte[bx]
mov [es:di],ax
add di,2
add bx,1
loop loopthiss

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp

ret 
messageprint2:
push bp
mov bp,sp
push es
push ax
push bx
push cx
push dx
push di

mov ax,0xb800
mov es,ax
xor di,di
mov ah, 0x3
mov cx,16
mov bx, m2
loopthis3:
mov al,byte[bx]
mov [es:di],ax
add di,2
add bx,1
loop loopthis3

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp

ret 

messageprint3:
push bp
mov bp,sp
push es
push ax
push bx
push cx
push dx
push di

mov ax,0xb800
mov es,ax
xor di,di
mov ah, 0x3
mov cx,32
mov bx, m3
loopthis:
mov al,byte[bx]
mov [es:di],ax
add di,2
add bx,1
loop loopthis

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp

ret 

start:
call clrscreen
xor ax,ax
mov es,ax
mov ax,[es:9*4]
mov [oldisr],ax
mov ax,[es:9*4+2]
mov [oldisr+2],ax


cli
mov word[es:9*4],kbisr
mov [es:9*4+2],cs
sti
mov cx,2
l1:
mov ah,0
int 0x16
loop l1

mov ax,[oldisr]
mov bx,[oldisr+2]
cli
mov [es:9*4],ax
mov [es: 9*4+2],bx
sti

mov ax,0x4c00
int 0x21