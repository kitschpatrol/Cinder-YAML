<!-- title({ prefix: "Cinder-" }) -->

# Cinder-YAML

<!-- /title -->

<!-- badges -->

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/license/mit)

<!-- /badges -->

<!-- short-description -->

**CinderBlock for YAML reading and writing, based on the yaml-cpp library.**

<!-- /short-description -->

## Overview

A [CinderBlock](https://libcinder.org/docs/guides/cinder-blocks/index.html) for reading and writing [YAML](https://yaml.org) in [Cinder](https://libcinder.org) apps, based on the [yaml-cpp](https://github.com/jbeder/yaml-cpp) library.

_Note: This block is just a bare wrapper of yaml-cpp at the moment; further Cinder type integration pending._

`kp::yaml::YamlTree` loads YAML from any `ci::DataSourceRef` into a `YAML::Node`. From there, reading, editing, and writing go through yaml-cpp's own API.

## Getting started

### Dependencies

Requires Cinder on macOS or Windows.

**All dependencies are included in the block.** The yaml-cpp headers and prebuilt static libraries are bundled for macOS (i386 and x86_64), Win32, and Windows x64.

Tested against the [Cinder master branch](https://github.com/cinder/Cinder/commit/02089928b3982f866a77a9e6e2168075f9f9e6f6) (0.9.1dev).

TinderBox-generated project files are known to work on:

- Mac OS X 10.11 x64 with Xcode 7.2
- Windows 10 with Visual Studio 2015 Community

This library was not built with an eye towards backwards compatibility. It's probably relatively trivially achievable by rebuilding the dependencies, but this isn't currently a priority.

### Installation

From your Cinder `blocks` directory:

```sh
git clone https://github.com/kitschpatrol/Cinder-YAML.git
```

Then add **YAML** to a project with [TinderBox](https://libcinder.org/docs/guides/tinderbox/index.html).

TinderBox enables the `/Gm` flag in Visual Studio projects by default, which conflicts with the `/MP` flag. Disable `/Gm` to take care of this.

## Usage

Load a file into a `YamlTree`, then work with its `doc` member through yaml-cpp:

```cpp
#include "cinder/app/App.h"
#include "Yaml.h"
#include <fstream>

// Inside your app, for example in setup():
kp::yaml::YamlTree yamlTree;
yamlTree.load(ci::app::loadAsset("config.yml"));

// Read
std::string title = yamlTree.doc["title"].as<std::string>();

// Edit
yamlTree.doc["count"] = 42;

// Write
std::ofstream file("output.yml");
file << yamlTree.doc;
```

The [Yaml.h](src/Yaml.h) API:

| Member             | Description                                                                                                                            |
| ------------------ | -------------------------------------------------------------------------------------------------------------------------------------- |
| `load(dataSource)` | Parse a data source into `doc`.                                                                                                        |
| `doc`              | The parsed document, a public `YAML::Node`. See the [yaml-cpp tutorial](https://github.com/jbeder/yaml-cpp/wiki/Tutorial) for its API. |

`Yaml.h` includes `<yaml-cpp/yaml.h>`, so the rest of yaml-cpp, such as `YAML::Emitter`, is available wherever you include it.

## Examples

### YamlBasic

The [basic sample](samples/YamlBasic/src/YamlBasicApp.cpp) loads a [remote `_config.yml` file](https://raw.githubusercontent.com/jonschlinkert/config.yml/master/_config.yml) with `loadUrl()` and logs the parsed document with `CI_LOG_V`. Cinder only prints verbose log messages in Debug builds.

Open [YamlBasic.xcodeproj](samples/YamlBasic/xcode/YamlBasic.xcodeproj) in Xcode or [YamlBasic.sln](samples/YamlBasic/vc2015/YamlBasic.sln) in Visual Studio 2015 to build it. The sample projects expect the block to be in Cinder's `blocks` directory.

## Updating bundled libraries

The headers in [`include/yaml-cpp`](include/yaml-cpp) and the static libraries in [`lib`](lib) come from [yaml-cpp](https://github.com/jbeder/yaml-cpp).

Mac dependencies were originally built through CMake, against [yaml-cpp commit 97d56c3](https://github.com/jbeder/yaml-cpp/commit/97d56c3f3608331baaee26e17d2f116d799a7edc) (\~version 0.5.2). The macOS library was rebuilt without Boost in January 2016, after yaml-cpp [replaced its Boost usage with C++11](https://github.com/jbeder/yaml-cpp/pull/342); the commit used for that build wasn't recorded.

Windows dependencies were built through CMake, against [yaml-cpp commit e92321a](https://github.com/jbeder/yaml-cpp/commit/e92321aee52fd27566601f9cca53ba90b41e15c1) (\~version 0.5.3, but with C++11 instead of Boost). The bundled headers match this commit.

For some reason the min-size Windows x64 release build of the library is crashy. Using the release build with debug symbols instead for now.

The Windows libraries were built with yaml-cpp's `MSVC_SHARED_RT` CMake option turned off, which links the static runtime (`/MT`) and adds the `mt` suffix to their names. The 32-bit libraries are in `lib/msw/x86` so the block manifest can select them through `$(PlatformTarget)`.

## Background

### Implementation notes

`YamlTree::load()` reads the data source with `ci::loadString()` and parses the result with `YAML::Load()`. The block adds `include` as a system include path, so `<yaml-cpp/yaml.h>` resolves to the bundled headers.

### Known issues

- No Cinder types are mapped yet. Vectors, colors, and other Cinder types have to be converted by hand or through your own `YAML::convert` specializations.
- `YamlTree` isn't modeled on Cinder's [`JsonTree`](https://libcinder.org/docs/classcinder_1_1_json_tree.html) yet and has no save method.
- `load()` always returns `true`. Malformed YAML throws a `YAML::ParserException` from yaml-cpp instead.
- The bundled macOS library is built for i386 and x86_64 only, so it won't link in a native Apple silicon (arm64) build.

## Maintainers

[kitschpatrol](https://github.com/kitschpatrol)

## Acknowledgments

Inspired by the [openFrameworks](https://openframeworks.cc) addon [ofxYAML](https://github.com/satoruhiga/ofxYAML), which was created by [Satoru Higa](https://github.com/satoruhiga), [Greg Borenstein](https://github.com/atduskgreg), and [Hiizoka Saka](https://github.com/hiz1).

<!-- contributing -->

## Contributing

[Issues](https://github.com/kitschpatrol/Cinder-YAML/issues) are welcome and appreciated.

Please open an issue to discuss changes before submitting a pull request. Unsolicited PRs (especially AI-generated ones) are unlikely to be merged.

This repository uses [MDAT](https://github.com/kitschpatrol/mdat) for readme placeholder expansion.

<!-- /contributing -->

<!-- license -->

## License

[MIT](license.txt) © Eric Mika

<!-- /license -->

The MIT license covers the wrapper code in [`src`](src) and the sample. The bundled yaml-cpp headers in [`include/yaml-cpp`](include/yaml-cpp) and the libraries in [`lib`](lib) are copyright Jesse Beder and distributed under yaml-cpp's own [MIT license](https://github.com/jbeder/yaml-cpp/blob/master/LICENSE).
