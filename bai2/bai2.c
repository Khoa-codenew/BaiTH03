#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    printf("ID hien tai cua tien trinh la: %d\n", getpid());
    printf("ID tien trinh cha hien tai la: %d\n", getppid());
    __pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("ID cua tien trinh con la: %d\n", getpid());
    }
    else
    {
        wait(NULL); // Cha đợi con kết thúc
        printf("ID cua tien trinh cha sau khi fork la: %d\n", getpid());
    }
}