#include "note.h"
#include "etudiant.h"
Note::Note()
{

}

Note::Note(Etudiant* etudiant)
{
	_pEtudiant = etudiant;
}

void Note::input()
{
	bool isCorrect;
	float note;
	do
	{
		_pEtudiant->display();
		cout<<": ";
		cin>>note;
		isCorrect = (note<=20 && note>=0);
		if(!isCorrect)
			cout<<"La note saisie n'es pas correcte"<<endl;
		else
			_note = note;
	}
	while(!isCorrect);
}

void Note::display()
{
	_pEtudiant->display();
	cout<<": "<<_note<<"/20"<<endl;
} 

float Note::getNote()
{
	return _note;
}