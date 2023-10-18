#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <iomanip>
#include <windows.h>

using namespace std;

//DECLARACION

//Variables
int OP, OP2, OP3, OP4, CP, CC, CA, CE, y=5, c;
char R[20];

//Estructuras
struct CLIENTES;
struct EMPLEADOS;
struct ARTICULOS;
struct PROVEEDORES;

//Funciones
int Buscar(int R);

//Procedimientos
void Menu();
void Submenu();
void SubmenuA();
void gotoxy(int x,int y);

//Procedimientos de Proveedores
void Agregar_P();
void Eliminar_P();
void Modificar_P();
void Buscar_P();
void Reportar_P();

//Procedimientos de Clientes
void Agregar_C();
void Eliminar_C();
void Modificar_C();
void Buscar_C();
void Reportar_C();

//Procedimiento de artículos
void Agregar_A();
void Eliminar_A();
void Modificar_A();
void Buscar_A();
void Reportar_A();
void Traslado_A();

//Procedimientos de Empleados
void Agregar_E();
void Eliminar_E();
void Modificar_E();
void Buscar_E();
void Reportar_E();

//Programa Principal
int main()
{
	setlocale(LC_ALL,"spanish");

	do 
	{
		Menu();
	}while (OP!=7);		
	
	getch();
	return 0;
}

//ESTRUCTURAS
struct PROVEEDORES
{
	char cod_p[10];
	char nombre_p[30];
	char NIT_p[10];
	char direccion_p[40];
	int telefono_p;
	bool eliminado_p;
} A_Proveedores[50];

struct CLIENTES
{
	char nombre_c[20];
	char apellido_c[15];
	char DPI_c[20];
	char direccion_c[40];
	char NIT_c[10];
	int telefono_c;
	int edad_c;
	bool eliminado_c;
} A_Clientes[50];

struct ARTICULOS
{
	char cod_a[10];
	char nombre_a[20];
	char descripcion_a[80];
	int cantidad_a;
	float pUnitario_a;
	char codP_a[10];
	bool eliminado_a;
} A_Articulos_t[100];
ARTICULOS A_Articulos_b[100];

struct EMPLEADOS
{
	char cod_e[10];
	char nombre_e[20];
	char apellido_e[20];
	char DPI_e[15];
	int telefono_e;
	bool eliminado_e;
} A_Empleados[50];

//Menú y submenú
void Menu()
{
	system("cls");
	
	cout<<"SISTEMA DE FACTURACIÓN"<<endl<<endl;
	
	cout<<"\t1. Proveedores"<<endl;
	cout<<"\t2. Clientes"<<endl;
	cout<<"\t3. Artículos"<<endl;
	cout<<"\t4. Empleados"<<endl;
	cout<<"\t5. Facturación"<<endl;
	cout<<"\t6. Reportes"<<endl;
	cout<<"\t7. Salir"<<endl<<endl;
	
	cout<<"Ingrese opción: ";
	cin>>OP;

	do
	{
		switch(OP)
		{
			case 1:	
			case 2:
				Submenu();	
			break;
			case 3:
				SubmenuA();
			break;
			case 4:
			case 5:
			case 6:
				Submenu();	
			break;
			case 7:		
				system("cls");
				cout<<"Hasta la próxima";
				getch();
			break;
			default:
				system("cls");
				cout<<"Opción inválida.";
				getch();	
			break;		
		}
	} while (OP!=7);
}

