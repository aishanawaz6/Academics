; Faiqa Adnan (20L-1116) & Aisha Muhammad Nawaz (20L-0921) COAL BSCS SECTION 3E PROJECT
[org 0x0100]
jmp start
m: db 'GAME OVER!'
s: dw 10
m1: db 'BALLOONS POPPED:'
s1: dw 16
m2: db 'BALLOONS MISSED:'
s2: dw 16
m3: db 'SCORE:'
s3: dw 6
oldisr: dd 0
oldisr2: dd 0
flag : dw 0
tickcount: dw 60
tickmin : dw 1
scroll_counter: dw 0
score: dw 0
pop_count: dw 0 ;count of balloons popped
total_count:dw 31 ;total count of balloons on screen during game



clrscr:
push es
push ax
push di

mov ax,0xb800
mov es,ax
mov di,0

next:mov word[es:di],0x0720
add di,2
cmp di,4000
jne next

pop di
pop ax
pop es
ret


ClearBallon:
push bp
mov bp,sp
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,byte[bp+4] ;multiply with y position
mul bl
add ax,[bp+6] ;add x position
shl ax,1
mov di,ax

mov cx, 3 ; counter
mov ax,0x0720
	
lpc1:
mov [es:di],ax
add di,2
loop lpc1 ; first horizontal line

mov al,80
mov bl,byte[bp+4]
add bl,3
mul bl
add ax,[bp+6]
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ax,0x0720
lpc2:
mov [es:di],ax
add di,2
loop lpc2 ; second horizontal line


mov ax,80
mov bl,byte[bp+4]
add bl,2
mul bl
add ax,[bp+6]
shl ax,1

mov di,ax ; printing num in between

mov ax,0x0720
mov [es:di],ax

mov cx,2
mov bl,byte[bp+4]
add bl,1
lpc3:
mov al,80
mul bl
add ax,[bp+6]
sub ax,1
shl ax,1
mov di,ax
mov ax,0x0720
mov [es:di],ax
add bl,1
loop lpc3 ; first vertical line


mov cx,2
mov bl,byte[bp+4]
add bl,1
lpc4:
mov al,80
mul bl
add ax,[bp+6]
add ax,3
shl ax,1
mov di,ax

mov ax,0x0720
mov [es:di],ax
add bl,1
loop lpc4 ; second vertical line


; string attached to ballon
mov ax,80
mov bl,byte[bp+4]
add bl,3
mul bl
add ax,[bp+6]
add ax,1
shl ax,1
mov di,ax

mov ax,0x0720
mov [es:di],ax


pop di
pop cx
pop ax
pop bx
pop dx
pop es
pop bp
ret 4

adelay:
push cx
mov cx,5 ; change the values  to increase delay time
delay_loop1:
push cx
mov cx, 0xFFFF
delay_loop2:
loop delay_loop2
pop cx
loop delay_loop1
pop cx
ret

mdelay: ; for end screen 
push cx
mov cx,80 ; change the values  to increase delay time
delay_loopm1:
push cx
mov cx, 0xFFFF
delay_loopm2:
loop delay_loopm2
pop cx
loop delay_loopm1
pop cx
ret

scrollup:
push bp
mov bp,sp
push ax
push cx
push si
push di
push es
push ds

mov ax,80
mul byte[bp+4] ;80*number of rows to shift
mov si,ax
push si
shl si,1
mov cx,2000
sub cx,ax
mov ax,0xb800
mov es, ax
mov ds,ax
xor di,di
cld 
rep movsw
mov ax,0x720
pop cx
rep stosw

pop ds
pop es
pop di
pop si
pop cx
pop ax
pop bp
ret 2

printBallon:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,10 ;multiply with y position
mul bl
add ax,20 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x4
mov al,0x2A
loopp1:
mov [es:di],ax
add di,2
loop loopp1 ; first horizontal line

mov al,80
mov bl,13
mul bl
add ax,20
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x4
mov al,0x2A
loopp2:
mov [es:di],ax
add di,2
loop loopp2 ; second horizontal line

mov di,1962 ; printing num in between
mov ah,0x8
mov al,'A'
mov [es:di],ax

mov cx,2
mov bl,11
loop3:
mov al,80
mul bl
add ax,19
shl ax,1
mov di,ax

