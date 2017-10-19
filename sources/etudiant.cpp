#include "etudiant.h"
#include "bulletin.h"

Etudiant::Etudiant()
{

}

Etudiant::Etudiant(string name, string nickname, int age)
{
	_name = name;
	_nickname = nickname;
	_age = age;
}

void Etudiant::input()
{
	cin.ignore();
	cout<<"Nom: ";
	getline(cin, _name);
	cout<<"Prénom: ";
	getline(cin, _nickname);
	cout<<"Age: ";
	cin>>_age;
}

void Etudiant::display()
{
	cout<<_name<<" "<<_nickname;
}

void Etudiant::addBulletin(Bulletin bulletin)
{
	cout<<"Etudiant::addBulletin(Bulletin bulletin)"<<endl;
	_vectBulletin.push_back(bulletin);
	_vectBulletin.back().setEtudiant(this);
	cout<<"Etudiant::addBulletin(Bulletin bulletin) fin"<<endl;
}

vector<Bulletin>* Etudiant::getVectBulletin()
{
	return &_vectBulletin;
}