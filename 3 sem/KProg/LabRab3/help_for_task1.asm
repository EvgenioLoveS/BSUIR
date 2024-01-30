 org $8000
 ldx #$8200
 ldy #$820f
 ldd #$0000

iteration:
 stab 0,x
 incb
 cpx #$82ff
 beq end
 inx
 jmp iteration

end:
 swi
 