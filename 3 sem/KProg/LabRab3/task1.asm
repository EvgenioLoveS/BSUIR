 org $8000
 ldx #$8200
 ldy #$82ff 
 sty $8310

loop:
 ldd $0,x
 cba
 bcs exchange_values

next_element:
 inx
 cpx $8310
 beq previous_element_loop
 jmp loop 

exchange_values:
 stab $0,x
 staa $1,x
 jmp next_element

previous_element_loop:
 dec $8311
 ldx #$8200
 cpx $8310
 beq end
 jmp loop

end:
 swi