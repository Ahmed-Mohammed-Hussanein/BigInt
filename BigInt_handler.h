/*
 * BigInt_handler.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Ahmed
 */

#ifndef INC_BIGINT_HANDLER_H_
#define INC_BIGINT_HANDLER_H_

#include "Platform_Types.h"

#define MAX_SIZE	128

typedef uint8_t big[MAX_SIZE];

typedef struct
{
	big num;
	uint8_t sign;
//	big fraction; // TODO
	uint32_t size;

} BigInt_t;

// TODO: BigInt Division


void BigInt_Init(BigInt_t *Int, uint8_t buffer[]);
void BigInt_print(BigInt_t *Int);
void BigInt_add(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2);
void BigInt_sub(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2);
void BigInt_mul(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2);
void BigInt_div(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2);

#endif /* INC_BIGINT_HANDLER_H_ */
