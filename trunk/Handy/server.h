/*
 *  server.h
 *  DemoHandy
 *
 *  Created by pierre on 1/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <cstdio>

#include <string.h>
#include <string>
#include <sstream>

#include <netinet/in.h>
#include <netdb.h>

#include <vector>

#define PORT        5542
/* REPLACE with your server machine name*/
#define HOST        "localhost"
#define CLOSE		"close"
#define MSG_SIZE	100


#define DIRSIZE     8192
#define BACKLOG 1

// creating the server component



struct Pos2d
{
	int x;
	int y;
	
	Pos2d(int _x, int _y): x(_x),y(_y){}
};


class HandyServer
{
private:
	char	hostname[100];
	char	dir[DIRSIZE];
	int		sd;
	int		conn;
	int		size_recv;
	char	message[100];
	struct	sockaddr_in ssin;
	struct	hostent *hp;

	void close_connection(void);
	void sendShort(std::stringstream &messagecpp);

public:
	HandyServer();
	~HandyServer();
	
	bool Init();
	void sendPos(const std::vector<Pos2d> &pos);

};

#endif // !SERVER_H_