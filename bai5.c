#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void collatz(int n)
{
    printf("%d ", n);
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        printf("%d ", n);
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Doi so khong hop le");
        return 1;
    }
    int n = atoi(argv[1]);
    if (n <= 0)
    {
        printf("Nhap so nguyen duong\n");
        return 1;
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid > 0) // tien trinh cha
    {
        wait(NULL); // doi tien trinh con ket thuc
        printf("Tien trinh cha ket thuc.\n");
    }
    else // tien trinh con
    {
        collatz(n);
        exit(0); // tien trinh con ket thuc
    }
    return 0;
}