mov ah,0x4
mov al,0x2A
mov [es:di],ax
add bl,1
loop loop3 ; first vertical line


mov cx,2
mov bl,11
loop4:
mov al,80
mul bl
add ax,23
shl ax,1
mov di,ax
mov ah,0x4
mov al,0x2A
mov [es:di],ax
add bl,1
loop loop4 ; second vertical line


; string attached to ballon

mov di,2122
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon2:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,30 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x2
mov al,0x2A
_loopp1:
mov [es:di],ax
add di,2
loop _loopp1 ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,30
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x2
mov al,0x2A
_loopp2:
mov [es:di],ax
add di,2
loop _loopp2 ; second horizontal line

mov di,3580 ; printing num in between
mov ah,0x8
mov al,'S'
mov [es:di],ax

mov cx,2
mov bl,21
_loop3:
mov al,80
mul bl
add ax,29
shl ax,1
mov di,ax

mov ah,0x2
mov al,0x2A
mov [es:di],ax
add bl,1
loop _loop3 ; first vertical line


mov cx,2
mov bl,21
_loop4:
mov al,80
mul bl
add ax,33
shl ax,1
mov di,ax
mov ah,0x2
mov al,0x2A
mov [es:di],ax
add bl,1
loop _loop4 ; second vertical line


; string attached to ballon

mov di,3742
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon3:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,15 ;multiply with y position
mul bl
add ax,25 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x5
mov al,0x2A
_lloopp1:
mov [es:di],ax
add di,2
loop _lloopp1 ; first horizontal line

mov al,80
mov bl,18
mul bl
add ax,25
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x5
mov al,0x2A
_lloopp2:
mov [es:di],ax
add di,2
loop _lloopp2 ; second horizontal line

mov di,2772 ; printing num in between
mov ah,0x8
mov al,'F'
mov [es:di],ax

mov cx,2
mov bl,16
_lloop3:
mov al,80
mul bl
add ax,24
shl ax,1
mov di,ax

mov ah,0x5
mov al,0x2A
mov [es:di],ax
add bl,1
loop _lloop3 ; first vertical line


mov cx,2
mov bl,16
_lloop4:
mov al,80
mul bl
add ax,28
shl ax,1
mov di,ax
mov ah,0x5
mov al,0x2A
mov [es:di],ax
add bl,1
loop _lloop4 ; second vertical line


; string attached to ballon

mov di,2932
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon4:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,10 ;multiply with y position
mul bl
add ax,35 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x3
mov al,0x2A
loopp1_:
mov [es:di],ax
add di,2
loop loopp1_ ; first horizontal line

mov al,80
mov bl,13
mul bl
add ax,35
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x3
mov al,0x2A
loopp2_:
mov [es:di],ax
add di,2
loop loopp2_ ; second horizontal line

mov di,1992; printing num in between
mov ah,0x8
mov al,'B'
mov [es:di],ax

mov cx,2
mov bl,11
loop3_:
mov al,80
mul bl
add ax,34
shl ax,1
mov di,ax

mov ah,0x3
mov al,0x2A
mov [es:di],ax
add bl,1
loop loop3_ ; first vertical line


mov cx,2
mov bl,11
loop4_:
mov al,80
mul bl
add ax,38
shl ax,1
mov di,ax
mov ah,0x3
mov al,0x2A
mov [es:di],ax
add bl,1
loop loop4_ ; second vertical line


; string attached to ballon

mov di,2152
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon5:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,70 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0xC
mov al,0x2A
_loopp1_:
mov [es:di],ax
add di,2
loop _loopp1_ ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,70
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0xC
mov al,0x2A
_loopp2_:
mov [es:di],ax
add di,2
loop _loopp2_ ; second horizontal line

mov di,3662 ; printing num in between
mov ah,0x8
mov al,'X'
mov [es:di],ax

mov cx,2
mov bl,21
_loop3_:
mov al,80
mul bl
add ax,69
shl ax,1
mov di,ax

mov ah,0xC
mov al,0x2A
mov [es:di],ax
add bl,1
loop _loop3_ ; first vertical line


mov cx,2
mov bl,21
_loop4_:
mov al,80
mul bl
add ax,73
shl ax,1
mov di,ax
mov ah,0xC
mov al,0x2A
mov [es:di],ax
add bl,1
loop _loop4_ ; second vertical line


