//
//  WIBound.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WIPoint.h"
#import "WISize.h"


@interface WIBound : NSObject {

	WIPoint	*origin;
	WISize	*size;
}

@property (nonatomic, retain) WIPoint	*origin;
@property (nonatomic, retain) WISize	*size;


#pragma mark -
#pragma mark Designated Initializers

-(id)init;
-(id)initWithOriginX:(NSInteger)xPos Y:(NSInteger)yPos andSizeW:(NSInteger)width H:(NSInteger)height;


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue;


#pragma mark -
#pragma mark Memory Management

-(void)dealloc;

@end
