**The GitHub repository is just a mirror. The [original code](https://gitlab.com/akutschi/janni/) is maintained at [GitLab](https://gitlab.com/)**

# JaNNI - Just another Neural Network Implementation

Basically this is a project for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

This application is in the moment just a first step towards a very simple neural network for image classification with the MNIST data set. **Currently it is able to prepare all MNIST data and hyper-parameters for further processing, it is not able to learn.**

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

## Files

### `main.cpp`

Entry point. Creates `PrintInfo` and several `ExecutionTimer` instances to measure the running time. For demonstration purposes `RunMNIST` creates the object `run` with the following parameters:

- Path to training images (curently a relative path that will work if the repo is cloned)
- Path to training labels
- Path to test images
- Path to test labels
- Information about input layer, hidden layers and the output layer
- Batch size
- Epochs
- Learning rate

### `print_info.h/.cpp` and `execution_timer.h/.cpp`

This are simple 'helper classes' to print some information and measure times.

### `run_mnist.h` and `run_mnist.cpp`

`RunMNIST` inherits from the abstract base class `RunCreator` in `run_creator.h/.cpp`. The constructor calls the constructor from the class `RunCreator` and hands over the parameters.

In class `RunMNIST` three functions have to be defined. These three 'steps' are the learning process. The functions are using the functions defined in the files which contains

- `activation_function.h/.cpp`
- `loss_function.h/.cpp`

### Abstract base class in `run_creator.h` and `run_creator.cpp`

The created class `RunCreator` has several strings a float and an **initializer list** as parameter. These parameters are used to create objects from the classes `MNISTDataSet` and `HyperParameters`.

`MNISTDataSet` creates two objects, one for the training data and another one for the test data. The `HyperParameters` object holds the other information for the learning process.

Also there are three **pure virtual functions** which must be provided by the derived class. The reason for this approach is, that the 'raw' setup of the learning process can be done in the derived class. The fine tuning will be done by calling the derived class with the appropriate parameters. Here: `RunMNIST` in `main.cpp`.

### `hyper_parameters.h` and `hyper_parameters.cpp`

Class `HyperParameters`. Here some parameters from `RunMNIST` are used. The constructor gets the initializer list and the float. This are the data for the number of neurons per layer and the number of the layers. The float equals the learning rate.

This class is using the namespace `WeightInitialization` in `weight_initialization.h/.cpp`. The **functor** is used as random number generator to fill up the `_weights` 'matrices` within a specific range. Later, other algorithms can be added.

### `mnist_data.h` and `mnist_data.cpp`

Class `MNISTDataSet`. Each object can store all information from the binary file in IDX format. Since there are two files - one for training data and one for label data - the class `IDXDataSet` in the implementation will be instantiated twice. All gathered information will be stored in a `struct`.

### `idx_data.h` and `idx_data.cpp`

Class `IDXDataSet`. Opens one IDX file and stores the information gathered from the magic number, the size of each dimension and the data bytes. 

[Definition](http://yann.lecun.com/exdb/mnist/) of the IDX file format.

### `activation_function.h/.cpp` and `loss_function.h/.cpp`

This files contain namespaces were the corresponding function are stored. This functions and mathematical function are used in the implementation of the pure virtual functions of the derived classes like `RunMNIST` in `run_mnist`.

## Rubric

### Loops, Functions, I/O

  + The project demonstrates an understanding of C++ functions and control structures.
  + The project reads data from a file and process the data, or the program writes data to a file.
    + See `idx_data.h.cpp`. Data is provided in this repository in folder `mnist_data`.
  + The project accepts user input and processes the input.
    + See `PrintInfo::proceed_confirmation()` in `print_info.cpp`

### Object Oriented Programming

  + The project uses Object Oriented Programming techniques.
  + Classes use appropriate access specifiers for class members.
  + Class constructors utilize member initialization lists.
  + Classes abstract implementation details from their interfaces.
  + Classes encapsulate behavior.
  + Classes follow an appropriate inheritance hierarchy.
  + Derived class functions override virtual base class functions.
	  + See `run_mnist.h/.cpp` and `run_creator.h/.cpp`

### Memory Management

  + The project makes use of references in function declarations.
	  + See `idx_data.h/.cpp`
  + The project uses destructors appropriately.
	  + At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.
  + The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
	  + The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.
  + The project follows the Rule of 5.
	  + For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.
  + The project uses move semantics to move data, instead of copying it, where possible.
	  + See `mnist_data.cpp`
  + The project uses smart pointers instead of raw pointers.
	  + The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.

### Concurrency

  + The project uses multithreading.
	  + The project uses multiple threads in the execution.
  + A promise and future is used in the project.
	  + A promise and future is used to pass data from a worker thread to a parent thread in the project code.
  + A mutex or lock is used in the project.
    + A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.
  + A condition variable is used in the project.
	  + A std::condition_variable is used in the project code to synchronize thread execution.
