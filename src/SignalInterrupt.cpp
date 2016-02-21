#include <iostream>
#include <cstdlib>
#include <csignal>
#include "SignalInterrupt.h"
#include "Buffer.h"

extern Buffer buffer;
void registerSig()
{
    signal(SIGINT, signalHandler);
}

void signalHandler(int sig)
{
    std::cout << "Interrupt signal("<<sig<<") received.\n";
    buffer.dumpData();
    buffer.close_db(); 
    std::cout << "saved data to Storage\n";
    exit(sig);

}


