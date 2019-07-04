#!/bin/sh

g++ ../src/loadimage.cpp -o loadimage `pkg-config --cflags --libs opencv`
