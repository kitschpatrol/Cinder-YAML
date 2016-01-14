#include "Yaml.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class YamlBasicApp : public App {
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void update() override;
	void draw() override;
};

void YamlBasicApp::setup() {
	kp::yaml::YamlTree yamlTree;
	CI_LOG_V("Loading YML");
	yamlTree.load(loadUrl("https://raw.githubusercontent.com/jonschlinkert/config.yml/master/_config.yml"));
	CI_LOG_V("YML:" << yamlTree.doc);
}

void YamlBasicApp::mouseDown(MouseEvent event) {
}

void YamlBasicApp::update() {
}

void YamlBasicApp::draw() {
	gl::clear(Color(0, 0, 0));
}

CINDER_APP(YamlBasicApp, RendererGl)