; string attached to ballon

mov di,3824
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon6:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,60 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0xC
mov al,0x2A
_lloopp1_:
mov [es:di],ax
add di,2
loop _lloopp1_ ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,60
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0xC
mov al,0x2A
_lloopp2_:
mov [es:di],ax
add di,2
loop _lloopp2_ ; second horizontal line

mov di,3640 ; printing num in between
mov ah,0x8
mov al,'P'
mov [es:di],ax

mov cx,2
mov bl,21
_lloop3_:
mov al,80
mul bl
add ax,59
shl ax,1
mov di,ax

mov ah,0xC
mov al,0x2A
mov [es:di],ax
add bl,1
loop _lloop3_ ; first vertical line


mov cx,2
mov bl,21
_lloop4_:
mov al,80
mul bl
add ax,63
shl ax,1
mov di,ax
mov ah,0xC
mov al,0x2A
mov [es:di],ax
add bl,1
loop _lloop4_ ; second vertical line


; string attached to ballon

mov di,3804
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon7:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,10 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x6
mov al,0x2A
_l1:
mov [es:di],ax
add di,2
loop _l1 ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,10
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x6
mov al,0x2A
_l2:
mov [es:di],ax
add di,2
loop _l2 ; second horizontal line

mov di,3540 ; printing num in between
mov ah,0x8
mov al,'U'
mov [es:di],ax

mov cx,2
mov bl,21
_l3:
mov al,80
mul bl
add ax,9
shl ax,1
mov di,ax

mov ah,0x6
mov al,0x2A
mov [es:di],ax
add bl,1
loop _l3 ; first vertical line


mov cx,2
mov bl,21
_l4:
mov al,80
mul bl
add ax,13
shl ax,1
mov di,ax
mov ah,0x6
mov al,0x2A
mov [es:di],ax
add bl,1
loop _l4 ; second vertical line


; string attached to ballon

mov di,3704
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret
printBallon8:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,15 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0xE	
mov al,0x2A
_lp1:
mov [es:di],ax
add di,2
loop _lp1 ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,15
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0xE
;2mov al,0x2A
_lp2:
mov [es:di],ax
add di,2
loop _lp2 ; second horizontal line

mov di,3550 ; printing num in between
mov ah,0x8
mov al,'M'
mov [es:di],ax

mov cx,2
mov bl,21
_lp3:
mov al,80
mul bl
add ax,14
shl ax,1
mov di,ax

mov ah,0xE
mov al,0x2A
mov [es:di],ax
add bl,1
loop _lp3 ; first vertical line


mov cx,2
mov bl,21
_lo4:
mov al,80
mul bl
add ax,18
shl ax,1
mov di,ax
mov ah,0xE
mov al,0x2A
mov [es:di],ax
add bl,1
loop _lo4 ; second vertical line


; string attached to ballon

mov di,3714
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret
printBallon9:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,50 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0xD
mov al,0x2A
_l1l:
mov [es:di],ax
add di,2
loop _l1l ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,50
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0xD
mov al,0x2A
_l2l:
mov [es:di],ax
add di,2
loop _l2l ; second horizontal line

mov di,3620 ; printing num in between
mov ah,0x8
mov al,'R'
mov [es:di],ax

mov cx,2
mov bl,21
_l3l:
mov al,80
mul bl
add ax,49
shl ax,1
mov di,ax

mov ah,0xD
mov al,0x2A
mov [es:di],ax
add bl,1
loop _l3l ; first vertical line


mov cx,2
mov bl,21
_l4l:
mov al,80
mul bl
add ax,53
shl ax,1
mov di,ax
mov ah,0xD
mov al,0x2A
mov [es:di],ax
add bl,1
loop _l4l ; second vertical line


; string attached to ballon

mov di,3784
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret
printBallon10:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,40 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0xB
mov al,0x2A
_l1_:
mov [es:di],ax
add di,2
loop _l1_ ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,40
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0xB
mov al,0x2A
_l2_:
mov [es:di],ax
add di,2
loop _l2_ ; second horizontal line

mov di,3600 ; printing num in between
mov ah,0x8
mov al,'L'
mov [es:di],ax

mov cx,2
mov bl,21
_l3_:
mov al,80
mul bl
add ax,39
shl ax,1
mov di,ax

