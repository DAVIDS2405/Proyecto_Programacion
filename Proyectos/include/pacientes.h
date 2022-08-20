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
void Guardar_Pac(const tLista &lista);
void Leer_Pac(tPacientes &pacientes);
void Insertar_Pac(tLista &lista, tPacientes &pacientes, bool &ok);
void Eliminar_Pac(tLista &lista, int pos, bool &ok);
string NombreCompleto(tPacientes &pacientes);
void Mostrar_Pac(tPacientes &pacientes);
void Listado_Pac(const tLista &lista);
void Ordenamiento_Pac(int ordenamiento[], int contador);
void Buscar_Pac(tLista &lista, string nombreBuscar, bool &ok);
