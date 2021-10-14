#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>


int foo(){

int j = 5 + 5;
  return(j);
}

long nanosec(struct timeval t){
  return((t.tv_sec*1000000+t.tv_usec)*1000);
}

int main(){
  int i,j,res;
  long N_iterations=1000000;
  float avgT1, avgT2;
  struct timeval t1, t2;

  res=gettimeofday(&t1,NULL); assert(res==0);
  for (i=0;i<N_iterations; i++){
    j=getpid();
  }
  res=gettimeofday(&t2,NULL);   assert(res==0);

  avgT1 =
  (nanosec(t2) - nanosec(t1))/(N_iterations*1.0);
  /* Find average time for Function call */
  res=gettimeofday(&t1,NULL);  assert(res==0);
  for (i=0;i<N_iterations; i++){
    j=foo();
  }
  res=gettimeofday(&t2,NULL);   assert(res==0);

  avgT2 =
  (nanosec(t2) - nanosec(t1))/(N_iterations*1.0);
  printf("Time for 1 : %lf\n",
  avgT1);
  printf("Time for 2 : %f\n",
  avgT2);

}
