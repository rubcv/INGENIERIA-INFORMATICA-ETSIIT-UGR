#include "imagen.h"
#include "paleta.h"
#include <fstream>

//ejecutar ./testimagen_paleta datos/paleta.txt

/**
 * @brief Pinta la paleta en una imagen
 * @param P: Paleta con los colores
 * @param I: imagen donde se pinta la paleta. ES MODIFICADO
 * @param scaladoi: cuantos filas se usarán para pintar un color
 * @prarm scaladoj: cuantas columnas se usarán para pintar un color
 */

void PintaPaleta_enImagen(const Paleta &P,Imagen &I,int scaladoi,int scaladoj){
  int n;
  n=P.Size(); 
  
  int j=0;
 
  for (int i=0;i<n;i++){ //Por cada color en la paleta
      color c;
      c=P.Get(i);
      Pixel p=c;
      p.transp=0;
      
      for (int ii=i*scaladoi;ii<(i+1)*scaladoi && ii<I.num_filas() ;ii++)	  
	for (int jj=j*scaladoj;jj<(j+1)*scaladoj && jj<I.num_cols() ;jj++){
	    I(ii,jj)=p;
         }
       
   } 
  
}   
   


int main(int argc, char * argv[]){
  if (argc!=2){
      cout<<"Los parametros son: ";
     cout<<"1.-Dime el nombre del fichero con la paleta"<<endl;
  }   
  
  
  Imagen I(256,100); //Creamos una imagen de 256x100 (256 filas x 100 columnas)
  
  Paleta P; //la paleta
  
  
  ifstream f (argv[1]);
  if (!f){
      cout<<"No puedo abrir "<<argv[1]<<endl;
      return 0;
  }
  f>>P;
  int sci=I.num_filas()/P.Size();//correspondencia entre numero de filas por cada color en la paleta
  int scj=I.num_cols();
  
  PintaPaleta_enImagen(P,I,sci,scj);    
  I.EscribirImagen("paleta.ppm");
}