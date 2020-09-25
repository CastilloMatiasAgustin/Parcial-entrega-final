#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "menues.h"
#include "Usuario.h"
using namespace std;

///PROTOTIPOS
void listarpersonas();
/*int almacenopromedio (int promedio);*/
int listadoentrepesos (int pesomax,int pesomen);
void mostrarpersonas (persona reg);
///FIN PROTOTIPOS A partir del ingreso de un peso mínimo y un peso máximo, listar el apellido y nombres de todos los usuarios que se encuentren dentro de ese rango.
///REPORTE 1:
void reporte1()
 {
int pesomax,pesomen;
   system ("cls");
   cout<< "Bienvenido ingrese un peso minimo "<<endl;
   cin>>pesomen;
   cout<<"Ingrese un peso maximo"<<endl;
   cin>>pesomax;
   listadoentrepesos (pesomax,pesomen);

}
int listadoentrepesos (int may, int men)
{
    system ("cls");
    persona reg;
    FILE *p;
    p=fopen("personas.dat","rb");
    if (p==NULL) {
        cout<<" Error en el archivo"<<endl;
        return -1;
    }
    while (fread(&reg, sizeof reg,1,p)==1)
    {
        if (reg.kg>men && reg.kg<may)
        {
            mostrarpersonas (reg);
        }
    }
    fclose (p);
    cin.get();
    return 0;
}

void mostrarpersonas (persona reg)
{
    FILE *p;
    p=fopen("personas.dat","rb");
    if (p==NULL) {
        cout<<"Error de archivo"<<endl;
    }
    while (fread(&reg,sizeof reg,1,p)==1) {
        cout<< "Apellidos: ";
        cout<< reg.apellidos<<endl;
        cout<< "Nombres: ";
        cout<< reg.nombre<<endl;
        cout<<endl<<endl;
        }
        cin.get();
        fclose (p);
}

/*///REPORTE 2: Por cada usuario, listar los Apellidos y nombres y el promedio de tiempo de actividad.
void reporte2()
{
    system ("cls");
    prototipo reg;
    reg=entrenamientos leerregistroentrenamientos(int pos);
    almacenopromedio (reg.promedio);



}

int almacenopromedio(int promedio)
{


}
*/

#endif // PROTOTIPO_H_INCLUDED
