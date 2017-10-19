#include "bulletin.h"
#include "etudiant.h"
#include "section.h"
#include "application.h"


Bulletin::Bulletin()
{
	//cout<<"Bulletin::Bulletin()"<<endl;
}

Bulletin::Bulletin(Section* section, Etudiant* etudiant)
{
	cout<<"début constrcuteur"<<endl;
	_section = section;
	_etudiant = etudiant;
	int size = section->getVectMatiere().size();
	for (int i = 0; i < size; ++i)
	{
		_mapLigneDeBulletin[section->getVectMatiere()[i]].sommeNote = 0;
		_mapLigneDeBulletin[section->getVectMatiere()[i]].nbreNote = 0;
	}
	cout<<"fin constrcuteur"<<endl;
}

void Bulletin::setEtudiant(Etudiant* etudiant)
{
    //_etudiant = etudiant;
}

void Bulletin::display()
{
	//cout<<"--Bulletin de "; 
	//_etudiant->display();
	/*for (map<Matiere*, LigneDeBulletin>::iterator it = _mapLigneDeBulletin.begin(); it != _mapLigneDeBulletin.end(); ++it)
	{
		float moyenne = it->second.sommeNote/it->second.nbreNote;
		it->first->display();
		cout<<moyenne<<endl;
	}*/
	cout<<"--"<<endl;
	//cout<<"fin display"<<endl;
}

void Bulletin::input()
{
    //cout<<"Bulletin::input()"<<endl;
	//cout<<"size de la map: "<<_mapLigneDeBulletin.size();
    for (map<Matiere*, LigneDeBulletin>::iterator it = _mapLigneDeBulletin.begin(); it != _mapLigneDeBulletin.end(); ++it)
	{
		it->first->display();
		cout<<": ";
		cin>>it->second.appreciation;
    }
	//cout<<"Bulletin::input() fin"<<endl;
}

void Bulletin::addNote(Matiere* matiere, Note* note)
{
	//_mapLigneDeBulletin[matiere].sommeNote+=note->getNote();
	//_mapLigneDeBulletin[matiere].nbreNote++;
}
