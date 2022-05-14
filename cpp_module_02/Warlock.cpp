#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
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
	spellbook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell_name) {
	spellbook.forgetSpell(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, ATarget const &target) {
	ATarget const	*test = 0;
	if (test == &target)
		return;
	ASpell *spell = spellbook.createSpell(spell_name);
	if (spell)
		spell->launch(target);
}