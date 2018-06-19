#define CTEST_MAIN

#include <stdbool.h>
#include <ctest.h>
#include <string.h>
#include "functions.h"
#include "game.h"

CTEST(INPUT_VALIDATION, FINE_INPUT)
{
	
	
	int opt = 2;
	
	bool result = mainMenu(opt) ;
	ASSERT_TRUE(result);
}


