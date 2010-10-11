//
//  UIElement.m
//  WidgetEditor
//
//  Created by Thomas Ait-taleb on 17/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "UIElement.h"


@implementation UIElement

@synthesize title;
@synthesize icon;

-(void)dealloc {

	[title release];
	[icon release];
	[super dealloc];
}

@end
