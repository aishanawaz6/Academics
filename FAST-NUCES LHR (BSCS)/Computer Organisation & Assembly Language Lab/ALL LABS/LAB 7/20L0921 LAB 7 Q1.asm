[org 0x0100]
jmp start
Video: times 2000 dw 0
oldisr: dd 0

kbisr:
push ax
push es

mov ax,0xb800
mov es,ax

in al,0x60
cmp al,0x1D
jne nextcmp

call clrscreen
jmp exit

nextcmp:
cmp al,0x9D
jne nomatch
;mov byte[es:0],'R'
call printstored
jmp exit

nomatch:
pop es
pop ax
jmp far[cs:oldisr]

exit:
mov al,0x20
out 0x20,al

pop es
pop ax
iret

clrscreen:
push es
push ax
push cx
push di

mov ax,0xb800
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

printstored:
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
mov di,0
mov cx,2000
mov bx,Video

loop2:
mov ax,[bx]
mov[es:di],ax
add di,2
add bx,2
loop loop2

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp

ret

store: 
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
mov di,0
mov bx,Video
mov cx, 2000

loop1:
mov ax,[es:di]
mov [bx],ax
add di,2
add bx,2
loop loop1

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp

ret 




start:
call store

xor ax,ax
mov es,ax
mov ax,[es:9*4]
mov[oldisr],ax
mov ax,[es:9*4+2]
mov [oldisr+2],ax
cli
mov word[es:9*4],kbisr
mov [es:9*4+2],cs
sti
mov dx,start
add dx,15
mov cl,4
shr dx,cl
mov ax,0x3100
int 0x21



mov ax,0x4c00
int 21h