#include <set>
#include <iostream>

using namespace std;

multiset<int> multi_insercion(const multiset<int> & m1, const multiset<int> & m2){
  multiset<int> res;
  multiset<int>::iterator i = m1.begin();
  multiset<int>::iterator j;

  for(i; i != m1.end(); i++){
    for(j = m2.begin(); j != m2.end() && (res.find(*i) != res.end()); j++){
      if(*i == *j){
        res.insert(*i);
        i++;
        j++;
      }
    }
  }

  return res;
}


int main(){
  multiset<int> m1;
  multiset<int> m2;

  m1.insert(2);
  m1.insert(2);
  m1.insert(3);
  m1.insert(3);

  m2.insert(1);
  m2.insert(2);
  m2.insert(3);
  m2.insert(3);
  m2.insert(3);
  m2.insert(4);


  cout<< "----- res -----" << endl;
  multiset<int> res = multi_insercion(m1, m2);
  cout<< "tam: " << res.size() << endl;
  multiset<int>::iterator it = res.begin();
  for(it; it != res.end(); it++){
    cout<< *it << " ";
  }
  cout << endl;
}
