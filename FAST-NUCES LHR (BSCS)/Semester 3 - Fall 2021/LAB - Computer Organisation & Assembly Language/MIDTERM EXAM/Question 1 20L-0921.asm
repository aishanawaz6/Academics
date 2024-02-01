[org 0x0100]
jmp starthere
arry : dw 7,4,8,2,7,7,9,5,6,1
starthere:
mov ax,[arry] ; ax will store smallest value
mov dx,[arry] ; dx will store largest value
mov bx,0 ; acts as a counter as well as helps in accessing array elements
mov cx,0

loop1:
mov cx,[arry+bx]
cmp cx,ax
jge loop2
mov ax,cx

loop2: 
cmp cx,dx
jle loop3
mov dx,cx

loop3:
add bx,2
cmp bx,20
jl loop1



mov ax,0x4c00
int 21h   