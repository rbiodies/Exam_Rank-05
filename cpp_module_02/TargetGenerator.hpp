#pragma	once

#include "ATarget.hpp"
#include <map>

class TargetGenerator {
private:
	TargetGenerator(TargetGenerator const &targetgenerator);
	TargetGenerator	&operator=(TargetGenerator const &targetgenerator);

	std::map<std::string, ATarget *>	targets;

public:
	TargetGenerator();
	~TargetGenerator();

	void	learnTargetType(ATarget *target);
	void	forgetTargetType(std::string const &target_name);
	ATarget	*createTarget(std::string const &target_name);
};