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
/*khi khong co dong NULL:
- tien trinh cha va con chay song song
- cha co the ket thuc truoc con
- con co the tro thanh zombie process hoac orphan process
- output co the bi xao tron vi ca 2 in cung luc

    khi co dong NULL:
- tien trinh cha se doi cho den khi tien trinh con ket thuc
- dam bao thu tu thuc thi: con chay xong roi cha moi chay tiep
- out put duoc sap xep co thu tu
*/