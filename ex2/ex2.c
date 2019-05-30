// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Both the child and parent can access the file because the text file is an external file. So both processes can access the same file and read and write to it.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp = fopen("./text.txt", "w+");

    int child = fork();

    if (child < 0)
    {
        printf("Process Failed");
        exit(1);
    }
    else if (child == 0)
    {
        fprintf(fp, "%s", "This is the child\n");
    }
    else
    {
        fprintf(fp, "%s", "This is the parent \n");
    }

    return 0;
}
