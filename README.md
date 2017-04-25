# Xplat Engine (pronounced "splat")
An opinionated cross-platform 3D game engine for web, ios* and android* in C/C++

\* platform not yet supported

## Prerequisites
* [WEB platform] a current version of [Emscripten](https://kripken.github.io/emscripten-site/)
  * installed such that `emmake` is on your PATH
* GIT SUBMODULE WARNING
  * this repository makes use of git submodules make sure to `git clone --recursive` or `git submodule update --init` 

## Building

### WEB platform
To build the web platform:
```
./build_web.sh
```

optionally you can specify `OUTDIR` on your environment to place the final files in a specific path.

To clean up your working directory:
```
./build_web.sh clean
```

## Other notes
This is still an early version, be gentle.

I have not tested the build on Windows or Mac (it probably doesn't work)

