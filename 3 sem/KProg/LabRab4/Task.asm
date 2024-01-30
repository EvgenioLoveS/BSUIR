.data 
     
    spaceSymbol db ' '
    newline  db 0dh,0ah,'$'
    promptString db 'Enter the string: ','$'  
    promptWord db 'Enter the word to delete: ', '$' 
    resultString db 'Result: ', '$'
    errorMessage db 'error (the string is empty/contains only spaces). Try again!',0dh,0ah,'$'
    cmpSymbol db '/'   
    bufferForFinish db 40  
    bufferForString db 40 
    inputStringLength db 0
    inputString db 200 dup('/')
    bufferForWord db 40  
    wordLength db 0
    targetWord db 200 dup('$')    
       
ends

.stack
    dw   256  dup(0)
ends

.code      

displayMessage macro MessageToDisplay
    mov ah,09h
    lea dx, MessageToDisplay
    int 21h
endm

getUserInputString macro buffer
    mov ah,0Ah   
    lea dx, buffer     
    int 21h  
endm    
       
isEmptyOrSpaces proc
    xor cx, cx
    mov cl, bufferForString+1
    xor bx, bx
    cmp cl, 0h
    je error
    
    mov si, offset bufferForString+2
    isVoidLoop:
        mov al, [si]
        cmp al, 20h
        je PlusSpace
        jmp skip
        
    PlusSpace:
        inc bx
        
    skip:
        inc si
            
    loop isVoidLoop
    
    cmp bl, bufferForString+1
    je error
    jmp return
    
    error:
    mov dx, offset errorMessage
    mov ah, 9h
    int 21h 
    jmp reenter    
    
    return:
        ret
    
isEmptyOrSpaces endp
          
start:
    
    mov ax, data
    mov ds, ax
    mov es, ax
    reenter:                          
    displayMessage promptString  
    getUserInputString bufferForString 
    call isEmptyOrSpaces     
    displayMessage newline      
    displayMessage promptWord
    getUserInputString bufferForWord
    displayMessage newline      
             
    mov cx,0
    mov cl,bufferForString[1]
                       
    ;if word is empty  go end                   
    mov dx,0
    mov dl,bufferForWord[1]
    or dx,dx
    jz endProgram          ; if 0
     
    lea si,inputString[0] 
    mov di,si       
     
findNextWord: ;looking for symbol
    lodsb      
    cmp al,spaceSymbol    
    jz startNewWord ;if != " " go to newWord
    loop findNextWord ;else go to for
    inc si ;when i want to delete last word

startNewWord:  
    pushf
    cld
    mov ax,si      ; ax = si count length of word in string
    sub ax,di      ; ax = ax - di
    dec ax         ; ax - 1
    cmp ax,dx      ; if ax == dx
    jne continueSearching ; if(wordInString.Length != wordForDelete.Length)
     
    ;comparer
    push    si     ; add in stack
    push    di
    push    cx
    push    es
    push    ds
    pop     es     
    mov     cx, dx    
    lea     si, targetWord[0]  ;comparer if (word in string - bufferForWord = 0) word in string=buferForWord
    repe    cmpsb ; cmp while symbols = (sym1 = sym2)
    pop     es
    pop     cx
    pop     di
    pop     si 
    
    jne     continueSearching               
    jcxz    skipCopy ; if cx = 0
    
    ;remove 
    push    cx
    push    si
    push    di
    push    es
    push    ds
    pop     es 
    inc     cx    
    rep movsb ; repeat while cx != 0
    pop     es
    pop     di
    pop     si
    pop     cx
    mov     si, di    
    
    loop findNextWord 
     
skipCopy:   
    inc cx
    rep     movsb

continueSearching:
    popf
    mov     di, si ; di = si
    jcxz    endProgram ; if(cx==0) go to end
    loop    findNextWord ; else go to for

endProgram: 
    displayMessage resultString     
           
     xor cx, cx
     mov si, offset inputString
     mov cl, 40 
     mov ah, 02h
     
     printLoop:
        mov dl, [si]
        mov bl,cmpSymbol
        mov al,[si]
        cmp al,bl
        je final
        int 21h
        inc si
        loop printLoop         
    
    final:
        mov ax, 4c00h 
        int 21h      
        int 20h
ends

end start 