#include "ORev.h"
#include <cmath>

ORev::ORev(){}

ORev::ORev(vector<_vertex3f> perfil, int n){

	Rotar(perfil,n);

}

float ORev::GradosARadianes(float grados){
	return (grados*M_PI)/180.0;
}

void ORev::Rotar(vector<_vertex3f> perfil, int n){
double angle;
vector<_vertex3i> lascaras;
vector<_vertex3f> losvertices(perfil);
angle = (2.0*M_PI) / n;
_vertex3f puntoCentral;
for (int step = 0; step < n; step++) {

	vector<_vertex3f> siguientePerfil(perfil.size());

	for (unsigned int k = 0; k < perfil.size(); k++)
		siguientePerfil[k] = RotarY(perfil[k], angle);

	vertices.insert(vertices.end(), siguientePerfil.begin(), siguientePerfil.end() );

	unsigned int inicioPerfil, finPerfil; inicioPerfil = step * perfil.size();
	finPerfil = inicioPerfil + perfil.size();

	for (unsigned int i = inicioPerfil+1, k = finPerfil+1; i < finPerfil; i++, k++) {
		caras.push_back(_vertex3i(i-1, k-1, k));
		caras.push_back(_vertex3i(i-1, k, i));
	}
	perfil = siguientePerfil;
}
	if (vertices.front().x) {
		puntoCentral(0.0, vertices.front().y, 0.0);
		vertices.push_back(puntoCentral);
		for (int step = 0; step < n; step++) {
			int perfilactual = step * perfil.size();
			int siguientePerfil = perfilactual + perfil.size();
			caras.push_back(_vertex3i(vertices.size()-1, siguientePerfil, perfilactual));
		}
	}
	if (vertices[perfil.size() - 1].x) {
		_vertex3f puntoCentral(0.0, vertices[perfil.size() - 1].y, 0.0);
		vertices.push_back(puntoCentral);
		for (int step = 0; step < n; step++) {
 			int perfilactual = (step+1) * perfil.size() -1;
 			int siguientePerfil = perfilactual + perfil.size();
 			caras.push_back(_vertex3i(vertices.size()-1, perfilactual,siguientePerfil));
		}
	}
	vertices = losvertices;
	caras = lascaras;
}




/*
	//Limpio para evitar revoluciones "incorrectas"
	vertices.clear();
	caras.clear();
	_vertex3f primerVertice, ultimoVertice;
	float nuevoGrado;
	int i;

int nperfil=perfil.size();

	if(perfil[0].x == 0){
		primerVertice = perfil[0];
		perfil.erase(perfil.begin());
		nperfil = perfil.size();
	}

	if(perfil[nperfil -1].x == 0){
		ultimoVertice = perfil[nperfil-1];
		perfil.pop_back();
		nperfil = perfil.size();
	}

for(int k = 0; k < n; k++){
	nuevoGrado = (360.0/n) * k; //Mas preciso que ir sumando grados
		vertices.push_back(RotarY(perfil[0],GradosARadianes(nuevoGrado)));

	for(int j = 1; j < nperfil; j++)
	{

		vertices.push_back(RotarY(perfil[j],GradosARadianes(nuevoGrado)));

	}

}

	vertices.push_back(ultimoVertice);
	vertices.insert(vertices.begin(),primerVertice);

for(int k = 0; k < n; k++){
	nuevoGrado = (360.0/n) * k; //Mas preciso que ir sumando grados


	for(int j = 1; j < nperfil; j++)
	{
		i=k*nperfil+j;



		_vertex3i cara;

		cara._0 = i;
		cara._1 = (i+nperfil-1)% (n*nperfil);
		cara._2 = (i-1);
		caras.push_back(cara);

		cara._0 = i;
		cara._1 = (i+nperfil)% (n*nperfil);
		cara._2 = (i+nperfil-1)% (n*nperfil);
		caras.push_back(cara);

	}

}


}// FIN ROTAR
*/
_vertex3f ORev::RotarY(_vertex3f p, float angulo){
	_vertex3f rotado;
	rotado.x = cos(angulo)*p.x + sin(angulo)*p.z;
	rotado.y = p.y;
	rotado.z = -sin(angulo)*p.x + cos(angulo)*p.z;

	return rotado;
}
