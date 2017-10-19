#include "evaluation.h"


int Evaluation::getSemestre()
{
	return _semestre;
}

void Evaluation::input(Matiere* matiere)
{
	_matiere = matiere;
	cout<<"Nom du sujet: ";
	cin>>_name;
	cout<<"Semestre: ";
	cin>>_semestre;
}

void Evaluation::inputNote(Etudiant* etudiant)
{
	_vectNote.push_back(Note(etudiant));
	_vectNote.back().input();
}

void Evaluation::displayEntete()
{
	cout<<_name<<" en ";
	_matiere->display();
	cout<<endl;
}

void Evaluation::display()
{
	int size = _vectNote.size();
	float somme = 0;
	for (int i = 0; i < size; ++i)
	{
		_vectNote[i].display();
		somme+=_vectNote[i].getNote();
	}
	cout<<"Moyenne: "<<somme/_vectNote.size()<<endl;
}