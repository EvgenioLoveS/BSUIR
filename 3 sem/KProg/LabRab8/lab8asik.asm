.model small
.stack 100h
.386
.data 
    whole_part_cur dq 1.0;
    result_value dq 0;

    coeff_a dq 1.0;
    coeff_b dq 5.0;
    coeff_c dq 6.0;
    
    zro dq 0.0;
    one dq 1.0;
    two dq 2.0;
    three dq 3.0;
    four dq 4.0;
    five dq 5.0;
    six dq 6.0;
    seven dq 7.0;
    eight dq 8.0;
    nine dq 9.0;
    ten dq 10.0;
    
    NaN dq 7FFFFFFFFFFFFFFFh;
    inf dq 7FF0000000000000h; 
    
    discriminant dq ?;
    root1 dq ?;
    root2 dq ?;
    b1root1 dq 1.0;
    b2root1 dq 2.0;
    b1root2 dq 3.0;
    b2root2 dq 4.0;
    count db 0;
    input_buffer db 15,15,20 dup ('$');
    whole_part_length db 0; 
    error_message db "Wrong input, try again",13,10,"$";
    discriminant_message db 13,10,"Calculating Discriminant...",13,10,"$";
    two_roots_message db "Two distinct real roots found.",13,10,"$"
    one_root_message db "One real root found.",13,10,"$"
    zero_roots_message db "No real roots found.",13,10,"$"
    exit_message db "Exiting assembly program.",13,10,"$"
    a_input_message db "Enter value for 'a'",13,10,"$"
    b_input_message db 13,10,"Enter value for 'b'",13,10,"$"
    c_input_message db 13,10,"Enter value for 'c'",13,10,"$"
    
    roots1_root1_message db 13,10,"Two distinct real roots found for Root 1",13,10,"$"
    one_root1_message db 13,10,"One real root found for Root 1",13,10,"$"
    zero_root1_message db 13,10,"No real roots found for Root 1",13,10,"$"
    
    roots2_root2_message db 13,10,"Two distinct real roots found for Root 2",13,10,"$"
    one_root2_message db 13,10,"One real root found for Root 2",13,10,"$"
    zero_root2_message db 13,10,"No real roots found for Root 2",13,10,"$"

.code  
public _asmsolution     

output_string macro str_to_output
    mov ah,09h
    mov dx,offset str_to_output
    int 21h
endm   

calculate_power macro exponent  
    LOCAL power_loop, power_skip
     
    push cx;          
    mov cl,exponent;
    cmp cl,0;
    je power_skip
    sbb cl,1; 
    cmp cl,0;
    je power_skip      
    
power_loop:
    fld ten;
    fmulp;
    cmp cl,0;
    loopne power_loop
    
power_skip:
    pop cx;
endm

end_program macro
    mov ah,09h 
    lea dx, error_message;
    int 21h 
endm

input_processing proc
RestartInput:

    mov whole_part_length,0;
    finit;

    fld one;
    fstp whole_part_cur;
   
    fldz;
    fstp result_value;
   
    finit;
    fld one;
    
    ;input
    mov ah,0Ah
    lea dx,input_buffer;
    int 21h;
    add dx,2;
    push cx;
     
    mov cl,[input_buffer+1];
    mov bx,dx; 
    
    ; check for +/-
    mov dl,[input_buffer+2]
    cmp dl,43;
    je PlusSign
    cmp dl,45;
    je MinusSign 
    mov ax,1;
    jmp NoSign
    
PlusSign:
    sub [input_buffer+1],1;
    add bx,1;
    sub cl,1; 
    jmp NoSign; 

MinusSign:
    sub [input_buffer+1],1;
    add bx,1;
    sub cl,1;
    fchs;
    
NoSign: 
    mov whole_part_length,cl;
    push ax;
    mov al,46;
    mov di,bx;
    repne scasb;
    
    sub whole_part_length,cl;
    sub di,1;
    mov dl, [di];
    cmp dl,46;
    jne over_whole
    sub whole_part_length,1;
    over_whole:
    pop ax;
    
    ;power
    calculate_power whole_part_length ;
        
    ;input whole part;
    mov cl,whole_part_length;
    cmp cl,0;
    jne WholePartException;
    sub bx,1;
    fld ten; 
    fdivp; 
    jmp wholePartEnd;

