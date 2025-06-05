#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int uocso(int n, int i)
{
    if (n % i == 0)
        return i;
    else
        return 0;
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Su dung: %s <so_nguyen>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int S = 0, sum_uoc = 0;
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid > 0) // tien trinh cha
    {
        // Tinh tong S = 1 + 2 + ... + n
        for (int i = 1; i <= n; i++)
        {
            S += i;
        }
        printf("Tien trinh cha - Tong S (1 den %d) = %d\n", n, S);

        wait(NULL); // doi tien trinh con ket thuc
        printf("Tien trinh cha ket thuc.\n");
    }
    else // tien trinh con
    {
        // Tinh tong cac uoc so cua n
        for (int i = 1; i <= n; i++)
        {
            sum_uoc += uocso(n, i);
        }
        printf("Tien trinh con - Tong uoc so cua %d = %d\n", n, sum_uoc);
        exit(0); // tien trinh con ket thuc
    }

    return 0;
}