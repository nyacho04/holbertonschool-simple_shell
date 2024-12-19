#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid1, pid2;

    pid1 = fork();  // Crea el primer hijo
    if (pid1 == 0) {
        printf("Soy el primer hijo. PID: %d\n", getpid());
    } else {
        pid2 = fork();  // Crea el segundo hijo
        if (pid2 == 0) {
            printf("Soy el segundo hijo. PID: %d\n", getpid());
        } else {
            printf("Soy el proceso padre. PID: %d\n", getpid());
        }
    }

    return 0;
}
