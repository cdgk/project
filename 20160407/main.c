#include "func.h"
int main(int argc,char* argv[])
{
    if(argc!=4)
    {
        printf("error args\n")
        return -1;
    }
    int num=atoi(argv[3]);
    pchild p=(pchild)malloc(num*sizeof(child));
    make_child(p,num);
    wait(NULL
