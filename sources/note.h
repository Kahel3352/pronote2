#ifndef NOTE
	#define NOTE


class Etudiant;

/*!
	@file note.h
	@version 0.1

	@class Note
	@brief Note pour un Etudiant et une Evaluation
*/

class Note
{
private:
	/*!
		@brief Note effective de l'Etudiant
		@brief Ex: _note = 12.5 <=> 12.5/20
	*/
	float _note;

	/*!
		Etudiant au quel appartient la Note
	*/
	Etudiant* _pEtudiant;

	/*!
		Si true l'Etudiant a été absent au control
	*/
	bool _absent;
	
public:
	/*!
		Constructeur par défaut
	*/
	Note();

	/*!
		Constructeur surchargé
		@param Etudiant Etudiant auquel correspond la note
	*/
	Note(Etudiant* etudiant);

	/*!
		Demande à l'utilisateur de saisir la note
	*/
	void input();

	/*!
		Affiche la note
	*/
	void display();

	/*!
		return Float La note
	*/
	float getNote();
};

#endif