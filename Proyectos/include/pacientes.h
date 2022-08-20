#include <string>
using namespace std;
const int MAX_PACIE = 30;

typedef struct{
    string nombrePAC;
    string apellidoPAC;
    string edadPAC;
    string cedulaPAC;
}tPacientes;

typedef struct{
    tPacientes elementos[MAX_PACIE];
    int contador = 0;
}tLista;

int Menu_Pac();
void Cargar_Pac(tLista &lista, bool &ok);
void guardar(const tLista &lista);
void leerPacientes(tPacientes &pacientes);
void insertarEstudiante(tLista &lista, tPacientes &pacientes, bool &ok);
void eliminarEstudiante(tLista &lista, int pos, bool &ok);
string nombreCompleto(tPacientes &pacientes);
void mostrarEstudiante(tPacientes &pacientes);
void listado(const tLista &lista, double media, int mayor);
