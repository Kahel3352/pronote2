#ifndef ETUDIANT
#define ETUDIANT

#include <iostream>
#include "bulletin.h"

using namespace std;

/*!
	@file etudiant.h
	@version 0.1

	@class Etudiant
	@brief Correspond à un élève dans une Section
*/

class Etudiant
{
private:

	/*!
		@brief Nom de l'Etudiant
	*/
	string _name;

	/*!
		@brief Prénom de l'Etudiant
	*/
	string _nickname;

	/*!
		@brief Âge de l'Etudiant
	*/
	int _age;

	/*!
		@brief Contient les Bulletin par semestre
		@brief _vectBulletin[0] correspond au bulletin du premier semestre pour cet Etudiant
	*/	
	vector<Bulletin> _vectBulletin;

public:
	/*!
		@brief Constructeur par défaut
	*/
	Etudiant();

	/*!
		@brief Constructeur surchargé
		@param string Nom de l'Etudiant
		@param string Prénom de l'Etudiant
		@param int Âge de l'Etudiant
	*/
	Etudiant(string name, string nickname, int age);

	/*!
		@brief Demande à l'utilisateur de saisir des informations sur l'Etudiant
	*/
	void input();

	/*!
		Affiche des informations sur l'Etudiant
	*/
	void display();

	/*!
		@brief Ajoute un Bulletin à l'Etudiant
		@param Bulletin Bulletin à ajouter à l'Etudiant
	*/
	void addBulletin(Bulletin bulletin);

	/*!
		@brief Accesseur du vecteur de Bulletin
		@return vector<Bulletin>* Pointeur vers le vecteur qui contient les Bulletin
	*/
	vector<Bulletin>* getVectBulletin();
};

#endif