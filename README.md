# Mouse Wiggler (Linux Uinput)

A Linux kernel-level mouse emulator written in **C**. It creates a virtual device in user space and sends low-level input events using the **uinput** module and **libevdev** library.
 
## System Requirements

**OS**: **Linux Only** (e.g., Ubuntu 22.04+). This project relies on the Linux-specific ```uinput``` kernel module and cannot run natively on macOS or Windows. Ubuntu Linux with a Graphical User Interface (GUI) is required (Wayland is **not** supported).
- To switch: Log out → Select User → Click the Gear Icon → Choose **"Ubuntu on Xorg"** → Log in.

**Environment Consistency**: Includes a ```Dockerfile``` to ensure the build environment is identical across different Linux distributions.

**Permissions**: Requires ```sudo``` to access ```/dev/uinput``` and ```/dev/input``` device files.

**Virtual Machine (UTM/QEMU):** **Mouse Capture** mode is mandatory. The host system's mouse integration will conflict with the simulated movement.
- *Action:* You must press `Control + Option` (or use the capture button) to lock the cursor exclusively inside the VM window.

## Installation & Usage

### 1. Host Machine (Direct Run)

Install the required development libraries:

```bash
sudo apt update 
sudo apt install -y clang libevdev-dev pkg-config
sudo clang -o mouse_wiggler mouse_wiggler.c $(pkg-config --cflags --libs libevdev)
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

**`Docker.sh`**: A shell script to automate the Docker build and privileged execution process.