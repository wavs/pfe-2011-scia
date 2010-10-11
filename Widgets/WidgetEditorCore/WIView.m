//
//  WIView.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WIView.h"


@implementation WIView

@synthesize bounds;
@synthesize backgroundColor;
@synthesize tag;
@synthesize subviews;


#pragma mark -
#pragma mark Designated Initializers

-(id)init {
	
	if (self = [super init]) {
		
		self.tag = 0;
		self.bounds = [[WIBound alloc] init];
		self.backgroundColor = [[WIColor alloc] init];
		self.subviews = [[NSMutableArray alloc] init];
	}
	
	return self;
}

-(id)initWithBounds:(WIBound*)theBounds {

	if (self = [super init]) {
	
		self.tag = 0;
		self.bounds = theBounds;
		self.backgroundColor = [[WIColor alloc] init];
		self.subviews = [[NSMutableArray alloc] init];
	}
	
	return self;
}


#pragma mark -
#pragma mark Subviews methods

-(void)addSubview:(WIView*)theView {

	[subviews addObject:theView];
}


#pragma mark -
#pragma mark XML related methods

-(NSXMLElement*)getXMLElement {
	
	NSArray			*keys = [[NSArray alloc] initWithObjects:@"bounds", @"tag", @"backgroundColor", nil];
	NSArray			*objects = [[NSArray alloc] initWithObjects:[bounds stringValue], [[NSNumber numberWithInteger:tag] stringValue], [backgroundColor stringValue], nil];
	NSDictionary	*attributes = [[NSDictionary alloc] initWithObjects:objects forKeys:keys];
	[keys release];
	[objects release];
	
	NSXMLElement	*xmlElement = [[NSXMLElement alloc] initWithName:@"WIView"];
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
	
	[bounds release];
	[backgroundColor release];
	
	[super dealloc];
}

@end