void Submenu()
{
	system("cls");
	cout<<"¿Qué desea realizar?"<<endl<<endl;
	
	cout<<"\t1. Ingreso"<<endl;
	cout<<"\t2. Eliminación"<<endl;
	cout<<"\t3. Modificación"<<endl;
	cout<<"\t4. Búsquedas"<<endl;
	cout<<"\t5. Reportes"<<endl;
	cout<<"\t6. Volver a menú principal"<<endl<<endl;
	
	cout<<"Ingrese opción: ";
	cin>>OP2;

	switch(OP2)
	{
		case 1:
			if (OP==1)
				Agregar_P();
			else if (OP==2)
				Agregar_C();
			else if (OP==4)
				Agregar_E();
			else if (OP==5){
				system("cls");
				cout<<"Agregar Factura";
				getch();	}
			else if (OP==6){
				system("cls");
				cout<<"Agregar reporte";
				getch();	}
		break;
		case 2:
			if (OP==1)
				Eliminar_P();
			else if (OP==2)
				Eliminar_C();
			else if (OP==4)
				Eliminar_E();
			else if (OP==5){
				system("cls");
				cout<<"Eliminar Factura";
				getch();	}
			else if (OP==6){
				system("cls");
				cout<<"Eliminar reporte";
				getch();	}
		break;
		case 3:
			if (OP==1)
				Modificar_P();
			else if (OP==2)
				Modificar_C();
			else if (OP==4)
				Modificar_E();
			else if (OP==5){
				system("cls");
				cout<<"Modificar Factura";
				getch();	}
			else if (OP==6){
				system("cls");
				cout<<"Modificar reporte";
				getch();	}
		break;
		case 4:
			if (OP==1)
				Buscar_P();
			else if (OP==2)
				Buscar_C();
			else if (OP==4)
				Buscar_E();
			else if (OP==5){
				system("cls");
				cout<<"Buscar Factura";
				getch();	}
			else if (OP==6){
				system("cls");
				cout<<"Buscar reporte";
				getch();	}
		break;
		case 5:
			if (OP==1)
				Reportar_P();
			else if (OP==2)
				Reportar_C();
			else if (OP==4)
				Reportar_E();
			else if (OP==5){
				system("cls");
				cout<<"Reporte de Factura";
				getch();	}
			else if (OP==6){
				system("cls");
				cout<<"Reporte de reporte";
				getch();	}
		break;
		case 6:
			Menu();
		break;
		default:
			system("cls");
			cout<<"Opción inválida.";
			getch();		
		break;	
	}
}

void SubmenuA()
{
	system("cls");
	cout<<"¿Qué desea realizar?"<<endl<<endl;
	
	cout<<"\t1. Ingreso"<<endl;
	cout<<"\t2. Eliminación"<<endl;
	cout<<"\t3. Modificación"<<endl;
	cout<<"\t4. Búsqueda"<<endl;
	cout<<"\t5. Reporte"<<endl;
	cout<<"\t6. Traslado"<<endl;
	cout<<"\t7. Volver a menú principal"<<endl<<endl;
	
	cout<<"Ingrese opción: ";
	cin>>OP2;

	switch(OP2)
	{
		case 1:
			Agregar_A();
		break;
		case 2:
			system("cls");
			cout<<"Eliminar artículos";
			getch();
		break;
		case 3:
			system("cls");
			cout<<"Modificar artículos";
			getch();
		break;
		case 4:
			system("cls");
			cout<<"Buscar artículos";
			getch();		
		break;
		case 5:
			system("cls");
			cout<<"Reporte de artículos";
			getch();	
		break;
		case 6:
			Traslado_A();
		break;
		case 7:
			Menu();
		break;
		default:
			system("cls");
			cout<<"Opción inválida";
			getch();
		break;
	}
}


