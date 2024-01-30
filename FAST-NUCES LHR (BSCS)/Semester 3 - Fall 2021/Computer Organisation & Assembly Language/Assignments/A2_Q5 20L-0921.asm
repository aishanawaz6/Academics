; Aisha Muhammad Nawaz 20L-0921 BSCS COAL Assignment 2 Question 5

[org 0x0100]
jmp start
m1: db 'Enter a number (0-9): '
m2: db 'Enter another number (0-9): '
m3: db 'Sum = ' 
m4: db 'Difference = ' 
m5: db 'Product = '
m6: db 'Division = '
m1l: dw 22  ; length of m1
m2l: dw 28  ; length of m2
m3l: dw 6  ; length of m3
m4l: dw 13 ; length of m4
m5l: dw 10 ; length of m5
m6l: dw 11 ; length of m6
n: db '1'
n1:db '0'
n2: db '0'
s: db 0
d: db 0
p: db 0
divi: db 0
clrscreen: ; Simple Clear Screen Subroutine
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

printstr: ; Subroutine for taking input from user, Saving it and displaying it
push bp
mov bp,sp
push es
push ax
push cx
push di
push bx
mov bx,0
mov ax, 0xb800
mov es,ax
mov di,[bp+4]
mov cx, 1
mov si,0
nextchr:
mov ah,01h ; For user input 
int 21h
mov byte[n],al
mov ah,0x0e ; For yellow colour
mov [es:di],ax
add di,2
add bx,1
loop nextchr
pop bx
pop di
pop cx
pop ax
pop es
pop bp
ret 2

start: ; Main from Here
call clrscreen

mov di,0
push di
mov ax,m1
push ax
push word[m1l] 
call printstr2

mov di,44
push di
call printstr ; Takes input from user
mov ax,[n]
mov [n1],ax

mov di,160
push di
mov ax,m2
push ax
push word[m2l]
call printstr2 

mov di,216
push di
call printstr ; Takes input from user
mov ax,[n]
mov [n2],ax

mov di,320
push di
mov ax,m3
push ax
push word[m3l]
call printstr2 

mov al,[n1] ;Displays Sum
add al,[n2]
sub al,48
mov [s],al
mov di,332
push di
mov ax,s
push ax
mov bx,1
push bx
call printstr2

mov di,480
push di
mov ax,m4
push ax
push word[m4l]
call printstr2 

mov al,byte[n1] ;Displays Difference
sub al,byte[n2]
add al,48
mov [d],al
mov di,506
push di
mov ax,d
push ax
mov bx,1
push bx
call printstr2

mov di,640
push di
mov ax,m5
push ax
push word[m5l]
call printstr2 

mov al,[n1] ;Displays Product
sub al,48
mov dl,[n2]
sub dl,48
mul dl
add al,48
mov byte[p],al
mov di,660
push di
mov ax,p
push ax
mov bx,1
push bx
call printstr2

mov di,800
push di
mov ax,m6
push ax
push word[m6l]
call printstr2 

;Does Division
mov al,[n1] 
sub al,48 ; covert from ascii to digit
cbw ; extend contets of al into ah

mov bl,[n2]
sub bl,48 ; covert from ascii to digit
div bl
add al,48; Converting back to ascii to display
mov [divi],al

mov di,822 ;Displays Division Answer
push di
mov ax,divi
push ax
mov bx,1
push bx
call printstr2

mov ax,0x4c00
int 21h