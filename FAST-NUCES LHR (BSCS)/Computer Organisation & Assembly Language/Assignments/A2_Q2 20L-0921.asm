; Aisha Muhammad Nawaz 20L-0921 BSCS COAL Assignment 2 Question 2
[org 0x0100]
jmp start
ALPHA: dw 36
message: db 'ALPHA is: '
l: dw 10
clrscr:
push es
push ax
push di

mov ax,0xb800
mov es,ax
mov di,0

loop1:
mov word[es:di],0x0720
add di,2
cmp di,4000
jne loop1 

pop di
pop ax
pop es
ret

pn:
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
mov ax,[bp+4]
mov bx,10
mov cx,0

nxt:
mov dx,0
div bx
add dl,0x30
push dx
inc cx
cmp ax,0
jnz nxt

mov di,20

np:
pop dx
mov dh,0x07
mov [es:di],dx
add di,2
loop np

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 2

pmes:
push bp
mov bp,sp
push es
push ax
push cx
push si
push di

mov ax,0xb800
mov es,ax
mov di,0

mov si,[bp+6]
mov cx,[bp+4]
mov ah,0x07

lop1:
mov al,[si]
mov [es:di],ax 
add di,2
add si,1
dec cx
jnz lop1

pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 4

start:
call clrscr
mov ax,message
push ax
push word[l]
call pmes
mov ax,word[ALPHA]
push ax
call pn
mov ax,0x4c00
int 21h