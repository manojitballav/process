#include"stdio.h"
#include"sys/types.h"
void main(){
int i;
pid_t pp,pc;

pc=fork();

if(pc!=0){
printf("\nParent exists.., parent id:%d",getpid());
sleep(15);
printf("\nParent exists.., parent id: %d",getpid());
}
else{
printf("Child process completed and returned, pid is: %d, ppid=%d",getpid(),getppid());
sleep(7);

}
}
//command to check the zombie process
//open another terminal and run the following 'ps -ax | grep a.out'
