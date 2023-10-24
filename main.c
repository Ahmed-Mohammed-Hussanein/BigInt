/*
 ============================================================================
 Name        : main.c
 Author      : Ahmed Hussanein
 Version     :
 Copyright   : Your copyright notice
 Description : Big Integer Handling in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Platform_Types.h"
#include "BigInt_handler.h"

#define FLUSH()		fflush(stdin), fflush(stdout)

int main(void)
{
	BigInt_t number1, number2;
	BigInt_t result;
	uint8_t temp[256];

	/* Example of get the number from user */
	scanf("%s", temp);
	BigInt_Init(&number1, temp);

	FLUSH();

	scanf("%s", temp);
	BigInt_Init(&number2, temp);

	/* printing the big interger */
	printf("\n");
	BigInt_print(&number1);
	BigInt_print(&number2);

	/* adding two big integer */
	printf("\n");
	BigInt_add(&result, &number1, &number2);

	BigInt_print(&result);

	/* substracting two big integer */
	printf("\n");
	BigInt_sub(&result, &number1, &number2);

	BigInt_print(&result);

	/* multiplying two big integer */
	printf("\n");
	BigInt_mul(&result, &number1, &number2);

	BigInt_print(&result);

	return EXIT_SUCCESS;
}
