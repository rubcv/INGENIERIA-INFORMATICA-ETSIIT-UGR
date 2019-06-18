#include <cassert>
#include <iostream>
using namespace std;

template <class Tbase>
void ArbolGeneral<Tbase>::destruir(nodo * n)
{
	if(n != 0)
	{
		destruir(n->izqda);
		destruir(n->drcha);
		delete n;
	}

}

template <class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig)
{
	dest = 0;
	if ( orig != NULL)
	{
		dest = new nodo;
		dest -> etiqueta = orig ->etiqueta;

		copiar(dest->izqda, orig->izqda);
		copiar(dest->drcha, orig->drcha);

		if(dest->izqda)
			dest->izqda->padre = dest;
		if(dest->drcha)
			dest->drcha->padre = dest;
	}

}

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const
{
	int suma=0;
	if(n!= NULL)
	{
		suma= contar(n->drcha) + suma;
		suma = contar(n->izqda) + suma;
	}
	return suma;
}

template <class Tbase>
 bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const
 {
	if (n1 == null() && n2 == null())
		return true;
	if (n1 != null() || n2 != null())
		return false;
	if (n1->etiqueta != n2->etiqueta)
		return false;
	if (!soniguales(n1->izqda(),n2.izqda()))
		return false;
	if (!equals(n1->drcha(),n2->drcha()))
		return false;
	return true;
 }

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const
{
	if( nod != NULL)
	{
		out << "e " << nod -> etiqueta;
		escribe_arbol(out,nod -> izqda);
		escribe_arbol(out,nod -> drcha);
	}
	else
		out << "* ";

}
template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo *& nod)
{
	char c ;
	in >> c;
	if(c != '*')
	{
		in >> nod-> etiqueta;
		lee_arbol(in,nod -> izqda);
		lee_arbol(in, nod ->drcha);
	}

}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral()
{
	padre = NULL;
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e)
{

}

template<class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator=(const ArbolGeneral<Tbase> &v)
{
	if( &v != this)
	{
		destruir(laraiz);
		copiar(laraiz,v.laraiz);
	}
	return *this;
}

template<class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral()
{
	destruir(laraiz);
}

template<class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e)
{
	if (!laraiz.null())
		laraiz.Nodo->etiqueta = e;
	else
	  laraiz = typename ArbolGeneral<Tbase>::Nodo(e);
}

template<class Tbase>
Nodo ArbolGeneral<Tbase>::raiz() const
{
	return laraiz;
}

template<class Tbase>
Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const
{
	return n.izqda;
}

template<class Tbase>
Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo n) const
{
	return n.drcha;
}

template<class Tbase>
Nodo ArbolGeneral<Tbase>::padre(const Nodo n) const
{
	return n.laraiz;
}

template<class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n)
{
	return n->etiqueta;
}

template<class Tbase>
const ArbolGeneral<Tbase>::Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) const
{
	return n->etiqueta;
}

template<class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod)
{
	if(&orig != this)
	{
		//al nodo que me pasan destruir y hago un copiar de la raiz del arbol que me han pasado y despues borro el arbol que me han pasado
		destruir(nod);
		copiar(nod,orig.laraiz);
		destruir(orig.laraiz);
	}

}

template<class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest)
{
	//borro dest despues copio en dest el hijo izq del nodo n y compruebo si es h izqda pongo
	if(n->izqda != NULL)
	{
		destruir(dest);
		dest.laraiz = n->izqda;
		n->izqda = NULL;
		dest.laraiz->padre = NULL;
		//copiar(dest,n->izqda);
		//destruir(n->izqda);
	}
}

template<class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest)
{
	if(n->drcha != NULL)
	{
		destruir(dest);
		dest.laraiz = n->drcha;
		n->drcha = NULL;
		dest.laraiz->padre = NULL;
	}
}

template<class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama)
{
	if(n->izqda != NULL)
		destruir(n->izqda)
	n->izqda = rama.laraiz;
	rama.laraiz->padre = NULL;
}

template<class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama)
{
	if(n->drcha != NULL)
		destruir(n->drcha);
	n->drcha = ramaa.laraiz;
	rama.laraiz->padre = NULL;
}

template<class Tbase>
void ArbolGeneral<Tbase>::clear()
{
	destruir(laraiz);
	laraiz = typename ArbolGeneral<Tbase>::Nodo();
}

template<class Tbase>
int ArbolGeneral<Tbase>::size() const
{
	return contar(laraiz);
}

template<class Tbase>
bool ArbolGeneral<Tbase>::empty() const
{
	bool vacio = true;
	if( laraiz != NULL)
		vacio = false;
	return vacio;
}
template<class Tbase>
bool ArbolGeneral<Tbase>::operator ==(const ArbolGeneral<Tbase>& v) const
{
	return equals(laraiz,v.laraiz);
}

template<class Tbase>
bool operator!= (const ArbolGeneral<Tbase>& v) const
{
	return !(*this == v);
}

template<class T>
friend std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v)
{
	v.destruir(v.laraiz);
	lee_arbol(in, v.laraiz);
	return in;
}

template<class T>
friend std::ostream& operator<< (std::ostream& out, const ArbolGeneral<T>& v)
{
	escribe_arbol(out,v.laraiz);
	return out;
}
