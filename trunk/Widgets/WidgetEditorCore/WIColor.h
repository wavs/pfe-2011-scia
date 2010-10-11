//
//  WIColor.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface WIColor : NSObject {
	
	NSUInteger	red;
	NSUInteger	green;
	NSUInteger	blue;
}

@property (nonatomic, assign) NSUInteger	red;
@property (nonatomic, assign) NSUInteger	green;
@property (nonatomic, assign) NSUInteger	blue;


#pragma mark -
#pragma mark Designated Initializers

-(id)init;
-(id)initWithRed:(NSUInteger)r Green:(NSUInteger)g Blue:(NSUInteger)b;


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue;


#pragma mark -
#pragma mark Color class methods

+(WIColor*)redColor;
+(WIColor*)blueColor;
+(WIColor*)greenColor;
+(WIColor*)blackColor;
+(WIColor*)whiteColor;

#pragma mark -
#pragma mark Memory management

-(void)dealloc;

@end
