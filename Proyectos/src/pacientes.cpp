#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "pacientes.h"
using namespace std;


int Menu_Pac(){
    int op = 0;
    while ((op < 1) || (op > 6))
    {
        cout << setw(41) << " --------------------------------------------" << endl;
        cout << "|" << setw(30) << "Menu Pacientes" << setw(15) << "|" << endl;
        cout << "|" << setw(24) << "1 - Agregar un nuevo paciente" << setw(21) << "|" << endl;
        cout << "|" << setw(25) << "2 - Eliminar un paciente" << setw(20) << "|" << endl;
        cout << "|" << setw(25) << "3 - Ordenar los pacientes" << setw(20) << "|" << endl;
        cout << "|" << setw(23) << "4 - Consultar pacientes" << setw(22) << "|" << endl;
        cout << "|" << setw(23) << "5 - Modificar pacientes" << setw(22) << "|" << endl;
        cout << "|" << setw(23) << "6 - Salir del menu pacientes" << setw(22) << "|" << endl;
        cout << setw(41) << " --------------------------------------------" << endl;

        cout << setw(10) << " Ingrese la opcion deseada: ";
        cin >> op;
        cin.ignore();
        if ((op < 1) || (op > 6))
        {
            cout << "Opcion no valida ingresar un numero valido" << endl;
        }
    }
    return op;
}
void Cargar_Pac(tLista &lista, bool &ok)
{
  tPacientes pacientes;
   ifstream archivo;
   char aux;
   
   lista.contador = 0; // Inicializamos la lista
   archivo.open("pacientes.txt");
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      ok = true;
      archivo >> pacientes.cedulaPAC;
      while ((pacientes.cedulaPAC != "-1") && (lista.contador < MAX_PACIE)) {
         getline(archivo, pacientes.nombrePAC);
         getline(archivo, pacientes.apellidoPAC);
         archivo >> pacientes.edadPAC;
         archivo.get(aux); 
         lista.elementos[lista.contador] = pacientes; 
         lista.contador++; 
         archivo >> pacientes.cedulaPAC; // Siguiente nombre
      } 
      archivo.close();
   }
}
void Guardar_Pac(const tLista &lista)
{
   ofstream archivo;

   archivo.open("pacientes.txt");
   for (int i = 0; i < lista.contador; i++) {
      archivo << lista.elementos[i].cedulaPAC << endl;
      archivo << lista.elementos[i].nombrePAC << endl;
      archivo << lista.elementos[i].apellidoPAC << endl;
      archivo << lista.elementos[i].edadPAC << endl;
   }
   archivo << "-1" << endl; // Centinela 
   archivo.close();
}
void Leer_Pac(tPacientes &pacientes)
{
cin.sync(); // Para descar cualquier entrada pendiente
   cout << "Cedula: ";
   cin >> pacientes.cedulaPAC;
   cout << "Nombre: ";
   getline(cin, pacientes.nombrePAC);
   cout << "Apellidos: ";
   getline(cin, pacientes.apellidoPAC);
   cout << "Edad: ";
   cin >> pacientes.edadPAC;
cin.sync(); 

}
void Insertar_Pac(tLista &lista, tPacientes &pacientes, bool &ok)
{

   ok = true;
   if (lista.contador == MAX_PACIE) {
      ok = false;
   }
   else {
      lista.elementos[lista.contador] = pacientes;
      // Insertamos al final de la lista
      lista.contador++;
   }

}
void Eliminar_Pac(tLista &lista, int pos, bool &ok)
{
       if ((pos < 0) || (pos > lista.contador - 1)) {
      ok = false; // En caso que no existan elementos en la lista
   }
   else {
      ok = true; 
      for (int i = pos; i < lista.contador - 1 ; i++) {
         lista.elementos[i] = lista.elementos[i + 1];
      }
      lista.contador--;
   }
}
string NombreCompleto(tPacientes &pacientes){
    return pacientes.nombrePAC + " " + pacientes.apellidoPAC;
}
void Mostrar_Pac(tPacientes &pacientes){
    cout << "Nombre del paciente " << NombreCompleto(pacientes) << endl;
    cout << "Edad del paciente " << pacientes.edadPAC << endl;
    cout << "Cedual del paciente" << pacientes.cedulaPAC << endl;
}
void Listado_Pac(tLista lista){
    for (int i = 0; i < lista.contador; i++)
    {
        cout << setw(3) << right << i + 1 << ": ";
        Mostrar_Pac(lista.elementos[i]);
    }
}
void Ordenamiento_Pac(int ordenamiento[], int n){
    int max{0}, min{0}, aux{0}, i{0}, j{0};
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (ordenamiento[j] < ordenamiento[min])
            {
                min = j;
            }
        }
        aux = ordenamiento[i];
        ordenamiento[i] = ordenamiento[min];
        ordenamiento[min] = aux;
    }
}
void Buscar_Pac(tLista &lista, string CedulaBuscar, bool &ok){
    tLista listaBus = lista;
    ok = false;
    int i = 0;

    while ((ok == false) && (i < lista.contador))
    {
        if (lista.elementos[i].cedulaPAC == CedulaBuscar)
        {
            ok = true;
            cout << "Nombre: " << NombreCompleto(lista.elementos[i]) << endl;
            cout << "Edad: " << listaBus.elementos[i].edadPAC << endl;
            cout << "Cedula: " << listaBus.elementos[i].cedulaPAC << endl;
                }
        i++;
    }

    if (ok == false)
    {
        cout << "La cedula ingresada no corresponde a ningun paciente" << endl;
    }
}