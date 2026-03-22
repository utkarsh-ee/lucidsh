#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>



#define MAX_ARGS 64
#define DELIM " \t\r\n\a"

void parse_to_argv(char *line, char *argv[])
{
	char *saveptr;
	int i = 0;

	char *token = strtok_r(line, DELIM, &saveptr);

	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok_r(NULL, DELIM, &saveptr);
	}

	argv[i] = NULL;
}


int main()
{
	

	while(1)
	{
		char line[125];
		char *argv[MAX_ARGS];
		printf("lucidsh > ");

		if (fgets(line, sizeof(line), stdin) == NULL)
		{
			perror("fgets failed");
			exit(1);
		}

		parse_to_argv(line, argv);

		if (argv[0] == NULL)
			continue;

		if (strcmp(argv[0], "exit") == 0)
				exit(0);

	pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork Fail");
			exit(1);
		}

		else if (pid ==0)
		{
			//Child Process

			if (execvp(argv[0], argv) == -1)
			{
				perror("execvp failed");
				exit(1);
			}
		} 
		
		else
		{
			//Parent Process
			int status;
			waitpid(pid, &status, 0);
		}

		

	}


	return 0;
}
