//
// Ejercicio 5 - Relacion Pilas_Colas
//
//
// 5. Se llama expresión en postfijo a una expresión matemática en
// la que cada operación aparece con sus dos operandos seguidos por el operador.
// Por ejemplo: 2 3 + 5 * Escribe un programa que evalue una expresión en postfijo.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;

double Postfijo(char* exp){
  stack<char> pila;
  // Valores posibles
  char suma = '+';
  char res  = '-';
  char mult = '*';
  char divi = '/';

  int TAM = 0; // Contador del tamaño
  while(exp[TAM] != '\0'){
    TAM++;
  }

// Guardar la expresion en la pila
  for(int i = 0; i < TAM; i++){
    char dato = exp[i];
    if(dato != ' '){ // Si no es espacio
      // Suma
      if(dato == suma){
        cout<< "SUMA" << endl;
        int b = pila.top() - '0';
        cout<< b << endl;
        pila.pop();
        int a = pila.top() - '0';
        cout<< a << endl;
        pila.pop();

        int r = a + b;
        cout << a + b << endl;
        pila.push((char)r);
      }

      // Resta
      if(dato == res){
        int b = pila.top() - '0';
        pila.pop();
        int a = pila.top() - '0';
        pila.pop();

        pila.push(a - b);
      }

      // Multiplicacion
      if(dato == mult){
        int b = pila.top() - '0';
        pila.pop();
        int a = pila.top() - '0';
        pila.pop();

        pila.push(a * b);
      }

      // Division
      if(dato == divi){
        int b = pila.top() - '0';
        pila.pop();
        int a = pila.top() - '0';
        pila.pop();

        pila.push(a / b);
      }

      // Numero
      pila.push(dato);
    }
  }

while(!pila.empty()){
  cout<< pila.top() - '0' << "   ";
  pila.pop();
}

  // En la pila debe quedar el resultado
  return 1 ;
}

int main(){
  const int TAM = 50;
  char* exp;
  double res;

  cout<< "\nIntroduce la expresion postfijo: (+,-,*,/)" << endl;
  cin.getline(exp, TAM, '\n'); // Getline para guardar la expresion
  cout<< "\nExpresion: " << exp << endl;

  res = Postfijo(exp);
  cout<< "\nResultado: "<< res << endl;
}
