#include "Apermutacion.h"

 bool Apermutacion::Repetidos(){
   for (int i=0;i<=level-1 && datos[i]>0 ;i++)
     for (int j=i+1;j<=level && datos[j]>0;j++)
      if (datos[i]==datos[j]) return true;
    return false;
 }
 /***************************************************/
 bool Apermutacion::CondicionProblem(){
   for (int i=0;i<=level && datos[i]>0 ;i++){
    if (datos[i]==(i+1)) return false;//asignar i a i
    if (datos[datos[i]-1]>0) //si se asigna 1-5 tiene que existir 5-1
       if (datos[datos[i]-1]!=(i+1)) return false;
   } 
    return true;
 }
 /***************************************************/
 bool Apermutacion::EsSecuencia(int l){
   if (Repetidos()) return false;
   if (!CondicionProblem()) return false;
   return l>=0 && l==(int)level;
 }   

 /***************************************************/  
 bool Apermutacion::PosibleSecuencia(int l){
   if (Repetidos()) return false;
   if (!CondicionProblem()) return false;
   return l>=0 && l<(int)level;
 }   
  
/***************************************************/  
bool Apermutacion::MasHermanos(int l){
  return l>=0 && datos[l]<(int)datos.size();
}
/***************************************************/  

bool Apermutacion::GeneraSiguienteProfundidad(){
  
  if (level<(int)datos.size()-1)//Podemos avanzar al siguiente nivel
     level=level+1;
  while (level>=0 && !MasHermanos(level)){
    datos[level]=0;
    level--;
  }  
  do{
    Next(level);
    if (EsSecuencia(level))
        return true;
   
    if (PosibleSecuencia(level)) level++;
    else
      while (level>=0 && !MasHermanos(level)){
        datos[level]=0;
        level--;
      }
  }while (level>=0);
  return false;
}  
     
/***************************************************/       


bool Apermutacion::GeneraSiguienteAnchura(){
  
  int nivel=(int)level;
  
  
   while (nivel>=0  && !MasHermanos(nivel)  ){
 
	      datos[nivel]=0; 
              nivel=nivel-1;
   }
   if (nivel<0){
     
    if (level<(int)datos.size()-1){
      level=level+1;
      nivel=0;
    }
    else
    return false;
   }
  
  do{
       Next(nivel); 
       
       if (EsSecuencia(nivel)){
	  //Imprimeaux(datos,n);
	  return true;
       }	
       if ( PosibleSecuencia(nivel)) 
           nivel=nivel+1;
       else{
          while (nivel>=0  && !MasHermanos(nivel)  ){
	      datos[nivel]=0; 
              nivel=nivel-1;
         }
         if (nivel<0){
	
	    if (level<(int)datos.size()-1){
	      level=level+1;
	      nivel=0;
	    }
	    else
	    return false;
   
	 }   
	      
         
       } 

   }while (nivel>=0 );   
   return false;
}   
     
/***************************************************/  

bool Apermutacion::Backtracking(){
 
  if (level==0 && !MasHermanos(level)) return false;
  else{
    while (level>=0 && !MasHermanos(level)){
      datos[level]=0;
      level--;
     }
     if (level<0) return false;
  }	
  do{
    Next(level);
    if (EsSecuencia(level))
        return true;
   
    if (PosibleSecuencia(level)) level++;
    else
      while (level>=0 && !MasHermanos(level)){
        datos[level]=0;
        level--;
      }
  }while (level>=0);
  return false;
}  


/***************************************************/  
int  Apermutacion::NumeroSecuenciasPosibles(){
     unsigned int suma=0;
  
    for (unsigned int k=1; k<=datos.size();k++){
     int total =1;
     for (unsigned int i=k;i<=datos.size();i++)
       total*=i;
      suma+=total;
   }
   return suma;
}   

/***************************************************/  
bool Apermutacion::Espadre(const Apermutacion &v)const {
  if (level>=v.level) return false;
    
  for ( int i=0;i<=level;i++)
   if  (datos[i]!=v.datos[i]) return false;
  return true;
}  
/***************************************************/  
  
vector<vector<int> > Apermutacion::GeneraHijos(){
   vector< vector< int> > out;
    
      Apermutacion vaux = *this;
      if (vaux.GeneraSiguienteProfundidad()){
        int nivel = vaux.GetLevel();
	bool seguir=true;
	
	while(seguir && nivel==level+1 && Espadre(vaux)) {
	 out.push_back(vaux.GetSecuencia());
	 
	 seguir=vaux.GeneraSiguienteAnchura();
	 if (seguir){
           nivel = vaux.GetLevel();
	}
      }
      }
      return out;
}      
/***************************************************/  
void Imprimeaux(ostream & os,const vector<int> & v,int n){
  for ( int i=0;i<n;i++)
    os<<v[i]<< " ";
  
} 
/***************************************************/  
ostream & operator<<(ostream & os, const Apermutacion &V){
   Imprimeaux(os,V.datos,V.level+1);
   return os;
}  