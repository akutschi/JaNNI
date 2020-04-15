**The GitHub repository is just a mirror. The [original code](https://gitlab.com/akutschi/janni/) is maintained at [GitLab](https://gitlab.com/)**

# JaNNI - Just another Neural Network Implementation

This application is in the moment just a first step - and has to be rewritten - towards a very simple neural network for image classification with the MNIST data set. **Currently it is able to prepare all MNIST data and hyper-parameters for further processing, it is not able to learn.**

The long term goal is to write a modular application so that different activation and loss functions can be tested.

## Dependencies for Running Locally

**NOTE:** Build and run was _neither tested under Windows nor macOS_, it might work, it might not work.

* cmake >= 3.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.5
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* **No other additional libraries are required**

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./JaNNI`

