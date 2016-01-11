/// COPYRIGHT NOTICE
/// Copyright (c) 2015, AFei
/// All rights reserved.
///
/// @TcpAcceptor.h
/// @Accept the connections from client

/// @version 1.0
/// @f1cheng
/// @2015.12.27

/// Socket Acceptor
#ifndef _TCPACCEPTOR_H_
#define _TCPACCEPTOR_H_

class TcpAcceptor
{
  private:
    int lst_sd;
  
  public:
    TcpAcceptor(const char *ip="", int port);
    ~TcpAcceptor();
    int listen();
    TcpStream *accept();

};

class TcpConnector
{
  public:
    TcpStream *connect(const char *server_ip, int port);
  private:
    int resolveHostName(const char *host, struct in_addr *addr);
};

class TcpStream
{
  private:
    int socket_id;

  public:
    friend class TcpAcceptor;
    friend class TcpConnector;
    ~TcpStream();
  int send(const char *buff, int len);
  int recv(char *buff, int len);
  
  private:
    TcpStream(int socket_id, struct sockaddr_in *addr);
}

#endif
