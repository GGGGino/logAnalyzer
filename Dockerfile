# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:latest

RUN apt-get update
RUN apt-get install -y cmake libboost-filesystem-dev libboost-program-options-dev libncurses5-dev

# These commands copy your files into the specified directory in the image
# and set that as the working location

COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

RUN cmake -Bbuild -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES && \
    cd build && make

# This command compiles your app using GCC, adjust for your source code
# RUN g++ -o myapp main.cpp

# This command runs your application, comment out this line to compile only
ENTRYPOINT ./build/logAnalyzer --file acces.log

LABEL Name=loganalyzer Version=0.0.1