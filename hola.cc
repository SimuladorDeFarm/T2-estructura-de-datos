#include <iostream> 
#include <fstream> 
#include <vector> 
#include <sstream> 
#include <string> 
using namespace std; //para no usar std::

//inegrantes Diego Salazar y Tomás Farías  seccion 412
//profesor : Mauro Castillo
//  

 struct datos_de_camas{  
	int anho; 
	int meses; 
	int dia; 
	int camas_totales;
	int camas_ocupadas; //campos, está puesto en string para probar el programa. 
	
	
} ;

void calcula_disponibilidad(struct datos_de_camas *camas, int LargoDelVector, string nombreArchivoSalida  ){
	
	ofstream archivo;  //fichero de escritura
	archivo.open(nombreArchivoSalida.c_str(), ios::out); //abrir archivo en modo escritura
	

	
	if(archivo.is_open()) { //corroborar si el archivo abrio

	
	for(int j = 0; j < LargoDelVector ; j++ ){ //posicion del vector	
		
		for( int i = 0; i < 4 ; i ++){
	
			string dato;
			stringstream sstream; //canal de datos
		
			switch(i){
				case 0:
				sstream << camas[j].anho; //se almacena el entero
				break;
				case 1:
				sstream << camas[j].meses;
				break;			
				case 2:
				sstream << camas[j].dia;
				break;
				case 3:
				sstream << (camas[j].camas_totales - camas[j].camas_ocupadas);	
				break;						
			}
	
			dato = sstream.str(); // convertir int a string
			
			archivo << dato <<";" ; //se agrega el campo al archivo	
			
		
		}
		archivo << endl;
	}


		





	}

	else{
		cout << endl << "ERROR AL ABRIR EL ARCHIVO" << endl;

	}
	
	
	archivo.close();
}


void variacion_porcentual( int anho , struct datos_de_camas *camas , int LargoDelVector ){
	float  promedio_1 , promedio_2, acumulado = 0, dia; 
	int desde = 0, hasta = 0, contador = 1;
	
	while( camas[hasta].anho  != anho  ){ // busca el inicio del año actual
		
		hasta++;
	}

	while( camas[desde].anho  != anho-1  ){ //inicio del año anterior
		
		desde++;
	}
	
	
	cout << endl << "Respecto al año anterior: " << endl << "Aumento de camas totales = (+)" << endl << "Disminucion de camas totales (-)" << endl << endl ;

	for(int i = 0 ; i <12 ; i++){ //se ejecuta 12 veces por que son 12 meses
		promedio_1 = 0;
		promedio_2 = 0;
		acumulado = 0;
		contador = 1;// dias del mes
		
		
	
	
	while ( camas[hasta+1].dia > camas[hasta].dia ){//suma del mes, el dia siguente tiene que ser mayor al anterior, delimita el fin del mes 
		
		
		acumulado = acumulado +  camas[hasta].camas_totales;
		
		hasta++;
		contador++;
	}
	

	
	promedio_1 = acumulado / contador; //promedio del mes del año actual
	
	contador = 1;// dias del mes
	acumulado = 0;

	while ( camas[desde+1].dia > camas[desde].dia ){
		
		
		acumulado = acumulado +  camas[desde].camas_totales;
		
		desde++;
		contador++;
	}
		
		
	promedio_2 = acumulado / contador; //promedio del mes del año anterior
	
	float variacion = 0;
	
	variacion = ( 100 * promedio_1 )/ promedio_2; //variacion porcentual
	
	
	
	
	if(variacion == 100){ //variacion nula
		
		cout << "No hubo variacion" << endl ;
		
	}
	if(variacion > 100){//variacion positiva
		float aux;
		aux = variacion - 100;
		cout << "Mes: " << i+1 << "    " << aux << "%(+)" << endl;
		
	}
	if(variacion < 100){//variacion negativa
		float aux;
		aux = 100 - variacion;
		cout << "Mes: "<< i+1 <<"    " << aux << "%(-)" << endl;
	
		
	}
	
	
	hasta++;
	desde++;
		
	}
	
	
	
	
}

