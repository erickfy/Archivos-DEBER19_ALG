#include <iostream>
using namespace std;
#include <fstream>//LIBRERIA PARA TRABAJAR O ALMACENAR ARCHIVOS
#include <string>//Para ingresar los caracteres o nombres;
#include <stdlib.h>
int entrada_de_datos();
int pantalla();

int main() 
{
  int opcion;
  while(opcion!=3)
  {
    cout << "\n=================================\n";
    cout << "\n1.- Ingresar Datos del usuario\n";
    cout << "\n2.- Visuzalizar datos del sistema\n";
    cout << "\n3.-Salir\n\n";
    cout << "Elija la opcion: ";cin >> opcion;
    cout << "\n=================================\n";

    switch(opcion)//sin break para que se repita el ciclo.
    {
      case 1:
      entrada_de_datos();
      case 2:
      pantalla();
      case 3:
      cout << "\nSalio del sistema\n\nGracias por preferirnos, vuelva pronto!";
    }
  }
  return 0;
}

int entrada_de_datos()
{
  char r;
  int edad;
  ofstream archivodatos;//creando un nuevo almacen de archivos
  string nombre, apellido; //entradas para el caracter en especial.
  do
  {
    system("cls");
    archivodatos.open("Datos.txt",ios::out|ios::app);//abriendo el almacen de archivos "del nombre" y utilizar el mismo nombre puesto.

    cout << "\n===============\n";
    cout << "Ingrese el Nombre: "; 
    cin >> nombre;
    
    cin.ignore(' ', '\n'); //elmina datos exedidos para no provocar el bucle infinito.
    cout << "Ingrese el Apellido: ";
    cin >> apellido;
    cin.ignore(' ', '\n');
    cout << "Ingrese su edad: ";
    cin >> edad;
    archivodatos<< "Nombre: " << nombre << "\n";
    archivodatos <<"Apellido: " << apellido << "\n";
    archivodatos << "Edad: " << edad <<"\n\n";
    cout << "Desea ingresar mas datos?(s/n): ";
    cin >> r;

    archivodatos.close(); //cerrando el almacen de archivos "del nombre" 
  }while(r=='s'); //proseguir con el bucle cuando sea la condición.
  return main();
}

int pantalla()
{
  string nombre,apellido;
  int edad;
  system("cls");
  ifstream archivodatos; //ifstream para leer el archivo con el mismo nombre del archivo que se guarda.
  string texto;
  archivodatos.open("Datos.txt",ios::in); //"in" para lectura. Poner el mismo nombre del archivo creado para abrirlo.
  while(!archivodatos.eof())
  {
    getline(archivodatos,texto);
    cout  << texto << endl ;
  }
  return main();
}