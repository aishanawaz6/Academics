[org 0x0100]
jmp start
arr: dw 1,0xAFFE,0x1230,0,0x1234
size: dw 3
f: dw 0
start:
mov cx,[size] ; stores size of array
mov bx, arr   ; stores address of array

loop1:      
mov dx,[bx]
cmp dx,0
je twob
cmp dx,1
je fourb
mov dx,word[f]
cmp dx,0
je tb2
cmp dx,1
je fb2

twob:
add bx,2
tb2:
mov ax,[bx]
div byte[2]
mov word[f],0
add bx,2
jmp here

fourb:
add bx,2
fb2:
mov ax,[bx]
div word[2]
mov word[f],1
add bx,2
jmp here

here:
sub cx,1
jnz loop1




mov ax,0x4c00
int 21h