void variacion_porcentual_ocupado( int anho , struct datos_de_camas *camas , int LargoDelVector ){
	float  promedio_1 , promedio_2, acumulado = 0, dia; 
	int desde = 0, hasta = 0, contador = 1;
	
	while( camas[hasta].anho  != anho  ){//busca el inicio del año actual
		
		hasta++;
	}

	while( camas[desde].anho  != anho-1  ){//busca el inicio del año anterior
		
		desde++;
	}
	

	cout << endl << "Respecto al año anterior: " << endl << "Aumento de camas ocupadas = (+)" << endl << "Disminucion de camas ocupadas (-)" << endl << endl;


	
	for(int i = 0 ; i <12 ; i++){//se ejecuta 12 veces por que son 12 meses
		promedio_1 = 0;
		promedio_2 = 0;
		acumulado = 0;
		contador = 1;
		
		
	
	
	while ( camas[hasta+1].dia > camas[hasta].dia ){//verificador del limite del mes
		
		
		acumulado = acumulado +  camas[hasta].camas_ocupadas;//suma de las camas ocupadas de cada dia 
		
		hasta++;
		contador++;
	}
	

	
	promedio_1 = acumulado / contador; //promedio del mes del año actual
	
	contador = 1;
	acumulado = 0;

	while ( camas[desde+1].dia > camas[desde].dia ){//verificacion del limite del mes del año anterior
		
		
		acumulado = acumulado +  camas[desde].camas_ocupadas;//suma de las camas ocupadas de cada dia 
		
		desde++;
		contador++;
	}
	
	
	promedio_2 = acumulado / contador; //promedio del mes del año anterior
	float variacion = 0;
	
	variacion = ( 100 * promedio_1 )/ promedio_2;//calculo de la variacion %
	
	
	if(variacion == 100){ //variacion nula
		
		cout << "No hubo variacion";
		
	}
	if(variacion > 100){//variacion positiva
		float aux;
		aux = variacion - 100;
		cout << "Mes: " << i+1 << "    " << aux << "%(+)" << endl;
		
	}
	if(variacion < 100){//variacion negativa
		float aux;
		aux = 100 - variacion;
		cout << "Mes: " << i+1 << "    " << aux << "%(+)" << endl;
	
		
	}
	
	
	hasta++;
	desde++;
		
	}
	
	
	
	
}





void buscar(int anho, int mes, struct datos_de_camas *camas, int LargoDelVector, int& desde, int& hasta  ){
	
	desde = 0;//intervalo
	hasta = 0;	
	
	if( camas[desde].anho != anho ){ // para no buscar 2020 linea por linea se salta 365 linas 
		
			desde = 365;		
	}
	

	while( camas[desde].meses != mes ){//desde donde se inicia el intervalo
		
		desde++;
				
	}
	
	
	hasta = desde; 
	
	
	
	if(hasta != LargoDelVector){
			
			while(  camas[hasta].dia < camas[hasta+1].dia ) {//linea hasta donde llega el mes escogido
			
			
				hasta++;
			
			}

	}




}


float promedio_disponibilidad(int anho, int mes, struct datos_de_camas *camas, int LargoDelVector ){
	
	int  acumulado = 0, resta = 0, desde = 0, hasta = 0;



	buscar(anho, mes, camas, LargoDelVector, desde, hasta );// se busca el intervalo de posiciones del arreglo segun fecha 
	
	
	
	
	for(int contador = desde; contador <= hasta; contador++ ){ //suma la disponibilidad de camas de cada dia del mes
		
		resta = camas[contador].camas_totales - camas[contador].camas_ocupadas;	
		acumulado = acumulado + resta;
		
	}
	
		
	float promedio, hasta_aux = hasta, desde_aux = desde; //igualo variables float a int, float =  float/ float
		
				
	promedio = acumulado / ((hasta_aux-desde_aux)+1);	//calcula promedio
		
	
	return promedio;
	
}





