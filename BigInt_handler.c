/*
 * BigInt_handler.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Ahmed
 */


#include <stdio.h>


#include "Platform_Types.h"
#include "BigInt_handler.h"

static void BigInt_fillZeros(BigInt_t *Int)
{
	uint32_t index;
	for(index = 0; index < MAX_SIZE; index++)
	{
		Int->num[index] = 0;
	}
}

static void BigInt_removeZeros(BigInt_t *Int)
{
	uint32_t index 		= 0;
	uint32_t sizeOfInt 	= Int->size;
	while(Int->num[sizeOfInt - index - 1] == 0)
	{
		if(Int->size == 0)
		{
			Int->size = 1;
			break;
		}

		Int->size--;
		index++;
	}

//	if(Int->size <= 0)
//	{
//		Int->size = 1;
//	}
}

void BigInt_Init(BigInt_t *Int, uint8_t buffer[])
{
	uint32_t index = 0, sizeOfInt = 0;
	uint8_t temp;

	/* fill the array with zeros */
	BigInt_fillZeros(Int);

	/* calculate the size and convert from string to int */
	while(buffer[index] != '\0')
	{
		Int->num[index] = buffer[index] - '0';
		sizeOfInt++;
		index++;
	}

	/* reverse the number 123 --> 321 */
	Int->size = sizeOfInt;
	for(index = 0; index * 2 < sizeOfInt; index++)
	{
		temp 							= Int->num[index];
		Int->num[index] 				= Int->num[sizeOfInt - index - 1];
		Int->num[sizeOfInt - index - 1] = temp;
	}

	/* remove the zeros from left 00123 --> 123 */
	BigInt_removeZeros(Int);
	//	index = 0;
	//	while(Int->num[sizeOfInt - index - 1] == 0)
	//	{
	//		Int->size--;
	//		index++;
	//	}

}

void BigInt_print(BigInt_t *Int)
{
	uint32_t index;
	for(index = 0; index < Int->size; index++)
	{
		printf("%u", Int->num[Int->size - index - 1]);
	}
	printf("\n");
}

void BigInt_add(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2)
{
	uint32_t index;
	uint32_t stopCondition = Int1->size > Int2->size ? Int1->size : Int2->size;
	BigInt_fillZeros(result);

	for(index = 0; index < stopCondition; index++)
	{
		result->num[index] 		= result->num[index] + Int1->num[index] + Int2->num[index];
		result->num[index + 1] 	= result->num[index] / 10;
		result->num[index] 		= result->num[index] % 10;
	}

	if(result->num[index] == 1)
	{
		result->size = ++index;
	}
	else
	{
		result->size = index;
	}


	//	uint32_t index1, index2, index3;
	//	uint8_t carry = 0;
	//	for(index1 = 0, index2 = 0, index3 = 0; index1 < Int1->size && index2 < Int2->size; index1++, index2++, index3++)
	//	{
	//		result->num[index3] 	= Int1->num[index1] + Int2->num[index2] + carry;
	//		carry					= result->num[index3] / 10;
	//		result->num[index3] 	= result->num[index3] % 10;
	//	}
	//
	//	for(; index1 < Int1->size; index1++, index3++)
	//	{
	//		result->num[index3] = Int1->num[index1] + carry;
	//		carry = 0;
	//	}
	//
	//	for(; index2 < Int2->size; index2++, index3++)
	//	{
	//		result->num[index3] = Int2->num[index2] + carry;
	//		carry = 0;
	//	}
	//
	//	result->num[index3++] = carry;
	//
	//	result->size = index3;
}

void BigInt_sub(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2)
{
	uint32_t index;
	uint32_t stopCondition = Int1->size > Int2->size ? Int1->size : Int2->size;
	BigInt_fillZeros(result);
	result->num[0] = 1;

	for(index = 0; index < stopCondition; index++)
	{
		result->num[index] 		= result->num[index] + Int1->num[index] + (9 - Int2->num[index]);
		result->num[index + 1] 	= result->num[index] / 10;
		result->num[index] 		= result->num[index] % 10;
	}

	result->size = index;

	BigInt_removeZeros(result);

	//	uint32_t index1, index2, index3;
	//	uint8_t carry = 1;
	//
	////	uint32_t stopCondition = Int1->size > Int2->size ? Int1->size : Int2->size;
	//	for(index1 = 0, index2 = 0, index3 = 0; index1 < Int1->size && index2 < Int2->size; index1++, index2++, index3++)
	//	{
	//		result->num[index3] 	= Int1->num[index1] + (9 - Int2->num[index2]) + carry;
	//		carry					= result->num[index3] / 10;
	//		result->num[index3] 	= result->num[index3] % 10;
	//	}
	//
	//	for(; index1 < Int1->size; index1++, index3++)
	//	{
	//		result->num[index3] 	= Int1->num[index1] + 9 + carry;
	//		carry					= result->num[index3] / 10;
	//		result->num[index3] 	= result->num[index3] % 10;
	//	}
	//
	//	for(; index2 < Int2->size; index2++, index3++)
	//	{
	//		result->num[index3] 	= Int2->num[index2] + 9 + carry;
	//		carry					= result->num[index3] / 10;
	//		result->num[index3] 	= result->num[index3] % 10;
	//	}
	//
	//	result->size = index3;
}

void BigInt_mul(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2)
{
	uint32_t index1, index2, index3 = 0;
	BigInt_fillZeros(result);

	for(index1 = 0; index1 < Int1->size; index1++)
	{
		for(index2 = 0, index3 = index1; index2 < Int2->size; index2++, index3++)
		{
			result->num[index3] 		 = Int1->num[index1] * Int2->num[index2] + result->num[index3];
			result->num[index3 + 1] 	+= result->num[index3] / 10;
			result->num[index3] 		 = result->num[index3] % 10;
		}
	}

	result->size = index3;
}

void BigInt_div(BigInt_t *result, BigInt_t *Int1, BigInt_t *Int2);
