#ifndef BITMATH_H
#define BITMATH_H

#define SetBit(REG, BIT)    (REG |= (1 << BIT))
#define ClearBit(REG, BIT)  (REG &= ~(1 << BIT))
#define ToggleBit(REG, BIT) (REG ^= (1 << BIT))
#define ReadBit(REG, BIT)   ((REG >> BIT) & 1)

#endif 