//PROCEDIMIENTOS Y FUNCIONES
void gotoxy(int x,int y){  
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos; 
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

int Buscar(char R[20])
{
	bool encontrado = false;
	int i = 0;

	if (OP==1)
	{
		while (i<CP && !encontrado)
		{
			if ((strcmp(A_Proveedores[i].cod_p, R)==0) && (!A_Proveedores[i].eliminado_p))
				encontrado = true;
				
			else
				i++;
		}	
	}	

	else if (OP==2)
	{
		while (i<CC && !encontrado)
		{
			if ((strcmp(A_Clientes[i].NIT_c, R)==0) && (!A_Clientes[i].eliminado_c))
				encontrado = true;
				
			else 
				i++;
		}	
	}
	
	else if (OP==3)
	{
		while (i<CA && !encontrado)
		{
			if ((strcmp(A_Articulos_t[i].cod_a, R)==0) && (!A_Articulos_t[i].eliminado_a)) 
				encontrado=true;
			else if ((strcmp(A_Articulos_t[i].nombre_a, R)==0) && (!A_Articulos_t[i].eliminado_a))
				encontrado=true;
			else 
				i++;
		}	
	}
	
	else if (OP==4)
	{
		while (i<CE && !encontrado)
		{
			if ((strcmp(A_Empleados[i].cod_e, R)==0) && (!A_Empleados[i].eliminado_e))
				encontrado = true;
				
			else 
				i++;
		}	
	}
	
	if (encontrado)
		return i;
	
	else 
		return -1;
}

int BuscarP(char R[10])
{
	bool encontrado = false;
	int i = 0;
	
	while (i<CP && !encontrado)
	{
		if ((strcmp(A_Proveedores[i].cod_p, R)==0) && (!A_Proveedores[i].eliminado_p))
			encontrado = true;
		else
			i++;
	}
	
	if (encontrado)
		return i;
		
	else 
		return -1;
}


void Agregar_P()
{
	system("cls");
	fflush(stdin);
	cout<<"\tAGREGAR PROVEEDOR"<<endl<<endl;
	cout<<"Código de proveedor: ";
	cin>>R;	
	
	int P = Buscar(R);	
	
	if (P == -1)
	{
		strcpy(A_Proveedores[CP].cod_p, R);
		
		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(A_Proveedores[CP].nombre_p, 30, '\n');
		cout<<"NIT: ";
		cin.getline(A_Proveedores[CP].NIT_p, 10, '\n');
		cout<<"Dirección: ";
		cin.getline(A_Proveedores[CP].direccion_p, 40, '\n');	
		cout<<"Teléfono: ";
		cin>>A_Proveedores[CP].telefono_p;

		A_Proveedores[CP].eliminado_p = false;
		
		CP++;	
		getch();		
	}

	else 
	{
		system("cls");
		cout<<"Proveedor ya existente.\nPor favor, inténtelo de nuevo."<<endl<<endl;
		getch();	
	}	
}

void Agregar_C()
{		
	system("cls");
	fflush(stdin);
	cout<<"\tAGREGAR CLIENTES"<<endl<<endl;
	cout<<"NIT: ";
	cin>>R;	
	
	int P = Buscar(R);	
	
	if (P == -1)
	{
		strcpy(A_Clientes[CC].NIT_c, R);
		
		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(A_Clientes[CC].nombre_c, 20, '\n');
		cout<<"Apellido: ";
		cin.getline(A_Clientes[CC].apellido_c, 15, '\n');
		cout<<"Dirección: ";
		cin.getline(A_Clientes[CC].direccion_c, 40, '\n');
		cout<<"DPI: ";
		cin>>A_Clientes[CC].DPI_c;	
		cout<<"Teléfono: ";
		cin>>A_Clientes[CC].telefono_c;
		cout<<"Edad: ";
		cin>>A_Clientes[CC].edad_c;
		
		A_Clientes[CC].eliminado_c = false;
		
		CC++;	
		getch();		
	}

	else 
	{
		system("cls");
		cout<<"Cliente ya existente.\nPor favor, inténtelo de nuevo."<<endl<<endl;
		getch();	
	}
}

void Agregar_A()
{
	system("cls");
	cout<<"\tAGREGAR ARTÍCULO"<<endl<<endl;
	fflush(stdin);
	cout<<"\nCódigo: ";
	cin>>R;
	
	int P = Buscar(R);
			
	if (P==-1)
	{
		strcpy(A_Articulos_b[CA].cod_a, R);
		strcpy(A_Articulos_t[CA].cod_a, R);
		fflush(stdin);
		cout<<"\nNombre: ";
		cin>>R;
		
		int p = Buscar(R);
		
		if (p==-1)
		{
			strcpy(A_Articulos_b[CA].nombre_a, R);			
			strcpy(A_Articulos_t[CA].nombre_a, R);
			fflush(stdin);
			cout<<"Descripción: ";
			cin.getline(A_Articulos_b[CA].descripcion_a, 80, '\n');
			strcpy(A_Articulos_t[CA].descripcion_a, A_Articulos_b[CA].descripcion_a);
			cout<<"Precio Unitario: Q. ";
			cin>>A_Articulos_b[CA].pUnitario_a;
			A_Articulos_t[CA].pUnitario_a = A_Articulos_b[CA].pUnitario_a;
			cout<<"\nIngrese código de proveedor: ";
			cin>>R;
		
			int b = BuscarP(R);
						
			if (b==-1)
			{
				system("cls");
				cout<<"Proveedor no existente.\nPor favor, inténtelo de nuevo.";
				getch();
			}
			else
			{
				strcpy(A_Articulos_b[CA].codP_a, R);
				strcpy(A_Articulos_t[CA].codP_a, R);
				cout<<"Cantidad: ";
				cin>>c;
				do
				{
					system("cls");
					cout<<"\n¿Dónde desea almacenar el artículo?"<<endl<<endl;
					cout<<"1. Bodega"<<endl;
					cout<<"2. Tienda"<<endl;
					cin>>OP3;
			
					if (OP3==1)
						A_Articulos_b[CA].cantidad_a+=c;
					
					else if (OP3==2)
						A_Articulos_t[CA].cantidad_a+=c;
						
					else 
						cout<<endl<<"Porfavor, ingrese una opción válida."<<endl;
						
				} while ((OP3!=1) && (OP3!=2));
				CA++;
				getch();
			}			
		}
		else 
		{
			system("cls");
			cout<<"Nombre existente"<<endl;
			cout<<"Nombre de articulo no coincide con código de articulo.\nPor favor, inténtelo de nuevo.";
			getch();
		}
	}
	else
	{
		cout<<"Nombre del artículo: "<<A_Articulos_b[P].nombre_a<<endl;
		cout<<"Descripción: "<<A_Articulos_b[P].descripcion_a<<endl;
		cout<<"Precio Unitario: "<<A_Articulos_b[P].pUnitario_a<<endl;
		cout<<"Código de proveedor: "<<A_Articulos_b[P].codP_a<<endl;
		cout<<"\nIngrese cantidad a almacenar: ";
		cin>>c;
				
		do
		{
			system("cls");
			cout<<"\n¿Dónde desea almacenar el artículo?"<<endl<<endl;
			cout<<"1. Bodega"<<endl;
			cout<<"2. Tienda"<<endl;
			cin>>OP3;
		
			if (OP3==1)
				A_Articulos_b[P].cantidad_a+=c;
				
			else if (OP3==2)
				A_Articulos_t[P].cantidad_a+=c;
					
			else 
			{
				cout<<endl<<"Porfavor, ingrese una opción válida."<<endl;
				getch();	
			}		
		} while ((OP3!=1) && (OP3!=2));	
		getch();
	}
}

void Agregar_E()
{	
	system("cls");
	cout<<"\tAGREGAR EMPLEADOS"<<endl<<endl;
	fflush(stdin);
	cout<<"Código de empleado: ";
	cin>>R;	
	
	int P = Buscar(R);
	
	if (P==-1)
	{
		strcpy(A_Empleados[CE].cod_e, R);
		
		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(A_Empleados[CE].nombre_e, 20, '\n');
		cout<<"Apellido: ";
		cin.getline(A_Empleados[CE].apellido_e, 20, '\n');	
		cout<<"DPI: ";
		cin>>A_Empleados[CE].DPI_e;
		cout<<"Teléfono: ";
		cin>>A_Empleados[CE].telefono_e;
		
		A_Empleados[CE].eliminado_e = false;
		
		CE++;	
		getch();
	}
	
	else 
	{
		system("cls");
		cout<<"Empleado ya existente.\nPor favor, inténtelo de nuevo."<<endl;
		getch();
	}
}

void Eliminar_P()
{
	system("cls");
	
	cout<<"ELIMINAR PROVEEDOR"<<endl<<endl;
	cout<<"Ingrese código del proveedor a eliminar: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nProveedor no encontrado";
		getch();
	}
	
	else 
	{
		A_Proveedores[P].eliminado_p = true;
		cout<<"\nProveedor eliminado."<<endl<<endl;
		getch();
	}
}

