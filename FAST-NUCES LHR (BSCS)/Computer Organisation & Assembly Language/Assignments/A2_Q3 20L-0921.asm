; Aisha Muhammad Nawaz 20L-0921 BSCS COAL Assignment 2 Question 3

[org 0x0100]
jmp start
m1: db 'Enter three lowercase alphabets (a~z): '
m2: db 'The output is: '
m3: db '000' ; this will save the converted aplhabets
m1l: dw 39 ; length of m1
m2l: dw 15 ; length of m2
m3l: dw 3  ; length of m3

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
mov bx,0
mov ax, 0xb800
mov es,ax
mov di,[bp+4]
mov cx, 3
mov si,0
nextchr:
mov ah,01h ; For user input 
int 21h
mov ah,0x0e ; For yellow colour
mov byte[m3+bx],Al ; TO save user input in memory in varible m3 one by one
sub byte[m3+bx],32 ; To convert saved Lowercase alphabets to uppercase
mov [es:di],ax
add di,2
add bx,1
loop nextchr
pop bx
pop di
pop cx
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

mov di,78
push di
call printstr ; Takes input from user

mov di,160
push di
mov ax,m2
push ax
push word[m2l]
call printstr2 

mov di,190
push di
mov ax,m3
push ax
push word[m3l]
call printstr2 ; final converted input displayed

mov ax,0x4c00
int 21h