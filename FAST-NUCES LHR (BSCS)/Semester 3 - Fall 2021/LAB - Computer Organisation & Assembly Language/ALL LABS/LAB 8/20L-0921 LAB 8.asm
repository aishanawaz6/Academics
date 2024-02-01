[org 0x0100]
jmp start
oldkb: dd 0
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


nd:
mov dx,0
div bx
add dl,0x30
push dx
inc cx
cmp ax,0
jnz nd
mov di,[bp+6]

np:
pop dx
mov dh,0x07
mov[es:di],dx
add di,2
loop np

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 4

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

timer:
push ax
push es

mov ax,126
push ax
mov al,04
out 0x70, al ; command byte written at first port
jmp D1 ; waste one instruction time
D1: in al, 0x71 ; result of command is in AL now ;Following are few commands: 00 Get current second 02 Get current minute 04 Get current hour
mov ah,0
push ax
call printnum

mov ax,0xb800
mov es,ax
mov byte[es:130],':'


mov ax,132
push ax
mov al,02
out 0x70, al ; command byte written at first port
jmp D2 ; waste one instruction time
D2: in al, 0x71 ; result of command is in AL now ;Following are few commands: 00 Get current second 02 Get current minute 04 Get current hour
mov ah,0
push ax
call printnum


mov ax,0xb800
mov es,ax
mov byte[es:136],':'


mov ax,138
push ax
mov al,00
out 0x70, al ; command byte written at first port
jmp D3 ; waste one instruction time
D3: in al, 0x71 ; result of command is in AL now ;Following are few commands: 00 Get current second 02 Get current minute 04 Get current hour
mov ah,0
push ax
call printnum

mov al,0x20
out 0x20,al
pop es
pop ax
iret


start:
call clrscr
xor ax,ax
mov es,ax
mov ax,[es:8*4]
mov [oldkb],ax

mov ax,[es:8*4+2]
mov [oldkb+2],ax
cli
mov word[es:8*4],timer
mov word[es:8*4+2],cs
sti

mov dx,start
add dx,15
mov cl,4
shr dx,cl
mov ax,0x3100
int 0x21