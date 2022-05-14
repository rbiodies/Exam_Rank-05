#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type) : type(type) {}

ATarget::ATarget(ATarget const &target) {
	*this = target;
}

ATarget	&ATarget::operator=(ATarget const &target) {
	if (this != &target) {
		this->type = target.type;
	}
	return *this;
}

ATarget::~ATarget() {}

std::string const 	&ATarget::getType() const {
	return this->type;
}

void	ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}