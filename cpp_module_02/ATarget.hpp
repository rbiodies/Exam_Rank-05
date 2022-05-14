#pragma	once

#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string	type;

public:
	ATarget();
	ATarget(std::string const &type);
	ATarget(ATarget const &target);
	ATarget	&operator=(ATarget const &target);
	virtual	~ATarget();

	std::string const 	&getType() const;

	virtual ATarget	*clone() const = 0;

	void	getHitBySpell(ASpell const &spell) const;
};