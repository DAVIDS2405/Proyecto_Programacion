#ifndef Medicos_h
#define Medicos_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "medicos.h"
using namespace std;

int MenuDoctores(){

    int op = 0;
    while ((op < 1) || (op > 7))
    {
        cout << setw(41) << " --------------------------------------------" << endl;
        cout << "|" << setw(30) << "Menu Doctores" << setw(15) << "|" << endl;
        cout << "|" << setw(41) << "1 - Agregar un nuevo doctor" << setw(4) << "|" << endl;
        cout << "|" << setw(36) << "2 - Eliminar un doctor" << setw(9) << "|" << endl;
        cout << "|" << setw(38) << "3 - Ordenar los doctores" << setw(7) << "|" << endl;
        cout << "|" << setw(36) << "4 - Consultar doctores" << setw(9) << "|" << endl;
        cout << "|" << setw(34) << "5 - Modificar doctor" << setw(11) << "|" << endl;
        cout << "|" << setw(32) << "6 - Mostrar doctor" << setw(13) << "|" << endl;
        cout << "|" << setw(42) << "7 - Salir del menu doctores" << setw(3) << "|" << endl;
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
}/// FIN DE LA FUNCIÓN MENU DE DOCTORES


void CargarDoctores(tListaDoc &listadoc, bool &okdoc){

    tDoctores doctor;
    ifstream archivo_lec;
    char aux = ' ';
    listadoc.contadorDoc = 0;
    archivo_lec.open("Medicos.txt",ios::in);

    if( !archivo_lec.is_open() ){
        okdoc = false;

    }else{
        okdoc = true;

        getline(archivo_lec, doctor.cedula);
        doctor.cedula = doctor.cedula.substr(0,10);

          while( (doctor.cedula != "XXX")&&(listadoc.contadorDoc < MAX_DOCS)  ){

              getline(archivo_lec, doctor.nombreMED);
              getline(archivo_lec, doctor.apellidoMED);
              archivo_lec >> doctor.edadMED;
              archivo_lec.get(aux);
              getline(archivo_lec, doctor.especialidad);
              listadoc.elementosDoc[listadoc.contadorDoc] = doctor;
              listadoc.contadorDoc++;
              getline(archivo_lec, doctor.cedula);
              doctor.cedula = doctor.cedula.substr(0,10);

          }


          archivo_lec.close();
    }//fin del else principal





}/// FIN DE LA FUNCIÓN Cargar DOCTORES


void GuardarDoctores(const tListaDoc &listadoc){

    ofstream archivo_esc;
    archivo_esc.open("Medicos.txt",ios::out);

    for(int i = 0; i < listadoc.contadorDoc; i++){

        archivo_esc <<listadoc.elementosDoc[i].cedula<<endl;
        archivo_esc <<listadoc.elementosDoc[i].nombreMED<<endl;
        archivo_esc <<listadoc.elementosDoc[i].apellidoMED<<endl;
        archivo_esc <<listadoc.elementosDoc[i].edadMED<<endl;
        archivo_esc <<listadoc.elementosDoc[i].especialidad<<endl;

    }

    archivo_esc<<"XXX"<<endl;
    archivo_esc.close();

}///FIN DE LA FUNCION GUARDAR DOCTORES


void LeerDoctor(tDoctores &doctores){

    cin.sync();
    cout <<"Ingrese la cedula del doctor: ";
    getline(cin, doctores.cedula);
    for(int i = 0; i < doctores.cedula.size(); i++){
        if(doctores.cedula[i] != '1' && doctores.cedula[i] != '2' &&doctores.cedula[i] != '3' &&doctores.cedula[i] != '4'
        &&doctores.cedula[i] != '5' &&doctores.cedula[i] != '6' &&doctores.cedula[i] != '7'
        &&doctores.cedula[i] != '8' &&doctores.cedula[i] != '9' &&doctores.cedula[i] != '0' ){
          cout <<"Ingrese la cedula del doctor: ";
          getline(cin, doctores.cedula);
        }
    }
    cout <<"Ingrese el nombre del doctor: ";
    getline(cin, doctores.nombreMED);
    cout <<"Ingrese el apellido del doctor: ";
    getline(cin, doctores.apellidoMED);
    cout <<"Ingrese la especialidad del doctor: ";
    getline(cin, doctores.especialidad);
    cout << "Ingrese la edad del doctor: ";
    cin >> doctores.edadMED;
    if(doctores.edadMED < 1){
      cout << "Ingrese la edad del doctor: ";
      cin >> doctores.edadMED;
    }
    cin.sync();
}///FIN DE LA FUNCIÓN LEER DOCTOR


void InsertarDoctor(tListaDoc &listadoc, tDoctores doctor, bool &okdoc){

    okdoc = true;
    if( listadoc.contadorDoc == MAX_DOCS){
        okdoc = false;

    }else{
        listadoc.elementosDoc[listadoc.contadorDoc] = doctor;
        listadoc.contadorDoc++;
    }



}///FIN DE LA FUNCIÓN INSERTAR DOCTOR


void EliminarDoctor(tListaDoc &listadoc, int pos, bool &okdoc){

    cout <<endl;
    if( pos < 0 || pos > listadoc.contadorDoc-1 ){
        okdoc = false;

    }else{

        okdoc = true;

        for(int i = pos; i < listadoc.contadorDoc-1; i++){
            listadoc.elementosDoc[i] = listadoc.elementosDoc[i+1];
        }

      listadoc.contadorDoc--;
    }

}/// FIN DE LA FUNCIÓN ELIMINAR DOCTOR


//NOMBRE COMPLETOS
string NombreCompleto(tDoctores doctor)
{
     return doctor.nombreMED + " " + doctor.apellidoMED;
}


//ORDENAR
void Ordenamiento_Doctores(tListaDoc &lista)
{
    for (int i = 1; i < lista.contadorDoc; i++)
    {
        int pos = i;
        while ((pos > 0) && (lista.elementosDoc[pos - 1].cedula > lista.elementosDoc[pos].cedula))
        {
            tDoctores aux;
            aux = lista.elementosDoc[pos];
            lista.elementosDoc[pos] = lista.elementosDoc[pos - 1];
            lista.elementosDoc[pos - 1] = aux;
            pos--;
        }
    }
    cout << "Lista ordenada por cedula: " << endl;
    ListadoDoctores(lista);
    GuardarDoctores(lista);
}
//BUSCAR
void Buscar_Doctores(tListaDoc &listadoc, string CedulaBuscar, bool &okdoc)
{
    tListaDoc listaBus = listadoc;
    okdoc = false;
    int i = 0;

    while ((okdoc == false) && (i < listadoc.contadorDoc))
    {
        if (listadoc.elementosDoc[i].cedula == CedulaBuscar)
        {
            okdoc = true;
            cout <<"Datos del doctor"<<endl;
            cout << "Nombre: " << NombreCompleto(listadoc.elementosDoc[i]) << endl;
            cout << "Edad: " << listaBus.elementosDoc[i].edadMED << endl;
            cout << "Cedula: " << listaBus.elementosDoc[i].cedula << endl;
            cout << "Especialidad: "<<listaBus.elementosDoc[i].especialidad<<endl;

        }
        i++;
    }

    if (okdoc == false)
    {
        cout << "La cedula ingresada no corresponde a ningun medico" << endl;
    }
}

void MostrarDoctor(tDoctores doctor){


      cout <<"Nombre del doctor: " << NombreCompleto(doctor)<< endl;
      cout << "Edad del doctor: " << doctor.edadMED << endl;
      cout << "Cedula del doctor: " << doctor.cedula << endl;
      cout << "Especialidad del doctor: "<< doctor.especialidad<<endl;


}///FIN DE LA FUNCION MOSTRAR Doctor


void ListadoDoctores(tListaDoc listadoc){
  string linea(50, '-');
  for (int i = 0; i < listadoc.contadorDoc; i++)
  {
      cout <<linea<<endl;
      cout << setw(3) << right << i + 1 << ": "<<endl;
      MostrarDoctor(listadoc.elementosDoc[i]);
      cout <<linea<<endl<<endl;
  }



}///FIN DE LA FUNCIÓN LISTADO DOCTORES

void ModificarDoctores(tListaDoc &listadoc, string CedulaBuscar){
    bool encontradoPE = false;
    int indice = 0;
    for(int i = 0; i < listadoc.contadorDoc && encontradoPE == false; i++){

        if(listadoc.elementosDoc[i].cedula == CedulaBuscar){
           indice = i;
           encontradoPE = true;

        }else{
          indice++;
        }

    }


    if(encontradoPE){
        cout <<"Ingrese los nuevos datos para el doctor"<<endl;
        LeerDoctor(listadoc.elementosDoc[indice]);
    }


}//FIN DE LA FUNCIÓN MODIFICAR DOCTORES

#endif
