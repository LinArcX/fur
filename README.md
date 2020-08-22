<h4 align="center">
    <img src="assets/mascot.svg" align="center" width="100"/>
</h4>

<h4 align="center">
  <img src="https://img.shields.io/github/languages/top/LinArcX/nubo.svg"/>  <img src="https://img.shields.io/github/repo-size/LinArcX/nubo.svg"/>  <img src="https://img.shields.io/github/tag/LinArcX/nubo.svg?colorB=green"/>
</h4>

# Nubo
> “The sky, a perfect empty canvas, offers clouds nonetheless. They shift and drift and beg interpretation… such is the nature of art.”― Jeb Dickerson

## Prerequisites
- `make`
- `glfw-devel`

## Build
1. Create a directory called: `libs` in your home directory.
2. Add it to `LD_LIBRARY_PATH`.
3. `make`

## Generate .h file from .ttf
If you want to use new fonts, just convert it to .h file using `xxd`. For instance:

`xxd -i Roboto-Bold.ttf > ttf_roboto_bold.h`

## What does nubo mean?
It's an Esperanto word means: "cloud".

## License
![License](https://img.shields.io/github/license/LinArcX/nubo.svg)
