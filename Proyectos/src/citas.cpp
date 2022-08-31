#ifndef Citas_H
#define Citas_H
#include "pacientes.h"
#include "medicos.h"
#include "citas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int Menucitas(){

  int op = 0;
  while ((op < 1) || (op > 7))
  {
      cout << setw(41) << " --------------------------------------------" << endl;
      cout << "|" << setw(26) << "Menu Citas" << setw(19) << "|" << endl;
      cout << "|" << setw(34) << "1 - Agregar una cita" << setw(11) << "|" << endl;
      cout << "|" << setw(35) << "2 - Eliminar una cita" << setw(10) << "|" << endl;
      cout << "|" << setw(35) << "3 - Ordenar las citas" << setw(10) << "|" << endl;
      cout << "|" << setw(32) << "4 - Consultar cita" << setw(13) << "|" << endl;
      cout << "|" << setw(32) << "5 - Modificar cita" << setw(13) << "|" << endl;
      cout << "|" << setw(30) << "6 - Mostrar cita" << setw(15) << "|" << endl;
      cout << "|" << setw(38) << "7 - Salir del menu citas" << setw(7) << "|" << endl;
      cout << setw(41) << " --------------------------------------------" << endl;
      cout << setw(10) << " Ingrese la opcion deseada: ";
      cin >> op;
      cin.ignore();
      cout <<endl;
      if ((op < 1) || (op > 7))
      {
          cout << "Opcion no valida ingresar un numero valido" << endl;
      }
  }
  return op;

}


void Cargar_citas(tListaC &listacita){

  ifstream  leer_archivo;
  char aux;
  listacita.contadorCit = 0;

  leer_archivo.open("Citas.txt");

  if( !leer_archivo.is_open()  ){
      cout <<"No se pudo abrir el archivo"<<endl;

  }
  else{
      leer_archivo >> listacita.elementosCitas[listacita.contadorCit].codigo_cita;
      while (listacita.elementosCitas[listacita.contadorCit].codigo_cita != -1 && listacita.contadorCit < MAX_CITAS)
      {
          leer_archivo.get(aux);
          getline(leer_archivo, listacita.elementosCitas[listacita.contadorCit].cedula);
          getline(leer_archivo, listacita.elementosCitas[listacita.contadorCit].cedulaPAC);
          leer_archivo >> listacita.elementosCitas[listacita.contadorCit].dia;
          leer_archivo >> listacita.elementosCitas[listacita.contadorCit].mes;
          leer_archivo >> listacita.elementosCitas[listacita.contadorCit].anio;
          listacita.contadorCit++;
          leer_archivo >> listacita.elementosCitas[listacita.contadorCit].codigo_cita;
        }

        leer_archivo.close();

  }

}

void Guardar_citas(const tListaC &listacita){
    ofstream archivo_pac("Citas.txt",ios::out);

    for(int i = 0; i < listacita.contadorCit; i++){
        archivo_pac << listacita.elementosCitas[i].codigo_cita<<endl;
        archivo_pac << listacita.elementosCitas[i].cedula<<endl;
        archivo_pac << listacita.elementosCitas[i].cedulaPAC<<endl;
        archivo_pac << listacita.elementosCitas[i].dia<<endl;
        archivo_pac << listacita.elementosCitas[i].mes<<endl;
        archivo_pac << listacita.elementosCitas[i].anio<<endl;
    }
    archivo_pac << -1<<endl;
    archivo_pac.close();
}

void Leer_citas(tCita & Cita){
    cin.sync();
    cout << "Ingrese el codigo de la cita: ";
    cin >> Cita.codigo_cita;
    cin.sync();
    cout << "Ingrese la cedula del doctor: ";
    getline(cin, Cita.cedula);
    cout << "Ingrese la cedula del paciente: ";
    getline(cin, Cita.cedulaPAC);
    cout << "Ingrese el dia de la cita: ";
    cin >> Cita.dia;
    cout << "Ingrese el mes de la cita: ";
    cin >> Cita.mes;
    cout << "Ingrese el año de la cita: ";
    cin >> Cita.anio;
    cin.sync();
}
void Insertar_cita(tListaC &listacita, tCita cita, bool &funca){
    funca = true;
    if (listacita.contadorCit == MAX_DOCS)
    {
        funca = false;
    }
    else
    {
        listacita.elementosCitas[listacita.contadorCit] = cita;
        listacita.contadorCit++;
    }
}


void Buscar_cita(tListaC &listacita, int codigo_buscar, bool &funca){
    for (int i = 0; i < listacita.contadorCit; i++)
    {
        if (codigo_buscar == listacita.elementosCitas[i].codigo_cita)
        {
            cout << "cita en la posicion " << i + 1 << endl;
        }
    }
}

void Eliminar_cita(tListaC &listacita, int codigo_buscar, bool &funca){
    cout << endl;
    if (codigo_buscar < 0 || codigo_buscar > listacita.contadorCit - 1)
    {
        funca = false;
    }
    else
    {

        funca = true;

        for (int i = codigo_buscar; i < listacita.contadorCit - 1; i++)
        {
            listacita.elementosCitas[i] = listacita.elementosCitas[i + 1];
        }

        listacita.contadorCit--;
    }
}

void Ordenar_cita(tListaC &listacita){
    for (int i = 1; i < listacita.contadorCit; i++)
    {
        int pos = i;
        while ((pos > 0) && (listacita.elementosCitas[pos - 1].cedula > listacita.elementosCitas[pos].cedula))
        {
            tCita aux;
            aux = listacita.elementosCitas[pos];
            listacita.elementosCitas[pos] = listacita.elementosCitas[pos - 1];
            listacita.elementosCitas[pos - 1] = aux;
            pos--;
        }
    }
    cout << "Lista ordenada por cedula del doctor: " << endl;
    ListadoCitas(listacita);
    Guardar_citas(listacita);
}

void MostrarCita(tCita cita){
    cout << "   Codigo de la cita:     " << cita.codigo_cita << endl;
    cout << "   Cedula del doctor:   " << cita.cedula << endl;
    cout << "   Cedula del paciente: " << cita.cedulaPAC << endl;
    cout << "   dia:                 " << cita.dia << endl;
    cout << "   mes:                 " << cita.mes << endl;
    cout << "   Año:                 " << cita.anio << endl;
    cout << endl;
}
void ListadoCitas(tListaC listacita){
    for (int i = 0; i < listacita.contadorCit; i++)
    {
        cout << setw(3) << right << i + 1 << ": ";
        MostrarCita(listacita.elementosCitas[i]);
    }
}

void Modificar_cita(tListaC &listacita, int codigo_buscar){
    bool encontradoPE = false;
    int indice = 0;
    for (int i = 0; i < listacita.contadorCit && encontradoPE == false; i++)
    {

        if (listacita.elementosCitas[i].codigo_cita == codigo_buscar)
        {
            indice = i;
            encontradoPE = true;
        }
        else
        {
            indice++;
        }
    }

    if (encontradoPE)
    {
        cout << "Ingrese los nuevos datos para la cita" << endl;
        Leer_citas(listacita.elementosCitas[indice]);
    }
}
#endif