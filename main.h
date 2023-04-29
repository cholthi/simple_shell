#ifndef MAIN_H
#define MAIN_H


/**
 * Desc: Declaration for types and function of the shell
 * 	without builtin functions
 *
 */

extern char **environ;

void ssh_loop(void);
char *ssh_read_line(void);
char **ssh_tokenize_line(char *line);
int ssh_execute(char **args, char **argv);
int ssh_launch(char **args, char **argv);
void _putchar(char c);
#endif
