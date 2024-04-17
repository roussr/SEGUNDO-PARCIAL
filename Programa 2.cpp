#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//************************************************************************************************************************************************
void leer(ifstream &Lec) {
    system("cls");
    
		struct empleadoinicial{
			string nombre, apellido;
	  		int edad, salario;
		}em;
		
	Lec.open("Empleados.txt", ios::in);
	
	if (Lec.is_open()){ //para que no se cre un ciclo infinito
	
        cout << "---------------Cartera de Empleados-------------------" << endl << endl;
        
		Lec >> em.nombre;
		
        while (!Lec.eof()) {
        	
        	Lec >> em.apellido;
			Lec >> em.edad;
			Lec >> em.salario;
			cout <<"Nombre del Empleado: "<< em.nombre<<endl;
			cout <<"Apellido del Empleado: "<<em.apellido<<endl;
			cout <<"Edad del Empleado: "<<em.edad<<endl;
			cout <<"Salario del Empleado:  Q."<< em.salario<<endl;
            cout << "----------------------------------------------------" << endl;
            
            Lec >> em.nombre;
        }
    Lec.close();
	}else
		cout<<"Error al ejecutar el archivo..."<<endl;
    system("pause");
}
//-----------------------------------------------------------------------------------------------------------------------------
void buscar(ifstream &Lec){
	system("cls");
	Lec.open("Flores.txt", ios::in);
	struct busqueda{
			string nombre,nomaux, apellido;
	  		int edad, salario;
		}b;
		
	bool encontrado=false;
	cout<<"Ingrese el nombre de la flor que desea buscar: ";
	cin>> b.nomaux;
	Lec >> b.nombre;
	while(!Lec.eof() && !encontrado){// ciclo ya no se recorre cuando se encuentra el dato buscado
		Lec >> b.apellido;
		Lec >> b.edad;
		Lec >> b.salario;

		if(b.nombre== b.nomaux){
			cout <<"Nombre del Empleado: "<< b.nombre<<endl;
			cout <<"Apellido del Empleado: "<<b.apellido<<endl;
			cout <<"Edad del Empleado: "<<b.edad<<endl;
			cout <<"Salario del Empleado:  Q."<< b.salario<<endl;
            cout << "----------------------------------------------------" << endl;
            encontrado =true;
		}
		Lec >> b.nombre;
	}
	Lec.close();
	if (!encontrado)
	
	cout<<"Empleado no encontrada."<<endl;
	
	system ("pause");
	
}
//****************************************************************************************************************************
//menu
int menu(){ 
	int x;
	system("cls");
	cout << "--------------Menu de opciones--------------" << endl;
        cout << "Seleccione una de las siguientes opciones:" << endl;
        cout << " 1. LEER" << endl;
        cout << " 2. BUSCAR" << endl;
        cout << " 3. SALIR" << endl;
        cout << endl;
		
		cout << "Elija una opcion: "; cin >> x;
		
		return x;
}

int main() {

    ofstream Esc; //declaracion de archivo
    ifstream Lec;
    int op;
    do{
    	
    	system("cls");
    	
    	op=menu();
		
			switch (op) { //op es el parametro de nuestro switch

		            
		        case 1:
		        	
		        	system("cls");
		        	leer(Lec);
		        	break;
		        	
		        case 2:
		        	
		        	system("cls");
		        	buscar(Lec);
		        	break;	
		        	
		

			}
	}while (op !=3);
	
	return 0;

}

//************************************************************************************

