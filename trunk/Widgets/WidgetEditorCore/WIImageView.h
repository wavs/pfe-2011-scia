//
//  WIImageView.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WIView.h"
#import "WIImage.h"


@interface WIImageView : WIView {

	WIImage	*image;
}

@property (nonatomic, retain) WIImage	*image;


#pragma mark -
#pragma mark Designated Initializers

-(id)initWithImage:(WIImage*)theImage;


#pragma mark -
#pragma mark XML related methods

-(NSXMLElement*)getXMLElement;


#pragma mark -
#pragma mark Memory Management

-(void)dealloc;

@end
