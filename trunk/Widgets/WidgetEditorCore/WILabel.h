//
//  WILabel.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WIView.h"
#import "WIColor.h"

@interface WILabel : WIView {

	NSString	*text;
	WIColor		*textColor;
	NSUInteger	fontSize;
}

@property (nonatomic, retain) NSString		*text;
@property (nonatomic, retain) WIColor		*textColor;
@property (nonatomic, assign) NSUInteger	fontSize;


#pragma mark -
#pragma mark Designated Initializers

-(id)initWithText:(NSString*)theText;


#pragma mark -
#pragma mark XML related methods

-(NSXMLElement*)getXMLElement;
	

#pragma mark -
#pragma mark Memory Management

-(void)dealloc;

@end
