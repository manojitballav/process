#include"stdio.h"
#include"sys/types.h"
#include"signal.h"
void main(){
int i;
pid_t pp,pc;

pc=fork();

if(pc==0){
printf("\nChild exists.., child id: %d ppid=%d",getpid(),getppid());
sleep(5);
printf("\nChild exists.., child id: %d ppid=%d",getpid(),getppid());
}
else{
printf("Parent process completed and returned, pid is: %d, ppid=%d",getpid(),getppid());
sleep(2);
//kill(getpid(),SIGKILL);//to kill the process
}
}
