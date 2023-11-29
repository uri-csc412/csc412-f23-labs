#!/bin/bash

# Download Crow package
wget https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow-v1.0+5.deb -O /tmp/crow.deb

# Install Crow package
sudo dpkg -i /tmp/crow.deb

# Check for and install dependencies if needed
sudo apt-get -y install -f

# Cleanup downloaded package
rm /tmp/crow.deb

# Install Boost libraries dependency for Crow
sudo apt-get update
sudo apt-get -y install libboost-all-dev