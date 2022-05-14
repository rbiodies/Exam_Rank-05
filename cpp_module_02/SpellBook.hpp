#pragma	once

#include "ASpell.hpp"
#include <map>

class SpellBook {
private:
	SpellBook(SpellBook const &spellbook);
	SpellBook	&operator=(SpellBook const &spellbook);

	std::map<std::string, ASpell *>	spells;

public:
	SpellBook();
	~SpellBook();

	void	learnSpell(ASpell *spell);
	void	forgetSpell(std::string const &spell_name);
	ASpell	*createSpell(std::string const &spell_name);
};