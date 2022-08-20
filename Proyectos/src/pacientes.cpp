#include <iostream>
#include <string>
#include <iomanip>
#include "pacientes.h"
using namespace std;

void Cargar_Pac(tLista &lista, bool &ok){

}
void Guardar_Pac(const tLista &lista){

}
void Leer_Pac(tPacientes &pacientes){

}
void Insertar_Pac(tLista &lista, tPacientes &pacientes, bool &ok){

}
void Eliminar_Pac(tLista &lista, int pos, bool &ok){

}
string NombreCompleto(tPacientes &pacientes){
    return pacientes.nombrePAC + " " + pacientes.apellidoPAC;
}
void Mostrar_Pac(tPacientes &pacientes){
    cout << "Nombre del paciente " << NombreCompleto(pacientes) << endl;
    cout << "Edad del paciente " << pacientes.edadPAC << endl;
    cout << "Cedual del paciente" << pacientes.cedulaPAC << endl;
}
void Listado_Pac(const tLista lista){
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