; Aisha Muhammad Nawaz 20L-0921 BSCS SECTION 3E1 COAL LAB 9 Q2 Fall 2021
[org 0x0100]
jmp start
m1: db 'Original Array:'
s1: dw 15
m2: db 'Sorted Array:'
s2: dw 13
 
arr: dw 2,3,2,1,1,4,2,1,3,5
swapflag: db 0

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

swap:
mov ax,[bx+si]
xchg ax,[bx+si+2]
mov [bx+si],ax
ret 

bubblesort:
dec cx
shl cx,1

mainloop: 
mov si,0
mov byte[swapflag],0

innerloop:
mov ax,[bx+si]
cmp ax,[bx+si+2]
jbe noswap

call swap
mov byte[swapflag],1

noswap:
add si,2
cmp si,cx
jne innerloop

cmp byte[swapflag],1
je mainloop
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

start:

call clrscr

mov di,0
push di
mov ax,m1 
push ax
mov ax,[s1]
push ax
call printstr2 ; to print message 1




mov bx,arr
mov cx,10
xor ax,ax

mov dx,160




mov ax,0xb800
mov es,ax
loop1: 
mov ax,0x1 ; passing arrtribute to print num
push ax
push dx; passing di position (Place to print)
mov ax,[bx]
push ax ; Passing num that needs to be printed
call printnum
cmp cx,1 ; To avoid printing last ','
je here
add dx,2
mov di,dx
mov byte[es:di],','
here:
add dx,2
add bx,2
loop loop1

mov bx,arr 
mov cx,10
call bubblesort ; to sort array



mov di,320
push di
mov ax,m2
push ax
mov ax,[s2]
push ax
call printstr2 ; to print message 2


mov bx,arr
mov cx,10
xor ax,ax
mov dx,480

mov ax,0xb800
mov es,ax

loop2: ; to print sorted array
mov ax,0x1 ; passing arrtribute to print num
push ax
push dx; passing di position (Place to print)
mov ax,[bx]
push ax ; Passing num that needs to be printed
call printnum
cmp cx,1 ; To avoid printing last ','
je here2
add dx,2
mov di,dx
mov byte[es:di],','
here2:
add dx,2
add bx,2
loop loop2




mov ax,0x4c00
int 21h