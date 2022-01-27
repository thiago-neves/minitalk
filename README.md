<h3 align="center">42 São Paulo</h3>
<div align="center">

![License](https://img.shields.io/github/license/thiago-neves/minitalk)
![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952?color=white)
![Top language](https://img.shields.io/github/languages/top/thiago-neves/minitalk?color=007FFF)

</div>

# minitalk
A communication program in the form of a client and a server utilizing signals.

## Contents
- [Getting started]()
- [How to use]()
- [Makefile commands]()

## Getting stated

Minitalk utilizes two signals (SIGUSR1 and SIGUSR2) to communicate between the server and the client. for more information about signals see [here](https://man7.org/linux/man-pages/man7/signal.7.html).

## How to use

To compile the project you'll need to use the command `make`. after compiled you'll have two executables the `client` and `server`, then all you need to do is start the server which will give you its PID, after that just initiate the client passing the server PID and the message you desire to pass to the server.

## Makefile commands

`make` compile and generates the libft.a.

`make clean` clean all the .o files from the folder.

`make fclean` executes the make clean command and remove libft.a from the folder.

`make re` executes the make clean and make commands to recompile the library.

