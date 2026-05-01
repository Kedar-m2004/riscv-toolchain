// Decode's code: 

#include<stdio.h>
#include"cpu.h"

void decode(uint32_t instruction, DecodedInstr*di){

    di->instruction = instruction;

    di->opcode = instruction & 0x7F;
    di->rd = (instruction >> 7) & 0x1F;
    di->funct3 = (instruction >> 12) & 0x7;
    di->rs1 = (instruction >> 15) & 0x1F;
    di->rs2 = (instruction >> 20) & 0x1F;
    di->funct7 = (instruction >> 25) & 0x7F;

    switch (di->opcode){

        case 0x13:      // I-type (ADDI)
        case 0x03:      // LW instruction (Also also an I-type instruction, hence, no "break;" used above)
        case 0x67:      // JALR instruction (Also also an I-type instruction, hence, no "break;" used above)

            // I-type: | OPCODE(7) | rd(5) | funct3 (3) | rs1(5) | imm(12) |

            di->imm = ( (int32_t)instruction) >> 20;
            break;

        case 0x23:{      // S-Type (SW)

            // S-Type: | OPCODE(7) | rd(5) | funct3 (3) | rs1(5) | imm(12) |

            int imm4_0 = (instruction >> 7) & 0x1F;
            int imm11_5 = (instruction >> 25) & 0x7F;
            
            int imm = (imm11_5 << 5) | imm4_0;

            // sign extended 12-bit number (for negative numbers)
            /*
                if( imm & 0x800 ){
                    imm |= 0xFFFFF000;
                }
                // Since, CPU registers are of 32 bits
                // So, (reg[rs1] + imm) will behave like a proper signed integer. 

                di->imm = imm;
            */
            
            // Instead of above commented code, we can directly use: 

            // sign extend 12-bit immediate
            di->imm = ((int32_t)imm << 20) >> 20;
            break;
        }
        
        case 0x63:{      // B-Type (BEQ, BNE) 

            // B-Type: 
            // | OPCODE(7) | imm[11](1) | imm[4:1](4) | funct3(3) | rs1(5) | rs2(5) | imm[10:5](6) | imm[12](1) |

            int imm11 = (instruction >> 7) & 0x1; 
            int imm4_1 = (instruction >> 8) & 0xF;
            int imm10_5 = (instruction >> 25) & 0x3F;
            int imm12 = (instruction >> 31) & 0x1;

            int imm = (
                (imm12 << 12) |
                (imm11 << 11) |
                (imm10_5 << 5)|
                (imm4_1 << 1)
                // last bit (bit-0) is always '0', 
                // So, actaully there are 13 bits, out of which only 12 appear in the instruction field.
            );

            // sign extend 13-bit immediate
            di->imm = ((int32_t)imm << 19) >> 19;

            break;
        }

        case 0x6F:{      // J-Type (JAL)

            //  J-Type: 
            //  | OPCODE(7) | rd(5) | imm[19:12](8) | imm[11] | imm[10:1] | imm[20] |

            int imm19_12 = (instruction >> 12) & 0xFF;
            int imm11 = (instruction >> 20) & 0x1;
            int imm10_1 = (instruction >> 21) & 0x3FF;
            int imm20 = (instruction >> 31) & 0x1;

            int imm = (
                imm20 << 20 |
                imm19_12 << 12 |
                imm11 << 11 |
                imm10_1 << 1 
                // bit zero of J-Type immediate field is bydefault zero.
                // So, actaully there are 21 bits, out of which only 20 appear in the instruction field.
            );

            // Sign extend 21-bit immediate
            di->imm = ((int32_t)imm << 11) >> 11;
            break;
        }

        default:
            di->imm = 0;
    }
}
