#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Hello from the child process!\n");
    } else {
        // Parent process
        printf("Parent process: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Hello from the parent process!\n");
    }

    return 0;
}

/*./q1 
Parent process: PID = 5888, PPID = 5674
Hello from the parent process!
Child process: PID = 5889, PPID = 5888
Hello from the child process!*/
