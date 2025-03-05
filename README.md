# Minecraft Clock Physical Replica

![Minecraft Clock](images/minecraft_clock_real.gif)

A physical, wearable replica of the Minecraft clock powered by a Raspberry Pi Pico and WaveShare 1.28" round LCD display. This project implements a functional clock that mimics the day/night cycle animation from Minecraft.

**Note:** This project is built upon WaveShare's [example code](https://files.waveshare.com/upload/9/9d/RP2040-LCD-1.28.zip).


## Features

- Accurate representation of Minecraft's in-game clock
- Low power consumption (~34mA)
- One minecraft pixel is 3.251mm x 3.251mm
- Wearable design with 3D printed case and watch band
- Full day/night cycle animation
- Powered by [Waveshare 1.28" round LCD display](https://www.waveshare.com/wiki/RP2040-LCD-1.28#Datasheet)

## Hardware Requirements

- WaveShare 1.28" Round LCD Display
- USB cable for programming
- 3D printer for case (optional)

## 3D Printing

The case and watch band can be 3D printed using the provided STL files.

- **Print-in-place design**: Use `full_watch.stl` for a complete watch with default band length
- **Customizable length**: Edit the `full_watch.stl` and add more links to increase the band length
- **Recommended settings**: 0.2mm layer height, 15% infill, supports only for surfaces right above the build plate, else links may fuse together

STL files are available in the `stl` directory.

## Software Setup

### Prerequisites

- [Pico SDK](https://github.com/raspberrypi/pico-sdk)
- [Picotool](https://github.com/raspberrypi/picotool) for uploading firmware
- CMake and build tools

### Installing Dependencies

1. **Install Picotool**:

```bash
pip install picotool
```

2. **Clone and set up Pico SDK**:

```bash
git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
cd ..
```

3. **Clone WaveShare LCD library**:

```bash
git clone https://github.com/waveshareteam/RP2040-Touch-LCD-1.28.git
```

### Building the Project

1. **Set SDK path:**
```bash
export PICO_SDK_PATH=/path/to/pico-sdk
```
2. **Create and enter build directory:**

```bash
mkdir -p build
cd build
```
3. **Configure and build:**

```bash
cmake ..
make
```

### Flashing to Pico

1. **Hold the BOOTSEL button on your Pico and connect it to your computer**
2. **Release the button after connecting**
3. **Flash the firmware:**

```bash
picotool load -x minecraft_clock.uf2
```

## Usage

Once powered, the clock will automatically display the current time in Minecraft's day/night cycle format. The display updates once per minute to conserve power.

## Contributing

Pull requests welcome! Please feel free to suggest improvements or report issues.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
