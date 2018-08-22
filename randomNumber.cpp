#include <ctime>
#include <stdlib.h>

int getRandomNumber(int min,int max);
void initRandomNumber();

bool hasInitGTGRNG = false;

int getRandomNumber(int min, int max){
  if(hasInitGTGRNG){
    return(rand() % (max-min) + min);
  }
  else{
    initRandomNumber();
    return(getRandomNumber(min,max));
  }
}

void initRandomNumber(){
  srand(time(NULL));
  hasInitGTGRNG = true;
}
