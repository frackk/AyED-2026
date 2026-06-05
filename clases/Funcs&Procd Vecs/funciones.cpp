#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

//Vectores
void agregar(int arr[], int n, int& len, int v){
	if(len < n){
		arr[len] = v;
		len++;
	} else {
		cout << "El vector esta lleno" << endl;
	}
}

void mostrar(int arr[], int len){
	
	for(int i=0; i < len; i++){
		cout << arr[i] << endl;
	}
	
}

void inicializar(int arr[],int n){
	for(int i=0; i < n; i++){
		arr[i] = 0;
	}
}

int buscar(int arr[], int len, int v){
	int pos;
	int i =0;
	
	while(i < len && arr[i] != v){
		i++;
	}
	
	if(arr[i]== v){ // i != len condición alternativa
		pos = i;
	} else {
		pos = -1;
	}
	
	return pos;	
}

void eliminar(int arr[], int& len, int pos){
	
	for(int i=pos; i < len-1; i++){
		arr[i] = arr[i+1];
	}
	
	arr[len-1] = 0;
	
	len--;
}


void insertar(int arr[], int& len, int v, int pos){
	
	//for(int i = len-1; i >= pos; i--){
	//	arr[i+1] = arr[i];
	//}
	
	//Opción 2
	for(int i = len; i > pos; i--){
		arr[i]=arr[i-1];
	}
	
	arr[pos] = v;
	len++;
}

int insertarOrdenado(int arr[], int& len, int v){
	int i = 0;
	
	while(i < len && arr[i] < v ){
		i++;
	} 
	
	insertar(arr,len,v,i);
	
	return i;
}


int buscaEInserta(int arr[], int& len, int v, bool& enc){
	int pos = buscar(arr,len,v);
	
	if(pos == -1){
		enc = false;
		pos = insertarOrdenado(arr,len,v);
	} else {
		enc = true;	
	}
	
	return pos;
}

//Ejercicio 1 Structs

int calcularMaxVelocidad(VelPais vec[],int len){
	int vMax = -100;
	int pos;
	
	for(int i=0; i < len; i++){
		if(vec[i].velMax > vMax){
			vMax = vec[i].velMax;
			pos = i;
		}
	}
	
	return pos;	
}

int calcularMaxVelocidad2(VelPais vec[],int len,string &paisVelocidadMaxima){
	int vMax = -100;
	
	
	for(int i=0; i < len; i++){
		if(vec[i].velMax > vMax){
			vMax = vec[i].velMax;
			paisVelocidadMaxima = vec[i].pais;
		}
	}
	
	return vMax;	
}

float calcularPromedio(VelPais vec[],int len){
	float sumaVelocidades = 0;
	
	for(int i=0; i < len; i++){
		sumaVelocidades += vec[i].velMax;
	}
	
	return sumaVelocidades/len;
}

int calcularMinVelocidad(VelPais vec[],int len){
	int vMin = 999999;
	int pos;
	
	for(int i=0; i < len; i++){
		if(vec[i].velMin < vMin){
			vMin = vec[i].velMin;
			pos = i;
		}
	}
	
	return pos;	
}

//Ejercicio 2 Structs

int buscaEInserta(int arr[], int& len, int v, bool& enc){
	int pos = buscar(arr,len,v);
	
	if(pos == -1){
		enc = false;
		pos = insertarOrdenado(arr,len,v);
	} else {
		enc = true;
	}
	
	return pos;
}

int calcularMaxInscriptos(Comision vec[],int len){
	int maxI = -100;
	int pos;
	
	for(int i =0; i < len; i++){
		if(vec[i].cantInscriptos > maxI){
			maxI = vec[i].cantInscriptos;
			pos = i;
		}
	}
	
	return pos;
}


int calcularMinInscriptos(Comision vec[],int len){
	int minI = vec[0].cantInscriptos;
	int pos = 0;
	
	for(int i =0; i < len; i++){
		if(vec[i].cantInscriptos < minI){
			minI = vec[i].cantInscriptos;
			pos = i;
		}
	}
	
	return pos;
}

float calcularPromedioInscriptos(Comision vec[],int len){
	float sumaInscriptos =0;
	
	for(int i = 0; i < len; i++){
		sumaInscriptos += vec[i].cantInscriptos;
	}
	
	return sumaInscriptos/len;
}

//Ejercicio 3 Structs
void mostrarMenu(){
	cout << "Bienvenido al sistema de gestión del Kiosquito. Presione:" << endl;
	cout << "1: para Dar de alta un producto nuevo" << endl;
	cout << "2: para Buscar un producto por su nombre" << endl;
	cout << "3: para Modificar el stock y precio de un producto dado. (Ingresar Prod por Nombre)" << endl;
	cout << "0: para salir " << endl;
}

void agregar(Producto arr[], int n, int& len, Producto v){
	if(n == len){
		cout << "No se puede agregar. Vector lleno" << endl;
	} else{
		arr[len] = v;
		len++;	
	}
}

void darDeAltaProducto(Producto vec[],int n,int &len){
	Producto prod;
	
	cout << "Ingrese el cod del producto" << endl;
	cin >> prod.cod;
	
	cout << "Ingrese el nombre del producto" << endl;
	cin >> prod.nombre;
	
	cout << "Ingrese el precio del producto" << endl;
	cin >> prod.precio;
	
	cout << "Ingrese el stock del producto" << endl;
	cin >> prod.stock;
	
	agregar(vec,n,len,prod);
	
}

int buscar(Producto vec[],int len,string nombreProductoABuscar){
	int i = 0;
	int pos;
	
	while(i < len && vec[i].nombre != nombreProductoABuscar){
		i++;
	}
	
	if(i==len){
		pos = -1;
	} else{
		pos = i;
	}
	
	return pos;
	
}

void buscarEImprimirProductoPorNombre(Producto vec[],int len){
	string nombreProductoABuscar;

	cout << "Ingresar el nombre del producto a buscar" << endl;
	cin >> nombreProductoABuscar;
	
	int pos = buscar(vec,len,nombreProductoABuscar);
	
	if(pos == -1){
		cout << "El producto no se encuentra cargado" << endl;
	} else{
		cout << "ID: " << vec[pos].cod << endl;
		cout << "Nombre: " << vec[pos].nombre << endl;
		cout << "Precio: " << vec[pos].precio << endl;
		cout << "Stock: " << vec[pos].stock << endl;
	}
	
}

void modificarStockyPrecio(Producto vec[],int len){
	string nombreProducto;
	
	cout << "Ingrese el nombre del producto a modificar" << endl;
	cin >> nombreProducto;
	
	int pos = buscar(vec,len,nombreProducto);
	
	if(pos == -1){
		cout << "El producto no se encuentra cargado" << endl;
	} else{
		cout << "Precio Actual: " << vec[pos].precio << endl;
		cout << "Ingrese el nuevo precio" << endl;
		cin >> vec[pos].precio;
		
		cout << "Stock Actual: " << vec[pos].stock << endl;
		cout << "Ingrese el nuevo stock" << endl;
		cin >> vec[pos].stock;
	}
}
