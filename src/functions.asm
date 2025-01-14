section .data
    four dd 4
    three dd 3
    eight dd 8
    two dq 2.0
    five dq 5.0

section .text
global _f1, _f2, _f3, _f1d, _f2d, _f3d
_f1:
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fmul st0, st0
    fld1
    faddp
    fidivr dword [four]
    fld1
    faddp st1, st0
    
    leave
    ret

_f1d:
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fimul dword [eight]
    fchs

    fld qword [ebp + 8] 
    fmul st0, st0 
    fld1
    faddp
    fld qword [ebp + 8] 
    fmul st0, st0 
    fld1
    faddp
    fmulp       
    fdivp   
    
    leave
    ret
    
_f2:
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fmul st0, st0
    fld qword [ebp + 8]
    fmul st1, st0
    fstp st0
    
    leave
    ret
    
_f2d:
    enter 0, 0
    
    finit
    fld qword [ebp + 8]
    fmul st0, st0
    fimul dword [three]
    
    leave
    ret
    
_f3:
    enter 0, 0 
     
    finit 
     
    fldl2e
    fldln2
    fld qword [ebp + 8]
    fchs
    fmulp 
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

_f3d:
    enter 0, 0
    
    fldl2e
    fldln2
    fld qword [ebp + 8]
    fmulp 
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
    
    fldln2
    fchs
    fdiv st0, st1
    
    leave
    ret