int menor_disponibilidad(int anho, int mes, struct datos_de_camas *camas, int LargoDelVector) {

	int desde=0, m_desponibilidad = 99999, hasta = 0,  aux_desde, linea; // m_desponibilidad busca el menor asique se inicializa en un numero grande
		

	buscar(anho, mes, camas, LargoDelVector, desde, hasta ); //busca el intervalo de posiciones del vector segun fecha escogida	
	
	
	
		
	aux_desde = desde;


	while( aux_desde <= hasta ){//busca el dia con menor disponibilidad
		
		
		if( camas[aux_desde].camas_totales - camas[aux_desde].camas_ocupadas < m_desponibilidad){
			
			m_desponibilidad = camas[aux_desde].camas_totales - camas[aux_desde].camas_ocupadas;
			linea = aux_desde;
			
		}
		
		
		aux_desde++;
		
	}
	
	
	
	
	return camas[linea].dia;
}


int mayor_ocupacion(int anho, int mes, struct datos_de_camas *camas, int LargoDelVector ){
	
	int desde=0, ocupacion= 0, hasta = 0, aux_desde, linea;
		

	buscar(anho, mes, camas, LargoDelVector, desde, hasta ); //encontrar intervalo de fechas	
	
	
	
	aux_desde = desde; 
	
	while( aux_desde <= hasta ){ //se busca la mayor ocupacion dentro de la fecha escogida
		
		
		if( camas[aux_desde].camas_ocupadas > ocupacion){
			
			ocupacion = camas[aux_desde].camas_ocupadas;
			linea = aux_desde;
			
		}
		
		
		aux_desde++;
		
	}
	
	
	
	
	
	return camas[linea].dia;
} 



int contar_largo( string nombre){
	
	int contador = 0;
	
	
	ifstream lectura; 
	lectura.open(nombre.c_str(), ios::in); // abrir el archivo en modo lectura
	
	
	string saltar; //saltar primera linea
	getline(lectura, saltar); 
	
	
	for(string linea; getline(lectura, linea);  ){ //contar lineas
		
		contador++;
		
	}
	
	
	lectura.close(); // cierra el archivo
	
	
	return contador; 
}






int convertir( string dato){
	int i;
	
	istringstream(dato) >> i; //sstream
	
	return i;
	
}






void leer(string nombre,struct datos_de_camas *camas, int LargoDelVector){ // camas de ser pasado por referencia 
	
	ifstream archivo; //ifstream es un tipo de dato y archivo es la variable(NombreVar)
	archivo.open(nombre.c_str(), ios::in);// abrir archivo en modo lectura
	
	
	string linea, saltar; 
	int contador = 0; // contador será la posicion del vector
	
			
if(archivo.is_open()){ //pregunta si el archivo se abrio correctamente
	
		getline(archivo, saltar); // se salta la primera linea
	
			
	
	
	while(getline(archivo, linea)){ // se ejecuta hasta que se acaben las lineas
		
		stringstream registro(linea); 
		string dato; 
	
			
		 // ';' es el delimitador
			
		for(int i =0 ;  getline(registro, dato, ';'); i++ ){ //pasa los datos del archivo a su campo correspondiente
		
			switch(i){
			
				case 0:
				camas[contador].anho = convertir(dato);  //funcion que combierte string en int
				break; 
				case 1:
				camas[contador].meses = convertir(dato);  
				break; 
				case 2:
				camas[contador].dia = convertir(dato);  
				break; 
				case 3:
				camas[contador].camas_totales = convertir(dato); 
				break; 
				case 4:
				camas[contador].camas_ocupadas = convertir(dato);  
				break; 
			
			}				
		}
						
			
		contador++;			
	}

	
}
 else{
 	
 		cout << endl << "ERROR AL ABRIR EL ARCHIVO" << endl;
	
 }


	archivo.close();  //cerrar archivo

}




