#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget *>::iterator	it_begin = targets.begin();
	std::map<std::string, ATarget *>::iterator	it_end = targets.end();
	while (it_begin != it_end) {
		delete it_begin->second;
		it_begin++;
	}
	this->targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *target) {
	if (target)
		targets.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const &target_name) {
	std::map<std::string, ATarget *>::iterator	it = targets.find(target_name);
	if (it != targets.end())
		delete it->second;
	targets.erase(target_name);
}

ATarget	*TargetGenerator::createTarget(std::string const &target_name) {
	std::map<std::string, ATarget *>::iterator	it = targets.find(target_name);
	if (it != targets.end())
		return targets[target_name];
	return NULL;
}