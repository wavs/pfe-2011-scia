//
//  DragDropView.m
//  WidgetEditor
//
//  Created by wavs on 17/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import "DragDropView.h"


@implementation DragDropView

- (id)initWithFrame:(NSRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
		[self registerForDraggedTypes:[NSArray arrayWithObjects:NSPasteboardTypePNG, 
									   NSFilenamesPboardType, nil]];
    }
    return self;
}

-(void)awakeFromNib {
	[self registerForDraggedTypes:[NSArray arrayWithObjects:NSPasteboardTypePNG, 
								   NSFilenamesPboardType, nil]];
}

- (NSDragOperation)draggingEntered:(id )sender
{
	//if ((NSDragOperationGeneric & [sender draggingSourceOperationMask])
	//	== NSDragOperationGeneric) {
	[[NSColor blueColor] set];
		return NSDragOperationGeneric;
		
	//} // end if
	
	// not a drag we can use
	//return NSDragOperationNone;
	
}

- (BOOL)prepareForDragOperation:(id )sender {

	return YES;
}




- (BOOL)performDragOperation:(id )sender {
	//NSPasteboard *zPasteboard = [sender draggingPasteboard];
	// define the images  types we accept
	// NSPasteboardTypeTIFF: (used to be NSTIFFPboardType).
	// NSFilenamesPboardType:An array of NSString filenames
	//NSArray *zImageTypesAry = [NSArray arrayWithObjects:NSPasteboardTypeTIFF,
	//						   NSFilenamesPboardType, nil];
	
	//NSString *zDesiredType =
	//[zPasteboard availableTypeFromArray:zImageTypesAry];
	
	//if ([zDesiredType isEqualToString:NSPasteboardTypeTIFF]) {
	//	NSData *zPasteboardData   = [zPasteboard dataForType:zDesiredType];
	//	if (zPasteboardData == nil) {
	//		NSLog(@"Error: MyNSView zPasteboardData == nil");
	//		return NO;
	//	} // end if
		
	//	self.nsImageObj = [[NSImage alloc] initWithData:zPasteboardData];
	//	[self setNeedsDisplay:YES];
	//	return YES;
		
	//} //end if
	
	
    //if ([zDesiredType isEqualToString:NSFilenamesPboardType]) {
		// the pasteboard contains a list of file names
		//Take the first one
	//	NSArray *zFileNamesAry =
	//	[zPasteboard propertyListForType:@"NSFilenamesPboardType"];
	//	NSString *zPath = [zFileNamesAry objectAtIndex:0];
	//	NSImage *zNewImage = [[NSImage alloc] initWithContentsOfFile:zPath];
		
	//	if (zNewImage == nil) {
	//		NSLog(@"Error: MyNSView performDragOperation zNewImage == nil");
	//		return NO;
	//	}// end if
		
	//	self.nsImageObj = zNewImage;
	//	[self setNeedsDisplay:YES];
	[[NSColor greenColor] set];
		return YES;
		
	//}// end if
	
	//this cant happen ???
	//NSLog(@"Error MyNSView performDragOperation");
	//return NO;
	
}


- (void)concludeDragOperation:(id )sender {
	
	[self setNeedsDisplay:YES];
}



- (void)drawRect:(NSRect)dirtyRect {
	//if (self.nsImageObj == nil) {
		[[NSColor blackColor] set];
		NSRectFill( dirtyRect );
	//} // end if
	//NSRect zOurBounds = [self bounds];
	[super drawRect:dirtyRect];
	//[self.nsImageObj compositeToPoint:(zOurBounds.origin)
	//						operation:NSCompositeSourceOver];
}


@end
