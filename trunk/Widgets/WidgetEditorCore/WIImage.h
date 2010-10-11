//
//  WIImage.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface WIImage : NSObject {

	NSString	*fileName;
}

@property (nonatomic, retain) NSString	*fileName;

#pragma mark -
#pragma mark Designated Initializers

-(id)initWithImageFile:(NSString*)name;


#pragma mark -
#pragma mark Value methods

-(NSString*)stringValue;

#pragma mark -
#pragma mark Memory management

-(void)dealloc;

@end
