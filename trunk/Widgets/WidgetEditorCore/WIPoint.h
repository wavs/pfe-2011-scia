//
//  WIPoint.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface WIPoint : NSObject {

	NSInteger	x;
	NSInteger	y;
}

@property (nonatomic, assign) NSInteger	x;
@property (nonatomic, assign) NSInteger	y;


#pragma mark -
#pragma mark Designated Initializers

-(id)init;
-(id)initWithX:(NSInteger)xPos Y:(NSInteger)yPos;


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue;


#pragma mark -
#pragma mark Memory Management

-(void)dealloc;

@end
