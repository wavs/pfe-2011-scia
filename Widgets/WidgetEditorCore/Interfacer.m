//
//  Interfacer.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "Interfacer.h"
#import "WIBound.h"


@implementation Interfacer

-(NSDictionary*)TESTWIwindowAttributes {
	
	WIBound			*bounds = [[WIBound alloc] initWithOriginX:0 Y:7 andSizeW:100 H:50];
	
	NSArray			*objects = [[NSArray alloc] initWithObjects:[bounds stringValue], @"green", nil];
	[bounds release];
	NSArray			*keys = [[NSArray alloc] initWithObjects:@"bounds", @"backgroundColor", nil];
	
	NSDictionary	*WIwindowAttributes = [[NSDictionary alloc] initWithObjects:objects forKeys:keys];
	[objects release];
	[keys release];
	
	return WIwindowAttributes;
}

-(void)saveUIWithFilename:(NSString*)name {

	
	NSDictionary	*WIwindowAttributes = [self TESTWIwindowAttributes];
	
	NSXMLElement	*rootElt = [[NSXMLElement alloc] initWithName:@"WidgetUI"];
	
	NSXMLDocument	*document = [[NSXMLDocument alloc] initWithRootElement:rootElt];
	[rootElt release];
	
	NSXMLElement	*windowElt = [[NSXMLElement alloc] initWithName:@"WIWindow"];
	[windowElt setAttributesAsDictionary:WIwindowAttributes];
	[WIwindowAttributes release];
	
	[rootElt addChild:windowElt];
	[windowElt release];
	[rootElt addChild:[NSXMLElement elementWithName:@"WIButton"]];
	[rootElt addChild:[NSXMLElement elementWithName:@"WIImageView"]];
	
	NSData	*data = [document XMLDataWithOptions:NSXMLNodePrettyPrint];
	[data writeToFile:[name stringByExpandingTildeInPath] atomically:YES];
	
	[document release];
}

-(void)saveUIFromMainView:(WIView*)theView WithFilename:(NSString*)theFilename {
	
	NSXMLElement	*rootElt = [[NSXMLElement alloc] initWithName:@"WidgetUI"];
	
	NSXMLDocument	*document = [[NSXMLDocument alloc] initWithRootElement:rootElt];
	[rootElt release];
	
	NSXMLElement	*mainViewElt = [theView getXMLElement];
	
	[rootElt addChild:mainViewElt];
	[mainViewElt release];
	
	NSData	*data = [document XMLDataWithOptions:NSXMLNodePrettyPrint];
	[data writeToFile:[theFilename stringByExpandingTildeInPath] atomically:YES];
	
	[document release];
}

@end
