#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

/**
 * main - A simple shell program
 *
 * Return: int 0 on success or any number above 0 on failure
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	do {
		_putchar('$');
		_putchar(' ');

		line = ssh_read_line();
		args = ssh_tokenize_line(line);
		if (argc)
			status = ssh_execute(args, argv);

		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}

/**
 * ssh_launch - Launches the process based on the given command line arguments
 * @args: A null terminated array of strings command line arguments
 *
 * Return: Int The process return status
 */

int ssh_launch(char **args, char **argv)
{
	pid_t pid;
	int status;
	/*char *arrev[] = {"USER=CHOL",NULL}; */

	pid = fork();
	if (pid == 0)
	{

		if (execve(args[0], args, environ) == -1)
			perror(argv[0]);

		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror(argv[0]);
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
/**
 * ssh_execute - Luanches a process based on given arguments
 * @args: Array of null terminated strings, Arguments to our shell
 *
 * Return: int The process return status
 */
int ssh_execute(char **args, char **argv)
{

	if (args[0] == NULL)
		return (1);

	return (ssh_launch(args, argv));
}
