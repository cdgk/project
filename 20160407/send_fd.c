#include "func.h"
void send fd(int fdw,int fd)
{
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec iov[2];
    iov[0].iov_base="hello";
    iov[0].iov_len=5;
    iov[1].iov_base="world";
    iov[1].iov_len=5;
    msg.msg_iov=iov;
    msg.msg_iovlen=2;
    struct cmsghdr* cmsg;
    int len=CMSG_LEN(sizeof(int));
    cmsg=(struct cmsghdr*)malloc(len);
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    cmsg->cmsg_len = len;
    *(int *) CMSG_DATA(cmsg)=fd;
    msg.msg_control=cmsg;
    msg.msg_controllen=len;
    int ret;
    ret=sendmsg(fdw,&msg,0);
    if(-1==ret)
    {
        perror("sendmsg");
        return;
    }
}
void recv_fd(int fdr,int* fd)
{
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec iov[2];
    char buf1[10]={0};
    char buf2[10]={0};
    iov[0].iov_base=buf1;
    iov[0].iov_len=5;
    iov[1].iov_base=buf2;
    iov[1].iov_len=5;
    msg.msg_iov=iov;
    msg.msg_iovlen=2;
    struct cmsghdr* cmsg;
    int len=CMSG_LEN(sizeof(int));
    cmsg=(struct cmsghdr*)malloc(len);
    cmsg->cmsg_levle = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    cmsg->cmsg_len = len;
    msg.msg_control=cmsg;
    msg.msg_controllen=len;
    int ret;
    ret=recvmsg(fdr,&msg,0);
    if(-1==ret)
    {
        perror("recvmsg");
        return;
    }
    *fd=*(int *) CMSG_DATA(cmsg);
}
