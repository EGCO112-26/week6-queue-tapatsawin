#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
  /* For struct Queue */
  Queue q;
  q.headPtr=NULL;
  q.tailPtr=NULL;
  q.size=0;

  int i,x;
  for(i=1;i<argc;i++){
    if(strcmp(argv[i],"x")==0){
      if(q.size > 0){
        x = dequeue_struct(&q);
        printf("dequeing %d\n", x);
      }
    }
    else if(strcmp(argv[i],"s")==0){
      if(q.size > 0){
        x = dequeue_struct(&q);
        printf("popping %d\n", x);
      }
    }
    else {
      enqueue_struct(&q, atoi(argv[i]));
    }
  }

  if(q.size > 0){
    printf("Remaining in queue: ");
    while(q.size > 0){
      printf("%d ", dequeue_struct(&q));
    }
    printf("\n");
  }

  return 0;
}