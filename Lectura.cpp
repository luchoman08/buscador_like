#include "Lectura.hpp"


Lectura::Lectura(){}
Lectura::~Lectura(){}

//Funciones compatibles con la salida de Matematica 10.2
//Soporta maximo cadenas de 127 caracteres.
void Lectura::Leer(string file){
		
		this->entrada.clear();
		this->palabras.clear();
		ifstream input(file.c_str());
		
		while(!input.eof()) 
		{
			input.getline(this->cadena, 128);
			string tmp = this->cadena;
			int tmp_size = tmp.length();
			string cadena_sin_espacios_ni_llaves = "";
			for(int i = 0; i < tmp_size; i++){
				
				if ((tmp[i] != '}')&&(tmp[i] != '{')&&(tmp[i] != ' ')){
					cadena_sin_espacios_ni_llaves = cadena_sin_espacios_ni_llaves + this->cadena[i];
					}
				}
				
			this->entrada.push_back(cadena_sin_espacios_ni_llaves);
			};
			
		int tmp_entrada_size = this->entrada.size();
		for (int pos_vector = 0 ; pos_vector < tmp_entrada_size; pos_vector++){
			
				int tmp_entrada_pos_vector_i = this->entrada[pos_vector].length();string palabra = "";
				for(int posicion_caracter = 0 ; posicion_caracter < tmp_entrada_pos_vector_i; posicion_caracter++){
						
						
						if ((this->entrada[pos_vector][posicion_caracter] != ',')and(posicion_caracter == tmp_entrada_pos_vector_i - 1)){
								palabra = palabra + this->entrada[pos_vector][posicion_caracter] ;
								this->palabras.push_back(palabra);
								palabra = "";
								
								}
						
						
						if(this->entrada[pos_vector][posicion_caracter] == ','){
							
								this->palabras.push_back(palabra);
								palabra = "";
							
							}else{
								
								palabra = palabra + this->entrada[pos_vector][posicion_caracter] ;
								
								}
						
					
					}
				
			}

	}
	
void Lectura::MostrarPalabras(){
	
		int tmp_tamano_palabras = this->palabras.size();
		for(int i = 0; i < tmp_tamano_palabras; i++){
			
				cout<<this->palabras[i]<<endl;
			
			}
	
	
	}



vector <string> Lectura::getPalabras(){
	
		return this->palabras;
	
	}
