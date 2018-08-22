#include <iostream>

using namespace std;

//typ namn(in data)
bool primeTest(int potentialPrime);
void printInt(int x);
int readInt();

int main(){
  int talAttTesta = 0;
  cout << "ange ett tal och testa om det är ett primtal" << endl;
  talAttTesta = readInt();
  bool prime = primeTest(talAttTesta);
  if (prime){
    cout << "wow vi har ett primtal!" << endl;
  } else {
    cout << "ditt tal är inte ett primtal." << endl;
  }
}

int readInt(){
  int x;
  cin >> x;
  return x;
}
bool primeTest(int potentialPrime){
  for(int i = 2; i < potentialPrime; i++){
    if (potentialPrime % i == 0){
      return(false);
    }
  }
  return(true);
}
