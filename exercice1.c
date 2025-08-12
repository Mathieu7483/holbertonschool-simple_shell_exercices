#include <stdio.h>
#include <unistd.h>

/**
*main - print the pid
*@void: print
*Return: the number of PID
*/
int main(void)
{
	pid_t pid = getpid();

	printf("Mon PID est : %d\n", pid);
	return (0);
}
