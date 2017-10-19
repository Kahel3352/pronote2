#ifndef MATIERE
#define MATIERE

#include <iostream>
using namespace std;

/*!
	@file matiere.h
	@version 0.1

	@class Matiere
	@brief Correspond à une matière scolaire (Maths, Français, ect...)
*/

class Matiere
{
private:
	/*!
		Nom de la Matiere
	*/
	string _name;

public:
	/*!
		Constructeur
		@param String Nom de la Matiere
	*/
	Matiere(string name);

	/*!
		Demande à l'utilisateur de saisir le nom de la Matiere
	*/
	void input();

	/*!
		Affiche le nom de la Matiere
	*/
	void display();

	/*!
		return String Le nom de la matière
	*/
	string getName();
};

#endif