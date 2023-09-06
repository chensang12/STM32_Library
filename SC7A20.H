#ifndef __SC7A20_H
#define __SC7A20_H


typedef int int16_t;

void SC7A20_Init(void);
void SC7A20_WriteReg(unsigned char Address, unsigned char Data);
unsigned char SC7A20_ReadReg(unsigned char Address);
void SC7A20_GetAcce(int16_t *AccX, int16_t *AccY, int16_t *AccZ);



void SC7A20_GetAccZ(int *AccZ);

#endif
