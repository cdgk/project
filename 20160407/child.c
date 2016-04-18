#include "func.h"

void make_child(pchild p,int n)
{
    int fds[2];
    pid_t pid;
    int i;
    for(i=0;i<n;i++)
    {
        socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
        if(!(pid=fork()))
        {
            close(fds[1]);
            child_handle(fds[0]);
        }
        close(fds[0]);
        p[i].pid=pid;
        p[i].fdw=fds[1];
        p[i].busy=0;
    }
}

void child_handle(int fdr)
{
    while(1);
}
