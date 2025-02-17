
# Minecraft Clock

## To Do

Delete unnecessary files.

## Installation

### Picotool

```bash
pip install picotool
```

### Pico SDK

```bash
git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
```

## Build

```bash
export PICO_SDK_PATH=$PWD/pico-sdk
cmake ..
make
```

## Flash

```bash
picotool load -x minecraft_clock.uf2
```
