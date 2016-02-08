#ifndef nodo_hpp
#define nodo_hpp

#include <vector>

public class Nodo{

private:
char caracter_actual;
char caracter_anterior;
int id_cadena;
 

public:
Nodo();
~Nodo();

char get_caracter_actual();
char get_caracter_siguiente();
char get_caracter_anterior();
int get_id_cadena();

void set_caracter_actual(char nuevo_caracter);
void set_caracter_siguiente(char nuevo_caracter);
void set_caracter_anterior(char nuevo_caracter);
void set_id_cadena(int nuevo_id);
};


#endif
