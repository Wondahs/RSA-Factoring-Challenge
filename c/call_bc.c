#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *
 *
 *
 */
void call_bc(char *str)
{
	int pipefd[2];
	pid_t child_pid;
	char sqrt[1024];

	strcpy(sqrt, "sqrt(");
	strcat(sqrt, str);
	strcat(sqrt, ")");

	if (pipe(pipefd) == -1)
		perror("pipe");
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *cmds[] = {"bc", sqrt, NULL};

		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execvp(cmds[1], cmds);

		perror("execve");
	}
	else
	{

	}
}