mov ah,0xB
mov al,0x2A
mov [es:di],ax
add bl,1
loop _l3_ ; first vertical line


mov cx,2
mov bl,21
_l4_:
mov al,80
mul bl
add ax,43
shl ax,1
mov di,ax
mov ah,0xB
mov al,0x2A
mov [es:di],ax
add bl,1
loop _l4_ ; second vertical line


; string attached to ballon

mov di,3764
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon11:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,30 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x2
mov al,0x2A
_bloopp1:
mov [es:di],ax
add di,2
loop _bloopp1 ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,30
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x2
mov al,0x2A
_bloopp2:
mov [es:di],ax
add di,2
loop _bloopp2 ; second horizontal line

mov di,3580 ; printing num in between
mov ah,0x8
mov al,'G'
mov [es:di],ax

mov cx,2
mov bl,21
_bloop3:
mov al,80
mul bl
add ax,29
shl ax,1
mov di,ax

mov ah,0x2
mov al,0x2A
mov [es:di],ax
add bl,1
loop _bloop3 ; first vertical line


mov cx,2
mov bl,21
_bloop4:
mov al,80
mul bl
add ax,33
shl ax,1
mov di,ax
mov ah,0x2
mov al,0x2A
mov [es:di],ax
add bl,1
loop _bloop4 ; second vertical line


; string attached to ballon

mov di,3742
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret
printBallon12:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,10 ;multiply with y position
mul bl
add ax,35 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x3
mov al,0x2A
bloopp1_:
mov [es:di],ax
add di,2
loop bloopp1_ ; first horizontal line

mov al,80
mov bl,13
mul bl
add ax,35
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x3
mov al,0x2A
bloopp2_:
mov [es:di],ax
add di,2
loop bloopp2_ ; second horizontal line

mov di,1992; printing num in between
mov ah,0x8
mov al,'Z'
mov [es:di],ax

mov cx,2
mov bl,11
bloop3_:
mov al,80
mul bl
add ax,34
shl ax,1
mov di,ax

mov ah,0x3
mov al,0x2A
mov [es:di],ax
add bl,1
loop bloop3_ ; first vertical line


mov cx,2
mov bl,11
bloop4_:
mov al,80
mul bl
add ax,38
shl ax,1
mov di,ax
mov ah,0x3
mov al,0x2A
mov [es:di],ax
add bl,1
loop bloop4_ ; second vertical line


; string attached to ballon

mov di,2152
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon13:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,10 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x6
mov al,0x2A
_bl1:
mov [es:di],ax
add di,2
loop _bl1 ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,10
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x6
mov al,0x2A
_bl2:
mov [es:di],ax
add di,2
loop _bl2 ; second horizontal line

mov di,3540 ; printing num in between
mov ah,0x8
mov al,'T'
mov [es:di],ax

mov cx,2
mov bl,21
_bl3:
mov al,80
mul bl
add ax,9
shl ax,1
mov di,ax

mov ah,0x6
mov al,0x2A
mov [es:di],ax
add bl,1
loop _bl3 ; first vertical line


mov cx,2
mov bl,21
_bl4:
mov al,80
mul bl
add ax,13
shl ax,1
mov di,ax
mov ah,0x6
mov al,0x2A
mov [es:di],ax
add bl,1
loop _bl4 ; second vertical line


; string attached to ballon

mov di,3704
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es
ret

printBallon14:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,20 ;multiply with y position
mul bl
add ax,60 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0xC
mov al,0x2A
_blloopp1_:
mov [es:di],ax
add di,2
loop _blloopp1_ ; first horizontal line

mov al,80
mov bl,23
mul bl
add ax,60
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0xC
mov al,0x2A
_blloopp2_:
mov [es:di],ax
add di,2
loop _blloopp2_ ; second horizontal line

mov di,3640 ; printing num in between
mov ah,0x8
mov al,'I'
mov [es:di],ax

mov cx,2
mov bl,21
_blloop3_:
mov al,80
mul bl
add ax,59
shl ax,1
mov di,ax

mov ah,0xC
mov al,0x2A
mov [es:di],ax
add bl,1
loop _blloop3_ ; first vertical line


