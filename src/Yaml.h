#pragma once

#include "cinder/DataSource.h"
#include <yaml-cpp/yaml.h>

namespace kp {
namespace yaml {

class YamlTree {
public:
	// TODO make more like cinder's Json implementation
	YAML::Node doc;
	bool load(ci::DataSourceRef dataSource);

private:
};
}
} // namespace kp::yaml