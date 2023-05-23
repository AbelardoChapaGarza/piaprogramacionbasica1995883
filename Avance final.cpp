#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include<math.h>
using namespace std;
struct Tienda
{
	float precio;
	int año, total, numarticulo, preciouni, impuesto;
	string videojuego, consola, descripcion, clasif, status, caract, nombre, genero, articulo;
};

int contador, alta;
Tienda *VIDEOJUEGO;
void Alta();
void lista();
void eliminar();
void modificar();
void archivos();

int main()
{
	int opc;
	
	printf("\t ****Bienvenido a la tienda de VIDEOJUEGOS**** \n");
	printf("1.-Alta de viedojuegos\n 2.-Lista de videojuego\n 3.-Eliminar Videojuego\n 4.-Modificacion de Videojuegos\n 5.-Limpiar pantalla\n 6.-salir\n");
	scanf_s("%d", &opc);

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;
		
	case 2:
		lista();
		return main();
		break;

	case 3:
		eliminar();
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		system("cls");
		return main();
		break;

	case 6:
		archivos();
		break;

	}
}
void Alta()
{
	printf("Cuantos videojuegos desea ordenar? \n");
	scanf_s("%d", &alta);
	VIDEOJUEGO = new Tienda[alta];
	for (int i = 0; i < alta; i++)
	{
		printf("Introdusca el num del articulo\n");
		scanf_s("%d", &VIDEOJUEGO[i].numarticulo);
		while (getchar() != '\n');
		printf("introdusca el nombre del Videojuego\n");
		getline(cin, VIDEOJUEGO[i].nombre);
		printf("introdusca el a%co en el que salio\n", 164);
		scanf_s("%d", &VIDEOJUEGO[i].año);
		printf("indique la clasificacion\n");
		scanf_s("%d", &VIDEOJUEGO[i].clasif);
		printf("ingrese del genero del videojuego\n");
		cin. ignore();
		getline(cin, VIDEOJUEGO[i].genero);
		printf("ingrese una breve descripcion del videojuego\n");
		cin.ignore();
		getline(cin, VIDEOJUEGO[i].descripcion);
		printf("ingrese la consola para el que lo desea\n");
		cin.ignore();
		getline(cin, VIDEOJUEGO[i].consola);
		printf("ingrese el precio del videojuego\n");
		scanf_s("%f", &VIDEOJUEGO[i].precio);
		VIDEOJUEGO[i].impuesto = VIDEOJUEGO[i].precio * .16;
		printf("el impuesto es: %f\n");
		VIDEOJUEGO[i].total = VIDEOJUEGO[i].precio + VIDEOJUEGO[i].impuesto;
	}
}
void lista()
{
	for (int i = 0; i < alta; i++)
	{
	
		if (VIDEOJUEGO[i].status == "ELIMINADO")
		{
			printf("VIDEOJUEGO ELIMINADO\n", i + 1);
		}
		else
		{
			printf(" ***/registro de Videojuego***\n", i + 1);
			printf("numero de articulo &d\n",VIDEOJUEGO[i].numarticulo);
			printf("%nombre del  videojuego %s\n", VIDEOJUEGO[i].nombre.c_str());
			printf("a%co de lanzamiento %d\n",164, VIDEOJUEGO[i].año);
			printf("clasificacion %d\n", VIDEOJUEGO[i].clasif);
			printf("caracteristicas %s\n", VIDEOJUEGO[i].caract);
			printf("descripcion %s\n", VIDEOJUEGO[i].descripcion.c_str());
			printf("genero %d\n", VIDEOJUEGO[i].genero);
			printf("precio unitario %f\n", VIDEOJUEGO[i].preciouni);
			printf("consola %s\n", VIDEOJUEGO[i].consola.c_str());
			printf("impuesto %d\n", VIDEOJUEGO[i].impuesto);
			printf("total %d\n", VIDEOJUEGO[i].total);
		}
	
		
	}
}
void eliminar()
{
	int j;
	printf("Ingrese el videojuego a eliminar\n");
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando videojuego\n", j + 1);
		VIDEOJUEGO[i].status = "ELIMINADO";

	}
}
void modificar()
{
	int j, opcion, op2;
	do
	{
		printf("ingrese el videojuego a cambiar");
		scanf_s("%d", &j);
		j = j - 1; 

		for (int i = j; i == j; i++)
		{
			if ((VIDEOJUEGO[i].status == "ELIMINADO"))
			{
				printf("VIDEOJUEGO ELIMINADO\n", i + 1);
				printf("ingrese un videojuego valido \n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf("ingrese el videojuego que desea cambiar \n");
	scanf_s("%d", &opcion);
	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			
			printf("Ingrese num del articulo\n");
			scanf_s("%f", VIDEOJUEGO[i].articulo);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("ingrese el nombre del videojuego\n");
			getline(cin, VIDEOJUEGO[i].nombre);
		}
		break;
	case 3:
		for (int i = j; i == j; i++)
		{
			printf("");
		}
	}
	
	
		

}
void archivos()
{
	ofstream archivo;
	string nombrearchivo;
	int texto;
	string texto2;

	nombrearchivo = "tiendavideojuegos.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO\n");
		exit(1);
	}
	archivo << "ARTICULO";
	archivo << "JUEGO";
	archivo << "A%cO DE SALIDA", 165;
	archivo << "CLASIFICACION";
	archivo << "CARACTERISTICAS";
	archivo << "DESCRIPCIÓN";
	archivo << "PRECIO UNITARIO";
	archivo << "IMPUESTO";
	archivo << "TOTAL";

	for (int i = 0; i < alta; i++)
	{
		if (VIDEOJUEGO[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i;
			archivo << texto2 << texto << "\n";

		}

		archivo.close();
	}
}

