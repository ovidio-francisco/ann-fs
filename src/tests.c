#include <stdio.h>
#include "functions.h"
#include "tests.h"


int count = 0;
int passeds = 0;


int test_sigmoid(double actual, double expected) {
	count++;
	if (actual == expected) {
		passeds++;
		return 1;
	}
	else {
		return 0;
	}
}

int test_all_sigmoids(){
	test_sigmoid(sigmoid(+4), 0.01798621);
	test_sigmoid(sigmoid(-4), 0.9820138);

	test_sigmoid(sigmoid(0), 0.5);
	test_sigmoid(sigmoid(-1), 0);
	test_sigmoid(sigmoid(+1), 1);

	return count = passeds;
}


int main() {
	printf("--- TESTS ---\n");

	if (test_all_sigmoids()) {
		printf("[ OK ] Sigmoid function\n");
	}
	else {
		printf("[    ] Sigmoid function failed\n");
	}
}
