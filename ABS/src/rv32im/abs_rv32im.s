.data

test_inputs:
    .word -5, 0, -2147483648, 2147483647, 100, -100, -1, 1, -1234567, 1234567

.text
.global main

main:
    la      s0, test_inputs
    li      s1, 10
    li      s2, 0

test_loop:
    beq     s2, s1, test_end
    
    lw      a0, 0(s0)
    jal     ra, abs_rv32im
    
    addi    s0, s0, 4
    addi    s2, s2, 1
    j       test_loop

test_end:
    li      a7, 10
    ecall

abs_rv32im:
    srai    t0, a0, 31
    xor     a0, a0, t0
    sub     a0, a0, t0
    ret