WholePartException:    
    
    WholePartInput:
        mov dx,0;
        mov dl,[bx]
    
        cmp dx,48
        jge MoreWhole
        end_program;
        pop cx
        jmp RestartInput
    MoreWhole:
        cmp dx,57
        jle LessWhole
        end_program; 
        pop cx;
        jmp RestartInput
    LessWhole:
        sub dx,48;
        imul dx,7; 
        add dx, offset numbersConversion
        push bx;
        mov bx,dx    
        jmp bx;
 
    numbersConversion:    
        fld zro;
        jmp afterConversion;
        fld one;
        jmp afterConversion;
        fld two;
        jmp afterConversion;
        fld three;
        jmp afterConversion;
        fld four;
        jmp afterConversion;
        fld five;
        jmp afterConversion;
        fld six;
        jmp afterConversion;
        fld seven;
        jmp afterConversion;
        fld eight;
        jmp afterConversion;
        fld nine;
        jmp afterConversion;
                
    afterConversion:
        pop bx;
        fmul st(0),st(1); 
        fld result_value;
        faddp;
        fstp result_value;
        fld ten; 
        fdivp;

        dec cx
        cmp cx,0
        je wholePartEnd
        add bx,1;   
        jmp WholePartInput
    wholePartEnd:  
        add bx,2; 
        mov cl,[input_buffer+1];
        sub cl,whole_part_length

        cmp cl,0;
        je DecimalPartEnd;

        sub cl,1;

        cmp cl,0;
        je DecimalPartEnd;

    DecimalPartInput:
        mov dx,0;
        mov dl,[bx]
    
        cmp dx,48
        jge MoreDecimal
        end_program;
        pop cx
        jmp RestartInput 
    
    MoreDecimal:
        cmp dx,57
        jle LessDecimal
        end_program; 
        pop cx;
        jmp RestartInput   
            
    LessDecimal:
        sub dx,48;
        imul dx,7; 
        add dx, offset DecimalNumbers
        push bx;
        mov bx,dx    
        jmp bx;   
            
    DecimalNumbers: 
        fld zro;
        jmp AfterDecimalConversion;
        fld one;
        jmp AfterDecimalConversion;
        fld two;
        jmp AfterDecimalConversion;
        fld three;
        jmp AfterDecimalConversion;
        fld four;
        jmp AfterDecimalConversion;
        fld five;
        jmp AfterDecimalConversion;
        fld six;
        jmp AfterDecimalConversion;
        fld seven;
        jmp AfterDecimalConversion;
        fld eight;
        jmp AfterDecimalConversion;
        fld nine;
        jmp AfterDecimalConversion;
                
    AfterDecimalConversion:
        pop bx;
        fmul st(0),st(1); 
        fld result_value;
        faddp;
        fstp result_value;
        fld ten; 
        fdivp;

        dec cx
        cmp cx,0
        je DecimalPartEnd
        add bx,1;   
        jmp DecimalPartInput 
        
    DecimalPartEnd:
        ;clear stack
        pop cx;
        ret      
        
input_processing endp

calculate_discriminant proc ; diskriminant
    finit
    fld coeff_a;
    fld coeff_c;
    fmulp ;
    fld four;
    fmulp;
    fld coeff_b;
    fmul st(0), st(0) ;
    fsub st(0), st(1);
    fstp discriminant;
    
    ret  
    
calculate_discriminant endp
    
calculate_2_roots proc ;D > 0
    finit ; root 1
    fld discriminant
    fsqrt;
    fldz;
    fld coeff_b;
    fsubp;
    fsub st(0),st(1);
    fld two;
    fld coeff_a;
    fmulp;
    fdiv ;
    fstp root1;
    finit ; root 2
    fld discriminant
    fsqrt;
    fldz;
    fld coeff_b;
    fsubp;
    fadd st(0),st(1);
    fld two;
    fld coeff_a;
    fmulp;
    fdiv ;
    fstp root2;
    
    ret  
    
calculate_2_roots endp
    
calculate_1_root proc ;D = 0
    finit ; root 1
    fld discriminant
    fsqrt;
    fldz;
    fld coeff_b;
    fsubp;
    fsub st(0),st(1);
    fld two;
    fld coeff_a;
    fmulp;
    fdiv ;
    fstp root1;
    fld NaN;
    fstp root2;
    ret
    
calculate_1_root endp

calculate_0_roots proc ;D < 0
    finit ; root 1
    fld NaN;
    fstp root1;
    fld NaN;
    fstp root2;
    ret
    
calculate_0_roots endp
    
calculate_A_exception proc ; A = 0
    finit ; root 1
    fld coeff_c;
    fldz;
    fsubp;
    fld coeff_b;
    fdivp;
    fstp root1;
    fld NaN;
    fstp root2;
    ret  
    
calculate_A_exception endp

