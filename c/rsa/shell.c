#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>


void call_shell(char *str)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *cmds[] = {
			"bash", "-c",
			"factorize() {\n"
				"  local num=$(echo \"$1\" | tr -d ':')\n"
				"  local fact=\"$2\"\n"
				"  local prime=$(echo \"$num / $fact\" | bc)\n"
				"  echo \"$num=$prime*$fact\"\n"
				"  exit 0\n"
				"}\n"
				"result=$(factor $0)\n"
				"factorize $result\n"
		, NULL, NULL};
		cmds[3] = str;

		execvp(cmds[0], cmds);

		perror("execve");
	}
	int status;
	wait(&status); // Wait for the child process to complete
}
