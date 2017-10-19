#include "section.h"
#include "application.h"
#include "bulletin.h"
#define DEBUG
Section::Section()
{

}

Section::Section(Application *parent, string name)
{
	_name = name;
	_parent = parent;
}

Application* Section::getParent()
{
	return _parent;
}

void Section::displayMenu()
{
	_isDisplaying = true;
	cout<<"--"<<_name<<"--"<<endl;
	cout<<"1: créer un étudiant | 2: afficher les étudiants | 3: ajouter une matière | 4: afficher les matières | 5: créer évaluation | 6: afficher une évaluation | 7:créer un bulletin | 8: afficher un bulletin | 9: quitter la section"<<endl;
}

void Section::actionEnFonctionDuChoix(int choix)
{
		switch(choix)
		{
			case 1:
				addEtudiant();
			break;
			case 2:
				displayEtudiants();
			break;
			case 3:
				addMatiere();
			break;
			case 4:
				displayMatieres();
			break;
			case 5:
				addEvaluation();
			break;
			case 6:
				displayEvaluation();
			break;
			case 7:
				addBulletin();
			break;
			case 8:
				displayBulletin();
			break;
			case 9:
				_isDisplaying = false;
			break;
			default:
				cout<<"choix invalide"<<endl;
			break;
		}
}

bool Section::isDisplaying()
{
	return _isDisplaying;
}

void Section::display()
{
	cout<<_name;
}

void Section::input()
{
	cin.ignore();
	cout<<"Nom de la section: ";
	cin>>_name;
}

void Section::addEtudiant()
{
	Etudiant etudiant;
	etudiant.input();
	addEtudiant(etudiant);
}

void Section::addEtudiant(Etudiant etudiant)
{
	_vectEtudiant.push_back(etudiant);
}

void Section::addMatiere()
{
	_parent->displayMatieres();
	int choix, coeff;
	choix = _parent->inputChoix();
	if(matiereExist(&_parent->getVectMatiere()->at(choix)))
		cout<<"Vous avez déjà ajouter cette matière"<<endl;
	else
	{
		cout<<"Coeff: ";
		cin>>coeff;
		addMatiere(&_parent->getVectMatiere()->at(choix), coeff);
	}
}

void Section::addMatiere(Matiere *matiere, int coeff)
{
	_vectMatiere.push_back(matiere);
	_vectCoeff.push_back(coeff);
}

void Section::addEvaluation()
{
	cout<<"Pour quelle matière voulez-vous ajouter cette évaluation: "<<endl;
	displayMatieres();
	int matiereNum;
	bool isCorrect;
	int size = _vectMatiere.size();
	do
	{
		cin>>matiereNum;
		isCorrect = (matiereNum>=0 && matiereNum<size);
		if(!isCorrect)
			cout<<matiereNum<<" ne correspond pas à une matière"<<endl;

	}while(!isCorrect);	
	_vectEvaluation.push_back(Evaluation());
	_vectEvaluation.back().input(_vectMatiere[matiereNum]);

	int sizeEtudiant = _vectEtudiant.size();
	for (int i = 0; i < sizeEtudiant; ++i)
	{
		_vectEvaluation.back().inputNote(&_vectEtudiant[i]);
	}
}

void Section::displayMatieres()
{
	cout<<"--Matieres--"<<endl;
	int size = _vectMatiere.size();
	if(size == 0)
		cout<<"(aucune matière)"<<endl;
	for (int i = 0; i < size; ++i)
	{
		_vectMatiere[i]->display();
		cout<<" (coeff. "<<_vectCoeff[i]<<")"<<endl;
	}
	cout<<"------------"<<endl;
}

void Section::displayEtudiants()
{
	cout<<"--Etudiants--"<<endl;
	int size = _vectEtudiant.size();
	if(size == 0)
		cout<<"(aucun étudiant)"<<endl;
	for (int i = 0; i < size; ++i)
	{
		_vectEtudiant[i].display();
		cout<<endl;
	}
	cout<<"------------"<<endl;
}

void Section::displayEvaluation()
{
	cout<<"Quelle évaluation voulez-vous afficher"<<endl;
	int size = _vectEvaluation.size();
	for (int i = 0; i < size; ++i)
	{
		_vectEvaluation[i].displayEntete();
	}

	int choix;
	bool isCorrect;
	do
	{
		cin>>choix;
		isCorrect = (choix>=0 && choix<size);
		if(!isCorrect)
			cout<<choix<<" ne correspond pas à une évaluation"<<endl;

	}while(!isCorrect);
	_vectEvaluation[choix].display();	
}

bool Section::matiereExist(Matiere* matiere)
{
	int size = _vectMatiere.size();
	bool exist = false;
	for (int i = 0; i < size-1; ++i)
	{
		if(matiere==_vectMatiere[i])
		{
			exist = true;
			break;
		}
	}
	return exist;
}

void Section::displayBulletin()
{
	cout<<"De quel élève voulez-vous afficher le bulletin"<<endl;
	displayEtudiants();

	int size = _vectEtudiant.size();
	int choix;
	cin>>choix;

	//si le choix de l'utilisateur est incorrect
	if(choix>size || choix<0)
		cout<<"Cet élève n'existe pas";
	//sinon
	else
		if(_vectEtudiant[choix].getVectBulletin()->size()==0)
			cout<<"Cet étudiant n'a pas de bulletin"<<endl;
		else
			_vectEtudiant[choix].getVectBulletin()->at(0).display(); //on affiche le bulletin de l'élève	

}

void Section::addBulletin()
{
	#ifdef DEBUG
	cout<<"void Section::addBulletin()"<<endl;
	#endif
	cout<<"Pour quel élève voulez-vous créer le bulletin"<<endl;
	displayEtudiants();

	int size = _vectEtudiant.size();
	int choix;
	cin>>choix;


	//si le choix de l'utilisateur est incorrect
	if(choix>size || choix<0)
		cout<<"Cet élève n'existe pas";
	//sinon
	else
	{
        Bulletin b(this, &_vectEtudiant[choix]);//bulletin qu'on créer
        b.input();//on entre les informations du bulletin

        _vectEtudiant[choix].addBulletin(b); //on ajout le bulletin à l'élève
				//_vectEtudiant[choix].display();
	}

	//#ifdef DEBUG
	cout<<"void Section::addBulletin() fin"<<endl;
	//#endif
}

vector<Matiere*> Section::getVectMatiere()
{
	return _vectMatiere;
}
