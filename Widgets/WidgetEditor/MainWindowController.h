//
//  MainWindowController.h
//  WidgetEditor
//
//  Created by Thomas Ait-taleb on 17/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "UIElement.h"

@interface MainWindowController : NSViewController <NSCollectionViewDelegate> {

	NSMutableArray	*uiElementsArray;
}

@property (nonatomic, retain) NSMutableArray	*uiElementsArray;

@end
