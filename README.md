# BadButBetterRaytracer
## Dependicies
- [SFML](https://github.com/SFML/SFML)
- CMake (v 3.15+)
## Installation
``` bash
git clone https://github.com/zeusf1re/BadButBetterRaytracer.git
mkdir build
cmake ..
cmake --build .
```
> Or with PreMake

## For hyprland users
If SFML window opens in tiling mode without it's expected size, this should help
``` ~/.config/hypr/hyprland.conf
windowrulev2 = float, class:^(SFML)$
windowrulev2 = center, class:^(SFML)$
```
