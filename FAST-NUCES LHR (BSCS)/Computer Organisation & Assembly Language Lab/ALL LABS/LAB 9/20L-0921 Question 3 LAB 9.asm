; Aisha Muhammad Nawaz 20L-0921 BSCS SECTION 3E1 COAL LAB 9 Q3 Fall 2021
[org 0x0100]
jmp start
arr: dw 2,3,2,1,1,4,2,1,3,5
m1: db 'found'
s1: dw 5
m2: db 'failed'
s2: dw 6

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
mov di, 0
mov si, [bp+6]
mov cx, [bp+4]
mov ah,byte[bp+8]
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


findkey:
push bp
mov bp,sp
push ax
push bx
push cx
push dx

mov bx,[bp+8] ; array address
mov dx,[bp+4] ; key
mov cx,[bp+6] ; size
loopit:
mov ax,[bx]
cmp ax,dx
je here 
add bx,2
loop loopit
jmp here2
here: ; key found
mov ax,0x82 ; arttribute
push ax
mov ax,m1 ; address of message
push ax
mov ax,[s1] ; size of message
push ax
call printstr2
jmp end
here2: ;key not found
mov ax,0x4 ; arttribute
push ax
mov ax,m2 ; address of message
push ax
mov ax,[s2] ; size of message
push ax
call printstr2



end:
pop bp
pop ax
pop bx
pop cx
pop dx
ret 6
start:
call clrscr

mov ax,arr ; array address
push ax
mov cx,10 ; array size
push cx 
mov ax, 5 ; key to search (To test : 5 will give found, 0 will give failed)
push ax 
call findkey





mov ax,0x4c00
int 21h