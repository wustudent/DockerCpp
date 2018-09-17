## Compile SystemC Project in Docker

### 1. Install *docker* and *docker-compose*

Follow these steps to **install** and **start** docker:<br>
[Docker for Windows](https://docs.docker.com/docker-for-windows/install/)<br>
[Docker for MacOS](https://docs.docker.com/docker-for-mac/install/)


### 2. Download this repo into your computer and open Powershell(in Windows) or Terminal(in MacOS)

Use following command to enter the folder:
```bash
cd DockerCpp
```

### 3. Start the compile environment
then run following commands to start the compile environment:
 
```bash
docker-compose build
docker-compose run --rm dockercpp
```

### 4. Compile your project
After ```#``` appears in the terminal, you can use following commands to build and run your project:
```bash
cd Proj
cmake -DCMAKE_CXX_STANDARD=11 -DCMAKE_BUILD_TYPE=Debug && cmake --build .
./main
```

To quit the terminal, use ```exit``` command.

You can put your own project in the Proj folder, don't forget to write a ```CMakeLists.txt``` and a ```Makefile```