/*
 *  server.cpp
 *  DemoHandy
 *
 *  Created by pierre on 1/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "server.h"

HandyServer::HandyServer()
{
	
}

HandyServer::~HandyServer()
{
	
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// creating the server

bool HandyServer::Init(void)
{
	strcpy((char*)this->hostname, (const char*)HOST);
	
	
	/* go find out about the desired host machine */
	
	if ((hp = gethostbyname(hostname)) == 0) {
		perror("gethostbyname");
		return(false);
	}
	
	/* fill in the socket structure with host information */
	
	
	
	memset(&ssin, 0, sizeof (struct sockaddr_in));
	ssin.sin_addr.s_addr = htonl(INADDR_ANY);
	ssin.sin_family = PF_INET;
	ssin.sin_port = htons(PORT);
	
	/* grab an Internet domain socket */
	
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		return(false);
	}
	
	
	/* connect to PORT on HOST */
	
	if (bind(sd,(struct sockaddr *)  &ssin, sizeof(ssin)) == -1) {
		perror("connect");
		close(sd);
		return(false);
	}
	
	if (listen(sd, BACKLOG) == -1)
	{
		perror("couldn't not connect");
		close(sd);
		return(false);
	}
	
	
	
	struct sockaddr_in ppin;
	socklen_t ss_sister = sizeof (struct sockaddr);
	conn = accept(sd, (struct sockaddr *)&ppin, &ss_sister);
	if (conn == -1)
	{
		perror("accept failed");
		close(sd);
		return(false);
	}
	
	memset(&message, 0, MSG_SIZE);
	
	
	
	size_recv = recv(conn, message, MSG_SIZE, MSG_PEEK);
	if ( size_recv == -1)
	{
		perror("didn't received message");
		close(sd);
		return (false);
	}
	else if ( size_recv == 0)
	{
		perror("the peer closed the connexion");
		close(sd);
		return (false);
	}
	else {
		std::cout << message << std::endl;
	}
	
	return (true);
	
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void HandyServer::close_connection(void)
{
	
	/// close the socket and send message
	if (send(conn, (const void*)CLOSE, 5, MSG_EOR) == -1)
	{
		perror("Cannot send CLOSE message");
		close(conn);
	}
	
	recv(conn, message, MSG_SIZE, MSG_PEEK);
	close(conn);
	return;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void HandyServer::sendShort(std::stringstream &messagecpp)
{
	std::string str_noob;
	str_noob = messagecpp.str();
	
	const char *message_to_send = str_noob.c_str();
	
	// server send and rcv!!
	
	send(conn, message_to_send, strlen(message_to_send), MSG_OOB);
	
	
	memset(&message, 0, MSG_SIZE);
	
	size_recv = recv(conn, message, MSG_SIZE, MSG_PEEK);
	if ( size_recv == -1)
	{
		perror("didn't received message");
		close(sd);
		return;
	}
	else if ( size_recv == 0)
	{
		perror("the peer closed the connexion");
		close(sd);
		return;
	}
	else {
		std::cout << message << std::endl;
	}	
}


void HandyServer::sendPos(const std::vector<Pos2d> &pos)

{
	std::stringstream messagecpp;
	
	// if size fo vector pos == 0 =----> " "up:1:" "
	if (pos.size() == 0) {
		messagecpp << "up:1:"  << 0 << ":" << 0;
		sendShort(messagecpp);
	} else {
		for (int i = 0; i < pos.size(); ++i) {
			messagecpp << "down:" << i << ":" << pos[i].x << ":" << pos[i].y;
			sendShort(messagecpp);
			messagecpp.flush();
			
		}
	}
	
	
}