mov cx,2
mov bl,21
_blloop4_:
mov al,80
mul bl
add ax,63
shl ax,1
mov di,ax
mov ah,0xC
mov al,0x2A
mov [es:di],ax
add bl,1
loop _blloop4_ ; second vertical line


; string attached to ballon

mov di,3804
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
pop es

ret

printBallon15:
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,10 ;multiply with y position
mul bl
add ax,20 ;add x position
shl ax,1
mov di,ax
mov cx, 3 ; counter

mov ah,0x4
mov al,0x2A
bloopp1:
mov [es:di],ax
add di,2
loop bloopp1 ; first horizontal line

mov al,80
mov bl,13
mul bl
add ax,20
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ah,0x4
mov al,0x2A
bloopp2:
mov [es:di],ax
add di,2
loop bloopp2 ; second horizontal line

mov di,1962 ; printing num in between
mov ah,0x8
mov al,'V'
mov [es:di],ax

mov cx,2
mov bl,11
bloop3:
mov al,80
mul bl
add ax,19
shl ax,1
mov di,ax

mov ah,0x4
mov al,0x2A
mov [es:di],ax
add bl,1
loop bloop3 ; first vertical line


mov cx,2
mov bl,11
bloop4:
mov al,80
mul bl
add ax,23
shl ax,1
mov di,ax
mov ah,0x4
mov al,0x2A
mov [es:di],ax
add bl,1
loop bloop4 ; second vertical line


; string attached to ballon

mov di,2122
mov ah,0x3
mov al,'|'
mov [es:di],ax




pop di
pop cx
pop ax
pop bx
pop dx
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
call adelay
loop npos

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 6

delay:
push cx
mov cx,10;This the time of delay 
loop1:
push cx
mov cx, 0xFFFF
loop2:
loop loop2
pop cx
loop loop1
pop cx
ret



printB:
push bp
mov bp,sp
push es
push dx
push bx
push ax
push cx
push di 


mov ax,0xb800
mov es,ax

mov al,80 ;load al with columns per row
mov bl,byte[bp+4] ;multiply with y position
mul bl
add ax,[bp+6] ;add x position
shl ax,1
mov di,ax

mov cx, 3 ; counter
mov ax,[bp+10]
	
lpb1:
mov [es:di],ax
add di,2
loop lpb1 ; first horizontal line

mov al,80
mov bl,byte[bp+4]
add bl,3
mul bl
add ax,[bp+6]
shl ax,1 
mov di,ax
mov cx,3 ; counter

mov ax,[bp+10]
lpb2:
mov [es:di],ax
add di,2
loop lpb2 ; second horizontal line


mov ax,80
mov bl,byte[bp+4]
add bl,2
mul bl
add ax,[bp+6]
add ax,1
shl ax,1

mov di,ax ; printing num in between

mov ah,byte[bp+12]
mov al,byte[bp+8]

mov [es:di],ax

mov cx,2
mov bl,byte[bp+4]
add bl,1
lpb3:
mov al,80
mul bl
add ax,[bp+6]
sub ax,1
shl ax,1
mov di,ax

mov ax,[bp+10]
mov [es:di],ax
add bl,1
loop lpb3 ; first vertical line


mov cx,2
mov bl,byte[bp+4]
add bl,1
lb4:
mov al,80
mul bl
add ax,[bp+6]
add ax,3
shl ax,1
mov di,ax

mov ax,[bp+10]
mov [es:di],ax
add bl,1
loop lb4 ; second vertical line


; string attached to ballon
mov ax,80
mov bl,byte[bp+4]
add bl,3
mul bl
add ax,[bp+6]
add ax,1
shl ax,1
mov di,ax

mov ax,[bp+14]
mov [es:di],ax


pop di
pop cx
pop ax
pop bx
pop dx
pop es
pop bp
ret 12

kbisr:
push ax
push es
push bx
push dx
mov ax,0xb800
mov es,ax
mov bx,0
mov dx,20

in al,0x60
cmp al,0x32
jne mloop
cloop1:add bx,1
cmp word[scroll_counter],bx
jne cloop2
mov ax,0x3121
push ax
mov ax,0x81
push ax
mov ax,0xE12A
push ax
mov ax,'M'
push ax
mov ax,15
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,15
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop2:
dec dx
jnz cloop1