int main() {

	
	string nombre = "camas.txt", nombreArchivoSalida = "nombreArchivoSalida.txt";  //camas.csv es el nombre del archivo a usar, y nombreArchivoSalida el archivo que se creara
	int LargoDelVector, mes, anho, volver = 1, usuario;

	
	LargoDelVector = contar_largo(nombre); // contar las nlineas que tiene el archivo
	
	struct datos_de_camas camas[LargoDelVector]; //vector de tipo datos_de_camas de tipo struct, el largo del vector sera indefinido pero hay que construir una funcion que cuente el vector. 	
	
	
	leer(nombre, camas, LargoDelVector );  //pasa los datos del archivo a un vector
	



	



		while(volver == 1){ //en caso de que el usuario quiere seguir usando el programa
			
		bool error = true;	
		
		
		
		cout << endl <<  " Digite el numero correspondiente a la informacion que quiera recibir" << endl  <<endl << "1.- Buscar un periodo mediante mes y año" << endl;
		cout << "2.- Variacion porcentual de cada mes sobre camas totales y camas ocupadas con respecto al año anterior" << endl;
		cout << "3.- Terminar el programa" << endl ;
		cin >> usuario;
		
		if(usuario == 3  ){// cierra el programa, crea le archivo pedido
			
			calcula_disponibilidad(camas, LargoDelVector, nombreArchivoSalida);

			return 0;
			
		}
		
		if(usuario == 1){ //opcion 1
			int i;


			error = true;
			while(error == true){
				
			cout << "indicar mes y año: " << endl << "Mes: ";
			cin >> mes;
			
			cout << "Año: ";
			cin >> anho;
			
				if( mes > 12 || mes < 1 || anho < 2019 || anho > 2020){
					
					cout << endl << "ERROR: DATO/S INVALIDO/S   VUELVA A INTENTAR";
					
				}
				else{
					error = false;
				}				
				
			}
			

			error = true ;
			while(error == true){
				
			cout << endl << "Que desa buscar?" << endl << endl << "1.- Dia con mayor ocupacion de camas dentro de este periodo" << endl << "2.- Dia con menor disponibilidad de camas dentro de este periodo";	
			cout << endl << "3.- Promedio de camas totales" << endl;
			cin >> i;
				
				if(i < 1 || i > 3){
					
					cout << endl <<" ERROR : INGRESE UNA DE LAS 3 OPCIONES" << endl << endl; 
					
				}
				else{
					error = false;
					
				}
				
			}
			
			
			
			
			
			if(i == 1){
				int mayor;
				mayor = mayor_ocupacion( anho , mes, camas, LargoDelVector);
				cout << "El dia con mayor ocupacion de camas del mes "<< mes <<" es: " << mayor <<" del " << anho << endl;
			}
			if(i == 2){
				int menor;	
				menor = menor_disponibilidad(anho, mes, camas, LargoDelVector);
				cout << "El dia con menor disponibilidad de camas del mes "<< mes <<" es: " << menor <<" del " << anho << endl;
	
			
			}
			if(i == 3){
				float promedio;
				promedio = promedio_disponibilidad( anho, mes, camas, LargoDelVector );
				cout << "Promedio de camas totales del mes "<< mes <<" es: " << promedio <<" del " << anho << endl;
				
			}
			
			 
		}
		
		
		
		if(usuario == 2){ // variacion porcentual
		
		int x;
		
		
			error = true;
			while(error == true){
				
			cout << "variacion porcentual de: " << endl << endl;
			cout << endl << "1.- Camas totales" << endl<< "2.- camas ocupadas" << endl;
			cin >> x;
			
			if(x < 1 || x > 2){
				
				cout << endl << " ERROR : INGRESE UNA DE LAS 2 OPCIONES" << endl << endl; 

				
			}
			else{
				
				error = false;
			}
				
			}
		
			
			
			
			if( x == 1){
								
				variacion_porcentual( 2020 , camas, LargoDelVector );
				
			}
			if( x == 2){
				
				variacion_porcentual_ocupado( 2020 , camas, LargoDelVector);
			}
			
			
			
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		error = true;
		while (error == true ){
			
			cout << endl << "Quiere realizar otra accion? 1: si 2: Terminar el programa" << endl; 
			cin >> volver;
			
			if(volver < 0 || volver > 2){
				
				cout << " ERROR : INGRESE UNA DE LAS 2 OPCIONES" << endl << endl; 
				
				
			}
			if( volver == 2){
				
				calcula_disponibilidad(camas, LargoDelVector, nombreArchivoSalida);
				return 0;
			}
			if( volver == 1){
				
				error = false;	

				
			}
			
		}
			
		
		
	}
	
			

	return 0;
}













