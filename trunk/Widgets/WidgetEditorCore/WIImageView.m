//
//  WIImageView.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WIImageView.h"


@implementation WIImageView

@synthesize image;


#pragma mark -
#pragma mark Designated Initializers

-(id)initWithImage:(WIImage*)theImage {

	if (self = [super init]) {
	
		self.image = theImage;
	}
	
	return self;
}


#pragma mark -
#pragma mark XML related methods

-(NSXMLElement*)getXMLElement {
	
	NSArray			*keys = [[NSArray alloc] initWithObjects:@"bounds", @"tag", @"backgroundColor", @"image", nil];
	NSArray			*objects = [[NSArray alloc] initWithObjects:[bounds stringValue], [[NSNumber numberWithInteger:tag] stringValue], [backgroundColor stringValue], [image stringValue], nil];
	NSDictionary	*attributes = [[NSDictionary alloc] initWithObjects:objects forKeys:keys];
	[keys release];
	[objects release];
	
	NSXMLElement	*xmlElement = [[NSXMLElement alloc] initWithName:@"WIImageView"];
	[xmlElement setAttributesAsDictionary:attributes];
	[attributes release];
	
	for (WIView *subview in subviews) {
		
		[xmlElement addChild:[subview getXMLElement]];
	}
	
	return xmlElement;
}


#pragma mark -
#pragma mark Memory management

-(void)dealloc {
	
	[image release];
	
	[super dealloc];
}

@end
