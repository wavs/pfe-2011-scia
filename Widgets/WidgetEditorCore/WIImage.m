//
//  WIImage.m
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "WIImage.h"


@implementation WIImage

@synthesize fileName;


#pragma mark -
#pragma mark Designated Initializers

-(id)initWithImageFile:(NSString*)name {
	
	if (self = [super init]) {
		
		self.fileName = name;
	}
	
	return self;
}


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue {
	
	return fileName;
}


#pragma mark -
#pragma mark Memory Management

-(void)dealloc {
	
	[fileName release];
	
	[super dealloc];
}

@end
