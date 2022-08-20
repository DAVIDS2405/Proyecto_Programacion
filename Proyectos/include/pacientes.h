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

