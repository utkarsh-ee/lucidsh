#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include "template.h" 

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
    print_banner(1);
    while (1)
    {   
        char line[1025];
        char *argv[MAX_ARGS];
        char *home_path_value = getenv("HOME");

        print_prompt(); 

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            printf("\n");
            break; 
        }

        parse_to_argv(line, argv);

        if (argv[0] == NULL)
            continue;

        if (strcmp(argv[0], "exit") == 0)
            exit(0);

        if (strcmp(argv[0], "cd") == 0)
        {
            if (argv[1] == NULL)
            {
                if (home_path_value == NULL)
                {
                    printf("HOME not set\n");
                }
                else if (chdir(home_path_value) == -1)
                {
                    perror("chdir failed");
                }
            }
            else
            {
                if (chdir(argv[1]) == -1)
                {
                    perror("chdir failed");
                }
            }
            continue;
        }

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Fork Fail");
            exit(1);
        }
        else if (pid == 0)
        {
            if (execvp(argv[0], argv) == -1)
            {
                perror("execvp failed");
                exit(1);
            }
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
