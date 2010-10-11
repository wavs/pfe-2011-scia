//
//  WILabel.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WILabel.h"


@implementation WILabel

@synthesize text;
@synthesize textColor;
@synthesize fontSize;


#pragma mark -
#pragma mark Designated Initializers

-(id)initWithText:(NSString*)theText {
	
	if (self = [super init]) {
		
		self.text = theText;
		self.textColor = [[WIColor alloc] init];
		self.fontSize = 10;
	}
	
	return self;
}


#pragma mark -
#pragma mark XML related methods

-(NSXMLElement*)getXMLElement {
	
	NSArray			*keys = [[NSArray alloc] initWithObjects:@"bounds", @"tag", @"backgroundColor", @"text", @"textColor", @"fontSize", nil];
	NSArray			*objects = [[NSArray alloc] initWithObjects:[bounds stringValue], [[NSNumber numberWithInteger:tag] stringValue], [backgroundColor stringValue], text, [textColor stringValue], [[NSNumber numberWithInteger:fontSize] stringValue], nil];
	NSDictionary	*attributes = [[NSDictionary alloc] initWithObjects:objects forKeys:keys];
	[keys release];
	[objects release];
	
	NSXMLElement	*xmlElement = [[NSXMLElement alloc] initWithName:@"WILabel"];
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
	
	[text release];
	[textColor release];
	
	[super dealloc];
}
@end
