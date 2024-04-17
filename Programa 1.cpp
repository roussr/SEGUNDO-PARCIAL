#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Declaracion de clase
class Empleado {
	// Declaracion de parametros de manera privada
private:
    string nombre, apellido;
	  int edad, salario;

public:
    // Constructor con parámetros
    Empleado(string nom, string apell, int ed, int sal): nombre (nom), apellido (apell), edad (ed), salario(sal){}


//****************************************************************************************************************************
//voids

void guardar(ofstream &es) { // archivo por referencia
	system("cls");
		struct empleadoinicial{
			string nombre, apellido;
	  		int edad, salario;
		}e;
		es.open("Empleados.txt", ios::out |ios::app);

		cout << "Nombre del Empleado: "; 
		cin >> e.nombre;
		cout << "Apellido del Empleado: ";
		cin >> e.apellido;
		cout <<"Edad del Empleado: ";
		cin >> e.edad;
		cout <<"Salario del Empleado:  Q.";
		cin >> e.salario;
		es<<e.nombre<<"\n"<<e.apellido<<"\n"<<e.edad<<"\n"<<e.salario<<"\n";
		
		es.close();		//cierre de archivo
}

//-----------------------------------------------------------------------------------------------------------------------------
void eliminar(ifstream &Lec){
		system("cls");
		struct elim{
			string 	nom, nomaux, nombre, apellido, apelaux, edad, edaux, salario, salaux;
			float pre, preaux;
		}e;
		
	Lec.open("Empleados.txt", ios::in);
	ofstream aux("Auxiliar.txt", ios::out |ios::app);
	if(Lec.is_open()){
		cout <<"Ingrese el nombre del empleado que desea eliminar: ";
		cin >> e.nomaux;
		
		Lec >> e.nombre;
	while(!Lec.eof() ){// ciclo ya no se recorre cuando se encuentra el dato buscado
		Lec >> e.apellido;
		Lec >> e.edad;
		Lec >> e.salario;
		if(e.nom== e.nomaux){
			cout << "El empleado seleccionado se elimino correctamente: ";
				system ("pause");
            
		}else
		
		aux<<e.nombre<<"\n"<<e.apellido<<"\n"<<e.edad<<"\n"<<e.salario<<"\n";
		
		
			Lec >> e.nombre;
	}
	Lec.close();
	aux.close();

	system ("pause");
		
	}else
			cout<<"Error al ejecutar el archivo"<<endl;
		remove ("Empleados.txt");
    	rename("auxiliar.txt", "Empleados.txt");
}

//****************************************************************************************************************************
//menu
int menu(){ 
	int x;
	system("cls");
	cout << "--------------Menu de opciones--------------" << endl;
        cout << "Seleccione una de las siguientes opciones:" << endl;
        cout << " 1. GUARDAR" << endl;
        cout << " 2. ELIMINAR" << endl;
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
		            guardar(Esc);
		            break;
		            
				
				case 2:
		        	
		        	system("cls");
		        	eliminar(Lec);
		        	break;		

			}
	}while (op !=3);
	
	return 0;

};
	return Empleado;
};

//************************************************************************************
