#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <string.h>
#include <sys/utsname.h>
#include <time.h>


void print_with_gradient(const char *lines[], int count, int r1, int g1, int b1, int r2, int g2, int b2) {
    for (int i = 0; i < count; i++) {
        int len = strlen(lines[i]);
        for (int j = 0; j < len; j++) {
            int r = r1 + (r2 - r1) * j / (len > 1 ? len - 1 : 1);
            int g = g1 + (g2 - g1) * j / (len > 1 ? len - 1 : 1);
            int b = b1 + (b2 - b1) * j / (len > 1 ? len - 1 : 1);
            printf("\x1b[38;2;%d;%d;%dm%c", r, g, b, lines[i][j]);
        }
        printf("\x1b[0m\n");
    }
}

void print_gradient_line(const char *text, int r1, int g1, int b1, int r2, int g2, int b2)
{
    int len = strlen(text);

    for (int j = 0; j < len; j++)
    {
        int r = r1 + (r2 - r1) * j / (len > 1 ? len - 1 : 1);
        int g = g1 + (g2 - g1) * j / (len > 1 ? len - 1 : 1);
        int b = b1 + (b2 - b1) * j / (len > 1 ? len - 1 : 1);

        printf("\x1b[38;2;%d;%d;%dm%c", r, g, b, text[j]);
    }

    printf("\x1b[0m");
}


void print_banner(int choice)
{
    const char *cyan = "\033[0;36m";

    printf("\x1b[3m\x1b[36m"); // Italic Cyan

    switch (choice)
    {
    case 1:
                const char *banner[] = {
                "                                                                    ",
                "                                                                    ",
                "##:::::::'##::::'##::'######::'####:'########:::'######::'##::::'##:",
                "##::::::: ##:::: ##:'##... ##:. ##:: ##.... ##:'##... ##: ##:::: ##:",
                "##::::::: ##:::: ##: ##:::..::: ##:: ##:::: ##: ##:::..:: ##:::: ##:",
                "##::::::: ##:::: ##: ##:::::::: ##:: ##:::: ##:. ######:: #########:",
                "##::::::: ##:::: ##: ##:::::::: ##:: ##:::: ##::..... ##: ##.... ##:",
                "##::::::: ##:::: ##: ##::: ##:: ##:: ##:::: ##:'##::: ##: ##:::: ##:",
                "########:. #######::. ######::'####: ########::. ######:: ##:::: ##:",
                "........:::.......::::......:::....::........::::......:::..:::::..:",
                "                                                                    ",
                "                                                                    ",


            };
            int count = sizeof(banner) / sizeof(banner[0]);

            //Yellow to Red (Org): 
            print_with_gradient(banner, count, 255, 255, 0,255, 0, 0);
            //Sunset Candy (Pink to Orange): 
            //print_with_gradient(banner, count, 255, 15, 107, 248, 155, 41);
            //Purple Love (Deep Pink to Purple): 
            //print_with_gradient(banner, count, 204, 43, 94, 117, 58, 136);
            //Neon Lagoon (Cyan to Green): 
            //print_with_gradient(banner, count, 0, 255, 135, 96, 239, 255);
            //Synth Dusk (Hot Pink to Blue): 
            //print_with_gradient(banner, count, 255, 27, 107, 69, 202, 255);
            //Emerald Pulse (Light Green to Green):
            //print_with_gradient(banner, count, 130, 244, 177, 48, 198, 124);
            //Cosmic Pop (Blue to Magenta): 
            //print_with_gradient(banner, count, 64, 201, 255, 232, 28, 255);
            //Cherry (Bright Red to Orange-Red): 
            //print_with_gradient(banner, count, 235, 51, 73, 244, 92, 67);
            //Aqua Marine (Blue to Green): 
            //print_with_gradient(banner, count, 37, 206, 199, 16, 179, 172);
            //Citrus Shine (Orange to Yellow): 
            //print_with_gradient(banner, count, 255, 147, 15, 255, 249, 91);
            //Electric Shore (Bright Blue to White-Blue): 
            //print_with_gradient(banner, count, 89, 92, 255, 198, 248, 255);
            //Bloody Mary (Red to Deep Pink): 
            //print_with_gradient(banner, count, 255, 81, 47, 221, 36, 118);
            //Plum Surge (Purple to Light Purple): 
            //print_with_gradient(banner, count, 212, 172, 251, 184, 79, 206);
            //Oceanic Flow (Dark Blue to Light Blue): 
            //print_with_gradient(banner, count, 159, 204, 250, 9, 116, 241);
            //Rose Mist (Soft Red to Light Pink): 
            //print_with_gradient(banner, count, 255, 88, 88, 255, 200, 200);

    break;


    default:
        printf("Lucid Shell\n");
    break;
    }

char *user = getenv("USER");

char hostname[256];
gethostname(hostname, sizeof(hostname));
struct utsname sysinfo;
uname(&sysinfo);

time_t now = time(NULL);
struct tm *t = localtime(&now);
char date[100];
strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", t);

user ? user : "unknown";

print_gradient_line("User: ",        255, 147, 15, 255, 249, 91); // Magenta to Cyan
print_gradient_line(user,           255, 147, 15, 255, 249, 91); // Magenta to Cyan
printf("\n");

print_gradient_line("Host: ",        255, 147, 15, 255, 249, 91); // Magenta to Cyan
print_gradient_line(hostname,        255, 147, 15, 255, 249, 91); // Magenta to Cyan
printf("\n");

print_gradient_line("OS: ",          255, 147, 15, 255, 249, 91); // Magenta to Cyan
print_gradient_line(sysinfo.release, 255, 147, 15, 255, 249, 91); // Magenta to Cyan
printf(" ");
print_gradient_line(sysinfo.sysname, 255, 147, 15, 255, 249, 91); // Magenta to Cyan
printf("\n");

print_gradient_line("Date: ",        255, 147, 15, 255, 249, 91); // Magenta to Cyan
print_gradient_line(date,            255, 147, 15, 255, 249, 91); // Magenta to Cyan
printf("\n");
}

void print_prompt()
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("\033[1;34mlucidsh: %s\033[0m > ", cwd);
    }
    else
    {
    printf("lucidsh > ");
    fflush(stdout);
}
}
