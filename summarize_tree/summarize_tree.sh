#!/usr/bin/bash

# Save working directory
home="$(pwd)"

# Get first argument passed as the directory to be entered
path=$1

cd $path

#Find all items with type directory
totaldir="$(find . -type d | xargs | wc -w)"

#Find all items with type file
totalfile="$(find . -type f | xargs | wc -w)"

#Output
echo "There were "$totaldir" directories."
echo "There were "$totalfile" regular files."

#return to original directory
cd $home
