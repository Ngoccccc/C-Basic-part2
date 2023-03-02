/*
  Name: Tran Tien Ngoc 20205009
  Date: 24-11-2022
  Muc dich: addition by popping number from the stack
  Updated:
*/



#include <stdio.h>

#include "stack.h"

int main()
{
  stack_t s1;
  stack_t s2;
  stack_t result;
  initialize(&s1);
  initialize(&s2);
  initialize(&result);
  int sum = 0, rem = 0;

  push(convert(8), &s1);
  push(convert(7), &s1);
  push(convert(3), &s1);
  push(convert(2), &s1);

  push(convert(5), &s2);
  push(convert(6), &s2);
  push(convert(2), &s2);
  push(convert(9), &s2);

  while (!isEmpty(s1) && !isEmpty(s2))
  {
    sum = (rem + s1.storage[s1.top-1] + s2.storage[s2.top-1]);

    push(sum % 10, &result);
    printf("%d--- %d\n", s1.storage[s1.top-1], s2.storage[s2.top-1]);
    rem = sum / 10;

    pop(&s1);
    pop(&s2);
  }

  while (!isEmpty(s1))
  {
    sum = (rem + s1.storage[s1.top-1]);
    push(sum % 10,&result);
    rem = sum / 10;
    pop(&s1);
  }

  while (!isEmpty(s2))
  {
    sum = (rem + s2.storage[s2.top-1]);
    push(sum % 10,&result);
    rem = sum / 10;
    pop(&s2);
  }

  while (rem > 0)
  {
    push(rem,&result);
    rem /= 10;
  }

  while(!isEmpty(result)){
    showData(pop(&result));
  }

  return 0;
}