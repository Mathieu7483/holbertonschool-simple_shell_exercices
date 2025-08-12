#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
* main - Executes /bin/ls -l /tmp in five child
* processes and prints their exit status.
* @argc: Argument count (unused).
* @argv: Argument vector (unused).
* @envp: Environment variables.
* Return: 0 on success, 1 on failure.
*/
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	for (int i = 0; i < 5; i++)

	{
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork failed");
			return (1);
		}
		else if (pid == 0)
		{
			char *path = "/bin/ls";

			char *args[] = { "ls", "-l", "/tmp", NULL };

			execve(path, args, envp);

			perror("execve failed");
			return (1);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
			printf("Child %d finished with status %d\n", pid, status);
		}
	}

	return (0);
}
