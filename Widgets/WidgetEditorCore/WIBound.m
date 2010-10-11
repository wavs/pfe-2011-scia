//
//  WIBound.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WIBound.h"


@implementation WIBound

@synthesize origin;
@synthesize size;


#pragma mark -
#pragma mark Designated Initializers

-(id)init {

	if (self = [super init]) {
		
		self.origin = [[WIPoint alloc] init];
		self.size = [[WISize alloc] init];
	}
	
	return self;
}
-(id)initWithOriginX:(NSInteger)xPos Y:(NSInteger)yPos andSizeW:(NSInteger)width H:(NSInteger)height {

	if (self = [super init]) {
	
		self.origin = [[WIPoint alloc] initWithX:xPos Y:yPos];
		self.size = [[WISize alloc] initWithWidth:width Height:height];
	}
	
	return self;
}


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue {
	
	return [NSString stringWithFormat:@"%@:%@", [origin stringValue], [size stringValue]];
}


#pragma mark -
#pragma mark Memory management

-(void)dealloc {

	[origin release];
	[size release];
	[super dealloc];
}

@end
