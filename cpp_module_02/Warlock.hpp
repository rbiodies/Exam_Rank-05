#pragma	once

#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
private:
	std::string	name;
	std::string	title;

	Warlock();
	Warlock(Warlock const &warlock);
	Warlock	&operator=(Warlock const &warlock);

	SpellBook	spellbook;

public:
	Warlock(std::string const &name, std::string const &title);
	virtual	~Warlock();

	std::string const 	&getName() const;
	std::string const	&getTitle() const;

	void	setTitle(std::string const &title);

	void	introduce() const;

	void	learnSpell(ASpell *spell);
	void	forgetSpell(std::string spell_name);
	void	launchSpell(std::string spell_name, ATarget const &target);
};