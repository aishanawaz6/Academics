; Aisha Muhammad Nawaz 20L-0921 BSCS COAL Assignment 2 Question 6

[org 0x0100]
jmp start
m1: db 'Enter a 2-digit number: '
m2: db 'Enter another 2-digit number: '
m3: db 'Value of ax: '
m1l: dw 24
m2l: dw 30
m3l: dw 13
n: dw 0
ten: db 10
clrscreen: ; Simple Clear Screen Subroutine
push es
push ax
push di
mov ax,0xb800
mov es,ax
mov di,0
nextchar:
mov word[es:di],0x0720
add di,2
cmp di,4000
jne nextchar
pop di
pop ax
pop es
ret
 
printstr2: ; Subroutine for displaying messages
push bp
mov bp,sp
push es
push ax
push cx
push si
push di
mov ax, 0xb800
mov es,ax
mov di, [bp+8]
mov si, [bp+6]
mov cx, [bp+4]
mov ah,0x07
nextchr2:
mov al,[si]
mov [es:di],ax
add di,2
add si,1
loop nextchr2
pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 6

printstr: ; Subroutine for taking input from user, Saving it and displaying it
push bp
mov bp,sp
push es
push ax
push cx
push di
push bx
push dx

mov bx,0
mov ax, 0xb800
mov es,ax
mov di,[bp+4]
mov cx, 2
mov si,0

nextchr:
mov ah,01h ; For user input
int 21h
 
cmp bx,0
jne hr
mov dl,al
sub al,48
mul byte[ten]
mov byte[n],al
mov al,dl
jmp hr2

hr: 
mov dl,al
sub al,48
add byte[n],al
mov al,dl

hr2: mov ah,0x0e ; For yellow colour
mov [es:di],ax
add di,2
add bx,1
loop nextchr


pop dx
pop bx
pop di
pop cx
pop ax
pop es
pop bp
ret 2


printnum:
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

nd: mov dx,0
div bx
add dl,0x30
push dx
inc cx
cmp ax,0
jnz nd

mov di,346

npo: pop dx
mov dh,0x07
mov [es:di],dx
add di,2
loop npo

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 2

start: ; Main from Here
call clrscreen

mov di,0
push di
mov ax,m1
push ax
push word[m1l] 
call printstr2


mov di,48
push di
call printstr ; Takes input from user
mov dx,[n]

mov di,160
push di
mov ax,m2
push ax
push word[m2l]
call printstr2 

mov di,220
push di
call printstr ; Takes input from user
add dx,[n]
mov [n],dx

mov di,320 ; for displaying ax value
push di
mov ax,m3 
push ax
push word[m3l]
call printstr2 

mov ax,[n] ; Storing in ax the sum and showing it to user
push ax
call printnum


mov ax,0x4c00
int 21h