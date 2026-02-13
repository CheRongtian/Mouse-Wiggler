#!/bin/bash
sudo docker build -t mouse_wiggler .
sudo docker run -it --privileged -v /dev:/dev mouse_wiggler