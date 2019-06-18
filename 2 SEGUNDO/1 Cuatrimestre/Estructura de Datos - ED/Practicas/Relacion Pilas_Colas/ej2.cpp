//
// Ejercicio 2 - Relacion Pilas_Colas
//
//
// 2. Implementa un función para determinar si una expresión
// contenida en un string tiene una configuración de paréntesis correcta.
// Debe tener un orden lineal. <- PILA


#include <stack>
#include <iostream>
#include <string>

using namespace std;

/*
  Se limpia el string para dejar solo parentesis,
  guardar en pila si es ) y sacar si es ( de forma
  que se detiene cuando hay un parentesis incorrecto
  (vas a sacar de la pila y ya esta vacia)
*/

bool EsCorrecta(string var){

  stack<char> pila; // Creamos pila
  char abre = '('; // Dos posibilidades
  char cierra = ')';
  int cont = 0, cont2 = 0;

  for(int i = 0; i < var.size(); i++){ // Se recorre el string
    if(var[i] == abre){ // Si es igual al que abre, se guarda en la pila
      pila.push(var[i]);
      cont++;
    }
    if(var[i] == cierra){ // Si es igual al que cierra, se saca de la pila
      if(!pila.empty()){
        pila.pop();
        cont2++;
      }else{ // Si la pila esta vacia y se quiere sacar, se devuelve false porque no estan pareados
        return false;
      }
    }
  }
return (cont == cont2); // Las veces que se guarda deben ser igual a las veces que se saca
}

int main(){
  string expr = ")("; // Expresion con los parentesis (Cambiar)

  if(EsCorrecta(expr)){
    cout<< "\nExpresion con los parentesis puestos correctamente" << endl;
  }else{
    cout<< "\nExpresion con los parentesis puestos de forma incorrecta" << endl;
  }

}
