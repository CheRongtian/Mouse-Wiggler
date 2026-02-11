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

CMD ["/bin/bash"]