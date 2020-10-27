#!/bin/bash

make
kvm -cdrom gb.iso
make clean