void Eliminar_C()
{
	system("cls");
	
	cout<<"ELIMINAR CLIENTE"<<endl<<endl;
	cout<<"Ingrese NIT del cliente a eliminar: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nCliente no encontrado";
		getch();
	}
	
	else 
	{
		A_Clientes[P].eliminado_c = true;
		cout<<"\nCliente eliminado."<<endl<<endl;
		getch();
	}
}

void Eliminar_E()
{
	system("cls");
	
	cout<<"ELIMINAR EMPLEADO"<<endl<<endl;
	cout<<"Ingrese código de empleado: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nEmpleado no encontrado";
		getch();
	}
	else 
	{
		A_Empleados[P].eliminado_e = true;
		cout<<"\nEmpleado eliminado."<<endl<<endl;
		getch();
	}
}

void Modificar_P()
{
	system("cls");
	
	cout<<"\tMODIFICAR PROVEEDOR"<<endl<<endl;
	cout<<"Ingrese código del proveedor a modificar: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nProveedor no encontrado";
		getch();
	}
	else 
	{
		cout<<"Ingrese los nuevos datos"<<endl<<endl;
		cout<<"Código del proveedor: ";
		cin>>R;
		
		int p = Buscar(R);
		
		if (p == -1)
		{
			strcpy(A_Proveedores[P].cod_p, R);
			fflush(stdin);
			cout<<"Nombre: ";
			cin.getline(A_Proveedores[P].nombre_p, 30, '\n');
			cout<<"NIT: ";
			cin.getline(A_Proveedores[P].NIT_p, 10, '\n');
			cout<<"Dirección: ";
			cin.getline(A_Proveedores[P].direccion_p, 40, '\n');	
			cout<<"Teléfono: ";
			cin>>A_Proveedores[P].telefono_p;			
		}
		
		else
		{
			cout<<endl<<"Proveedor ya existente.\nPor favor, inténtelo de nuevo."<<endl;
			getch();
		}
	}
}

