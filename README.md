pal2json [![Build Status](https://travis-ci.org/falltergeist/pal2json.svg?branch=develop)](https://travis-ci.org/falltergeist/pal2json) [![Version](https://img.shields.io/github/release/falltergeist/pal2json.svg)](https://github.com/falltergeist/pal2json/releases/latest) [![Discord](https://img.shields.io/discord/401990446747877376.svg)](https://discord.gg/jxs6WRq)
========
Fallout 1\2 *.pal to json converter

Installation:
=============

Ubuntu
------

```bash
sudo add-apt-repository ppa:falltergeist/falltergeist
sudo apt-get update
sudo apt-get install pal2json
```

Compilation from source:
============

Dependencies:
-------------

- CMake >= 2.8

Build:

```bash
mkdir build && cd build && cmake .. && make
```

Usage:
======

```bash
./pal2json PATH_TO_FILE.pal
```

Converted file will be written to STDOUT
