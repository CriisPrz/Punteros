#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//Este programa almacena los datos de n alumnos mediante una clase, y el uso de estructura.Examen

class universidad
{

public:
universidad ();
~universidad ();
void leer ();
void imprimir ();
void guardar ();
void cargar ();
int prsn;

private:

struct datos
{
char nombre[32];
char apellido[32];
long int cod;
float cal1,cal2,cal3,prom;
};
datos dat[30];


};
universidad::universidad ()
{
cout<<"\tUniversidad Mariano Galvez de Guatemala"<<endl;
cout<<"PRSN ingresa el numero de Alumnos para guardar : ";
cin>>prsn;


}
universidad::~universidad ()
{}
void universidad::leer ()
{
for(int i=0; i<prsn; i++)
{



cout<<"\n\tNombre del Alumno: \n"<<endl;
cin.ignore(100,'\n');
cin.getline(dat[i].nombre,32);
cout<<"\n\tApellido: \n"<<endl;
cin>>dat[i].apellido;
cout<<"\n\tCodigo: \n"<<endl;
cin>>dat[i].cod;
cout<<"\n\tPrimer Calificacion: \n"<<endl;
cin>>dat[i].cal1;
cout<<"\n\tSegunda Calificacion: \n"<<endl;
cin>>dat[i].cal2;
cout<<"\n\tTercera Calificacion: \n"<<endl;
cin>>dat[i].cal3;

}
return;

}


void universidad::imprimir()
{
for(int i=0; i<prsn; i++)
{

cout<<"Los datos del Alumno son los siguentes:"<<endl
<<"\t\tNombre: "<<dat[i].nombre<<endl
<<"\t\tCodigo: "<<dat[i].cod<<endl
<<"\t\tApellido: "<<dat[i].apellido<<endl
<<"\t\tPrimera calificacion: "<<dat[i].cal1<<endl
<<"\t\tSegunda calificacion: "<<dat[i].cal2<<endl
<<"\t\tTercera calificacion: "<<dat[i].cal3<<endl
<<"\t\tPromedio final: "<<dat[i].prom<<endl;

if(dat[i].prom>=6)
{
cout<<"\t\nNOTA: El Alumno tiene un promedio aprobatorio, es un nene inteligente\n\n"<<endl;
}
else
{
cout<<"\t\nNOTA: El Alumno tiene un promedio reprobatorio RECURSAMIENTO OBLIGATORIO\n\n"<<endl;
}
}
return;

}

void universidad::guardar()
{
const int MAXCARACTERES=15;
char nombrearchivo[MAXCARACTERES]="registro.dat";
ofstream archivo_sale;
archivo_sale.open(nombrearchivo);
if(archivo_sale.fail())
{

cout<<"El archivo no se abrio exitosamente"<<endl;
exit(1);
}
for (int i=0; i<prsn; i++)
{
archivo_sale<<dat[i].nombre<<"\n"
<<dat[i].apellido<<"\n"
<<dat[i].cod<<"\n"

;}
archivo_sale.close();
cout<<"Los datos fueron guardados correctamente en"<<nombrearchivo<<endl;
system("PAUSE");
return;
}
void universidad::cargar()
{

const int MAXCARACTERES=15;
char nombrearchivo[MAXCARACTERES]="registro.dat";
ifstream archivo_entra;
archivo_entra.open(nombrearchivo);
if (!archivo_entra)
{

cout<<"El archivo"<<nombrearchivo<<"no se abrio exitosamente \n verifique si existe"<<endl;
system("PAUSE");
exit(1);
}
cout<<"Los datos del registro de alumno son:";
for (int i=0; i<prsn; i++)
{

archivo_entra>>dat[i].nombre;
cout<<"Nombre del alumno: "<<dat[i].nombre<<endl;
archivo_entra>>dat[i].apellido;
cout<<"Apellido: "<<dat[i].apellido<<endl;
archivo_entra>>dat[i].cod;
cout<<"Codigo: "<<dat[i].cod<<endl;


}
system("PAUSE");
return;
}
int main ()
{

universidad datos;


system ("CLS");

if(datos.prsn>30)
{
cout<<"ERROR SOBRE CUPO DE ALUMNOS VOY A MORIR XD \n Maximo pueden ser 30 alumnos asi que introduce un num maximo a 30"<<endl;
}
else
{


datos.leer();

datos.guardar();

system("CLS");

datos.imprimir();


cout<<"Los datos cargados desde el archivo:"<<endl;

datos.cargar();


}


system ("PAUSE");
return 0;
}


