#include <unistd.h>
/**
* helloWorld - prints hello world
*/

void helloWorld(void)
{
	const char msg[] = "Hello, World!\n";

write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}
