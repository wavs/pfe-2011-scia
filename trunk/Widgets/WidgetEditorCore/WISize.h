//
//  WISize.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface WISize : NSObject {

	NSInteger	width;
	NSInteger	height;
}

@property (nonatomic, assign) NSInteger	width;
@property (nonatomic, assign) NSInteger	height;

#pragma mark -
#pragma mark Designated Initializers

-(id)init;
-(id)initWithWidth:(NSInteger)w Height:(NSInteger)h;


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue;

#pragma mark -
#pragma mark Memory management

-(void)dealloc;


@end
