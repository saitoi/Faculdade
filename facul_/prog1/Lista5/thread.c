#include<pthread.h>
#include<stdio.h>
// a simple pthread example
// compile with -lpthreads
long int i=0;
// create the function to be executed as a thread
void *thread(void *ptr)
{
  long int j=0;
  while (j<20000000)
  {
    i++;  j++;
  }
  return 0;
}

int main(int argc, char **argv)
{
// create the thread objs
pthread_t thread1, thread2;
// start the threads
pthread_create(&thread1, NULL, *thread, (void *) NULL);
pthread_create(&thread2, NULL, *thread, (void *) NULL);
// wait for threads to finish
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
fprintf(stderr,"i=%ld\n",i);

return 0;
}