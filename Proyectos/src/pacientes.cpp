#ifndef pacientes_h
#define pacientes_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#include "pacientes.h"

int Menu_Pac()
{
    int op = 0;
    while ((op < 1) || (op > 7))
    {
        cout << setw(41) << " --------------------------------------------" << endl;
        cout << "|" << setw(30) << "Menu Pacientes" << setw(15) << "|" << endl;
        cout << "|" << setw(41) << "1 - Agregar un nuevo paciente" << setw(4) << "|" << endl;
        cout << "|" << setw(36) << "2 - Eliminar un paciente" << setw(9) << "|" << endl;
        cout << "|" << setw(37) << "3 - Ordenar los pacientes" << setw(8) << "|" << endl;
        cout << "|" << setw(35) << "4 - Consultar pacientes" << setw(10) << "|" << endl;
        cout << "|" << setw(35) << "5 - Modificar pacientes" << setw(10) << "|" << endl;
        cout << "|" << setw(33) << "6 - Mostrar pacientes" << setw(12) << "|" << endl;
        cout << "|" << setw(40) << "7 - Salir del menu pacientes" << setw(5) << "|" << endl;
        cout << setw(41) << " --------------------------------------------" << endl;
        cout << setw(10) << " Ingrese la opcion deseada: ";
        cin >> op;
        cin.ignore();
        if ((op < 1) || (op > 7))
        {
            cout << "Opcion no valida ingresar un numero valido" << endl;
        }
    }
    return op;
}
// CARGAR
void Cargar_Pac(tLista &lista, bool &ok)
{
    tPacientes pacientes;
    ifstream archivo;
    char aux;

    lista.contador = 0;
    archivo.open("pacientes.txt");
    if (!archivo.is_open())
    {
        ok = false;
    }
    else
    {
        ok = true;

        getline(archivo, pacientes.cedulaPAC);
        while ((pacientes.cedulaPAC != "XXX") && (lista.contador < MAX_PACIE))
        {
            getline(archivo, pacientes.nombrePAC);
            getline(archivo, pacientes.apellidoPAC);
            archivo >> pacientes.edadPAC;
            archivo.get(aux);
            lista.elementos[lista.contador] = pacientes;
            lista.contador++;
            getline(archivo, pacientes.cedulaPAC);
        }
        archivo.close();
    }
}
// GUARDAR
void Guardar_Pac(const tLista &lista)
{
    ofstream archivo;

    archivo.open("pacientes.txt");
    for (int i = 0; i < lista.contador; i++)
    {

        archivo << lista.elementos[i].cedulaPAC << endl;
        archivo << lista.elementos[i].nombrePAC << endl;
        archivo << lista.elementos[i].apellidoPAC << endl;
        archivo << lista.elementos[i].edadPAC << endl;
    }
    archivo << "XXX" << endl;
    archivo.close();
}
// LEER
void Leer_Pac(tPacientes &pacientes)
{
    cin.sync();
    cout << "Cedula: ";
    getline(cin, pacientes.cedulaPAC);
    for(int i = 0; i < pacientes.cedulaPAC.size(); i++){
        if(pacientes.cedulaPAC[i] != '1' && pacientes.cedulaPAC[i] != '2' &&pacientes.cedulaPAC[i] != '3' &&pacientes.cedulaPAC[i] != '4'
        &&pacientes.cedulaPAC[i] != '5' &&pacientes.cedulaPAC[i] != '6' &&pacientes.cedulaPAC[i] != '7'
        &&pacientes.cedulaPAC[i] != '8' &&pacientes.cedulaPAC[i] != '9' &&pacientes.cedulaPAC[i] != '0' ){
          cout << "Cedula: ";
          getline(cin, pacientes.cedulaPAC);
        }
    }
    cout << "Nombre: ";
    getline(cin, pacientes.nombrePAC);
    cout << "Apellidos: ";
    getline(cin, pacientes.apellidoPAC);
    cout << "Edad: ";
    cin >> pacientes.edadPAC;
    if(pacientes.edadPAC < 1){
      cout << "Edad: ";
      cin >> pacientes.edadPAC;
    }
    cin.sync();
}
// INSERTAR
void Insertar_Pac(tLista &lista, tPacientes &pacientes, bool &ok)
{

    ok = true;
    if (lista.contador == MAX_PACIE)
    {
        ok = false;
    }
    else
    {
        lista.elementos[lista.contador] = pacientes;
        lista.contador++;
    }
}
// ELIMINAR
void Eliminar_Pac(tLista &lista, int pos, bool &ok)
{
    if ((pos < 0) || (pos > lista.contador - 1))
    {
        ok = false;
    }
    else
    {
        ok = true;
        for (int i = pos; i < lista.contador - 1; i++)
        {
            lista.elementos[i] = lista.elementos[i + 1];
        }
        lista.contador--;
    }
}
// NOMBRE COMPLETO
string NombreCompleto(tPacientes pacientes)
{
    return pacientes.nombrePAC + " " + pacientes.apellidoPAC;
}
void Mostrar_Pac(tPacientes pacientes)
{

    cout << "Nombre del paciente: " << NombreCompleto(pacientes)<<endl;
    cout << "Cedula del paciente: " << pacientes.cedulaPAC<< endl;
    cout << "Edad del paciente: " << pacientes.edadPAC<< endl;

}
// LISTADO
void Listado_Pac(tLista lista)
{
    string linea(50,'-');
    for (int i = 0; i < lista.contador; i++)
    {
        cout <<linea<<endl;
        cout << setw(3) << right << i + 1 << ": "<<endl;
        Mostrar_Pac(lista.elementos[i]);
        cout << linea<<endl<<endl;
    }
}
// ORDENAR
void Ordenamiento_Pac(tLista &lista)
{

    for (int i = 1; i < lista.contador; i++)
    {
        int pos = i;
        while ((pos > 0) && (lista.elementos[pos - 1].cedulaPAC > lista.elementos[pos].cedulaPAC))
        {
            tPacientes aux;
            aux = lista.elementos[pos];
            lista.elementos[pos] = lista.elementos[pos - 1];
            lista.elementos[pos - 1] = aux;
            pos--;
        }
    }
    cout << "Lista ordenada por cedula: " << endl;
    Listado_Pac(lista);
    Guardar_Pac(lista);

}
// BUSCAR
void Buscar_Pac(tLista &lista, string CedulaBuscar, bool &ok)
{
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
//MODIFICAR
void ModificarPac(tLista &lista, string CedulaBuscar)
{
    bool encontradoPA = false;
    int indice = 0;
    for(int i = 0; i < lista.contador && encontradoPA == false; i++){

        if(lista.elementos[i].cedulaPAC == CedulaBuscar){
           indice = i;
           encontradoPA = true;

        }else{
          indice++;
        }

    }


    if(encontradoPA){
        cout <<"Ingrese los nuevos datos para el paciente"<<endl;
        Leer_Pac(lista.elementos[indice]);
    }


}
#endif
