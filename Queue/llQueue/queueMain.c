#include <stdio.h>
#include "queue.h"

int main() {
  queue_t q = queueInit();
  int count = 0;
  data_t t;
  for(int i = 0; i <20;i++) {
    
    count++;
    if(count<=10){
      q=enqueue(q,i);
    }
    else{
      q=enqueue(q,i);
      q=dequeue(q);
    }
  }


  // Pop data from Stack and display to screen
  while (!isEmpty(q)) {
    showData(top(q));
    q = dequeue(q);
  }

  return 0;
}