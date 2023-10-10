#include "header.h"

void _fork()
{

    // Declaring the buffer array to have a size of BUFFER_SIZE instead
    // of typing the number each time
    char buffer[BUFFER_SIZE];

    //If the user entered nothing and hit enter:
    if (fgets(buffer, BUFFER_SIZE, stdin)==NULL)
    {
        //Print:
        printf("Empty, Closing!");
    }

    // Clearing trailing next line character by replacing it with a null character '0'
    // So in short, '\n' is replaced by '\0'
    buffer[strcspn(buffer, "\n")] = '\0';
    pid_t pid = fork();

    //If the fork call failed, pid < 0 therefore:
    if (pid < 0)
    {
        //Let the user know
        fprintf(stderr, "Fork Failed");
    }

    //If the command is not found:
    else if (pid == 0)
    {
        execlp(buffer, buffer, NULL);
        fprintf(stderr, "Command %s not found\n", buffer);
        exit(EXIT_FAILURE);
    }

    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}