void Modificar_C()
{
	system("cls");
	
	cout<<"\tMODIFICAR CLIENTE"<<endl<<endl;
	cout<<"Ingrese NIT del cliente a modificar: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nCliente no encontrado";
		getch();
	}
	else
	{
		cout<<"\nIngrese los nuevos datos: "<<endl<<endl;
		cout<<"NIT: ";
		cin>>R;
		
		int p = Buscar(R);
		if (p==-1)
		{
			strcpy(A_Clientes[P].NIT_c, R);
			fflush(stdin);
			cout<<"Nombre: ";
			cin.getline(A_Clientes[P].nombre_c, 20, '\n');
			cout<<"Apellido: ";
			cin.getline(A_Clientes[P].apellido_c, 15, '\n');
			cout<<"Dirección: ";
			cin.getline(A_Clientes[P].direccion_c, 40, '\n');
			cout<<"DPI: ";
			cin>>A_Clientes[P].DPI_c;
			cout<<"Teléfono: ";
			cin>>A_Clientes[P].telefono_c;
			cout<<"Edad: ";
			cin>>A_Clientes[P].edad_c;		
		}
		
		else 
		{
			cout<<endl<<"Cliente ya existente, según NIT.\nPor favor, inténtelo de nuevo."<<endl;
			getch();
		}
	}
}

void Modificar_E()
{
	system("cls");
	
	cout<<"\tMODIFICAR EMPLEADO"<<endl<<endl;
	cout<<"Ingrese código de empleado a modificar: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nEmpleado no encontrado";
		getch();
	}
	
	else
	{
		cout<<"\nIngrese los nuevos datos: "<<endl<<endl;
		cout<<"Código de empleado: ";
		cin>>R;
		
		int p = Buscar(R);
		if (p == -1)
		{
			strcpy(A_Empleados[P].cod_e, R);
			fflush(stdin);
			cout<<"Nombre: ";
			cin.getline(A_Empleados[P].nombre_e, 20, '\n');
			cout<<"Apellido: ";
			cin.getline(A_Empleados[P].apellido_e, 20, '\n');	
			cout<<"DPI: ";
			cin>>A_Empleados[P].DPI_e;
			cout<<"Teléfono: ";
			cin>>A_Empleados[P].telefono_e;		
		}
		
		else 
		{
			cout<<endl<<"Empleado ya existente.\nPor favor, inténtelo de nuevo."<<endl;
			getch();
		}
	}	
}

