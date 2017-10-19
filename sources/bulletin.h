#ifndef BULLETIN
#define BULLETIN

#include <vector>
#include <map>
#include "matiere.h"
#include "note.h"

struct LigneDeBulletin
{
	string appreciation;
	int sommeNote;
	int nbreNote;
};

class Section;
class Bulletin
{
private:

	//map<int, int> test;
    map<Matiere*, LigneDeBulletin> _mapLigneDeBulletin;
	//set<int> test;

	Etudiant* _etudiant;
	Section* _section;
	int _semestre;

public:
	Bulletin();
    Bulletin(Section* section, Etudiant* etudiant);
	void setEtudiant(Etudiant* etudiant);
	void addNote(Matiere* matiere, Note* note);
	void display();
	void input();
};

#endif
