#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::map<std::string, ASpell *>::iterator	it_begin = spells.begin();
	std::map<std::string, ASpell *>::iterator	it_end = spells.end();
	while (it_begin != it_end) {
		delete it_begin->second;
		it_begin++;
	}
	this->spells.clear();
	std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const 	&Warlock::getName() const {
	return this->name;
}

std::string const	&Warlock::getTitle() const {
	return this->title;
}

void	Warlock::setTitle(std::string const &title) {
	this->title = title;
}

void	Warlock::introduce() const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell) {
	if (spell)
		spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	Warlock::forgetSpell(std::string spell_name) {
	std::map<std::string, ASpell *>::iterator	it = spells.find(spell_name);
	if (it != spells.end())
		delete it->second;
	spells.erase(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, ATarget const &target) {
	ASpell *spell = spells[spell_name];
	if (spell)
		spell->launch(target);
}