void Buscar_P()
{
	system("cls");
	
	cout<<"BUSCAR PROVEEDOR"<<endl<<endl;
	cout<<"Ingrese código de proveedor: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"Proveedor no encontrado";
		getch();
	}
	
	else
	{
		cout<<"Los datos del proveedor son: "<<endl<<endl;
		cout<<"Código No. "<<A_Proveedores[P].cod_p<<endl;
		cout<<"Nombre: "<<A_Proveedores[P].nombre_p<<endl;
		cout<<"NIT: "<<A_Proveedores[P].NIT_p<<endl;
		cout<<"Dirección: "<<A_Proveedores[P].direccion_p<<endl;
		cout<<"Teléfono: "<<A_Proveedores[P].telefono_p<<endl;
		getch();
	}
}

void Buscar_C()
{
	system("cls");
	
	cout<<"BUSCAR CLIENTE: "<<endl<<endl;
	cout<<"Ingrese No. NIT del cliente: ";
	cin>>R;
	
	int P = Buscar(R);	
	
	if (P == -1)
	{
		cout<<"\nCliente no encontrado";
		getch();
	}
	
	else 
	{
		cout<<"\nLos datos del cliente son: "<<endl<<endl;
		cout<<"Nombre: "<<A_Clientes[P].nombre_c<<endl;
		cout<<"Apellido: "<<A_Clientes[P].apellido_c<<endl;
		cout<<"DPI: "<<A_Clientes[P].DPI_c<<endl;
		cout<<"NIT: "<<A_Clientes[P].NIT_c<<endl;
		cout<<"Dirección: "<<A_Clientes[P].direccion_c<<endl;
		cout<<"Teléfono: "<<A_Clientes[P].telefono_c<<endl;
		cout<<"Edad: "<<A_Clientes[P].edad_c<<endl;
		getch();		
	}
}

void Buscar_E()
{
	system("cls");
	
	cout<<"BUSCAR EMPLEADO: "<<endl<<endl;
	cout<<"Ingrese código de empleado: ";
	cin>>R;
	
	int P = Buscar(R);	
	
	if (P == -1)
	{
		cout<<"\nEmpleado no encontrado";
		getch();
	}
	
	else 
	{
		cout<<"\nLos datos del empleado son: "<<endl<<endl;
		cout<<"Código de empleado: "<<A_Empleados[P].cod_e<<endl;
		cout<<"Nombre: "<<A_Empleados[P].nombre_e<<endl;
		cout<<"Apellido: "<<A_Empleados[P].apellido_e<<endl;
		cout<<"DPI: "<<A_Empleados[P].DPI_e<<endl;
		cout<<"Teléfono: "<<A_Empleados[P].telefono_e<<endl;
		getch();		
	}
}

void Reportar_P()
{
	y = 5;
	system("cls");
	
	cout<<"\n\tREPORTE DE Proveedores"<<endl<<endl;
	
	gotoxy(0,3); cout<<"Código Proveedor";
	gotoxy(20,3); cout<<"Nombre";
	gotoxy(55,3); cout<<"NIT";	
	gotoxy(70,3); cout<<"Teléfono";
	gotoxy(85,3); cout<<"Dirección";
	
	for (int i=0; i<CP; i++)
	{
		if (!A_Proveedores[i].eliminado_p)
		{
			gotoxy(0,y); cout<<A_Proveedores[i].cod_p;
			gotoxy(20,y); cout<<A_Proveedores[i].nombre_p;
			gotoxy(55,y); cout<<A_Proveedores[i].NIT_p;
			gotoxy(70,y); cout<<A_Proveedores[i].telefono_p;
			gotoxy(85,y); cout<<A_Proveedores[i].direccion_p<<endl;
			y++;	
		}
	}
	getch();	
}

