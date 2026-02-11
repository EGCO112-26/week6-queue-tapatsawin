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

  int i, x;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i], "x") == 0){
        // ตรวจสอบก่อนว่ามีของไหม ถ้ามีให้ print "dequeing"
        // ถ้าไม่มี ให้เรียก dequeue_struct เพื่อให้มัน print "Empty queue"
        if(q.size > 0){
            x = dequeue_struct(&q);
            printf("dequeing %d\n", x);
        } else {
            dequeue_struct(&q); 
        }
    }
    else if(strcmp(argv[i], "s") == 0){
        if(q.size > 0){
            x = dequeue_struct(&q); // ออกจากหัวเหมือนกัน
            printf("popping %d\n", x);
        } else {
            printf("Empty stack\n");
        }
    }
    else {
      enqueue_struct(&q, atoi(argv[i]));
    }
  }

  return 0;
}