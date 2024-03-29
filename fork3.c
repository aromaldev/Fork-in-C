#include <unistd.h> 
#include <stdio.h> 
#include <sys/wait.h>
int main() 
{ 
    // Creating first child 
    int n1 = fork();   
    // Creating second child. First child 
    // also executes this line and creates 
    // grandchild. 
    int n2 = fork(); 
  
    if (n1 > 0 && n2 > 0) 
    { 
        printf("parent\n"); 
        printf("%d %d \n", n1, n2); 
        printf(" my id is %d \n", getpid()); 
        printf(" my parentid is %d \n", getppid());
        wait(NULL); 
    } 
    else if (n1 == 0 && n2 > 0) 
    { 
        printf("First child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("my id is %d  \n", getpid()); 
        printf("my parentid is %d \n", getppid()); 
        wait(NULL);
    } 
    else if (n1 > 0 && n2 == 0) 
    { 
        printf("second child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("my id is %d  \n", getpid()); 
        printf(" my parentid is %d \n", getppid()); 
    } 
    else { 
        printf("third child\n"); 
        printf("%d %d \n", n1, n2); 
        printf(" my id is %d \n", getpid()); 
        printf(" my parentid is %d \n", getppid()); 
    } 
  
    return 0; 
} 