#pragma once
#include<vector>
#include<utility>

using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMD;

class Nod;

typedef Nod* PNod;

class Nod {

private:
	TElem e;
	PNod urm;
public:
	friend class IteratorMD;
	friend class MD;
	Nod(TElem e, PNod urm);

};

class MD
{
	friend class IteratorMD;
	friend class Nod;

private:
	/* aici e reprezentarea */
	int m;
	int nrElem;
	vector<PNod> keys;

	//  BC = WC = AC = Theta(1)
	int hashCode(TCheie cheie) const;

public:
	// constructorul implicit al MultiDictionarului
	//  BC = WC = AC = Theta(1)
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	// BC = WC = AC = Theta(1)
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	// The BC = WC = AC = Theta(n)
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//  BC = WC = AC = Theta(1)
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD
	// BC = WC = AC = Theta(1)
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	//  BC = WC = AC = Theta(m)
	bool vid() const;

	// se returneaza iterator pe MD
	//  BC = WC = AC = Theta(1)
	IteratorMD iterator() const;


	/*returneaza un vector cu toate valorile din multidictionar
	Caz favorabil = Theta(m)
	Caz defavorabil = Theta(m)
	Caz mediu = Theta(m)
	Complexitate generala: Theta(m)
	Subalgoritm colectiaValorilor()
	pre: mdo multidictionar ordonat
	post: vectorValori vector de TValori
	 vectorValori<- vector de TValori
	pentru i = 0,< mdo.m,1 executa
		p<-mdo.keys[i]
		cat timp p!= null ptr executa
			push_back(vectorValori),mdo.[keys[i]].e.second
			p<-[p].urm
		sf cat timp
		sf pentru
	returneaza vectorValori
	sf subalgorutm	

	
	
	
	
	
	*/
	vector<TValoare> colectiaValorilor() const;

	// destructorul MultiDictionarului	
	~MD();



};

