//
//  UIElement.h
//  WidgetEditor
//
//  Created by Thomas Ait-taleb on 17/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface UIElement : NSObject {
	
	NSString	*title;
	NSImage		*icon;
}

@property(retain, readwrite) NSString	*title;
@property(retain, readwrite) NSImage	*icon;

@end
