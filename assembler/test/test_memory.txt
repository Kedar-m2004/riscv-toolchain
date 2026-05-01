; Memory Test

ADDI R1, R0, 100
ADDI R2, R0, 55

SW R2, 0(R1)
LW R3, 0(R1)

HLT
