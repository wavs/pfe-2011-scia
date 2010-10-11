//
//  WISize.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WISize.h"


@implementation WISize

@synthesize width;
@synthesize height;


#pragma mark -
#pragma mark Designated Initializers

-(id)init {
	
	if (self = [super init]) {
		
		self.width = 0;
		self.height = 0;
	}
	
	return self;
}

-(id)initWithWidth:(NSInteger)w Height:(NSInteger)h {
	
	if (self = [self init]) {
		
		self.width = w;
		self.height = h;
	}
	
	return self;
}


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue {
	
	return [NSString stringWithFormat:@"%i,%i", self.width, self.height];
}


#pragma mark -
#pragma mark Memory Management

-(void)dealloc {

	[super dealloc];
}

@end
