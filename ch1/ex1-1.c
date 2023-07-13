// Tested with gcc 10.2.1

// /* Correct Version

// Code:

#include <stdio.h>

main()
{
	printf("Namaste!\n");
}

// Errors:

// warning: return type defaults to ‘int’ [-Wimplicit-int]

// */

/* Removing the Preprocessor directive

// Code:

main()
{
	printf("Namaste!\n");
}

// Errors:

// warning: return type defaults to ‘int’ [-Wimplicit-int]
// warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
// warning: incompatible implicit declaration of built-in function ‘printf’

*/

/* Removing the main function

// Code:

#include <stdio.h>

// Errors:

// /usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/10/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
// (.text+0x20): undefined reference to `main'
// collect2: error: ld returned 1 exit status

*/

/* Removing the semicolon

// Code:

#include <stdio.h>

main()
{
	printf("Namaste!\n")
}

// Errors:

// warning: return type defaults to ‘int’ [-Wimplicit-int]
// In function ‘main’:
// error: expected ‘;’ before ‘}’ token

*/

/* Removing the header filename

// Code:

#include

main()
{
	printf("Namaste!\n");
}

// Errors:

// error: #include expects "FILENAME" or <FILENAME>
// warning: return type defaults to ‘int’ [-Wimplicit-int]
// In function ‘main’:
// warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
// warning: incompatible implicit declaration of built-in function ‘printf’

*/

/* Removing the arguments for printf

// Code:

#include <stdio.h>

main()
{
	printf();
}

// Errors:

// warning: return type defaults to ‘int’ [-Wimplicit-int]
// In function ‘main’:
// error: too few arguments to function ‘printf’

*/