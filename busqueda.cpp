#include <iostream>
#include <vector>
#include <time.h>
#include "counter.cpp"
/*
@author Rafael Rios
@version 2.0 since 1.0

this class was done as a homework for the algorithm and data structure class in c++
*/
class Busqueda{
public:
	template <typename T> int sequencial(std::vector <T> elementos, int valor){
		int size = elementos.size();
		for (int i = 0; i < size; ++i){
			if (elementos[i] == valor){
				return i;
			}
		}
		return -1;
	}
	template <typename T> int sequencialConM(std::vector <T> elementos, int valor){

		int size = elementos.size();

		for(int posicion = 0; posicion < size; posicion++){

			if (elementos[posicion] == valor){
				elementos.erase(elementos.begin()+posicion);
				elementos.insert(elementos.begin(), valor);
				return posicion;
			}

		}
		return -1;

	}

	template <typename T> int sequencialConT(std::vector <T> elementos, int valor){
		int size = elementos.size();
		

		for(int posicion = 0; posicion < size; posicion++){
			if (elementos[posicion] == valor){
				int primero = elementos[0];

				//insertar valor encontrado
				elementos.erase(elementos.begin());

				//eliminar primer valor
				elementos.insert(elementos.begin(), valor);
				

				elementos.insert(elementos.begin()+posicion, primero);
				elementos.erase(elementos.begin()+posicion+1);

				return posicion;
			}
		}
		return -1;
		
	}

	template <typename T> int sequencialConO(std::vector <T> elementos, int valor){
		
		std::sort(elementos.begin(), elementos.end()); 
		
		int posicion = 0;
		int size = elementos.size();

		while(true){
			
			if (elementos[posicion] ==  valor){
				return posicion;
			}

			else if ((elementos[posicion] > valor) || posicion >= size){
				return -1;
			}

			posicion++;
		}
	}

	template <typename T> int binaria(std::vector<T> elementos, int valor){

		//ordenar vector
		std::sort(elementos.begin(), elementos.end()); 
		bool encontrado = false;

		int final = elementos.size()-1;
		int start = 0;
		int medio = final/2;

		while (true){
			if (elementos[medio] == valor){
				return medio;
			}
			else if(medio == start || medio == final){
				return -1;
			}
			else if (elementos[medio] < valor){
				start = medio;
				if (final - start == 1){
					medio += 1;
				}
				else{
					medio = (final + start) / 2;
				}
			}

			else if (elementos[medio] > valor){
				final = medio;
				if (final - start == 1){
					medio -= 1;
				}
				else{
					medio = (final + start) / 2;
				}
			}
		}

	}
 

	std::vector<int> creador( int val){
		std::vector<int> numeros;

		srand(time(0));
		for (int i = 0; i < val; ++i){
			numeros.push_back(rand() % (100000) + 1);
		}
		return numeros;
	}

	
};

int main(){
	tiempo();
	Busqueda busqueda;
	int numero = 1;
	std::vector<int> lista;

	lista = busqueda.creador(100000);
	
	std::cout << busqueda.sequencial(lista, numero) << std::endl;
	//std::cout << busqueda.sequencialConM(lista, numero) << std::endl;
	//std::cout << busqueda.sequencialConT(lista, numero) << std::endl;
	//std::cout << busqueda.sequencialConO(lista, numero) << std::endl;
	//std::cout << busqueda.binaria(lista, numero) << std::endl;
	return 0;
}