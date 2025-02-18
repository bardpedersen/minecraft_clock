
# Minecraft Clock

## To Do

Delete unnecessary files.
Add comments.

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

### WaveShare example code

```bash
git clone https://github.com/waveshareteam/RP2040-Touch-LCD-1.28.git
```

## Build

```bash
export PICO_SDK_PATH=$PWD/pico-sdk
cd build
cmake ..
make
```

## Flash

```bash
picotool load -x minecraft_clock.uf2
```
