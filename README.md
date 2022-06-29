# Table of Contents
* [About](#about)
* [Build](#build)
* [Usage](#usage)
* [Documentation](#document)


## About <a name="about"></a>
This program can be used as client to connect using TCP sockets or as server
to listen on a chosen port.

## Build <a name="build"></a>
Builded and tested in 5.18.5-arch1-1 version of arch linux.

~~~
git clone https://github.com/krisszzzz/TCP-client-server
cd TCP-client-server
make
~~~

## Usage <a name="usage"></a>
This program is using TCP sockets to connect to network with passed ip address and port or
you can use this program as server to listen on a passed port.  
~~~
Usage: ./tcp [options] <optional_arguments>  
Options:  
--help               Display this information.   
--server <port>      Start listen on a chosen port. If no port was provided the default port (80) will be used  
--client <ip> <port> Connect using TCP with selected ip address and port. 
                     You can leave out the port as an argument, in which case port 80 will be used by default. 
                     You can also leave out the ip address along with it, in which case it will be set 
                     to 127.0.0.1 (localhost). But passing a port without passing an ip address will result 
                     in an error: an ip address is always expected as the first argument.  
~~~

I checked the client side of program with [Wireshark](https://ru.wikipedia.org/wiki/Wireshark). Just for illustration I open server binded to localhost (127.0.0.1) and send packet through client. You can see full trace here.
![wire](pictures/wireshark_tcp.png)

## Documentation <a name="document"></a>
I created [pdf documentation](https://github.com/krisszzzz/TCP-client-server/blob/master/doc.pdf) with using [Doxygen](https://doxygen.nl).
