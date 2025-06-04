#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    // tien trinh A
    pid_t pidB, pidC, pidD, pidE, pidH;
    printf("ID tien trinh A: %d, ID tien trinh cha: %d\n", getpid(), getppid());
    // tien trinh A sinh ra tien trinh B;
    pidB = fork();
    if (pidB < 0)
    {
        printf("Fork B failed\n");
        return 1;
    }
    else if (pidB == 0) // trong than tien trinh B(con)
    {
        printf("ID tien trinh B: %d, ID tien trinh cha: %d\n", getpid(), getppid());

        pidD = fork(); // tien trinh B sinh ra tien trinh D
        if (pidD < 0)
        {
            printf("fork D failed\n");
            return 1;
        }
        else if (pidD == 0) // trong tien trinh D
        {
            printf("ID tien trinh D: %d, ID tien trinh cha: %d\n", getpid(), getppid());
            exit(0); // tien trinh D ket thuc
        }

        pidE = fork(); // tien trinh B sinh ra tien trinh E
        if (pidE < 0)
        {
            printf("fork E failed\n");
            return 1;
        }
        else if (pidE == 0) // trong tien trinh E
        {
            printf("ID tien trinh E: %d, ID tien trinh cha: %d\n", getpid(), getppid());
            exit(0); // tien trinh E ket thuc
        }
        // tien trinh B doi tien trinh D va E ket thuc
        waitpid(pidD, NULL, 0); // doi tien trinh D ket thuc
        waitpid(pidE, NULL, 0); // doi tien trinh E ket thuc
        exit(0);                // tien trinh B ket thuc
    }

    // tien trinh A sinh ra tien trinh C
    pidC = fork();
    if (pidC < 0)
    {
        printf("Fork C failed\n");
        return 1;
    }
    else if (pidC == 0) // trong tien trinh C
    {
        printf("ID tien trinh C: %d, ID tien trinh cha: %d\n", getpid(), getppid());

        pidH = fork(); // tien trinh C sinh ra tien trinh H
        if (pidH < 0)
        {
            printf("Fork H failed\n");
            return 1;
        }
        else if (pidH == 0) // trong tien trinh H
        {
            printf("ID tien trinh H: %d, ID tien trinh cha: %d\n", getpid(), getppid());
            exit(0); // tien trinh H ket thuc
        }
        // tien trinh C doi tien trinh H ket thuc
        waitpid(pidH, NULL, 0); // doi tien trinh H ket thuc
        exit(0);                // tien trinh C ket thuc
    }
    // tien trinh A doi tien trinh B va C ket thuc
    waitpid(pidB, NULL, 0); // doi tien trinh B ket thuc
    waitpid(pidC, NULL, 0); // doi tien trinh C ket thuc

    return 0;
}