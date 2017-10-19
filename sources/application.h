#ifndef APPLICATION
	#define APPLICATION

#include <vector>
#include "matiere.h"
#include "section.h"

using namespace std;

/*!
	@file application.h
	@version 0.1

	@class Application application.h 
	@brief L'application est instanciée une seule fois dans main
*/

class Application
{
private:
	/*! @brief contient les section de l'application */
	vector<Section> _vectSection;

	/*! @brief contient les matières de l'application */
	vector<Matiere> _vectMatiere;

	/*! @brief Si faux l'application s'arette */
	bool isRunning; 

	/*!
		@fn void stop()
		@brief Arrête l'application
	*/
	void stop();

	/*!
		@fn void displayMenu()
		@brief affiche le menu
	*/
	void displayMenu();

	/*!
		@fn void actionEnFonctionDuChoix(int choix)
		@brief execute une action en fonction du choix correspondant au menu
		@param int choix
		@brief choix du menu

	*/
	void actionEnFonctionDuChoix(int choix);

	/*!
		@fn void createSection()
		@brief créer une section dans l'application en demandant à l'utilisateur d'entrer des informations
	*/
	void createSection();

	/*!
		@fn void displaySections()
		@brief affiche les sections dans l'application
	*/
	void displaySections();

	/*!
		@fn void pickSection()
		@brief demande à l'utilisateur de choisir une section puis rentre dans le menu de cette section
	*/
	void pickSection();

	/*!
		@fn void createMatiere()
		@brief créer une matière dans l'application en demandant le nom de la matière à l'utilisateur
	*/
	void createMatiere();

public:
	/*!
		@fn Application()
		@brief constructeur d'Application (appellé qu'une seule fois dans main)
	*/
	Application();
	/*! 
		@fn void run()
		@brief est lancé une fois au démarrage du programme
	*/
	void run();

	/*!
		@fn int inputChoix()
		@brief demande à l'utilisateur de saisir un choix numéroté
	*/
	int inputChoix();

	/*!
		@fn void displayMatieres()
		@brief affiche les matières dans l'application
	*/
	void displayMatieres();

	/*!
		@fn vector<Matiere>* getVectMatiere()
		@brief permet d'acceder à un pointeur vers le vecteur qui contient les matières
		@return vector<Matiere>*
	*/
	vector<Matiere>* getVectMatiere();
};

#endif