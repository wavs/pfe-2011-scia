//
//  WIColor.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WIColor.h"


@implementation WIColor

@synthesize red;
@synthesize green;
@synthesize blue;


#pragma mark -
#pragma mark Designated Initializers

-(id)init {
	
	if (self = [super init]) {
		
		self.red = 0;
		self.green = 0;
		self.blue = 0;
	}
	
	return self;
}

-(id)initWithRed:(NSUInteger)r Green:(NSUInteger)g Blue:(NSUInteger)b {
	
	if (self = [super init]) {
		
		self.red = r;
		self.green = g;
		self.blue = b;
	}
	
	return self;
}


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue {
	
	return [NSString stringWithFormat:@"%i,%i,%i", red, green, blue];
}


#pragma mark -
#pragma mark Color class methods

+(WIColor*)redColor {

	return [[WIColor alloc] initWithRed:255 Green:0 Blue:0];
}

+(WIColor*)blueColor {
	
	return [[WIColor alloc] initWithRed:0 Green:0 Blue:255];
}

+(WIColor*)greenColor {
	
	return [[WIColor alloc] initWithRed:0 Green:255 Blue:0];
}

+(WIColor*)blackColor {
	
	return [[WIColor alloc] initWithRed:0 Green:0 Blue:0];
}

+(WIColor*)whiteColor {
	
	return [[WIColor alloc] initWithRed:255 Green:255 Blue:255];
}

#pragma mark -
#pragma mark Memory management

-(void)dealloc {
	
	[super dealloc];
}
@end
