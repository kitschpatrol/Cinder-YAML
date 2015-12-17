#Cinder-YAML

**[YAML](http://www.yaml.org) reading and writing for [Cinder](https://libcinder.org), based on the [yaml-cpp](https://github.com/jbeder/yaml-cpp) library. Wraps some Cinder native types for convenience.**

----

*Note: This block is just a bare wrapper of yaml-cpp at the moment, further Cinder type integration pending.*

----


## Getting Started
Take a look at the YamlBasic example.


## Origin

Inspired by the [openFrameworks](http://openframeworks.cc) addon [ofxYaml](https://github.com/satoruhiga/ofxYAML), which was created by [Satoru Higa](https://github.com/satoruhiga), [Greg Borenstein](https://github.com/atduskgreg), and [Hiizoka Saka](https://github.com/hiz1).

## Compatibility

Tested against the [Cinder master branch](https://github.com/cinder/Cinder/commit/02089928b3982f866a77a9e6e2168075f9f9e6f6) (~v9.1).

Tinderbox-generated project files are known to work on:

- Mac OS X 10.11 x64 with Xcode 7.2

This library was not built with an eye towards backwards compatibility. It's probably relatively trivially achievable by rebuilding the dependencies, but this isn't currently a priority.

## Known Issues

### Xcode

None.

### Visual Studio

Tinderbox enables the /gm flag in Visual Studio projects by default, which will conflicts with the /mp flag. Disable /gm to take care of this.

## Dependences

**All dependencies are included in the block.**

Dependencies were built through CMake, against [yaml-cpp commit 97d56c3][https://github.com/jbeder/yaml-cpp/commit/97d56c3f3608331baaee26e17d2f116d799a7edc] (~version 0.5.2).

Libraries are included Mac x64, Win32, and Windows x64.

##TODO
- Test on Windows.
- [Rebuild yaml-cpp without Boost](https://github.com/jbeder/yaml-cpp/pull/342) once the pull request is sorted and merged.
- Map more Cinder types.