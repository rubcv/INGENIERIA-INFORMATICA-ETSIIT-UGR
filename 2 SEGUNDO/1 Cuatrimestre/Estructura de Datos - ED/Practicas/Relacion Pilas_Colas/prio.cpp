#include <iostream>
#include <queue>

using namespace std;


struct Comp{
  bool operator()(int a, int b){
    return (a > b);
  }
};

int main(){
  priority_queue<int, vector<int>, Comp> una;

  una.push(1);
  una.push(2);
  una.push(3);
  una.push(4);
  una.push(5);
  una.push(6);
  una.push(7);


  while(!una.empty()){
    cout << una.top();
    una.pop();
  }


}
