;Aisha Muhammad Nawaz 20L-0921 BSCS SECTION 3E1 COAL QUIZ 1

[org 0x0100]
jmp start
mySeries: dw 0,1 ; Array that stores Answers
temp : dw 0 ; temp variable to ease calculation
total: dw 0
start:
mov ax,8 ; value of n
mov bx,2
mul bx
mov word[total],ax

mov cx,0
mov dx,1
mov word[temp],cx
mov bx,4

loop1:
mov word[temp],dx
add dx,cx
mov cx,word[temp]
mov word[mySeries+bx],dx

add bx,2
cmp bx,ax
jl loop1


mov bx,0b; to check values of array
loop2:
mov cx,[mySeries+bx]
add bx,2
cmp bx,ax
jnz loop2


mov ax,0x4c00
int 21h