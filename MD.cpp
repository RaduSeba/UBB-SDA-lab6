#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;


Nod::Nod(TElem e, PNod urm) {
	this -> e = e;
	this->urm = urm;

}




MD::MD() {
	this->m = 10;
	this->nrElem = 0;
	for (int i = 0; i < 10; i++) {
		this->keys.push_back(nullptr);
	}
}


void MD::adauga(TCheie c, TValoare v) {
	int key = this->hashCode(c) % this->m;
	TElem elem = make_pair(c, v);
	PNod value = new Nod(elem, nullptr);

	if (this->keys[key] == nullptr) {
		this->keys[key] = value;
		this->nrElem++;
		return;
	}
	PNod p = this->keys[key];
	while (p->urm != nullptr)
	{
		p = p->urm;
	}
	p->urm = value;
	this->nrElem++;

}


bool MD::sterge(TCheie c, TValoare v) {
	int key = this->hashCode(c) % this->m;
	if (this->keys[key] == nullptr)
		return false;

	if (this->keys[key]->e.first == c && this->keys[key]->e.second == v)
	{
		this->keys[key] = this->keys[key]->urm;
		this->nrElem--;
		return true;
	}
	PNod p = this->keys[key];
	PNod anterior = p;
	p = p->urm;
	while (p != nullptr)
	{
		if (p->e.first == c && p->e.second == v)
		{
			anterior->urm = p->urm;
			this->nrElem--;
			return true;
		}
		anterior = p;
		p = p->urm;
	}
	return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
	
	
	
	int key = this->hashCode(c) % this->m;
	if (this->keys[key] == nullptr)
		return vector<TValoare>();

	PNod p = this->keys[key];
	vector<TValoare> vectorValori;
	while (p != nullptr)
	{
		if (p->e.first == c)
			vectorValori.push_back(p->e.second);
		p = p->urm;
	}
	return vectorValori;

}


int MD::dim() const {
	return this->nrElem;
}


bool MD::vid() const {
	for (int i = 0; i < this->m; i++)
	{
		if (keys[i]!=nullptr)
			return false;
	}
	return true;
}

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}




vector<TValoare> MD::colectiaValorilor() const
{
	vector<TValoare> vectorValori;
	
	for (int i = 0; i < this->m; i++)
	{	
		PNod p = this->keys[i];
		while(p!=nullptr)
		{
			//PNod p = this->keys[i];
			vectorValori.push_back(this->keys[i]->e.second);
			p = p->urm;
		}
	}


	return vectorValori;
}


int MD::hashCode(TCheie cheie) const {
	return cheie + 10000;
}


MD::~MD() {
	/* de adaugat */
}

