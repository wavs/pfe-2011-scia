//
//  MainWindowController.m
//  WidgetEditor
//
//  Created by Thomas Ait-taleb on 17/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "MainWindowController.h"


@implementation MainWindowController

@synthesize uiElementsArray;

-(void)insertObject:(UIElement *)p inUiElementsArrayAtIndex:(NSUInteger)index {
    [uiElementsArray insertObject:p atIndex:index];
}

-(void)removeObjectFromUiElementsArrayAtIndex:(NSUInteger)index {
    [uiElementsArray removeObjectAtIndex:index];
}

-(void)setUiElementsArray:(NSMutableArray *)a {
    uiElementsArray = a;
}

-(NSArray*)uiElementsArray {
    return uiElementsArray;
}

- (void)awakeFromNib {
	
	UIElement	*wiView = [[UIElement alloc] init];
	[wiView setTitle:@"WIView"];
	[wiView setIcon:[NSImage imageNamed:@"WIView_icon.png"]];
    
	UIElement	*wiImageView = [[UIElement alloc] init];
	[wiImageView setTitle:@"WIImageView"];
	[wiImageView setIcon:[NSImage imageNamed:@"WIImageView_icon.png"]];
	
	UIElement	*wiLabel = [[UIElement alloc] init];
	[wiLabel setTitle:@"WILabel"];
	[wiLabel setIcon:[NSImage imageNamed:@"WILabel_icon.png"]];
    
    NSMutableArray * tempArray = [NSMutableArray arrayWithObjects:wiView, wiImageView, wiLabel, nil];
    [self setUiElementsArray:tempArray];
}



#pragma mark -
#pragma mark NSCollectionViewDelegate methods

-(BOOL)collectionView:(NSCollectionView *)collectionView acceptDrop:(id <NSDraggingInfo>)draggingInfo 
				index:(NSInteger)index dropOperation:(NSCollectionViewDropOperation)dropOperation {
	
	return YES;
}

-(BOOL)collectionView:(NSCollectionView *)collectionView canDragItemsAtIndexes:(NSIndexSet *)indexes withEvent:(NSEvent *)event {
	
	return YES;
}

-(NSDragOperation)collectionView:(NSCollectionView *)collectionView validateDrop:(id <NSDraggingInfo>)draggingInfo
		proposedIndex:(NSInteger *)proposedDropIndex dropOperation:(NSCollectionViewDropOperation *)proposedDropOperation {
	
	return NSDragOperationEvery;
}

- (NSImage *)collectionView:(NSCollectionView *)collectionView draggingImageForItemsAtIndexes:(NSIndexSet *)indexes
				  withEvent:(NSEvent *)event offset:(NSPointPointer)dragImageOffset {
	
	return [NSImage imageNamed:@"WIView_icon.png"];
}

- (BOOL)collectionView:(NSCollectionView *)cv writeItemsAtIndexes:(NSIndexSet *)indexes toPasteboard:(NSPasteboard *)pasteboard {

	return YES;
}


@end
