#ifndef SECTION
	#define SECTION

#include <string>
#include <vector>
#include "evaluation.h"
#include "etudiant.h"

using namespace std;

class Application;

/*!
	@file section.h
	@version 0.1

	@class Section
	@brief Contient des élèves
*/

class Section
{
private:
	/*!
		@brief Pointe vers l'application qui contient cette section
	*/
	Application *_parent;

	/*!
		@brief Nom de la section
	*/
	string _name;

	/*!
		@brief Contient les étudiants de la section
	*/
	vector<Etudiant> _vectEtudiant;

	/*!
		@brief Si vrai affiche le menu de la section sinon retourne dans le menu principal
	*/
	bool _isDisplaying;

	/*!
		@brief Contient les pointeurs des matières de la section
	*/
	vector<Matiere*> _vectMatiere;

	/*!
		@brief Contient les coefficients pour chaque matières
	*/
	vector<int> _vectCoeff;

	/*!
		@brief Contient les évaluation de la section
	*/
	vector<Evaluation> _vectEvaluation;

	/*!
		@fn bool matiereExist(Matiere* matiere)
		@brief Vérifie si une matière existe dans la section
		@param Pointeur vers la matière qu'on veut verifier
		@return true la matière existe dans la section
		@return false la matière n'existe pas dans la section
	*/
	bool matiereExist(Matiere* matiere);

public:
	/*!
		@fn Section()
		@brief Constructeur par défaut
	*/
	Section();

	/*!
		@fn Section(Application* parent, string name)
		@brief Constructeur surchargé qui permet de donnée un nom à la Section et de faire le lien avec l'Application
		@param Application* Application dans laquelle est instanciée la section
		@param string Nom de la section
	*/
	Section(Application* parent, string name);

	/*!
		@return Application Le parent
	*/
	Application* getParent();
	/*!
		@fn void displayMenu()
		@brief Affiche le menu de la Section
	*/
	void displayMenu();

	/*!
		@fn void actionEnFonctionDuChoix(int choix)
		@brief Execute une action en fonction du choix correspondant au menu
	*/
	void actionEnFonctionDuChoix(int choix);

	/*!
		@fn bool isDisplaying()
		@return true la section doit continuer à s'afficher
		@return false la section est quittée
	*/
	bool isDisplaying();

	/*!
		@brief Affiche des informations sur la Section
	*/
	void display();

	/*!
		@brief Demande à l'utilisateur le nom de la Section
	*/
	void input();

	/*!
		@brief Demande à l'utilisateur des informations sur un Etudiant et le rajoute à la Section
	*/
	void addEtudiant();

	/*!
		@brief Ajoute un Etudiant à la Section
		@param Etudiant Etudiant à ajouter à la section
	*/
	void addEtudiant(Etudiant etudiant);

	/*!
		@brief Demande à l'utilisateur des informations sur une Matiere et le rajoute à la Section
	*/
	void addMatiere();

	/*!
		@brief Ajoute une Matiere à la Section
		@param Matiere* Matiere dans l'Application à ajouter à la section
		@param int Coefficient de la Matiere dans la Section
	*/
	void addMatiere(Matiere *matiere, int coeff);

	/*!
		@brief Demande à l'utilisateur des informations sur une Evaluation et la rajoute à la Section
	*/
	void addEvaluation();

	/*!
		@brief Affiche les Matiere de la Section
	*/
	void displayMatieres();

	/*!
		@brief Affiche les étudiants de la Sections
	*/
	void displayEtudiants();

	/*!
		@brief Affiche les Evaluation de la section
	*/
	void displayEvaluation();

	/*!
		@brief Affiche les Bulletin de la Section
	*/
	void displayBulletin();

	/*!
		@brief Demande des informations sur un Bulletin à l'utilisateur et l'ajoute à la Section
	*/
	void addBulletin();

	vector<Matiere*> getVectMatiere();
};

#endif