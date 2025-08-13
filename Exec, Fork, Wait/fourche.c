#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* main - Entry point of the program
* Return: 0 on success, 1 on failure
*/
int main(void)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		return (1);
	} else if (pid == 0)
	{
		printf("Je suis l'enfant ! PID = %d, PPID = %d\n", getpid(), getppid());
	}
	else
	{
		printf("Je suis le parent ! PID = %d, enfant PID = %d\n", getpid(), pid);
		wait(NULL);
	}

	return (0);
}
