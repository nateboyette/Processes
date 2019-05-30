// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable

// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?

// -- The value of the variable in the child process is going to be whatever is assigned to it within that process.

// What happens to the variable when both the child and parent change the value of x?

// -- Each process has it's own address and the variable is being assigned a space in memory within that process. So the variable being returned by the child process is a different variable in memory than the parent.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    int rc = fork();

    if (rc < 0)
    {
        printf("Process Failed");
        exit(1);
    }
    else if (rc == 0)
    {
        x = 90;
        // printf("Child: %d\n", x);
    }
    else
    {
        // x = 50;
        // printf("Parent: %d\n", x);
    }

    printf("%d\n", x);

    return 0;
}
