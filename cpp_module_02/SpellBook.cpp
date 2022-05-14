#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::map<std::string, ASpell *>::iterator	it_begin = spells.begin();
	std::map<std::string, ASpell *>::iterator	it_end = spells.end();
	while (it_begin != it_end) {
		delete it_begin->second;
		it_begin++;
	}
	this->spells.clear();
}

void	SpellBook::learnSpell(ASpell *spell) {
	if (spell)
		spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(std::string const &spell_name) {
	std::map<std::string, ASpell *>::iterator	it = spells.find(spell_name);
	if (it != spells.end())
		delete it->second;
	spells.erase(spell_name);
}

ASpell	*SpellBook::createSpell(std::string const &spell_name) {
	std::map<std::string, ASpell *>::iterator	it = spells.find(spell_name);
	if (it != spells.end())
		return spells[spell_name];
	return NULL;
}