[org 0x0100]
jmp start
array: dw 1h,2h,3h,4h,5h,6h,7h

start:
mov ax,5h ;key (ax used as a key in the program but in the end as result)
mov bx,0 ;mid
mov cx,12 ;last (6*2=12 multiply by 2 because word used)
mov dx,0 ;first

mov bx,cx
add bx,dx
shr bx,1 ; equivalent to mid=(last+first)/2

start2: 
cmp[array+bx],ax
jl less

cmp [array+bx],ax
jne great
mov ax,1 ; ax=1 indicates key found
jmp end

great:
mov cx,bx
sub cx,2 ; subtract two instead of one becuase word used
jmp check

less:
mov dx,bx
add dx,2 ; add two instead of one becuase word used

check:
mov bx,cx
add bx,dx
shr bx,1 ; shr 1 equivalent to dividing by two
cmp dx,cx
jbe start2

cmp dx,cx ; last check to verify if key found
jbe end
mov ax,0 ; ax = 0 if key not found

end:
mov ax,0x4c00
int 21h