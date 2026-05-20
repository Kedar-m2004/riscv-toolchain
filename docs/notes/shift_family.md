
SLL  = Shift Left Logical 
SRL  = Shift Right Logical
SRA  = Shift Right Arithmetic
SLLI = Shift Left Logical Immediate
SRLI = Shift Right Logical Immediate 
SRAI = Shift Right Arithmetic Immediate

There is no SLA or SLAI in RV32I, because:
Left shift logical = left shift arithmetic (for 2’s complement integers)

While, Arithmetic Right Shift

Preserves sign bit

Binary:

11111000 >> 1
↓
11111100