calculate_AB_exception proc ; A = 0, B = 0
    finit ; root 1
    fld coeff_c;
    fldz;
    fcom;
    je infinit_sols;
    fld NaN;
    jmp over_inf;
    infinit_sols: fld inf;
    over_inf: fstp root1;
    fld NaN;
    fstp root2;
    
    ret 
    
calculate_AB_exception endp
    
solve_equation proc
   finit; CHECK A = 0
   fldz;
   fld coeff_a;
   fcom;
   fnstsw ax;
   sahf;
   jne nonzero_A;
   fldz; CHECK A = 0, B = 0
   fld coeff_b;
   fcom; 
   fnstsw ax;
   sahf;
   je ABexception  
   
    Aexception:   
        call calculate_A_exception;
        jmp end_proc;
    
    ABexception:
        call calculate_AB_exception;
        jmp end_proc;
   
    nonzero_A: ;A <> 0
        output_string discriminant_message;
        call calculate_discriminant; 
        finit; 
        fld zro;
        fld discriminant;
        fcom;
        fnstsw ax;
        sahf;
        jc error ; 
        je roots1
   
    roots2: ; D > 0   
        output_string two_roots_message 
        call calculate_2_roots;
        jmp end_proc; 
    
    roots1: ; D = 0
        output_string one_root_message
        call calculate_1_root;
        jmp end_proc; 
    
    error:
        output_string zero_roots_message
        call calculate_0_roots; 
       
    end_proc:
        ret   
        
solve_equation endp
    
   
handle_biquadratic_roots proc
   ;root1
   finit
   fldz;
   fld root1;
   fcom;
   fnstsw ax;
   sahf;
   jc NoRoots1
   je OneRoot1;
   jnc TwoRoots1;
   jmp Exception1;
   
   NoRoots1:
        output_string zero_root1_message
        fld NaN;
        fstp b1root1;
        fld NaN;
        fstp b2root1;
        jmp EndRoot1
    OneRoot1:
        push di
        lea di, count
        add [di],1
        pop di
        output_string one_root1_message
        fldz;
        fstp b1root1;
        fld NaN;
        fstp b2root1;
        jmp EndRoot1 
        
    TwoRoots1:
        push di
        lea di, count
        add [di], 2
        pop di
        output_string roots1_root1_message
        fld root1;
        fsqrt;
        fst b1root1;
        fchs;
        fst b2root1;
        jmp EndRoot1 
        
    Exception1:
        push di
        lea di, count
        mov [di], 5
        pop di
        fld root1;
        fld inf;
        fnstsw ax;
        sahf;
        jne NoRoots1;
        finit
        fld inf;
        fld inf;
        fstp b1root1;
        fstp b2root1 ;
        
    EndRoot1:   
        ;root2
        finit
        fldz;
        fld root2;
        fcom;
        fnstsw ax;
        sahf;
        jc NoRoots2
        je OneRoot2;
        jnc TwoRoots2;
        jmp Exception2; 
        
    NoRoots2:
        output_string zero_root2_message
        fld NaN;
        fstp b1root2;
        fld NaN;
        fstp b2root2;
        jmp EndRoot2    
    
    OneRoot2:
        push di
        lea di, count
        add [di], 1
        pop di
        output_string one_root2_message
        fldz;
        fstp b1root2;
        fld NaN;
        fstp b2root2;
        jmp EndRoot2  
        
    TwoRoots2:
        push di
        lea di, count
        add [di], 2
        pop di
        output_string roots2_root2_message
        fld root2;
        fsqrt;
        fst b1root2;
        fchs;
        fst b2root2;
        jmp EndRoot2
        
    Exception2:
        push di
        lea di, count
        mov [di], 5
        pop di
        fld root2;
        fld inf;
        fnstsw ax;
        sahf;
        jne NoRoots2;
        finit
        fld inf;
        fld inf;
        fstp b1root2;
        fstp b2root2 ;  
        
    EndRoot2:   
        ret
        
handle_biquadratic_roots endp
   
_asmsolution proc
    mov ax,@data;
    mov ds,ax;
    mov es,ax;

    ;input a , b , c
    output_string a_input_message
    call input_processing
    finit;
    fld result_value;
    fstp coeff_a;
    
    output_string b_input_message
    call input_processing
    finit;
    fld result_value;
    fstp coeff_b;
    
    output_string c_input_message
    call input_processing
    finit;
    fld result_value;
    fstp coeff_c;

    call solve_equation; 
    call handle_biquadratic_roots; 
    
    mov bx,1;
    
    fld b1root1;
    fld b2root1;
    fld b1root2;
    fld b2root2;
    output_string exit_message;
    ret 
    
_asmsolution  endp   
end _asmsolution;

