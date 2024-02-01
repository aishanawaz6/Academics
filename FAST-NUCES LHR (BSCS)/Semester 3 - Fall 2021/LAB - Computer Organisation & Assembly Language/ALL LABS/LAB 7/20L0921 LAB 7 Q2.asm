[org 0x0100]
jmp start

oldisr: dd 0

kbisr:
push ax
push es

mov ax,0xb800
mov es,ax

in al,0x60
cmp al,0x2a
jne nextcmp
mov byte[es:0],'H'
mov byte[es:2],'e'
mov byte[es:6],'h'
mov byte[es:8],'a'
mov byte[es:10],'s'
mov byte[es:14],'f'
mov byte[es:16],'o'
mov byte[es:18],'o'
mov byte[es:20],'d'
mov byte[es:24],'d'
mov byte[es:26],'n'
mov byte[es:28],'a'
mov byte[es:32],'d'
mov byte[es:34],'r'
mov byte[es:36],'i'
mov byte[es:38],'n'
mov byte[es:40],'k'
mov byte[es:42],'s'
jmp exit

nextcmp:
cmp al,0x36
jne nextcmp2
mov byte[es:0],'H'
mov byte[es:2],'e'
mov byte[es:6],'s'
mov byte[es:8],'a'
mov byte[es:10],'h'
mov byte[es:14],'f'
mov byte[es:16],'o'
mov byte[es:18],'o'
mov byte[es:20],'d'
mov byte[es:24],'a'
mov byte[es:26],'n'
mov byte[es:28],'d'
mov byte[es:32],'d'
mov byte[es:34],'r'
mov byte[es:36],'i'
mov byte[es:38],'n'
mov byte[es:40],'k'
mov byte[es:42],'s'
jmp exit

nextcmp2:
cmp al,0xaa
jne nextcmp3
;mov byte[es:0],'_'
call clrscreen
jmp exit

nextcmp3:
cmp al,0xb6
jne nomatch
;mov byte[es:0],'_'
call clrscreen
jmp exit


nomatch:
pop es
pop ax
jmp far[cs:oldisr]

exit:
mov al,0x20
out 0x20,al

pop es
pop ax
iret

clrscreen:
push es
push ax
push cx
push di

mov ax,0xb800
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





start:


xor ax,ax
mov es,ax
mov ax,[es:9*4]
mov[oldisr],ax
mov ax,[es:9*4+2]
mov [oldisr+2],ax
cli
mov word[es:9*4],kbisr
mov [es:9*4+2],cs
sti
mov dx,start
add dx,15
mov cl,4
shr dx,cl
mov ax,0x3100
int 0x21



mov ax,0x4c00
int 21h