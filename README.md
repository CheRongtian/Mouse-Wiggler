# Mouse Wiggler (Linux Uinput)

A Linux kernel-level mouse emulator written in **C**. It creates a virtual device in user space and sends low-level input events using the **uinput** module and **libevdev** library.
 
## System Requirements

**OS**: **Linux Only** (e.g., Ubuntu 22.04+). This project relies on the Linux-specific ```uinput``` kernel module and cannot run natively on macOS or Windows.

**Environment Consistency**: Includes a ```Dockerfile``` to ensure the build environment is identical across different Linux distributions.

**Permissions**: Requires ```sudo``` to access ```/dev/uinput``` and ```/dev/input``` device files.

## Installation & Usage

### 1. Host Machine (Direct Run)

Install the required development libraries:

```bash
sudo apt update 
sudo apt install -y clang libevdev-dev pkg-config
```

Run the provided build script (Make sure you double check ```those comments``` in that shell command):

```bash
chmod +x Command.sh
sudo ./Command.sh
```

### 2. Docker (Containerized Run)

The `Dockerfile` automates the setup of the compilation environment. To allow the container to access your hardware, you must enable **privileged mode**:

```bash
# Build the image
sudo docker build -t mouse_wiggler .

# Run with hardware access
sudo docker run -it --privileged -v /dev:/dev mouse_wiggler
```

## Project Structure

**`mouse_wiggler.c`**: The main source file 

**`Dockerfile`**: Defines the Ubuntu 22.04 build environment and dependencies.

**`Command.sh`**: A shell script for local compilation and testing.

**`Docker.sh`**: A shell script to automate the Docker build and privileged execution process.
