#include <map>
#include <iostream>


using namespace std;

int main(){
  multimap<string, int> mapa;
  multimap<string, int>::iterator it;


  mapa.insert(pair<string, int>("hola", 3));
  it = mapa.begin();
  cout<< it->second << endl;

  mapa.erase(it);
  cout<< "TAM: " << mapa.size() << endl;

}
