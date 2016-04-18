#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
typedef struct {
    pid_t pid;
    int fdw;
    int busy;
}child,*pchild;

void make_child(pchild,int);//创建多个子进程用于给客户端发送文件
void child_handle(int);
