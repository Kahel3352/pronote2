#include "note.h"
#include "matiere.h"
#include <vector>
using namespace std;

class Evaluation
{
private:
	int _semestre;
	string _name;

	Matiere* _matiere;
	vector<Note> _vectNote;

public:
	int getSemestre();
	void input(Matiere* matiere);
	void inputNote(Etudiant* etudiant);
	void displayEntete();
	void display();
};