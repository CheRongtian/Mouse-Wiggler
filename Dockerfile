FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    clang \
    lldb \
    gdb \
    libevdev-dev \
    pkg-config \
    evtest \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN clang -o mouse_wiggler mouse_wiggler.c $(pkg-config --cflags --libs libevdev)
# if you want to compile and run in local
# you could: sudo clang -o mouse_wiggler mouse_wiggler.c $(pkg-config --cflags --libs libevdev)

CMD ["/bin/bash"]