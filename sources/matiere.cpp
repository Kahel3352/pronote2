#include "matiere.h"

Matiere::Matiere(string name)
{
	_name = name;
}

void Matiere::input()
{
	string name;
	cout<<"Nom: ";
	cin>>name;
	_name = name;
}

void Matiere::display()
{
	cout<<_name;
}

string Matiere::getName()
{
	return _name;
}