#include "Yaml.h"
#include "cinder/Utilities.h"

using namespace kp::yaml;

bool YamlTree::load(ci::DataSourceRef dataSource) {

	std::string yamlString = ci::loadString(dataSource);

	doc = YAML::Load(yamlString);

	// YAML::Emitter out;

	//	std::cout << doc["root"] << std::endl;

	return true;
}
