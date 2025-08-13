#include <stdio.h>
#include <unistd.h>
/**
* main - Entry point for the program that executes /bin/ls using execve
* @argc: Argument count
* @argv: Argument vector
* @envp: Environment variables
* Return: 1 on failure
*/
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	char *path = "/bin/ls";

	char *args[] = { "ls", "-l", NULL };

	if (execve(path, args, envp) == -1)
	{
		perror("execve failed");
	}

	return (1);
}
