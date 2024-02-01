[org 0x0100]
jmp start
arr: dw 5,4,5,8,6 
size: dw 5
swap: db 0
count : dw 0
remdub:
push bp
mov bp,sp
push ax
push bx
push cx
push dx
push si
push di

mov bx,[bp+6] ; arr address
mov cx,[bp+4] ; size of array

loop1:
mov ax,[bx]
mov si,0
mov di,0
loop2:
mov dx,[arr+si]
cmp ax,dx
jne con2
add di,1
cmp di,2
jl con2
mov word[arr+si],-1
add word[count],1
con2:
add si,2
cmp si,10
jne loop2

con:
add bx,2
sub cx,1
cmp cx,0
jne loop1
; bubble sort here
mov bx,[bp+6]
mov cx,[bp+4]

bs: 
dec cx
shl cx,1
ml: 
mov si,0
mov byte[swap],0

il: 
mov ax,[arr+si]
cmp ax,-1
je swapp
cmp word[arr+si+2],-1
je noswap
cmp ax,[arr+si+2]
jbe noswap
swapp:
mov dx,[arr+si+2]
mov [arr+si],dx
mov [arr+si+2],ax
mov byte[swap],1

noswap:
add si,2
cmp si,cx
jne il
cmp byte[swap],1
je ml









mov bx,[bp+6]
mov cx,0
disp:
mov ax,[bx]
add bx,2
add cx,1
cmp cx,5
jne disp

mov cx,[bp+4]
sub cx,[count]
mov word[size],cx

pop di 
pop si
pop dx
pop cx
pop bx
pop ax
pop bp
ret 4

start:
mov ax,arr
push ax
mov ax,[size]
push ax
call remdub



mov ax,0x4c00
int 21h