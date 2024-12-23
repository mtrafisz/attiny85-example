# Example project for ATtiny85.

## Requirements

You'll need `cmake`, `avr-gcc`, `avr-libc` and `avrdude`, and some kind of build system, like `make`.
In debian-likes you can paste:

```bash
sudo apt install cmake gcc-avr arvdude build-essential
```

You'll also need Arduino that's set up as ISP programmer. Search the web or ask ChatGPT to figure that out.

This template includes `.vscode` directory - VSCode config to work nicely with IntelliSense. 

## Usage

This project is meant to be used as a template. To add source files to the project, append names of those files to `${SOURCE_FILES}` in `CMakeLists.txt`. To build Your project, You initialy have to run commands:

```bash
mkdir build
cd build
cmake ..
```

You also have to run `cmake ..` while in `./build` every time you change something in `CMakeLists.txt`

To build your source code and upload it to ATtiny, run in `./build`:

```bash
make
make upload
```

## Something's broken?

The only thing I can think of, that is not portable, is the `/dev/ttyUSB0` part of `CMakeLists.txt` (line 45). Make sure, that your Arduino is indeed connected to that port (for example in arduino IDE), or change this part of cmake config.

Other than that - I've only run this code on KUbuntu 24.10. Everything else is untested, and not guaranteed to work.

## Licensing

This software is part of public domain. See [UNLICENSE](UNLICENSE).
