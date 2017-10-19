#include "application.h"
#include "section.h"

Application::Application()
{
	//debugcout<<"Application::Application"<<endl;
	isRunning = false;

	//jeu d'essai
	//création des matières(3)
	_vectMatiere.push_back(Matiere("Maths"));
	_vectMatiere.push_back(Matiere("Fançais"));
	_vectMatiere.push_back(Matiere("EDM"));
    //2 sections
	_vectSection.push_back(Section(this, "SIO1"));
	_vectSection.back().addMatiere(&_vectMatiere[0], 3);
	_vectSection.back().addMatiere(&_vectMatiere[1], 2);
	_vectSection.back().addEtudiant(Etudiant("Pierre", "Paul", 18));
	_vectSection.back().addEtudiant(Etudiant("John", "Doe", 21));

	_vectSection.push_back(Section(this, "SIO2"));
	_vectSection.back().addMatiere(&_vectMatiere[0], 3);
	_vectSection.back().addMatiere(&_vectMatiere[1], 2);
	_vectSection.back().addMatiere(&_vectMatiere[2], 2);
	_vectSection.back().addEtudiant(Etudiant("Michaël", "Vanlerberghe", 20));
	_vectSection.back().addEtudiant(Etudiant("Peterson", "Rostain", 21));
	_vectSection.back().addEtudiant(Etudiant("Mélanie", "Lebeau", 19));

}

//méthodes privées
void Application::displayMenu()
{
	cout<<"1: créer une section, 2: afficher les sections, 3: choisir une section, 4: créer une matière, 5: afficher les matières, 6: quitter"<<endl;
}

int Application::inputChoix()
{
	//debugcout<<"Application::inputChoix"<<endl;
	int choix;
	cin>>choix;
	return choix;
}

void Application::actionEnFonctionDuChoix(int choix)
{
	//debugcout<<"Application::actionEnFonctionDuChoix"<<endl;
		switch(choix)
		{
			case 1:
				createSection();
			break;
			case 2:
				displaySections();
			break;
			case 3:
				pickSection();
			break;
			case 4:
				createMatiere();
			break;
			case 5:
				displayMatieres();
			break;
			case 6:
				stop();
			break;
			default:
				cout<<"choix invalide"<<endl;
			break;
		}
}

void Application::createSection()
{
	//debugcout<<"Application::createSection()"<<endl;
	Section section;
	section.input();
	_vectSection.push_back(section);
}

void Application::displaySections()
{
	//debugcout<<"Application::displaySections()"<<endl;
	cout<<"----Sections----"<<endl;
	int size = _vectSection.size();
	for (int i = 0; i < size; ++i)
	{
		cout<<i<<": ";
		_vectSection[i].display();
		cout<<endl;
	}
	cout<<"----------------"<<endl;
}

void Application::displayMatieres()
{
	//debugcout<<"void Application::displayMatieres()"<<endl;
	cout<<"----Matiere----"<<endl;
	int size = _vectMatiere.size();
	for (int i = 0; i < size; ++i)
	{
		cout<<i<<": ";
		_vectMatiere[i].display();
		cout<<endl;
	}
	cout<<"----------------"<<endl;
}

void Application::pickSection()
{
	//debugcout<<"void Application::pickSection()"<<endl;
	displaySections();
	int choix = inputChoix();
	do
	{
		_vectSection[choix].displayMenu();
		_vectSection[choix].actionEnFonctionDuChoix(inputChoix());
	}while(_vectSection[choix].isDisplaying());
	
}

void Application::createMatiere()
{
	//debugcout<<"void Application::createMatiere()"<<endl;
	string name;
	cout<<"Nom de la nouvelle matière: ";
	cin.ignore(1);
	getline(cin,name);

	//verif que le nom de la matière n'existe pas déjà
	int noCase=0;
	int nbMatiere=_vectMatiere.size();
	while(!(noCase==nbMatiere||name==_vectMatiere[noCase].getName()))
	{
		noCase++;
	}
	if(noCase==nbMatiere)//si on ne l'a pas trouvé
	{
		_vectMatiere.push_back(Matiere(name));
	}
	else
	{
		cout<<"La matière \""<<name<<"\" existe déjà"<<endl;
	}
}


void Application::run()
{
	//debugcout<<"Application::run"<<endl;
	isRunning = true;
	do
	{
		displayMenu();
		actionEnFonctionDuChoix(inputChoix());
	}while(isRunning);
}

void Application::stop()
{
	//debugcout<<"Application::stop"<<endl;
	isRunning = false;
}

std::vector<Matiere>* Application::getVectMatiere()
{
	return &_vectMatiere;
}