void Reportar_C()
{
	y = 5;
	system("cls");
	
	cout<<"\n\tREPORTE DE CLIENTES"<<endl<<endl;
	
	gotoxy(0,3); cout<<"Nombre";
	gotoxy(20,3); cout<<"Apellido";
	gotoxy(35,3); cout<<"DPI";
	gotoxy(55,3); cout<<"NIT";
	gotoxy(68,3); cout<<"Teléfono";
	gotoxy(80,3); cout<<"Edad";
	gotoxy(86,3); cout<<"Dirección";
	
	
	for (int i=0; i<CC; i++)
	{
		if (!A_Clientes[i].eliminado_c)
		{
			gotoxy(0,y); cout<<A_Clientes[i].nombre_c;
			gotoxy(20,y); cout<<A_Clientes[i].apellido_c;
			gotoxy(35,y); cout<<A_Clientes[i].DPI_c;
			gotoxy(55,y); cout<<A_Clientes[i].NIT_c;
			gotoxy(68,y); cout<<A_Clientes[i].telefono_c;
			gotoxy(80,y); cout<<A_Clientes[i].edad_c<<endl;
			gotoxy(86,y); cout<<A_Clientes[i].direccion_c;
			y++;	
		}
	}
	getch();
}

void Reportar_E()
{
	y = 5;
	system("cls");
	
	cout<<"\n\tREPORTE DE EMPLEADOS"<<endl<<endl;

	gotoxy(0,3); cout<<"Código Empleado";	
	gotoxy(20,3); cout<<"Nombre";
	gotoxy(45,3); cout<<"Apellido";
	gotoxy(70,3); cout<<"DPI";
	gotoxy(85,3); cout<<"Teléfono";
	
	for (int i=0; i<CE; i++)
	{
		if (!A_Empleados[i].eliminado_e)
		{
			gotoxy(0,y); cout<<A_Empleados[i].cod_e;
			gotoxy(20,y); cout<<A_Empleados[i].nombre_e;
			gotoxy(45,y); cout<<A_Empleados[i].apellido_e;
			gotoxy(70,y); cout<<A_Empleados[i].DPI_e;
			gotoxy(85,y); cout<<A_Empleados[i].telefono_e;
			y++;	
		}
	}
	getch();	
}

void Traslado_A()
{
	system("cls");
	cout<<"\tTRASLADO DE ARTICULOS"<<endl<<endl;
	
	cout<<"Ingrese código de artículo: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P==-1)
	{
		system("cls");
		cout<<"El artículo no existe. Por favor, inténtelo de nuevo.";
		getch();
	}
	else
	{
		cout<<"\n\nTraslado de "<<A_Articulos_t[P].nombre_a<<endl;
		cout<<"Cantidad existente: "<<endl;
		cout<<"Tienda: "<<A_Articulos_t[P].cantidad_a<<endl<<"Bodega: "<<A_Articulos_b[P].cantidad_a<<endl<<endl;
	
		cout<<"\tTRASLADO "<<endl;
		cout<<"1. De Bodega a Tienda"<<endl;
		cout<<"2. De Tienda a Bodega"<<endl;
		cout<<"Ingrese el traslado que desea realizar: ";
		cin>>OP4;
		
		switch (OP4)
		{
			case 1:
				cout<<"\nIngrese la cantidad a trasladar: ";
				cin>>c;
				
				if (A_Articulos_b[P].cantidad_a>=c)
				{
					A_Articulos_b[P].cantidad_a-=c;	
					A_Articulos_t[P].cantidad_a+=c;	
				}
				else if (A_Articulos_b[P].cantidad_a<c)
				{
					system("cls");
					cout<<"\nNo hay suficientes articulos existentes para realizar la transacción"<<endl;
					cout<<"Por favor, inténtelo de nuevo.";
					getch();
				}
				else if (c<=0)
				{
					system("cls");
					cout<<"Cantidad inválida.\nPor favor, inténtelo de nuevo.";
					getch();
				}
			break;
			case 2:	
				cout<<"\nIngrese la cantidad a trasladar: ";
				cin>>c;
				
				if (A_Articulos_t[P].cantidad_a>=c)
				{
					A_Articulos_t[P].cantidad_a-=c;	
					A_Articulos_b[P].cantidad_a+=c;	
				}
				else if (A_Articulos_t[P].cantidad_a<c)
				{
					system("cls");
					cout<<"\nNo hay suficientes articulos existentes para realizar la transacción"<<endl;
					cout<<"Por favor, inténtelo de nuevo.";
					getch();
				}
				else if (c<=0)
				{
					system("cls");
					cout<<"Cantidad inválida.\nPor favor, inténtelo de nuevo.";
					getch();
				}
			break;
			default:
				system("cls");
				cout<<"Opción inválida.";
				getch();
			break;
		}
	}
}
