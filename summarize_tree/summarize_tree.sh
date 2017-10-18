#!/usr/bin/bash

home="$(pwd)"
path=$1

cd $path

totaldir="$(find . -type d | xargs | wc -w)"
totalfile="$(find . -type f | xargs | wc -w)"

echo "There were "$totaldir" directories."
echo "There were "$totalfile" regular files."

cd $home
