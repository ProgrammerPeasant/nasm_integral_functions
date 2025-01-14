section .data
    four dd 4
    three dd 3
    eight dd 8
    two dq 2.0
    five dq 5.0

section .text
global f4, f5, f6

_f4:
    enter 0, 0 
 
    finit 
 
    fld1 
    fchs 
    fld qword [ebp + 8] 
    fdivp st1, st0 
 
    leave 
    ret

_f4d:
    enter 0, 0 
 
    finit 
 
    fld1 
    fld qword [ebp + 8]
    fld qword [ebp + 8]
    fmulp 
    fdivp st1, st0
 
    leave 
    ret
    
_f5:
    enter 0, 0 
     
    finit 
     
    fldl2e 
    fld qword [ebp + 8] 
    fmulp 
    fld st0 
    frndint 
    fxch st1 
    fsub st0, st1 
    f2xm1 
    fld1 
    faddp st1, st0 
    fscale 
    fld1 
    fxch 
    fld1 
    fxch 
    
    leave 
    ret

_f5d:
    enter 0, 0 
     
    finit 
     
    fldl2e 
    fld qword [ebp + 8] 
    fmulp 
    fld st0 
    frndint 
    fxch st1 
    fsub st0, st1 
    f2xm1 
    fld1 
    faddp st1, st0 
    fscale 
    fld1 
    fxch 
    fld1 
    fxch 
    
    leave 
    ret
    
_f6:
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fmul qword [two]
    fadd qword [two]
    
    leave
    ret

_f6d:
    enter 0, 0
    
    finit
    fld qword [two]
    
    leave
    ret