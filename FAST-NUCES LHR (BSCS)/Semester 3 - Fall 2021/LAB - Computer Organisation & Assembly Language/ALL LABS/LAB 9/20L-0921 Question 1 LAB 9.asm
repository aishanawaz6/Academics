; Aisha Muhammad Nawaz 20L-0921 BSCS SECTION 3E1 COAL LAB 9 Q1 Fall 2021
[org 0x0100]
jmp start
arr: dw 2,3,2,1,1,4,2,1,3,5

clrscr:push es
push ax
push di
mov ax,0xb800
mov es,ax
mov di,0

nextloc: mov word [es:di],0x0720
add di,2
cmp di,4000
jne nextloc

pop di
pop ax
pop es
ret
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
mov di,[bp+6]


nd:
mov dx,0
div bx
add dl,0x30
push dx
inc cx
cmp ax,0
jnz nd

npos:
pop dx
mov dh,[bp+8]
mov [es:di],dx
add di,2
loop npos

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 6

start:
mov bx,arr
mov cx,10
xor ax,ax

loop1: ; to get sum
add ax,[bx]
add bx,2
loop loop1
mov dx,ax ; result store in dx

call clrscr

mov ax,0x4 ; passing arrtribute to print result
push ax
mov ax,0 ; passing di position (Place to print)
push ax
push dx ; Passing result that needs to be printed
call printnum



mov ax,0x4c00
int 21h