mloop:in al,0x60
cmp al,0x1E
jne mloop2
cloop3:add bx,1
cmp word[scroll_counter],bx
jne cloop4
mov ax,0x2122
push ax
mov ax,0x81
push ax
mov ax,0x422A
push ax
mov ax,'A'
push ax
mov ax,20
push ax
mov ax,10
sub ax,bx
push ax
call printB
call delay
mov ax,20
push ax
mov ax,10
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop4:
dec dx
jnz cloop3

mloop2:in al,0x60
cmp al,0x1F
jne mloop3
cloop5:add bx,1
cmp word[scroll_counter],bx
jne cloop6
mov ax,0x3742
push ax
mov ax,0x81
push ax
mov ax,0x212A
push ax
mov ax,'S'
push ax
mov ax,30
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,30
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop6:
dec dx
jnz cloop5


mloop3:in al,0x60
cmp al,0x21
jne mloop4
cloop7:add bx,1
cmp word[scroll_counter],bx
jne cloop8
mov ax,0x2932
push ax
mov ax,0x81
push ax
mov ax,0xB12A
push ax
mov ax,'F'
push ax
mov ax,25
push ax
mov ax,15
sub ax,bx
push ax
call printB
call delay
mov ax,25
push ax
mov ax,15
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop8:
dec dx
jnz cloop7


mloop4:in al,0x60
cmp al,0x30
jne mloop5
cloop9:add bx,1
cmp word[scroll_counter],bx
jne cloop10
mov ax,0x2152
push ax
mov ax,0x81
push ax
mov ax,0x312A
push ax
mov ax,'B'
push ax
mov ax,35
push ax
mov ax,10
sub ax,bx
push ax
call printB
call delay
mov ax,35
push ax
mov ax,10
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop10:
dec dx
jnz cloop9


mloop5:in al,0x60
cmp al,0x2D
jne mloop6
cloop11:add bx,1
cmp word[scroll_counter],bx
jne cloop12
mov ax,0x3824
push ax
mov ax,0x81
push ax
mov ax,0xC12A
push ax
mov ax,'X'
push ax
mov ax,70
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,70
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit

cloop12:
dec dx
jnz cloop11


mloop6:in al,0x60
cmp al,0x19
jne mloop7
cloop13:add bx,1
cmp word[scroll_counter],bx
jne cloop14
mov ax,0x3804
push ax
mov ax,0x81
push ax
mov ax,0xC12A
push ax
mov ax,'P'
push ax
mov ax,60
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,60
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop14:
dec dx
jnz cloop13



mloop7:in al,0x60
cmp al,0x16
jne mloop8
cloop15:add bx,1
cmp word[scroll_counter],bx
jne cloop16
mov ax,0x3704
push ax
mov ax,0x81
push ax
mov ax,0x612A
push ax
mov ax,'U'
push ax
mov ax,10
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,10
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit

cloop16:
dec dx
jnz cloop15


mloop8:in al,0x60
cmp al,0x13
jne mloop9
cloop17:add bx,1
cmp word[scroll_counter],bx
jne cloop18
mov ax,0x3784
push ax
mov ax,0x81
push ax
mov ax,0xD12A
push ax
mov ax,'R'
push ax
mov ax,50
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,50
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit

cloop18:
dec dx
jnz cloop17

mloop9:in al,0x60
cmp al,0x26
jne mloop10
cloop19:add bx,1
cmp word[scroll_counter],bx
jne cloop20
mov ax,0x3764
push ax
mov ax,0x81
push ax
mov ax,0xB12A
push ax
mov ax,'L'
push ax
mov ax,40
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,40
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit

cloop20:
dec dx
jnz cloop19

mloop10:in al,0x60
cmp al,0x22
jne mloop11
cloop21:add bx,1
cmp word[scroll_counter],bx
jne cloop22
mov ax,0x3742
push ax
mov ax,0x81
push ax
mov ax,0x212A
push ax
mov ax,'G'
push ax
mov ax,30
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,30
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit

cloop22:
dec dx
jnz cloop21


mloop11:in al,0x60
cmp al,0x2C
jne mloop12
cloop23:add bx,1
cmp word[scroll_counter],bx
jne cloop24
mov ax,0x2152
push ax
mov ax,0x81
push ax
mov ax,0x312A
push ax
mov ax,'Z'
push ax
mov ax,35
push ax
mov ax,10
sub ax,bx
push ax
call printB
call delay
mov ax,35
push ax
mov ax,10
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit

