#include<iostream>
#include<vector>
#include<random>
#include <time.h>

using namespace std;

/*Función para imprimir el vector.*/
void Imprimir_Vector(vector<int>Array_Numeros, int Tamano, int estado) {
	if (estado == 0) { //Usamos el estado para no reutilizar la función imprimir así quitamos lineas de código.
		cout << "----------------------" << endl;
		cout << "Vector Desordenado" << endl;
		cout << "----------------------" << endl;
		for (int i = 0; i < Tamano; i++) {
				cout << Array_Numeros.at(i) << " ";
		}
		cout << endl;
	}
	if (estado == 1) {
		cout << "----------------------" << endl;
		cout << "Vector Ordenado" << endl;
		cout << "----------------------" << endl;
		for (int i = 0; i < Tamano; i++) {
			if (i == Tamano - 1) {
				cout << Array_Numeros.at(i)<<endl;
			}
			else
			{
				cout << Array_Numeros.at(i) << " < ";
			}
		}
	}
}

/*Función de ordenamiento "Insert sort"*/
void Insertion_Sort(vector<int>Array_Numeros,int Tamano) {
	int Clave = 0; 
	int i = 0;
	for (int j= 1; j < Tamano; j++)
	{
		Clave = Array_Numeros.at(j);
		i = j - 1;
		while (i >= 0 && Array_Numeros.at(i) > Clave) {
			Array_Numeros.at(i + 1) = Array_Numeros.at(i);
			i = i - 1;
		}
		Array_Numeros.at(i + 1) = Clave;
	}
	Imprimir_Vector(Array_Numeros, Tamano,1); //Función para imprimir el vector ordenado. 
}

/* Función para insertar en el vector los números aleatorios. */
void Insertar_Numero_Aleatorio(vector<int>Array_Numeros,int Tamano) {
	
	int Numero_Aleatorio = 0; 

	for (int i = 0; i < Tamano; i++) {
		Numero_Aleatorio = rand() % 100;  //Generar número aleatorio.
		Array_Numeros.push_back(Numero_Aleatorio); //Insertar en el vector.
	}
	Imprimir_Vector(Array_Numeros, Tamano,0); //Función para imprimir el vector desordenado.
	Insertion_Sort(Array_Numeros, Tamano); //Función de ordenamiento "Insert sort".
}


int main() {
	int Tamano = 0; //Declaramos esta variable para definir el tamaño del vector.
	vector<int>Array_Numeros; //Declaramos el vector que vamos a insertar los numeros.

	cout << "Introducir tamano de array" << endl; 
	cin >> Tamano;
	clock_t start = clock(); //Utilizamos esta función para iniciar el tiempo de la ejecución del programa.
	Insertar_Numero_Aleatorio(Array_Numeros,Tamano); //Función para insertar en el vector los números aleatorios.
	cout<<"Milisegundos: "<<(((double)clock() - start) / CLOCKS_PER_SEC)*1000<<endl; //Muestra del tiempo de ejecución del programa.
	system("Pause");
}

