#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define ERROR -1

int safe_multiply(const int number1, const int number2)
{
	/* Multiply the int32's into an int they can't overflow */
	int64_t test = (int64_t) number1 * number2;
	
	/* check if they would overflow a standard int32 */
	if (test >= (int64_t) INT_MIN && test <= (int64_t) INT_MAX ) {
		/* If they don't overflow, send the result back */
		return number1 * number2;
	}
	else {
		/* If they overflow, send an error */
		return ERROR;
	}
}

int main()
{

	#ifdef UNIT_TEST
	/* Initalize Unit Test Variables */
	int test;
	#endif //UNIT_TEST

	#ifdef UNIT_TEST
	/* Unit Test Case 1: Two positives */
	test = 0;
	test = safe_multiply(20,30);

	if(test != 600) {
		printf("Unit Test 1: Two positives failed!  Result: %d\n\n", test );
	} else {
		printf("Unit Test 1: Two positives successful!\n\n");
	}
	#endif //UNIT_TEST

	#ifdef UNIT_TEST
	/* Unit Test Case 2: Two negatives */
	test = 0;
	test = safe_multiply(-20,-30);
	if(test != 600) {
		printf("Unit Test 2: Two negatives failed!  Result: %d\n\n", test );
	} else {
		printf("Unit Test 2: Two negatives successful!\n\n");
	}
	#endif //UNIT_TEST

	#ifdef UNIT_TEST
	/* Unit Test Case 3: First negative, then positive */
	test = 0;
	test = safe_multiply(-20,30);
	if(test != -600) {
		printf("Unit Test 3: First negative, then positive failed!  Result: %d\n\n", test );
	} else {
		printf("Unit Test 3: First negative, then positive successful!\n\n");
	}
	#endif //UNIT_TEST

	#ifdef UNIT_TEST
	/* Unit Test Case 4: First negative, then positive */
	test = 0;
	test = safe_multiply(20,-30);
	if(test != -600) {
		printf("Unit Test 4: First postive, then negative failed!  Result: %d\n\n", test );
	} else {
		printf("Unit Test 4: First postive, then negative successful!\n\n");
	}
	#endif //UNIT_TEST

	#ifdef UNIT_TEST
	/* Unit Test Case 5: Large numbers */
	test = 0;
	test = safe_multiply(1000000,1000000);
	if(test != ERROR) {
		printf("Unit Test 5: Large numbers failed!  Result: %d\n\n", test );
	} else {
		printf("Unit Test 5: Large numbers successful!\n\n");
	}
	#endif //UNIT_TEST

	#ifdef UNIT_TEST
	/* Unit Test Case 6: Large numbers (Negative) */
	test = 0;
	test = safe_multiply(-1000000,1000000);
	if(test != ERROR) {
		printf("Unit Test 6: Large numbers (Negative) failed!  Result: %d\n\n", test );
	} else {
		printf("Unit Test 6: Large numbers (Negative) successful!\n\n");
	}
	#endif //UNIT_TEST

	return 0;
}