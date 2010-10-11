//
//  WIView.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WIBound.h"
#import "WIColor.h"

@interface WIView : NSObject {

	WIBound			*bounds;
	WIColor			*backgroundColor;
	NSUInteger		tag;
	NSMutableArray	*subviews;
}

@property (nonatomic, retain) WIBound			*bounds;
@property (nonatomic, retain) WIColor			*backgroundColor;
@property (nonatomic, assign) NSUInteger		tag;
@property (nonatomic, retain) NSMutableArray	*subviews;


#pragma mark -
#pragma mark Designated Initializers

-(id)init;
-(id)initWithBounds:(WIBound*)theBounds;


#pragma mark -
#pragma mark Subviews methods

-(void)addSubview:(WIView*)theView;


#pragma mark -
#pragma mark XML related methods

-(NSXMLElement*)getXMLElement;


#pragma mark -
#pragma mark Memory Management

-(void)dealloc;

@end
