; Aisha Muhammad Nawaz 20L-0921 BSCS COAL Assignment 2 Question 1
[org 0x0100]
jmp start
db 'abc'
message: db 'I won $25000 in loterry but I lost $5000.' ; Message to display
length: dw 41

clrscreen:
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

printstr:
push bp
mov bp,sp
push es
push ax
push cx
push si
push di

mov ax, 0xb800
mov es,ax
mov di, 0
mov si, [bp+6]
mov cx, [bp+4]
mov ah,0x07

nextchr:
mov al,[si]
mov [es:di],ax
add di,2
add si,1
loop nextchr
pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 4
start:
call clrscreen
mov ax,message
push ax
push word[length]
call printstr

mov ax,0x4c00
int 21h