#include <iostream>
using namespace std;

double nBallVol(int dim, double r);

int main(){
  int dim = 0;
  double r = 0;
  cout << "enter the number of dimensions: ";
  cin >> dim;
  cout << endl << "enter the radius of the ball: ";
  cin >> r;
  double vol = nBallVol(dim, r);
  cout << endl << "it has volume " << vol;
}

double nBallVol(int dim, double r){
  if(dim > 3){
    return(nBallVol(dim-2, r) * 2*3.1415*r*r/dim);
  }
  if(dim == 3){
    return 4/3 * 3.1415 * r * r * r;
  }
  return 3.1415*r*r;
}
