#!/bin/sh

g++ src/loadimage.cpp -o bin/loadimage `pkg-config --cflags --libs opencv`
