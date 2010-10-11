//
//  WIPoint.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WIPoint.h"


@implementation WIPoint

@synthesize x;
@synthesize y;


#pragma mark -
#pragma mark Designated Initializers

-(id)init {

	if (self = [super init]) {
		
		self.x = 0;
		self.y = 0;
	}
	
	return self;
}

-(id)initWithX:(NSInteger)xPos Y:(NSInteger)yPos {

	if (self = [self init]) {
	
		self.x = xPos;
		self.y = yPos;
	}
	
	return self;
}


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue {

	return [NSString stringWithFormat:@"%i,%i", self.x, self.y];
}


#pragma mark -
#pragma mark Memory Management

-(void)dealloc {
	
	[super dealloc];
}

@end