cloop24:
dec dx
jnz cloop23

mloop12:in al,0x60
cmp al,0x14
jne mloop13
cloop25:add bx,1
cmp word[scroll_counter],bx
jne cloop26
mov ax,0x3704
push ax
mov ax,0x81
push ax
mov ax,0x612A
push ax
mov ax,'T'
push ax
mov ax,10
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,10
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit

cloop26:
dec dx
jnz cloop25

mloop13:in al,0x60
cmp al,0x17
jne mloop14
cloop27:add bx,1
cmp word[scroll_counter],bx
jne cloop28
mov ax,0x3804
push ax
mov ax,0x81
push ax
mov ax,0xC12A
push ax
mov ax,'I'
push ax
mov ax,60
push ax
mov ax,20
sub ax,bx
push ax
call printB
call delay
mov ax,60
push ax
mov ax,20
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop28:
dec dx
jnz cloop27

mloop14:in al,0x60
cmp al,0x2F
jne nomatch
cloop29:add bx,1
cmp word[scroll_counter],bx
jne cloop30
mov ax,0x2122
push ax
mov ax,0x81
push ax
mov ax,0x422A
push ax
mov ax,'V'
push ax
mov ax,20
push ax
mov ax,10
sub ax,bx
push ax
call printB
call delay
mov ax,20
push ax
mov ax,10
sub ax,bx
push ax
call ClearBallon
add word[cs:score],10
add word[cs:pop_count],1
jmp exit
cloop30:
dec dx
jnz cloop29


jmp exit

nomatch:
pop dx
pop bx
pop es
pop ax
jmp far[cs:oldisr]

exit:
mov al,0x20
out 0x20,al

pop dx
pop bx
pop es
pop ax
iret

timer:
push bx
push es
push ax
push di
push si
push dx
push cx
push dx

loopmain:
mov si,2
mov cx,1
innerloop:
cmp word[cs:tickmin],0
jne heree2
cmp word[cs:tickcount],58
jne heree2
cmp cx,1
jne heree2
mov word[scroll_counter],0
call printBallon12
call printBallon11
call printBallon13
call printBallon14


heree2:cmp word[cs:tickmin],0
jne hereee
cmp word[cs:tickcount],47
jne hereee
cmp cx,1
jne hereee
mov word[scroll_counter],0
call printBallon15
call printBallon10
call printBallon8

hereee:cmp word[cs:tickmin],1
jne here2
cmp word[cs:tickcount],47
jne here2
cmp cx,1
jne here2
mov word[scroll_counter],0
call printBallon3
call printBallon


here2:
cmp word[cs:tickcount],35
jne here3
cmp cx,1
jne here3
mov word[scroll_counter],0
call printBallon9
call printBallon5
call printBallon10


here3:
cmp word[cs:tickcount],21
jne here4
cmp cx,1
jne heree
mov word[scroll_counter],0
call printBallon3
call printBallon6
call printBallon8


here4:
cmp word[cs:tickcount],8
jne heree
cmp cx,1
jne heree
mov word[scroll_counter],0
call printBallon2
call printBallon7
call printBallon4

heree:

mov ax,1
push ax
call scrollup


; for score
mov ax,0xb800
mov es,ax
mov ah,0xa
mov al,'S'
mov [es:2],ax
mov al,'C'
mov[es:4],ax
mov al,'O'
mov [es:6],ax
mov al,'R'
mov [es:8],ax
mov al,'E'
mov [es:10],ax
mov al,':'
mov [es:12],ax





; for time
mov ah,0xe
mov al,'T'
mov [es:136],ax
mov al,'I'
mov[es:138],ax
mov al,'M'
mov [es:140],ax
mov al,'E'
mov [es:142],ax
mov al,'R'
mov [es:144],ax
mov al,':'
mov [es:146],ax
mov al,':'
mov [es:152],ax


mov ax,0xe
push ax
mov ax,150
push ax
push word[cs:tickmin]
call printnum
; till here for time

mov ax,0xa
push ax
mov ax,16
push ax
push word[cs:score]
call printnum
;till here for score


add word[scroll_counter],1

