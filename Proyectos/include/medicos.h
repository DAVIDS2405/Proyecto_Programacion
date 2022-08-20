#include <string>
using namespace std;
const int MAX_DOCS = 30;

typedef struct{
    string nombreMED;
    string apellidoMED;
    string edadMED;
    string especialidad;
    string cedula;
}tDoctores;

typedef struct{
    tDoctores elementos[MAX_DOCS];
    int contador = 0;
}tLista;

//PROTOTIPOS DE LAS FUNCIONES PARA LOS MÉDICOS
int MenuDoctores();
void CargarDoctores(tLista &lista, bool& ok);
void GuardarDoctores(const tLista &lista);
void LeerDoctor(tDoctores &doctores);
void InsertarDoctor(tLista &lista, tDoctores doctor, bool &ok);
void EliminarDoctor(tLista &lista, int pos, bool &ok);
string NombreCompleto(tDoctores doctor);
void MostrarDoctor(tDoctores doctor);
void ListadoDoctores(const tLista &lista);
void OrdenarDoctores(tLista &lista);
