#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md) : md(_md) {
	/* de adaugat */
	this->pozCurent = 0;
	deplasare();
}


void IteratorMD::deplasare() {
	while ((this->pozCurent < md.m) && md.keys[pozCurent] == nullptr)
	{
		pozCurent++;
	}
	if (this->pozCurent < this->md.m)
		this->curent = this->md.keys[this->pozCurent];

}

TElem IteratorMD::element() const {
	
	if (!valid())
		throw(exception());
	return this->curent->e;
}

bool IteratorMD::valid() const {
	if (this->pozCurent < this->md.m)
		return true;
	return false;
}

void IteratorMD::urmator() {
	/* de adaugat */
	if (!valid())
		throw(exception());
	this->curent = this->curent->urm;
	if (this->curent == nullptr)
	{
		this->pozCurent++;
		deplasare();
	}
}

void IteratorMD::prim() {
	this->pozCurent = 0;

	deplasare();
}