int 9
dec cx
dec si
jnz innerloop
dec word[cs:tickcount]
mov ax,0xe
push ax
mov ax,154
push ax
push word[cs:tickcount]
call printnum


here:
cmp word[cs:tickcount],0
jne heret
cmp word[cs:tickmin],0
jne endi
xor ax,ax
mov es,ax
cli
mov word[es:8*4],endscreen
mov [es:8*4+2],cs
sti

endi:
mov word[cs:tickcount],60
sub word[cs:tickmin],1


heret:
mov al,0x20
out 0x20,al
end:
pop dx
pop cx
pop dx
pop si
pop di
pop ax
pop es
pop bx
iret


endscreen:
push bx
push es
push ax
push di
push si
push cx
push dx

call clrscr


mov ax,0xb800
mov es,ax
mov di,1356
mov cx,[s]
mov si,m
mov ah,0x2
loop100:
mov al,[si]
mov [es:di],ax
add di,2
add si,1
loop loop100

call mdelay
call clrscr
call printrec




mov word[cs:flag],1

mov ax,[oldisr2]
mov bx,[oldisr2+2]
xor ax,ax
mov es,ax
cli
mov [es:8*4],ax
mov [es:8*4+2],bx
sti


pop dx
pop cx
pop si
pop di
pop ax
pop es
pop bx
jmp far[cs:oldisr2]





printrec:
push es
push ax
push bx
push cx
push dx
push di
push si





; boundary of m1
mov ax,0xb800
mov es,ax
mov ah,0x4
mov al,'!'
mov cx,[s1]
add cx,[s1]

mov di,502
looprecb:
mov [es:di],ax
add di,2
cmp di,534
jne hh
mov di,822
hh:
loop looprecb





;m1 itself
mov si,m1
mov cx,[s1]
mov ah,0x4

mov di,664

looprec
mov al,[si]
mov [es:di],ax
add si,1
add di,2
loop looprec
mov ax,0x4
push ax
push di
mov ax,[pop_count]
push ax
call printnum




; boundary of m2
mov ax,0xb800
mov es,ax
mov ah,0x3
mov al,'!'
mov cx,[s2]
add cx,[s2]
mov di,584

looprecb2:
mov [es:di],ax
add di,2
cmp di,616
jne hh2
mov di,904
hh2:
loop looprecb2







;m2 itself
mov ax,0xb800
mov es,ax
mov si,m2
mov cx,[s2]
mov ah,0x3

mov di,744

looprec2:
mov al,[si]
mov [es:di],ax
add si,1
add di,2
loop looprec2
mov ax,0x3
push ax
push di
mov ax,[total_count]
sub ax,[pop_count]
push ax
call printnum




; boundary of m3
mov ax,0xb800
mov es,ax
mov ah,0x1
mov al,'!'
mov cx,[s3]
add cx,[s3]
mov di,1196

looprecb3:
mov [es:di],ax
add di,2
cmp di,1208
jne hh3
mov di,1516
hh3:
loop looprecb3



;m3 itself
mov ax,0xb800
mov es,ax
mov si,m3
mov cx,[s3]
mov ah,0x1

mov di,1356

looprec3:
mov al,[si]
mov [es:di],ax
add si,1
add di,2
loop looprec3
mov ax,0x1
push ax
push di
mov ax,[score]
push ax
call printnum




pop si
pop di
pop dx
pop cx
pop bx
pop ax
pop es
ret

start:
call clrscr
mov ax,0xb800
mov es,ax
mov byte[es:146],'0' ; intial timer
mov byte[es:148],'2'
mov byte[es:150],':'
mov byte[es:152],'0'
mov byte[es:154],'0'

call printBallon4
call printBallon2
call printBallon8
call printBallon6
call delay


xor ax,ax
mov es,ax
mov ax,[es:9*4]
mov[oldisr],ax
mov ax,[es:9*4+2]
mov [oldisr+2],ax


xor ax,ax
mov es,ax
mov ax,[es:8*4]
mov[oldisr2],ax
mov ax,[es:8*4+2]
mov [oldisr2+2],ax

cli
mov word[es:9*4],kbisr
mov [es:9*4+2],cs
sti


cli
mov word[es:8*4],timer
mov [es:8*4+2],cs
sti

timerloop:
int 8
cmp word[cs:flag],1
jne timerloop

mov ax,0x4c00
int 21h


