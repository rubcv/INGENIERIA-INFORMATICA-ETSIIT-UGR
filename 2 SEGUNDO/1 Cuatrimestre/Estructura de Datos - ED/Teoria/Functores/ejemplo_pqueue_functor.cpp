#include <queue>
#include <iostream>

using namespace std;

struct comp {
  bool operator() (int a, int b)
  {
    // los pares son "menores" y luego los impares y entre ellos por orden
    if (a%2== 0 && b%2==0)
      return a<b;
    else
      if (a%2==0) // b debe ser impar
	return true;
      else
	if (b%2==0) // a debe ser impar
          return false;
        else
	  return a<b;
  }
};

int main()
{
  priority_queue<int, vector<int>, comp > pq;
  for (int i= 0; i<20; i++)
    pq.push(i);
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}
