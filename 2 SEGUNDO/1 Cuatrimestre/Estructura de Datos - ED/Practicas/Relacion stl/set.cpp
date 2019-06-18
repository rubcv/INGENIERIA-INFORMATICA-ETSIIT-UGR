#include <iostream>
#include <set>

using namespace std;

int main(){

multiset<int> uno;
uno.insert(100);
set<int>::iterator it = uno.begin();
cout << *it;


}
