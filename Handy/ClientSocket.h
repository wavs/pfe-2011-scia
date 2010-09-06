/*
 *  ClientSocket.h
 *  DemoHandy
 *
 *  Created by pierre on 9/6/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.h"


class ClientSocket : private Socket
{
public:
	
	ClientSocket ( std::string host, int port );
	virtual ~ClientSocket(){};
	
	const ClientSocket& operator << ( const std::string& ) const;
	const ClientSocket& operator >> ( std::string& ) const;
	
};


#endif