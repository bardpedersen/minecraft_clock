git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init

export PICO_SDK_PATH=$PWD/pico-sdk
cmake ..
make



picotool load -x minecraft_clock.uf2 
