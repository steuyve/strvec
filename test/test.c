#include <stdio.h>
#include <stdlib.h>

#include "../strvec.h"

int main(void)
{
	printf("======= Initialization ========\n");
	strvec *test = strvec_init(2);
	strvec_print(test);
	printf("\n");

	printf("======= Push 3 items =======\n");
	for (int i = 0; i < 3; i++) {
		strvec_push(test, "Hello World!");
	}
	strvec_print(test);
	printf("\n");

	printf("======= Pop an item =======\n");
	char *popped_val = strvec_pop(test);
	strvec_print(test);
	printf("Popped Value: %s\n", popped_val);
	free(popped_val);
	printf("\n");

	printf("======== Try to pop from an empty strvec =======\n");
	strvec *test2 = strvec_init(0);
	strvec_pop(test2);
	strvec_print(test2);
	strvec_destroy(test2);
	printf("\n");

	printf("======= Get item at index 1 =======\n");
	char *got_val = strvec_get(test, 1);
	strvec_print(test);
	printf("Gotten Value: %s\n", got_val);
	printf("\n");

	printf("======= Try to get an item at index 99 =======\n");
	strvec_get(test, 99);
	strvec_print(test);
	printf("\n");

	printf("======= Replace item at index 1 =======\n");
	strvec_replace(test, 1, "Replaced!");
	strvec_print(test);
	printf("\n");

	printf("======= Try to replace an item at index 99 =======\n");
	strvec_replace(test, 99, "This should not appear");
	strvec_print(test);
	printf("\n");

	printf("======= Insert an item at index 0 =======\n");
	strvec_insert(test, 0, "Inserted0!");
	strvec_print(test);
	printf("\n");

	printf("======= Insert an item at index 1 ========\n");
	strvec_insert(test, 1, "Inserted1!");
	strvec_print(test);
	printf("\n");

	printf("======= Insert an item at the end =======\n");
	strvec_insert(test, 3, "Inserted3!");
	strvec_print(test);
	printf("\n");

	printf("======= Try to insert an item at index 99 =======\n");
	strvec_insert(test, 99, "This should not appear!");
	strvec_print(test);
	printf("\n");

	printf("======= Remove an item at index 0 ========\n");
	char *rmed_val = strvec_remove(test, 0);
	strvec_print(test);
	printf("Removed Value: %s\n", rmed_val);
	free(rmed_val);
	printf("\n");

	printf("======== Remove an item at index 2 ========\n");
	char *rmed_val2 = strvec_remove(test, 2);
	strvec_print(test);
	printf("Removed Value: %s\n", rmed_val2);
	free(rmed_val2);
	printf("\n");

	printf("======= Remove an item at the end ========\n");
	char *rmed_val3 = strvec_remove(test, 2);
	strvec_print(test);
	printf("Removed Value: %s\n", rmed_val3);
	free(rmed_val3);
	printf("\n");

	printf("======= Try to remove an item at index 99 =======\n");
	strvec_print(test);
	printf("\n");

	strvec_destroy(test);
	exit(EXIT_SUCCESS);
}
