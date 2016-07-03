#include<iostream>
#include<vector>
#include<random>
#include <time.h>

using namespace std;

/*Funci�n para imprimir el vector.*/
void Imprimir_Vector(vector<int>Array_Numeros, int Tamano, int estado) {
	if (estado == 0) { //Usamos el estado para no reutilizar la funci�n imprimir as� quitamos lineas de c�digo.
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

/*Funci�n de ordenamiento "Insert sort"*/
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
	Imprimir_Vector(Array_Numeros, Tamano,1); //Funci�n para imprimir el vector ordenado. 
}

/* Funci�n para insertar en el vector los n�meros aleatorios. */
void Insertar_Numero_Aleatorio(vector<int>Array_Numeros,int Tamano) {
	
	int Numero_Aleatorio = 0; 

	for (int i = 0; i < Tamano; i++) {
		Numero_Aleatorio = rand() % 100;  //Generar n�mero aleatorio.
		Array_Numeros.push_back(Numero_Aleatorio); //Insertar en el vector.
	}
	Imprimir_Vector(Array_Numeros, Tamano,0); //Funci�n para imprimir el vector desordenado.
	Insertion_Sort(Array_Numeros, Tamano); //Funci�n de ordenamiento "Insert sort".
}


int main() {
	int Tamano = 0; //Declaramos esta variable para definir el tama�o del vector.
	vector<int>Array_Numeros; //Declaramos el vector que vamos a insertar los numeros.

	cout << "Introducir tamano de array" << endl; 
	cin >> Tamano;
	clock_t start = clock(); //Utilizamos esta funci�n para iniciar el tiempo de la ejecuci�n del programa.
	Insertar_Numero_Aleatorio(Array_Numeros,Tamano); //Funci�n para insertar en el vector los n�meros aleatorios.
	cout<<"Milisegundos: "<<(((double)clock() - start) / CLOCKS_PER_SEC)*1000<<endl; //Muestra del tiempo de ejecuci�n del programa.
	system("Pause");
}

